#ifndef VARIABLEEXPRESSIONNODE_HPP
#define VARIABLEEXPRESSIONNODE_HPP

#include <iostream>
#include <QString>
#include "expressionnode.hpp"

class VariableExpressionNode : public ExpressionNode
{
private:
    QString m_name;
    double m_value;
    bool m_valueSet;

public:
    VariableExpressionNode(QString p_name);
    void setValue(double p_value);
    double getValue() override;
    NodeType getType() override;
};

#endif // VARIABLEEXPRESSIONNODE_HPP
