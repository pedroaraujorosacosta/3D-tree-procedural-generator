#include "PlusNode.h"
#include <iostream>

namespace GeneratorNodes
{
	PlusNode::PlusNode() : tokenString("+")
	{

	}

	std::string PlusNode::getName() const
	{
		return tokenString;
	}

	void PlusNode::print() const
	{
		std::cout << tokenString;
	}
}