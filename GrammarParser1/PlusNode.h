#include "Node.h"

#ifndef _PLUS_NODE_H_
#define _PLUS_NODE_H_

namespace GeneratorNodes
{
	class PlusNode : public Node
	{
		const std::string tokenString;
	public:
		PlusNode();

		std::string getName() const;

		virtual void print() const;
	};
}
#endif