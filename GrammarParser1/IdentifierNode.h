#include "Node.h"

namespace GeneratorNodes
{
	class IdentifierNode : public Node
	{
	public:
		IdentifierNode(std::string tokenString);

		std::string getName();
	};
}