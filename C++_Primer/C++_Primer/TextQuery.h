#pragma once
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <set>

class QueryResult;  // declaration needed for return type in the query funciton.
class TextQuery
{
public:
	// to make our code a bit easier to read, define a type member to refer to line numbers.
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file;  // input file
	// map of each word to the set of line numbers
	std::map<std::string,
		std::shared_ptr<std::set<line_no>>> wm;
};

