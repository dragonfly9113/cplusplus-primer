#include "pch.h"
#include "Query.h"
#include "WordQuery.h"

std::ostream& operator<<(std::ostream& os, const Query& query)
{
	// Query::rep makes a virtual call through its Query_base pointer to rep()
	return os << query.rep();
}

inline
Query::Query(const std::string &s): q(new WordQuery(s)) { }
