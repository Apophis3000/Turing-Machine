#ifndef _Estate_h
#define _Estate_h

#include<string>

enum EstateType
{
	Start,
	Default,
	Final
};

class Estate
{
private:
	std::string id;
	EstateType type;
public:
	Estate(std::string id, EstateType type);
	std::string GetId();
	EstateType GetType();
};

#endif