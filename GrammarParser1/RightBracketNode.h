#include "Node.h"

#ifndef _RIGHT_NODE_H_
#define _RIGHT_NODE_H_

namespace GeneratorNodes
{
	class RightBracketNode : public Node
	{
		const std::string tokenString;
	public:
		RightBracketNode();

		std::string getTokenString() const;

		virtual void print() const;
	};
}
#endif