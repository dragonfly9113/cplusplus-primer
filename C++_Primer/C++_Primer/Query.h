#pragma once
#include <string>

#include "Query_base.h"

// Interface class to manage the Query_base inheritance hierarchy
class Query
{
	// these operators need access to the shared_ptr constructor
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query(const std::string&);  // builds a new WordQuery

	// interface functions: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const
						{ return q->eval(t); }
	std::string rep() const { return q->rep(); }

private:
	Query(std::shared_ptr<Query_base> query): q(query) {}
	std::shared_ptr<Query_base> q;
};
