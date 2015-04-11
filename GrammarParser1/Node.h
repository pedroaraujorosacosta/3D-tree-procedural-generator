#include <string>

#ifndef _NODE_H_
#define _NODE_H_

namespace GeneratorNodes
{
	class Node
	{
	public:
		Node() {}

		virtual void print() const = 0;
	};
}
#endif