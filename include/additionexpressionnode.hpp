#ifndef ADDITIONEXPRESSIONNODE_HPP
#define ADDITIONEXPRESSIONNODE_HPP

#include "expressionnode.hpp"
#include "sequenceexpressionnode.hpp"

class AdditionExpressionNode : public SequenceExpressionNode
{
public:
    AdditionExpressionNode();
    AdditionExpressionNode(ExpressionNode& p_expr, bool p_positive);
    NodeType getType() override;
    double getValue() override;
};

#endif // ADDITIONEXPRESSIONNODE_HPP
