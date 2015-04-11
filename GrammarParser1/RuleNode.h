#include "Node.h"

#ifndef _RULE_NODE_H_
#define _RULE_NODE_H_

namespace GeneratorNodes
{
	class RuleNode : public Node
	{
		const std::string RULE_STRING;
		const Node* antecedent;
		const Node* consequent;
	public:
		RuleNode(const Node* antecedent, const Node* consequent);
		~RuleNode();

		virtual void print() const;
	};
}
#endif