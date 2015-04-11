#include <vector>
#include "Node.h"

class GeneratorNodes::Node;

struct TokenInfo
{
	GeneratorNodes::Node* tokenNode;
	enum TokenType { RULE_TOKEN, INVALID_TOKEN, EMPTY_TOKEN } tokenType;

	TokenInfo() { tokenNode = 0; tokenType = INVALID_TOKEN; }
	TokenInfo(TokenType type) { tokenType = type; }
	~TokenInfo() { if (tokenNode) delete tokenNode; }
};

class GrammarParser
{
	void parseLine(const std::string& line, TokenInfo& parsedTree);
	bool parseVar(const std::string& str);
	bool parseRule(const std::vector<std::string>& tokenStrings, TokenInfo& parsedTree);
	bool parseAssociationSymbols(const std::string& str);
	bool parseLeftBracket(const std::string& str);
	bool parseRightBracket(const std::string& str);
	bool parsePlusSymbol(const std::string& str);
	bool parseMinusSymbol(const std::string& str);

	int createIndex(std::vector<std::string>& references, const std::string& newValue);

public:
	GrammarParser();
	~GrammarParser();

	bool parseGrammar(const std::vector<std::string>& grammar, TokenInfo& parsedTree);
};