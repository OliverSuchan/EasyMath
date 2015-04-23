#include "additionexpressionnode.hpp"

AdditionExpressionNode::AdditionExpressionNode()
    : SequenceExpressionNode()
{

}

AdditionExpressionNode::AdditionExpressionNode(ExpressionNode &p_expr, bool p_positive)
    : SequenceExpressionNode(p_expr, p_positive)
{

}

ExpressionNode::NodeType AdditionExpressionNode::getType()
{
    return ADDITION_NODE;
}

double AdditionExpressionNode::getValue()
{
    double sum = .0;
    for(Term t : m_terms)
    {
        if(t.m_positive)
            sum += t.m_expression.getValue();
        else
            sum -= t.m_expression.getValue();
    }
    return sum;
}
