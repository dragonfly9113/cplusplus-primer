#pragma once
#include <memory>

#include "TextQuery.h"
#include "QueryResult.h"

// Abstract class acts as a base class for concrete query types; all members a private
class Query_base
{
	friend class Query;
protected:
	using line_no = TextQuery::line_no;	// used in the eval functions
	virtual ~Query_base() = default;
private:
	// eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQuery&) const = 0;

	// rep is a string representation of the query
	virtual std::string rep() const = 0;
};
