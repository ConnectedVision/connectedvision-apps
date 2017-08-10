// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// stubs/Store_SQLite_Stub_Skeleton_output_Average.cpp
// NEVER TOUCH this file!

#include <exception>
#include <boost/assign/list_of.hpp>

#include "../Store_SQLite_Skeleton_output_Average.h"

#include "Store_SQLite_Stub_Skeleton_output_Average.h"

// --> Do NOT EDIT <--
namespace ConnectedVision {
namespace Module {
namespace Skeleton {
namespace DataHandling {

//////////////////////////////////////////////////////////////////////////////
//
// Store_SQLite_Stub_Skeleton_output_Average
//
//////////////////////////////////////////////////////////////////////////////

// --> Do NOT EDIT <--
static const std::string _tableName = "Skeleton_output_Average";

// --> Do NOT EDIT <--
static const std::vector<std::string> _columnDesc = boost::assign::list_of
	("'_sortID' BIGINT NOT NULL DEFAULT '0' /* object sortable id () */")
	("'id' VARCHAR(32) NOT NULL DEFAULT '' /*  (string) */")
	("'configID' VARCHAR(32) NOT NULL DEFAULT '' /*  (string) */")
	("'timestamp' BIGINT NOT NULL DEFAULT '0' /* first detection (integer) */")
	("'color.R' BIGINT /* red (integer) */")
	("'color.G' BIGINT /* green (integer) */")
	("'color.B' BIGINT /* blue (integer) */")
;

// --> Do NOT EDIT <--
Store_SQLite_Stub_Skeleton_output_Average::Store_SQLite_Stub_Skeleton_output_Average(const id_t& configID, DBConnection& db) :
	Store_SQLite_BaseClass<Class_Skeleton_output_Average>(configID, db, _tableName, _columnDesc)
{
}

// --> Do NOT EDIT <--
Store_SQLite_Stub_Skeleton_output_Average::~Store_SQLite_Stub_Skeleton_output_Average()
{
}

#ifdef ENABLE_SQLITE_SEARCH
// --> Do NOT EDIT <--
/**
 *  Get objects filtered by id
 */
std::vector<shared_ptr<const Class_Skeleton_output_Average> > Store_SQLite_Stub_Skeleton_output_Average::getBy_id(const ConnectedVision::id_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("id", Store::Op::EQUAL, IDToStr(val) ) );
	return getByFilter(filterList, sortList);
}

// --> Do NOT EDIT <--
/**
 *  Get objects filtered by configID
 */
std::vector<shared_ptr<const Class_Skeleton_output_Average> > Store_SQLite_Stub_Skeleton_output_Average::getBy_configID(const ConnectedVision::id_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("configID", Store::Op::EQUAL, IDToStr(val) ) );
	return getByFilter(filterList, sortList);
}

// --> Do NOT EDIT <--
/**
 *  Get objects filtered by timestamp
 */
std::vector<shared_ptr<const Class_Skeleton_output_Average> > Store_SQLite_Stub_Skeleton_output_Average::getBy_timestamp(const ConnectedVision::timestamp_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("timestamp", Store::Op::EQUAL, val) );
	return getByFilter(filterList, sortList);
}

#endif

// --> Do NOT EDIT <--
int Store_SQLite_Stub_Skeleton_output_Average::readObject(sqlite3_stmt *stmt, shared_ptr<const Class_Skeleton_output_Average>& outObj, sqlite3 *db)
{
	int error = SQLITE_ROW;

	int64_t objSortID = sqlite3_column_int64(stmt, 0);
	int64_t sortID = objSortID;
	outObj.reset( new Class_Skeleton_output_Average() );
	auto obj = this->create();

	while ( (error == SQLITE_ROW) && (sortID == objSortID) )
	{
		// process row
			// Skeleton_output_Average_id -> ConnectedVision::id_t
  			if ( sqlite3_column_type(stmt, 1) != SQLITE_NULL )
  				obj->set_id( strToID( reinterpret_cast<const char *>(sqlite3_column_text(stmt,1) ) ) );
			// Skeleton_output_Average_configID -> ConnectedVision::id_t
  			if ( sqlite3_column_type(stmt, 2) != SQLITE_NULL )
  				obj->set_configID( strToID( reinterpret_cast<const char *>(sqlite3_column_text(stmt,2) ) ) );
			// Skeleton_output_Average_timestamp -> ConnectedVision::timestamp_t
  			if ( sqlite3_column_type(stmt, 3) != SQLITE_NULL )
  				obj->set_timestamp( sqlite3_column_int64(stmt,3) );
			// Skeleton_output_Average_color -> Class_Skeleton_output_Average_color
  			{
  				boost::shared_ptr<Class_Skeleton_output_Average_color>&& o1 = obj->get_color(); // rvalue reference for const functions
  				if ( !o1 ) o1.reset( new Class_Skeleton_output_Average_color );
				// Skeleton_output_Average_color_R -> int64_t
  				if ( sqlite3_column_type(stmt, 4) != SQLITE_NULL )
  					o1->set_R( sqlite3_column_int64(stmt,4) );
				// Skeleton_output_Average_color_G -> int64_t
  				if ( sqlite3_column_type(stmt, 5) != SQLITE_NULL )
  					o1->set_G( sqlite3_column_int64(stmt,5) );
				// Skeleton_output_Average_color_B -> int64_t
  				if ( sqlite3_column_type(stmt, 6) != SQLITE_NULL )
  					o1->set_B( sqlite3_column_int64(stmt,6) );
  			}

		error = sqlite3_step(stmt);
		if ( error == SQLITE_ROW )
			sortID = sqlite3_column_int64(stmt, 0);
	}

	outObj = this->make_const(obj);
	return error;
}

// --> Do NOT EDIT <--
int Store_SQLite_Stub_Skeleton_output_Average::writeObject(sqlite3_stmt *stmt, const shared_ptr<const Class_Skeleton_output_Average>& obj, sqlite3 *db, const int64_t sortID)
{
	int error = 0;


		sqlite3_reset(stmt);
		sqlite3_clear_bindings(stmt);

		bind_Skeleton_output_Average( stmt, obj, sortID );

		bind_color( stmt, obj->getconst_color(), sortID );
		// write object base data and sub objects
		error = sqlite3_step(stmt);
		if ( error != SQLITE_DONE )
			return error;
	return error;
}

// --> Do NOT EDIT <--
void Store_SQLite_Stub_Skeleton_output_Average::bind_Skeleton_output_Average(sqlite3_stmt *stmt, const boost::shared_ptr<const Class_Skeleton_output_Average>& obj, const int64_t sortID) const
{
	sqlite3_bind_int64(stmt, 1, sortID );
	sqlite3_bind_text(stmt, 2, IDToChar(obj->getconst_id()), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, IDToChar(obj->getconst_configID()), -1, SQLITE_TRANSIENT);
	sqlite3_bind_int64(stmt, 4, obj->getconst_timestamp() );
	// object: color handled separately
}

// --> Do NOT EDIT <--
void Store_SQLite_Stub_Skeleton_output_Average::bind_color(sqlite3_stmt *stmt, const boost::shared_ptr<const Class_Skeleton_output_Average_color>& obj, const int64_t sortID) const
{
	sqlite3_bind_int64(stmt, 1, sortID );
  	sqlite3_bind_int64(stmt, 5, obj->getconst_R() );
  	sqlite3_bind_int64(stmt, 6, obj->getconst_G() );
  	sqlite3_bind_int64(stmt, 7, obj->getconst_B() );
}

// --> Do NOT EDIT <--
void Store_SQLite_Stub_Skeleton_output_Average::appendObjectGrouping(std::vector< Store::SortEntry >& sortList) const
{
	sortList.push_back( Store::SortEntry ("_sortID", Store::Order::ASC) );
}

// --> Do NOT EDIT <--
/**
 *  append object internal sort criteria to list
 */
const std::string Store_SQLite_Stub_Skeleton_output_Average::objectKey() const
{
	return std::string("_sortID");
}


//////////////////////////////////////////////////////////////////////////////
//
// Store_SQLite_Factory_Stub_Skeleton_output_Average
//
//////////////////////////////////////////////////////////////////////////////

// --> Do NOT EDIT <--
Store_SQLite_Factory_Stub_Skeleton_output_Average::Store_SQLite_Factory_Stub_Skeleton_output_Average(DBConnection& db) :
	db(db)
{}

// --> Do NOT EDIT <--
Store_SQLite_Factory_Stub_Skeleton_output_Average::~Store_SQLite_Factory_Stub_Skeleton_output_Average()
{}

shared_ptr< ConnectedVision::DataHandling::IStore_ReadWrite<Class_Skeleton_output_Average> > Store_SQLite_Factory_Stub_Skeleton_output_Average::create(const id_t configID = ID_NULL)
{
#ifdef Store_SQLite_Factory_Skeleton_output_Average_enabled
	return boost::dynamic_pointer_cast< ConnectedVision::DataHandling::IStore_ReadWrite<Class_Skeleton_output_Average> > (make_shared< DataHandling::Store_SQLite_Skeleton_output_Average >(configID, this->db));
#else
	return shared_ptr< ConnectedVision::DataHandling::IStore_ReadWrite<Class_Skeleton_output_Average> >();
#endif
}


} // namespace DataHandling
} // namespace Skeleton
} // namespace Module
} // namespace ConnectedVision