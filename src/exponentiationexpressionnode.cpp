#include "exponentiationexpressionnode.hpp"

ExponentiationExpressionNode::ExponentiationExpressionNode(ExpressionNode &p_base, ExpressionNode &p_exponent)
    : m_base(p_base),
      m_exponent(p_exponent)
{
}

ExpressionNode::NodeType ExponentiationExpressionNode::getType()
{
    return EXPONENTIATION_NODE;
}

double ExponentiationExpressionNode::getValue()
{
    return std::pow(m_base.getValue(), m_exponent.getValue());
}
