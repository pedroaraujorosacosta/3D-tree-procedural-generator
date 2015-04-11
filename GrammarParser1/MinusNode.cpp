#include "MinusNode.h"
#include <iostream>

namespace GeneratorNodes
{
	MinusNode::MinusNode() : tokenString("-")
	{

	}

	std::string MinusNode::getTokenString() const
	{
		return tokenString;
	}

	void MinusNode::print() const
	{
		std::cout << tokenString;
	}
}