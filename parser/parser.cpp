#include "parser.hpp"


Parser::Parser(std::vector<Token> tokens)
{
    this->tokens = tokens;
    pos = 0;
}

Token Parser::peek(int offset)
{
    if (pos + offset < tokens.size())
        return tokens[pos + offset];
    return Token("eof", "");
}

bool Parser::match(const std::string& type, const std::string& value )
{
    if (peek().getType() == type && (value.empty() || peek().getValue() == value))
    {
        return true;
    }
    return false;
}

Token Parser::expect(const std::string& type, const std::string& value )
{
    Token t = peek();
    if (peek().getType() == type && (value.empty() || peek().getValue() == value)){
        pos++;
        return t;
    }
    throw::std::runtime_error("Unexpected token: "+ t.getType());
}

Node* Parser::parseExpression()
{
    Token t = peek();
    if (t.getType() == "number")
    {
        pos++;
        return new NumberNode(t.getValue());
    } else if (t.getType() == "ident")
    {
        pos++;
        return new IdentifierNode(t.getValue());
    }
    throw::std::runtime_error("Expected expression, got:" + t.getValue());
}

