#include "Node.h"

#ifndef _ID_NODE_H_
#define _ID_NODE_H_

namespace GeneratorNodes
{
	class IdentifierNode : public Node
	{
		std::string name;
	public:
		IdentifierNode(const std::string& tokenString);

		std::string getName() const;

		virtual void print() const;
	};
}
#endif