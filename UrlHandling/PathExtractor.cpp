#include "PathExtractor.h"
#pragma warning(disable : 4996)

PathExtractor::PathExtractor(const std::string & value)
{
	std::size_t found = value.find("/");
	if (found != std::string::npos)
	{
		_component = value.substr(1, value.length());
	}
	else
	{
		
	}
}

//method to split the string and return the vector
std::vector<std::string> splitp(std::string component, std::string delim) {

	//converting the string into pointer of characters
	char* cstr = const_cast<char*>(component.c_str());
	char* current;

	std::vector<std::string> _pathComponents;

	current = strtok(cstr, delim.c_str());
	while (current != NULL) {
		_pathComponents.push_back(current);
		current = strtok(NULL, delim.c_str());
	}

	//returning the vector
	return _pathComponents;
}



bool PathExtractor::HasComponent() const
{
	if (_component.length() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

const std::string& PathExtractor::GetBase() const
{
	return _base;
}

const std::string& PathExtractor::GetComponent() const
{
	return _component;
}

bool PathExtractor::IsAbsolute() const
{
	return true;
}

const std::vector<std::string>& PathExtractor::GetPathComponents() const
{
	std::string _delimiter = "/";
	return splitp(_component, _delimiter);
}