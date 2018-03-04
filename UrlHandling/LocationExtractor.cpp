#include "LocationExtractor.h"


LocationExtractor::LocationExtractor(const std::string & value)
{
	//if the string starts with "//" it has a location
	std::size_t found = value.find("//");
	if (found != std::string::npos)
	{

		// check if there is no thrid slash
		std::size_t thirdSlash = value.find("com");
		if (thirdSlash != std::string::npos)
		{
			_component = value.substr(value.find("//") + 2, value.find("com")+1);
			_base = value.substr(value.find("com")+3, value.length());
			_hasLocation = true;
		}

		std::size_t thirdSlashn = value.find("net");
		if (thirdSlashn != std::string::npos)
		{
			_component = value.substr(value.find("//") + 2, value.find("net") + 1);
			_base = value.substr(value.find("net") + 3, value.length());
			_hasLocation = true;
		}

		std::size_t thirdSlashe = value.find("edu");
		if (thirdSlashe != std::string::npos)
		{
			_component = value.substr(value.find("//") + 2, value.find("edu") + 1);
			_base = value.substr(value.find("net") + 3, value.length());
			_hasLocation = true;
		}
		// check if is empty
		std::size_t emptyLocation = value.find("///");
		if (emptyLocation != std::string::npos)
		{
			
			_base = value.substr(value.find("///", value.length()));
			_hasLocation = false;
		}


	}
	//if you matches return false for _hasLocation
	else if (found = std::string::npos)
	{
		_hasLocation = false;
	}
}


bool LocationExtractor::HasComponent() const
{
	// has location will be true if it has "//" or false if it doesn't
	return _hasLocation;
}

const std::string & LocationExtractor::GetBase() const
{
	return _base;
}

const std::string & LocationExtractor::GetComponent() const
{
	return _component;
}

