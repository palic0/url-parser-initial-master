#include "FragmentExtractor.h"

int ftrue;

FragmentExtractor::FragmentExtractor(const std::string & value)
{
	// look for '#' character
	std::size_t found = value.find("#");
	// if exists, _component = everything to the right of '#'
	if (found != std::string::npos)
	{
		_component = value.substr(value.find("#") + 1, value.length());
		_base = value.substr(0, value.find("#"));
		ftrue = 1;
	}
	else
	{
		_base = value.substr(0, value.length());
		ftrue = 0;
	}
}

bool FragmentExtractor::HasComponent() const
{
	if (ftrue == true) return true;
	if (ftrue == false) return false;

}

const std::string & FragmentExtractor::GetBase() const
{
	return _base;
}

const std::string & FragmentExtractor::GetComponent() const
{
	return _component;
}
