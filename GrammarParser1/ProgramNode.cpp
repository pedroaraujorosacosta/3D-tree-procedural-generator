#include "ProgramNode.h"
#include <iostream>

namespace GeneratorNodes
{
	ProgramNode::ProgramNode(std::vector<Node*>& sequence)
	{
		this->sequence = sequence;
	}

	ProgramNode::~ProgramNode()
	{
		if (sequence.size())
		{
			for (std::vector<Node*>::const_iterator it = sequence.end() - 1; it != sequence.begin() - 1; it--)
			{
				sequence.erase(it);
				delete *it;
			}
		}
	}

	std::vector<Node*> ProgramNode::getSequence() const
	{
		return sequence;
	}

	void ProgramNode::print() const
	{
		for (std::vector<Node*>::const_iterator it = sequence.begin(); it != sequence.end(); it++)
		{
			(*it)->print();
			std::cout << std::endl;
		}
	}
}