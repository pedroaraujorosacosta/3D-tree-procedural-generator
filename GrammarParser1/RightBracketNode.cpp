#include "RightBracketNode.h"
#include <iostream>

namespace GeneratorNodes
{
	RightBracketNode::RightBracketNode() : tokenString("]")
	{

	}

	std::string RightBracketNode::getName() const
	{
		return tokenString;
	}

	void RightBracketNode::print() const
	{
		std::cout << tokenString;
	}
}