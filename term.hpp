#ifndef TERM_HPP
#define TERM_HPP

#include "expressionnode.hpp"

class Term
{
public:
    Term(bool p_positive, ExpressionNode &p_expression);
    bool m_positive;
    ExpressionNode &m_expression;
};

#endif // TERM_HPP
