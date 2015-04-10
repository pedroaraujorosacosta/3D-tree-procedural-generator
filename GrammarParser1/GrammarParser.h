#include <vector>

class GrammarParser
{
	//std::vector<std::string> vars;
	enum ParserState { READING_VARS, READING_RULES, INVALID_SYNTAX } parserState;
	enum TokenType { DIVIDER_TOKEN, VAR_TOKEN, RULE_TOKEN, INVALID_TOKEN, EMPTY_TOKEN };

	TokenType parseLine(const std::string& line);
	bool parseVar(const std::string& str);
	bool parseRule(const std::string& str);
	bool parseSymbol(const std::string& str);

	int createIndex(std::vector<std::string>& references, const std::string& newValue);
	//bool isInSymbolTable(const std::string& varName) const;
	//bool parseDivider(const std::string& str);

public:
	GrammarParser();
	~GrammarParser();

	bool parseGrammar(const std::vector<std::string>& grammar);
	
	//void printVars();
};