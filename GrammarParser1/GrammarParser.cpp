#include <list>
#include <locale>
#include <iostream>
#include "GrammarParser.h"
#include "StringTokenizer.h"


GrammarParser::GrammarParser() : parserState(READING_VARS)
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
		/*if (parseVar(line))
		{
		createIndex(vars, line);
		ret = VAR_TOKEN;
		std::cout << "PARSEVAR " << line << std::endl;
		}
		else if (parseDivider(line))
		{
		ret = DIVIDER_TOKEN;
		std::cout << "PARSEDIV " << line << std::endl;
		}
		else*/ if (parseRule(line))
		{
			ret = RULE_TOKEN;
		}
	}
	else
		ret = EMPTY_TOKEN;

	return ret;
}

bool GrammarParser::parseVar(const std::string& str)
{
	std::locale loc;
	bool ret = true;

	if (!std::isalpha(str[0], loc))
		ret = false;
		//std::cout << line[0] << " is a character." << std::endl;

	for (unsigned int i = 1; i < str.length(); i++)
	{
		if (!std::isalnum(str[i], loc))
			ret = false;
		/*	std::cout << line[i] << " is an alnum." << std::endl;
		else
			return false;*/
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

bool GrammarParser::parseRule(const std::string& str)
{
	bool ret = true;
	unsigned int i = 0;

	std::cout << "parse rule begin" << std::endl;

	// rules have the form A := A B 
	while (i < str.length() && str[i++] != ':');

	// process the antecedent part of the rule:
	if (i > 0)
	{
		// antecedent must be variable, get it's string
		const std::string newVar = str.substr(0, i - 1);

		// process the ':=' part of the rule
		if (str[i - 1] != ':' || str[i] != '=')
			ret = false;

		// process the consequent:
		if (i + 1 <= str.length())
		{
			const std::string rest = str.substr(i + 1, str.length());

			// a consequent has at least one variable
			std::vector<std::string> tokens;
			StringTokenizer::tokenize(rest, tokens, " ");
			bool foundInvalidToken = false;
			bool foundVariable = false;
			for (std::vector<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); it++)
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

			std::cout << "rest-> " << rest << std::endl;
		}
	}

	std::cout << "parse rule end" << std::endl;

	return ret;
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

/*void GrammarParser::printVars()
{
	for (std::vector<std::string>::iterator it = vars.begin(); it != vars.end(); it++)
		std::cout << *it << std::endl;
}*/

/*bool GrammarParser::isInSymbolTable(const std::string& varName) const
{
	int result = std::find(vars.begin(), vars.end(), varName) - vars.begin();
	if (result == vars.size())
	{
		std::cout << "Syntax error: variable " << varName << " not found." << std::endl;
		return false;
	}
	else
		return true;
}*/

/*bool GrammarParser::parseDivider(const std::string& str)
{
std::locale loc;
bool ret = true;
int i = 0;

// read the divider (4 asterisks)
while (str[i] == '*' && i < 4) i++;
if (i < 4) ret = false;

// eat whitespaces
while (std::isspace(str[i], loc)) i++;

if (str.length() != i) ret = false;

return ret;
}*/