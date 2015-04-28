#include "variableexpressionnode.hpp"

QLinkedList<VariableExpressionNode::Variable> VariableExpressionNode::m_vars = QLinkedList<VariableExpressionNode::Variable>();

VariableExpressionNode::VariableExpressionNode(QString p_name)
    : m_name(p_name)
{
}

double VariableExpressionNode::getValue()
{
    for(QLinkedList<Variable>::iterator it = m_vars.begin(); it != m_vars.end(); it++)
    {
        if(std::get<0>(*it) == m_name)
        {
            return std::get<1>(*it);
        }
    }
}

ExpressionNode::NodeType VariableExpressionNode::getType()
{
    return VARIABLE_NODE;
}

void VariableExpressionNode::initMainVars()
{
    std::setprecision(50);
    addVar("pi", M_PI);
    addVar("e", M_E);
}

void VariableExpressionNode::addVar(QString p_name, double p_value)
{
    for(QLinkedList<Variable>::iterator it = m_vars.begin(); it != m_vars.end(); it++)
    {
        if(std::get<0>(*it) == p_name)
        {
            std::cerr << "This variablename is already taken" << std::endl;
            return;
        }
    }
    m_vars.append(std::make_tuple(p_name, p_value));
}
