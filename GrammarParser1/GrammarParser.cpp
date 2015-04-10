#include <list>
#include <locale>
#include <iostream>
#include "GrammarParser.h"
#include "StringTokenizer.h"


GrammarParser::GrammarParser() : parserState(READING_RULES)
{

}

GrammarParser::~GrammarParser()
{

}

bool GrammarParser::parseGrammar(const std::vector<std::string>& grammar)
{
	int lineNum = 1;
	std::vector<std::string>::const_iterator it = grammar.begin();

	while (it != grammar.end())
	{
		if (parseLine((*it++)) == INVALID_TOKEN)
		{
			std::cout << "Invalid syntax on line " << lineNum << std::endl;
			return false;
		}
		lineNum++;
	}

	return true;
}

GrammarParser::TokenType GrammarParser::parseLine(const std::string& line)
{
	TokenType ret = INVALID_TOKEN;

	// strip whitespaces & tokenize line
	std::vector<std::string> tokenStrings;
	StringTokenizer::tokenize(line, tokenStrings, StringTokenizer::WHITESPACES);

	for (std::vector<std::string>::iterator it = tokenStrings.begin(); it != tokenStrings.end(); it++)
		std::cout << "tokenString: " << *it << std::endl;

	if (tokenStrings.size() > 0)
	{
		if (parseRule(tokenStrings))
		{
			ret = RULE_TOKEN;
		}
	}
	else
		ret = EMPTY_TOKEN;

	return ret;
}

bool GrammarParser::parseRule(const std::vector<std::string>& tokenStrings)
{
	bool ret = true;
	unsigned int i = 0;

	std::cout << "parse rule begin" << std::endl;
	
	// rules have the form A := A B, so check if the second token string corresponds to the ':=' association symbols
	// and the first to a valid variable name
	if (parseVar(tokenStrings[0]) && parseAssociationSymbols(tokenStrings[1]))
	{
		// a consequent has at least one variable
		bool foundInvalidToken = false;
		bool foundVariable = false;
		for (std::vector<std::string>::const_iterator it = tokenStrings.begin()+2; it != tokenStrings.end(); it++)
		{
			if (parseVar(*it)) {
				std::cout << "Found a var: " << *it << std::endl;
				foundVariable = true;
			}
			else if (!parseSymbol(*it)) {
				std::cout << "foud in" << std::endl;
				foundInvalidToken = true;
			}
		}

		if (foundInvalidToken || !foundVariable)
			ret = false;
	}
	else
		ret = false;

	std::cout << "parse rule end" << std::endl;

	return ret;
}

bool GrammarParser::parseVar(const std::string& str)
{
	std::locale loc;
	bool ret = true;

	if (!std::isalpha(str[0], loc))
		ret = false;

	for (unsigned int i = 1; i < str.length(); i++)
	{
		if (!std::isalnum(str[i], loc))
			ret = false;
	}

	return ret;
}

bool GrammarParser::parseSymbol(const std::string& str)
{
	if (str.length() == 1 && str[0] == '[' || str[0] == ']' || str[0] == '+' || str[0] == '-')
		return true;
	else
		return false;
}

bool GrammarParser::parseAssociationSymbols(const std::string& str)
{
	if (str.length() == 2 && str[0] == ':' || str[1] == '=')
		return true;
	else
		return false;
}

int GrammarParser::createIndex(std::vector<std::string>& references, const std::string& newValue)
{
	int results = std::find(references.begin(), references.end(), newValue)
		- references.begin();
	if (results == references.size()) {
		references.push_back(newValue);
	}
	return results;
}