//
// Created by truemorgan on 11/9/25.
//

#ifndef FLUX_PL_TOKENIZER_HPP
#define FLUX_PL_TOKENIZER_HPP
#include "token/token.hpp"


class Tokenizer
{
    private:
    static char state;

    static std::string buffer;
    public:
    static std::vector<Token> tokenize(std::string untokenizedStr);

};
#endif //FLUX_PL_TOKENIZER_HPP