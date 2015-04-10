#include <string>

namespace GeneratorNodes
{
	class Node
	{
	protected:
		std::string tokenString;
	public:
		Node(std::string& tokenString);
	};
}