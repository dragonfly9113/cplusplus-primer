#pragma once
#include "Query_base.h"
#include "Query.h"

class QueryResult;
class TextQuery;

class NotQuery : public Query_base
{
	friend Query operator~(const Query &);
	NotQuery(const Query &q): query(q) { }
	
	// concrete class: NotQuery defines all inherited pure virtual functions
	std::string rep() const { return "~(" + query.rep() + ")"; }
	QueryResult eval(const TextQuery&) const;

	Query query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}
