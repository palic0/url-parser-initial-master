#include "Url.h"

#include <numeric>
#include <sstream>
#include <memory>

#include "FragmentExtractor.h"
#include "SchemeExtractor.h"
#include "LocationExtractor.h"
#include "QueryExtractor.h"
#include "PathExtractor.h"
#include "UrlFormatException.h"
using namespace std;

Url::Url(const string& url)
	: _fragmentExtractor(nullptr)
	, _schemeExtractor(nullptr)
	, _locationExtractor(nullptr)
	, _queryExtractor(nullptr)
	, _pathExtractor(nullptr)
{
	// URL should be parsed as follows
	string parsing = url;

	// 1. Check for a fragment and remove it from url if it is 
	_fragmentExtractor = make_unique<FragmentExtractor>(parsing);
	if (_fragmentExtractor->HasComponent())
	{
		parsing = _fragmentExtractor->GetBase();
	}

	// 2. Check for a scheme and remove it from url if it is found
	_schemeExtractor = make_unique<SchemeExtractor>(parsing);
	if (_schemeExtractor->HasComponent())
	{
		parsing = _schemeExtractor->GetBase();
	}

	// 3. Check for a lication and remove it from url if it is found
	_locationExtractor = make_unique<LocationExtractor>(parsing);
	if (_schemeExtractor->HasComponent())
	{
		parsing = _locationExtractor->GetBase();
	}

	// 4. Check for a query and remove it from url if it is found
	_queryExtractor = make_unique<QueryExtractor>(parsing);
	if (_queryExtractor->HasComponent())
	{
		parsing = _queryExtractor->GetBase();
	}

	// 5. Only the path remains
	_pathExtractor = make_unique<PathExtractor>(parsing);
	parsing = _pathExtractor->GetBase();


	// 6. If a scheme was provided, but no network location, throw a UrlFormatException
	if ((_schemeExtractor->HasComponent)())
	{
		if ((_locationExtractor->HasComponent)())
		{

		}
		else
		{
			throw UrlFormatException("A scheme was provided,but a network location was not.");
		}
	}
	
	
}

std::string Url::GetFragment() const
{
	return _fragmentExtractor->HasComponent() ? _fragmentExtractor->GetComponent() : "";
}


std::string Url::GetScheme() const
{
	return _schemeExtractor->HasComponent() ? _schemeExtractor->GetComponent() : "";
}

std::string Url::GetLocation() const
{
	return _locationExtractor->HasComponent() ? _locationExtractor->GetComponent() : "";
}

std::string Url::GetPath() const
{
	return _pathExtractor->HasComponent() ? _pathExtractor->GetComponent() : "";
}

std::string Url::GetQuery() const
{
	return _queryExtractor->HasComponent() ? _queryExtractor->GetComponent() : "";
}

std::ostream& operator<<(std::ostream& stream, const Url& url) 
{	
	

	if ((url._schemeExtractor->HasComponent)())
	{
		stream << "URL:" << (url.GetScheme)() << "://";
	}
	if ((url._locationExtractor->HasComponent)())
	{
		stream << (url.GetLocation)() << "/";
	}
	if ((url._pathExtractor->HasComponent)())
	{
		stream << (url.GetPath)();
	}
	if ((url._queryExtractor->HasComponent)())
	{
		stream << "?" << (url.GetQuery)();
	}
	if ((url._fragmentExtractor->HasComponent)())
	{
		stream << "#" << (url.GetFragment)();
	}
	stream << endl;

	return stream;
}