#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "GrammarParser.h" 
#include "ProgramNode.h"
#include "IdentifierNode.h"
#include "GrammarGenerator.h"
#include "RendererVisitor.h"
#include "StandardOutputVisitor.h"

using namespace GeneratorNodes;

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

			ProgramNode grammar = *(ProgramNode*)grammarRules.tokenNode;

			// print grammar
			grammar.accept(new StandardOutputVisitor());
			//std::cout << grammar.getName() << std::endl;

			std::cout << std::endl << "*1st Generation*****************************" << std::endl << std::endl;
			IdentifierNode* idNode = new IdentifierNode("s");
			IdentifierNode* idNode2 = new IdentifierNode("A23a");
			std::vector<const Node*> symbols;
			symbols.push_back(idNode);
			symbols.push_back(idNode2);
			GrammarGenerator::generate(grammar, symbols);
			GrammarGenerator::printSymbols(symbols);

			std::cout << std::endl << "*2nd Generation*****************************" << std::endl << std::endl;
			GrammarGenerator::generate(grammar, symbols);
			GrammarGenerator::printSymbols(symbols);

			std::cout << std::endl << "*3rd Generation*****************************" << std::endl << std::endl;
			GrammarGenerator::generate(grammar, symbols);
			GrammarGenerator::printSymbols(symbols);
		}
		else
			std::cout << "Error: unable to open file: " << filename << std::endl;

	}
	else 
		printInstructions(std::string(argv[0]));

	return 0;
}