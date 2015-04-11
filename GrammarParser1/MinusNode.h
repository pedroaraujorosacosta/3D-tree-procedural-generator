#include "Node.h"

#ifndef _MINUS_NODE_H_
#define _MINUS_NODE_H_

namespace GeneratorNodes
{
	class MinusNode : public Node
	{
		const std::string tokenString;
	public:
		MinusNode();

		std::string getTokenString() const;

		virtual void print() const;
	};
}
#endif