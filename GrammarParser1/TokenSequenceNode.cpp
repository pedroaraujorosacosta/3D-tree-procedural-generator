#include "TokenSequenceNode.h"
#include <iostream>

namespace GeneratorNodes
{
	TokenSequenceNode::TokenSequenceNode(std::vector<Node*>& sequence)
	{
		this->sequence = sequence;
	}

	TokenSequenceNode::~TokenSequenceNode()
	{
		for (std::vector<Node*>::const_iterator it = sequence.end() - 1; it != sequence.begin() - 1; it--)
		{
			sequence.erase(it);
			delete *it;
		}
	}

	std::vector<Node*> TokenSequenceNode::getSequence() const
	{
		return sequence;
	}

	void TokenSequenceNode::print() const
	{
		for (std::vector<Node*>::const_iterator it = sequence.begin(); it != sequence.end(); it++)
		{
			(*it)->print();
			std::cout << " ";
		}
	}
}