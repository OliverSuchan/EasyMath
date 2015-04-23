#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include "tokenizer.hpp"

class Parser
{
private:
    QLinkedList<Token> m_tokens;
    Token m_lookAhead;
    void expression();
    void signedTerm();
    void sumOp();
    void term();
    void factor();
    void termOp();
    void factorOp();
    void signedFactor();
    void argument();
    void value();
    void nextToken();

public:
    Parser();
    void parse(QLinkedList<Token> p_tokens);
};

#endif // PARSER_HPP
