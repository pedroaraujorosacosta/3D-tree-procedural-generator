#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "GrammarParser.h" 

std::vector<std::string> grammarText;

void printInstructions(const std::string& programName) 
{
	std::cout << "Invalid usage of " << programName				<< std::endl;
	std::cout << "  Usage: "									<< std::endl;
	std::cout << programName << " grammarFileName.txt"			<< std::endl;
}

void printReadGrammar(const std::vector<std::string>& grammar)
{
	for (std::vector<std::string>::const_iterator it = grammar.begin(); it != grammar.end(); it++)
		std::cout << *it << std::endl;
}

int main(int argc, char** argv) 
{
	GrammarParser gp;
	std::string line, filename;
	std::ifstream ifStream;

	if (argc == 2)
	{
		filename = argv[1];
		
		ifStream.open(filename);
		if (ifStream.is_open())
		{
			// read and store the grammar file's lines
			while (getline(ifStream, line))
				grammarText.push_back(line);
			ifStream.close();

			// parse the grammar, get its rules
			TokenInfo grammarRules;
			gp.parseGrammar(grammarText, grammarRules);
			if (grammarRules.tokenNode) grammarRules.tokenNode->print();
		}
		else
			std::cout << "Error: unable to open file: " << filename << std::endl;
	}
	else 
		printInstructions(std::string(argv[0]));

	return 0;
}