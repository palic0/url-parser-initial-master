#include "SchemeExtractor.h"

int strue;

SchemeExtractor::SchemeExtractor(const std::string & value)
{
	std::size_t found = value.find("://");
	if (found != std::string::npos)
	{
		//everything to the left of ":" becomes the component
		_component = value.substr(0, value.find(":"));

		//everything to the right of ":" including // becomes the base
		_base = value.substr(value.find(":")+1, value.length());

		// check for scheme type
		std::size_t findHttp = value.find("http");
		std::size_t findFile = value.find("file");

		//if "http" was found that means it either has http or https
		if (findHttp != std::string::npos)
		{
			SchemeType _type = SchemeType::Net;
		}
		//if "file" was found that means it has file
		if (findFile != std::string::npos)
		{
			SchemeType _type = SchemeType::Local;
		}
		//if both cases above are not found it is then unknown
		else
		{
			SchemeType _type = SchemeType::Unknown;
		}

		strue = 1;
	}
	else
	{
		strue = 0;
	}
}



bool SchemeExtractor::HasComponent() const
{
	if (strue == true) return true;
	if (strue == false) return false;
}

const std::string & SchemeExtractor::GetBase() const
{
	return _base;
}

const std::string & SchemeExtractor::GetComponent() const
{
	return _component;
}

SchemeType SchemeExtractor::GetType() const
{
	return _type;
}