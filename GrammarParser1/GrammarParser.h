#include <vector>

class GrammarParser
{
	enum ParserState { READING_RULES, INVALID_SYNTAX } parserState;
	enum TokenType { RULE_TOKEN, INVALID_TOKEN, EMPTY_TOKEN };

	TokenType parseLine(const std::string& line);
	bool parseVar(const std::string& str);
	bool parseRule(const std::vector<std::string>& tokenStrings);
	bool parseSymbol(const std::string& str);
	bool parseAssociationSymbols(const std::string& str);

	int createIndex(std::vector<std::string>& references, const std::string& newValue);

public:
	GrammarParser();
	~GrammarParser();

	bool parseGrammar(const std::vector<std::string>& grammar);
};