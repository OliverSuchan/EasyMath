#include "constantexpressionnode.hpp"

ConstantExpressionNode::ConstantExpressionNode(double p_value)
    : m_value(p_value)
{

}

ConstantExpressionNode::ConstantExpressionNode(QString p_value)
{
    m_value = p_value.toDouble();
}

double ConstantExpressionNode::getValue()
{
    return m_value;
}

ExpressionNode::NodeType ConstantExpressionNode::getType()
{
    return CONSTANT_NODE;
}
