#ifndef MULTIPLICATIONEXPRESSIONNODE_HPP
#define MULTIPLICATIONEXPRESSIONNODE_HPP

#include "sequenceexpressionnode.hpp"

class MultiplicationExpressionNode : public SequenceExpressionNode
{
public:
    MultiplicationExpressionNode();
    MultiplicationExpressionNode(ExpressionNode& p_expr, bool p_positive);
    NodeType getType() override;
    double getValue() override;
};

#endif // MULTIPLICATIONEXPRESSIONNODE_HPP
