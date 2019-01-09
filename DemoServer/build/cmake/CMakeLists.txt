cmake_minimum_required(VERSION 2.8.12)

project(DemoServer)

# download Conan CMake wrapper file if it does not already exist
if(NOT EXISTS "${CMAKE_CURRENT_LIST_DIR}/conan.cmake")
	message(STATUS "downloading conan.cmake from https://github.com/memsharded/cmake-conan")
	file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake" "${CMAKE_CURRENT_LIST_DIR}/conan.cmake")
endif()

include(${CMAKE_CURRENT_LIST_DIR}/conan.cmake)

set(conanOptions)

# if a specific toolchain e.g. form ARM build was specified, then pass it on to the Connected Vision Conan package as an option
if(CMAKE_TOOLCHAIN_FILE)
	set(conanOptions "ConnectedVision:toolchain=${CMAKE_TOOLCHAIN_FILE}")
endif()

# call Conan CMake without targets
conan_cmake_run(REQUIRES "ConnectedVision/2.3.0@covi/stable" OPTIONS "${conanOptions}" BASIC_SETUP BUILD outdated)

# function for extracting parameters from conanbuildinfo.cmake file generated as a result of calling conan_cmake_run
function(get_conan_variable name result)
	include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
	set(${result} ${${name}} PARENT_SCOPE)
endfunction()

# extract the Connected Vision include directory
get_conan_variable("CONAN_INCLUDE_DIRS_CONNECTEDVISION" includeDir)

# load the Connected Vision CMake helper functions
include(${includeDir}/common.cmake)

# call Conan CMake with targets
conan_cmake_run(REQUIRES "ConnectedVision/2.3.0@covi/stable" OPTIONS "${conanOptions}" BASIC_SETUP CMAKE_TARGETS BUILD outdated)

add_subdirectory(../../../Skeleton/build/cmake Skeleton)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/../../" CACHE PATH "default install path" FORCE)
endif()

# create the version info file based on the current Git checkout
get_filename_component(rootDirAbs "../../.." REALPATH BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
create_version_info_file("${rootDirAbs}" "${rootDirAbs}/DemoServer/build/resources/VersionInfoTemplate.h" "${rootDirAbs}/DemoServer/build/resources/VersionInfo.h")

set(platformSpecificSources)
set(resourceFiles)

if(MSVC)
	set(resourceFiles
		../resources/ConnectedVision.ico
		../resources/DemoServer.rc
	)
	
	get_conan_variable("CONAN_INCLUDE_DIRS_STACKWALKER" stackWalkerIncludeDir)
	
	set(platformSpecificSources
		${stackWalkerIncludeDir}/StackWalker.cpp
		${resourceFiles}
	)
endif()

set(sourceFiles
	../../src/MyServer.cpp
	../../src/main.cpp
	${platformSpecificSources}
)

if(resourceFiles)
	source_group("Resource Files" FILES ${resourceFiles})
endif()

add_executable(${PROJECT_NAME} ${sourceFiles})

target_link_libraries(${PROJECT_NAME}
	Skeleton
	CONAN_PKG::ConnectedVision
)

if(MSVC)
	# set startup project
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
	
	# set debugger working directory so that the same data directory will be used for all configurations (Debug/Release) when starting the server from within Visual Studio
	set(binDir "${CMAKE_INSTALL_PREFIX}/bin")
	file(MAKE_DIRECTORY "${binDir}")
	set_target_properties(${PROJECT_NAME} PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${binDir}")
endif()

get_bin_install_directory(dst)
install(TARGETS ${PROJECT_NAME} DESTINATION ${dst})