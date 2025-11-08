#ifndef FLUX_PL_TOKEN_HPP
#define FLUX_PL_TOKEN_HPP

#define NORMAL_STATE 0
#define STATE_LITERAL 1
#define STATE_NUMBER 2
#define STATE_OPERATOR 3
#define STATE_BRACKET 4
#define STATE_SEMICOLON 5
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>



const std::vector<char> BRACKETS = {'{', '}', '(', ')', '[', ']'};
const std::vector<std::string> TYPES = {"int", "char", "bool"};
const std::vector<char> OPERATORS = {'+', '-', '*', '/', '=', '<', '>', '%', '!', '&', '|', '^'};


class Token
{
private:
    std::string value;
    std::string type;

public:
    Token(const std::string& type, const std::string& value);
    std::vector<Token> tokenize(std::string untokenizedStr);

    friend std::ostream& operator<<(std::ostream& os, const Token& obj);
};


inline std::ostream& operator<<(std::ostream& os, const Token& obj)
{
    os << obj.type << "(" << obj.value << ")";
    return os;
}

#endif
