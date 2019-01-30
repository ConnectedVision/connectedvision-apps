# Connected Vision Apps

## Build on Windows (x86/x86_64) with Visual Studio 2017

1. install the [Connected Vision Core](https://github.com/ConnectedVision/connectedvision/blob/master/README.md)
2. clone the [Connected Vision Apps repository](https://github.com/ConnectedVision/connectedvision-apps) into your working directory (e.g. `C:\ConnectedVisionApps`)
3. create a temporary directory for the Visual Studio solution (**this is a temporary file, the main project file is the CMake file!**), object files and other build artefacts within the `DemoServer\build` directory and switch into it (e.g. `DemoServer\build\temp`).
	- `mkdir C:\ConnectedVisionApps\DemoServer\build\temp`
	- `cd C:\ConnectedVisionApps\DemoServer\build\temp`
4. execute CMake configure
	- `cmake -G "Visual Studio 15 2017 Win64" ..\cmake`
5. build the `DemoServer.sln` solution using Visual Studio 2017 or from the command line
	- `cmake --build . --config Release --target install`

## Build on Linux (x86/x86_64) with GCC

1. install the [Connected Vision Core](https://github.com/ConnectedVision/connectedvision/blob/master/README.md)
2. clone the [Connected Vision Apps repository](https://github.com/ConnectedVision/connectedvision-apps) into your working directory
3. create and change to a temporary working directory
	- `mkdir $HOME/ConnectedVisionApps/DemoServer/build/temp`
	- `cd $HOME/ConnectedVisionApps/DemoServer/build/temp`
4. execute CMake configure:
	- `cmake ../cmake`
5. build the project
	- `cmake --build . --config Release --target install`

## Using the Demo Server
1. start the Demo Server executable
	- Windows:
		- if asked, confirm the firewall message
		- in case the console shows an exception like `Exception: no network interface found (install at least a loopback adapter)` then do as suggested:
			- Windows 7: `devmgmt.msc -> Action -> add legacy hardware -> next -> Install the hardware [...] -> next -> Network adapters -> next -> Microsoft Loopback Adapter -> next -> next -> finish`
			- Windows 10: `hdwwiz.cpl -> next -> Install the hardware [...] -> next -> Network adapters -> next -> Microsoft KM-TEST Loopback Adapter -> next -> next -> finish`
1. open [http://localhost:2020](http://localhost:2020) in a web browser
	- you should see the Connected Vision overview page with all available modules
	- for a bare Demo Server, these are the core modules plus the `Skeleton` module

## Developing a Connected Vision Module

See [Module Developer Guide](doc/ModuleDeveloperGuide.md)

## Using a Connected Vision Module

See [Skeleton Module API documentation](https://htmlpreview.github.io/?https://raw.githubusercontent.com/ConnectedVision/connectedvision-apps/dev/Skeleton/doc/html/index.html)
