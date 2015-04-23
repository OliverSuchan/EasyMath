#include "variableexpressionnode.hpp"

VariableExpressionNode::VariableExpressionNode(QString p_name)
    : m_name(p_name)
{
    m_valueSet = false;
}

void VariableExpressionNode::setValue(double p_value)
{
    m_value = p_value;
    m_valueSet = true;
}

double VariableExpressionNode::getValue()
{
    if(m_valueSet)
        return m_value;
    else
        std::cerr << "Variable '" + m_name.toStdString() + "' was not initialized." << std::endl;
}

ExpressionNode::NodeType VariableExpressionNode::getType()
{
    return VARIABLE_NODE;
}
