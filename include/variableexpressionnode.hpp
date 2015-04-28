#ifndef VARIABLEEXPRESSIONNODE_HPP
#define VARIABLEEXPRESSIONNODE_HPP

#define _USE_MATH_DEFINES
#include <iostream>
#include <tuple>
#include <iomanip>
#include <math.h>
#include <QLinkedList>
#include <QString>
#include "expressionnode.hpp"

class VariableExpressionNode : public ExpressionNode
{
private:
    typedef std::tuple<QString, double> Variable;
    QString m_name;
    static QLinkedList<Variable> m_vars;

public:
    VariableExpressionNode(QString p_name);
    double getValue() override;
    NodeType getType() override;
    static void initMainVars();
    static void addVar(QString p_name, double p_value);
};

#endif // VARIABLEEXPRESSIONNODE_HPP
