// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// stubs/Stub_Skeleton_input_Detections_boundingBox.cpp
// NEVER TOUCH this file!

#include <utility>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>
#include <boost/make_shared.hpp>

#include "Stub_Skeleton_input_Detections_boundingBox.h"
#include "../Class_Skeleton_input_Detections_boundingBox.h"

// --> Do NOT EDIT <--
namespace ConnectedVision {
namespace Module {
namespace Skeleton {




// --> Do NOT EDIT <--
/* copy constructors */
Stub_Skeleton_input_Detections_boundingBox::Stub_Skeleton_input_Detections_boundingBox(const Stub_Skeleton_input_Detections_boundingBox& other)
{
	// TODO: other.readLock
	// left
	left = other.left;
	// right
	right = other.right;
	// top
	top = other.top;
	// bottom
	bottom = other.bottom;
}

// --> Do NOT EDIT <--
/* copy assignment operator */
Stub_Skeleton_input_Detections_boundingBox& Stub_Skeleton_input_Detections_boundingBox::operator =(const Stub_Skeleton_input_Detections_boundingBox& other)
{
	Stub_Skeleton_input_Detections_boundingBox tmp(other); // re-use copy-constructor
	*this = std::move(tmp); // re-use move-assignment
	return *this;
}

// --> Do NOT EDIT <--
/* mopy assignment operator */
Stub_Skeleton_input_Detections_boundingBox& Stub_Skeleton_input_Detections_boundingBox::operator =(Stub_Skeleton_input_Detections_boundingBox&& other) noexcept
{
	// left
    std::swap(left, other.left);
	// right
    std::swap(right, other.right);
	// top
    std::swap(top, other.top);
	// bottom
    std::swap(bottom, other.bottom);

	return *this;
}

// --> Do NOT EDIT <--
/* default constructors */
Stub_Skeleton_input_Detections_boundingBox::Stub_Skeleton_input_Detections_boundingBox()
{
	clear();
}

// --> Do NOT EDIT <--
Stub_Skeleton_input_Detections_boundingBox::Stub_Skeleton_input_Detections_boundingBox(const rapidjson::Value& value)
{
	clear();
	parseJson( value );
}

// --> Do NOT EDIT <--
Stub_Skeleton_input_Detections_boundingBox::Stub_Skeleton_input_Detections_boundingBox(const std::string& str)
{
	clear();
	parseJson( str );
}

// --> Do NOT EDIT <--
Stub_Skeleton_input_Detections_boundingBox::~Stub_Skeleton_input_Detections_boundingBox()
{
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::clear()
{
	this->left = static_cast<double>(0.0);
	this->right = static_cast<double>(0.0);
	this->top = static_cast<double>(0.0);
	this->bottom = static_cast<double>(0.0);
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::parseJson(const char *str)
{
	// ignore empty data
	if ( str[0] == 0 )
		return;
	
	// parse data
	rapidjson::Document document;
	if (document.Parse<0>(str).HasParseError())
	{
		std::string context;
		size_t off = document.GetErrorOffset();
		size_t i, line_start = 0, context_start = 0;
		int num_line = 1;
		for ( i = 0; (i < off) && str[i]; i++ )
		{
			if ( str[i] == '\n' )
			{ line_start = i+1; context_start = i+1; num_line++; }
			if ( str[i] == '{' || str[i] == '[' )
			{ context_start = i; }
		}
		for ( i = context_start; str[i]; i++ )
		{
			if ( str[i] == '\n' || str[i] == '\r' ) break;
			context += str[i];
			if ( str[i] == '}' || str[i] == ']' ) break;
		}
		throw ConnectedVision::runtime_error( std::string("parse error of JSON Object: ") + rapidjson::GetParseError_En(document.GetParseError()) + std::string(" at line ") + ConnectedVision::intToStr( num_line ) + ": " + context);
	}

	parseJson(document);
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::parseJson(const rapidjson::Value& value)
{
	clear();
	if ( !value.IsObject() )
		throw ConnectedVision::runtime_error( "no JSON Object");

	// left
	if ((value.HasMember("left")) && value["left"].IsNumber())
	{
		set_left( value["left"].GetDouble() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'left'");

	// right
	if ((value.HasMember("right")) && value["right"].IsNumber())
	{
		set_right( value["right"].GetDouble() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'right'");

	// top
	if ((value.HasMember("top")) && value["top"].IsNumber())
	{
		set_top( value["top"].GetDouble() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'top'");

	// bottom
	if ((value.HasMember("bottom")) && value["bottom"].IsNumber())
	{
		set_bottom( value["bottom"].GetDouble() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'bottom'");

}

// --> Do NOT EDIT <--
std::string Stub_Skeleton_input_Detections_boundingBox::toJsonStr() const
{
	rapidjson::StringBuffer s;
	rapidjson::Document doc; doc.SetObject();
	this->toJson(doc, doc.GetAllocator());
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
	doc.Accept(writer);
	return std::string(s.GetString());
}

// --> Do NOT EDIT <--
std::string Stub_Skeleton_input_Detections_boundingBox::toJson() const
{
	rapidjson::StringBuffer s;
	rapidjson::Document doc; doc.SetObject();
	this->toJson(doc, doc.GetAllocator());
	rapidjson::Writer<rapidjson::StringBuffer> writer(s);
	doc.Accept(writer);
	return std::string(s.GetString());
}

// --> Do NOT EDIT <--
rapidjson::Value& Stub_Skeleton_input_Detections_boundingBox::toJson(rapidjson::Value& node, rapidjson::Value::AllocatorType& allocator) const
{
	{ // left
		node.AddMember("left", rapidjson::Value().SetDouble( get_left() ), allocator);
	}
	{ // right
		node.AddMember("right", rapidjson::Value().SetDouble( get_right() ), allocator);
	}
	{ // top
		node.AddMember("top", rapidjson::Value().SetDouble( get_top() ), allocator);
	}
	{ // bottom
		node.AddMember("bottom", rapidjson::Value().SetDouble( get_bottom() ), allocator);
	}
	return node;
}

// --> Do NOT EDIT <--
double Stub_Skeleton_input_Detections_boundingBox::get_left() const
{
	return( this->left );
}

// --> Do NOT EDIT <--
const double Stub_Skeleton_input_Detections_boundingBox::getconst_left() const
{
	return( this->left );
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::set_left(double value)
{
	this->left = value;
}

// --> Do NOT EDIT <--
double Stub_Skeleton_input_Detections_boundingBox::get_right() const
{
	return( this->right );
}

// --> Do NOT EDIT <--
const double Stub_Skeleton_input_Detections_boundingBox::getconst_right() const
{
	return( this->right );
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::set_right(double value)
{
	this->right = value;
}

// --> Do NOT EDIT <--
double Stub_Skeleton_input_Detections_boundingBox::get_top() const
{
	return( this->top );
}

// --> Do NOT EDIT <--
const double Stub_Skeleton_input_Detections_boundingBox::getconst_top() const
{
	return( this->top );
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::set_top(double value)
{
	this->top = value;
}

// --> Do NOT EDIT <--
double Stub_Skeleton_input_Detections_boundingBox::get_bottom() const
{
	return( this->bottom );
}

// --> Do NOT EDIT <--
const double Stub_Skeleton_input_Detections_boundingBox::getconst_bottom() const
{
	return( this->bottom );
}

// --> Do NOT EDIT <--
void Stub_Skeleton_input_Detections_boundingBox::set_bottom(double value)
{
	this->bottom = value;
}


} // namespace Skeleton
} // namespace Module
} // namespace ConnectedVision