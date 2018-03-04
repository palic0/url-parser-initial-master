#include "QueryExtractor.h"
#pragma warning(disable : 4996)


int qtrue;


QueryExtractor::QueryExtractor(const std::string & value)
{
	std::size_t found = value.find("?");
	if (found != std::string::npos)
	{
		if (value.find("?") == value.length())
		{
			//if the location of "?" is the length of the string then there is an empty query
			//_component = nullptr;
			_base = value.substr(0, value.find("?")-1);
			qtrue = 1;
		}
		else
		{
			_component = value.substr(value.find("?") + 1, value.length());
			_base = value.substr(0, value.find("?"));
			qtrue = 1;
		}

	}
	else
	{
		qtrue = 0;
	}

}

bool QueryExtractor::HasComponent() const
{
	//if (_component.length() > _base.length()) return true;
	if (qtrue == 1) return true;
	if (qtrue == 0) return false;
}

const std::string & QueryExtractor::GetBase() const
{
	return _base;
}

const std::string & QueryExtractor::GetComponent() const
{
	return _component;
}

//method to split the string and return the vector
std::vector<std::string> split(std::string component, std::string delim) {

	//converting the string into pointer of characters
	char* cstr = const_cast<char*>(component.c_str());
	char* current;

	std::vector<std::string> _parameters;

	current = strtok(cstr, delim.c_str());
	while (current != NULL) {
		_parameters.push_back(current);
		current = strtok(NULL, delim.c_str());
	}

	//returning the vector
	return _parameters;
}




const std::vector<std::string>& QueryExtractor::GetQueryParameters() const
{	
	std::string _delimiter = "&";
	return split(_component, _delimiter);
}

void QueryExtractor::FindParameters()
{
	
}

