#ifndef FLUX_PL_PARSER_HPP
#define FLUX_PL_PARSER_HPP
#include <string>
#include <vector>
#include "../tokenizer/token/token.hpp"
#include "defines/defines.hpp"
class Parser
{
public:
    Parser(std::vector<Token> tokens);
    void parse();
    Token peek(int offset = 0);
    bool match(const std::string& type, const std::string& value = "");
    Token expect(const std::string& type, const std::string& value ="");
    Node* parseExpression();
    Node* parseVarDeclaration();

private:
    std::vector<Token> tokens;
    int pos;
};

#endif