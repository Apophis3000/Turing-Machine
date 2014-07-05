#include "Estate.h"

using std::string;

Estate::Estate(string id, EstateType type)
{
	this->id = id;
	this->type = type;
}

string Estate::GetId()
{
	return this->id;
}

EstateType Estate::GetType()
{
	return this->type;
}