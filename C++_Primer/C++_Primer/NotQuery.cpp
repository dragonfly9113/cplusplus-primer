#include "pch.h"
#include "NotQuery.h"

QueryResult
NotQuery::eval(const TextQuery& text) const
{
	// virtual call to eval through the Query operand
	auto result = query.eval(text);

	// start out with an empty result set
	auto ret_lines = std::make_shared<std::set<line_no>>();





}
