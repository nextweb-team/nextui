#include <iostream>
#include "tokenizer/tokenizer.hpp"
#include "parser/parser.hpp"
#include "tokenizer/token/token.hpp"
#include "loader/loader.hpp"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main()
{
    std::string l = Loader::loadFile("main.nui");
    std::vector<Token> tokenz = Tokenizer::tokenize(l);
    Parser parser(tokenz);
    Node* node = parser.parseExpression();
    node->print();


}
