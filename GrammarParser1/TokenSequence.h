#include <vector>
#include "Node.h"

namespace GeneratorNodes
{
	class SequenceNode : public Node
	{
		std::vector<Node> sequence;
	public:
		SequenceNode(std::string tokenString);

		std::vector<Node> getSequence();
	};
}