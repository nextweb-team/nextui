#include <iosfwd>
#include "token.hpp"

Token::Token(const std::string& type, const std::string& value)
{
    this->type = type;
    this->value = value;
}

std::vector<Token> Token::tokenize(std::string untokenizedStr)
{
    int state = NORMAL_STATE;
    int lastState = state;
    std::vector<Token> tokens;
    std::string buffer;

    for (char c : untokenizedStr)
    {
        lastState = state;

        if (std::find(BRACKETS.begin(), BRACKETS.end(), c) != BRACKETS.end())
            state = STATE_BRACKET;
        else if (std::isdigit(c) && state != STATE_LITERAL)
            state = STATE_NUMBER;
        else if (std::isalnum(c) || c == '_')
            state = STATE_LITERAL;
        else if (std::find(OPERATORS.begin(), OPERATORS.end(), c) != OPERATORS.end())
            state = STATE_OPERATOR;
        else if (c == ';')
            state = STATE_SEMICOLON;
        else if (c == ' ' || c == '\n' || c == '\t')
            state = NORMAL_STATE;


        if (lastState != state && lastState != NORMAL_STATE && !buffer.empty())
        {
            if (lastState == STATE_LITERAL)
                tokens.push_back(Token("ident", buffer));
            else if (lastState == STATE_NUMBER)
                tokens.push_back(Token("number", buffer));
            else if (lastState == STATE_OPERATOR)
                tokens.push_back(Token("operator", buffer));

            buffer.clear();
        }


        if (state == STATE_LITERAL || state == STATE_NUMBER || state == STATE_OPERATOR)
            buffer += c;


        if (state == STATE_BRACKET) {
            tokens.push_back(Token("bracket", std::string(1, c)));
            state = NORMAL_STATE;
        }
        if (state == STATE_SEMICOLON) {
            tokens.push_back(Token("semicolon", ";"));
            state = NORMAL_STATE;
        }
    }
    if (!buffer.empty()) {
        if (state == STATE_LITERAL)
            tokens.push_back(Token("ident", buffer));
        else if (state == STATE_NUMBER)
            tokens.push_back(Token("number", buffer));
        else if (state == STATE_OPERATOR)
            tokens.push_back(Token("operator", buffer));
    }

    return tokens;
}

