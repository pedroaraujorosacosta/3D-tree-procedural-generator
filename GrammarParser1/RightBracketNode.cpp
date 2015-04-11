#include "RightBracketNode.h"
#include <iostream>

namespace GeneratorNodes
{
	RightBracketNode::RightBracketNode() : tokenString("]")
	{

	}

	std::string RightBracketNode::getTokenString() const
	{
		return tokenString;
	}

	void RightBracketNode::print() const
	{
		std::cout << tokenString;
	}
}