#include "IdentifierNode.h"

namespace GeneratorNodes
{
	IdentifierNode::IdentifierNode(std::string tokenString) : Node(tokenString)
	{

	}

	std::string IdentifierNode::getName()
	{
		return tokenString;
	}
}