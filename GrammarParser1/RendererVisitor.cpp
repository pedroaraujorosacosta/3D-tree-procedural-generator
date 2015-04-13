#include "RendererVisitor.h"
#include "AllNodes.h"

using namespace GeneratorNodes;

void RendererVisitor::visit(Node* node)
{
	node->accept(this);
}

void RendererVisitor::visit(IdentifierNode* node)
{
	
}

void RendererVisitor::visit(LeftBracketNode* node)
{
	
}

void RendererVisitor::visit(RightBracketNode* node)
{
	
}

void RendererVisitor::visit(PlusNode* node)
{
	
}

void RendererVisitor::visit(MinusNode* node)
{
	
}

void RendererVisitor::visit(ProgramNode* node)
{
	
}

void RendererVisitor::visit(RuleNode* node)
{
	
}

void RendererVisitor::visit(TokenSequenceNode* node)
{
	
}