#ifndef PARSER_HPP
#define PARSER_HPP

#include <algorithm>
#include "tokenizer.hpp"
#include "constantexpressionnode.hpp"
#include "variableexpressionnode.hpp"
#include "functionexpressionnode.hpp"
#include "exponentiationexpressionnode.hpp"
#include "additionexpressionnode.hpp"
#include "multiplicationexpressionnode.hpp"

class Parser
{
private:
    QLinkedList<Token> m_tokens;
    Token m_lookAhead;
    ExpressionNode& expression();
    ExpressionNode& signedTerm();
    ExpressionNode& sumOp(ExpressionNode& p_expr);
    ExpressionNode& term();
    ExpressionNode& factor();
    ExpressionNode& termOp(ExpressionNode& p_expr);
    ExpressionNode& factorOp(ExpressionNode& p_expr);
    ExpressionNode& signedFactor();
    ExpressionNode& argument();
    ExpressionNode& value();
    void nextToken();

public:
    Parser();
    ExpressionNode& parse(QLinkedList<Token> p_tokens);
};

#endif // PARSER_HPP
