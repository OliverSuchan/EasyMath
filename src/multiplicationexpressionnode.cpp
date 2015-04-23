#include "multiplicationexpressionnode.hpp"

MultiplicationExpressionNode::MultiplicationExpressionNode()
    : SequenceExpressionNode()
{

}

MultiplicationExpressionNode::MultiplicationExpressionNode(ExpressionNode &p_expr, bool p_positive)
    : SequenceExpressionNode(p_expr, p_positive)
{

}

ExpressionNode::NodeType MultiplicationExpressionNode::getType()
{
    return MULTIPLICATION_NODE;
}

double MultiplicationExpressionNode::getValue()
{
    double prod = 1.0;
    for(Term t : m_terms)
    {
        if(t.m_positive)
            prod *= t.m_expression.getValue();
        else
            prod /= t.m_expression.getValue();
    }
    return prod;
}
