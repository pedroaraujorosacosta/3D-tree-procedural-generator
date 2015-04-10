#include "TokenSequence.h"

namespace GeneratorNodes
{
	SequenceNode::SequenceNode(std::string tokenString) : Node(tokenString)
	{

	}

	std::vector<Node> SequenceNode::getSequence()
	{
		return sequence;
	}
}