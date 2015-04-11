#include "Node.h"

#ifndef _LEFT_NODE_H_
#define _LEFT_NODE_H_

namespace GeneratorNodes 
{
	class LeftBracketNode : public Node
	{
		const std::string tokenString;
	public:
		LeftBracketNode();

		std::string getName() const;

		virtual void print() const;
	};
}
#endif