#pragma once
#include <string>

#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base
{
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s):
		lhs(l), rhs(r), opSym(s) { }

	// abstract class: BinaryQuery doesn't define eval
	std::string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;		// right- and left-hand operands
	std::string opSym;	// name of the operator
};

