#include "LeftBracketNode.h"
#include <iostream>

namespace GeneratorNodes
{
	LeftBracketNode::LeftBracketNode() : tokenString("[")
	{

	}

	std::string LeftBracketNode::getName() const
	{
		return tokenString;
	}

	void LeftBracketNode::print() const
	{
		std::cout << tokenString;
	}
}