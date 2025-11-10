#include <iosfwd>
#include "token.hpp"

Token::Token(const std::string& type, const std::string& value)
{
    this->type = type;
    this->value = value;
}

std::string Token::getType()
{
    return this->type;
}


std::string Token::getValue()
{
    return this->value;
}