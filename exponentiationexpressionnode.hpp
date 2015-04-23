#ifndef EXPONENTIATIONEXPRESSIONNODE_HPP
#define EXPONENTIATIONEXPRESSIONNODE_HPP

#include <cmath>
#include "expressionnode.hpp"

class ExponentiationExpressionNode : public ExpressionNode
{
private:
    ExpressionNode& m_base;
    ExpressionNode& m_exponent;

public:
    ExponentiationExpressionNode(ExpressionNode& p_base, ExpressionNode& p_exponent);
    NodeType getType() override;
    double getValue() override;
};

#endif // EXPONENTIATIONEXPRESSIONNODE_HPP
