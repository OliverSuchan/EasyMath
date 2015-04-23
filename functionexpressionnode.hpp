#ifndef FUNCTIONEXPRESSIONNODE_HPP
#define FUNCTIONEXPRESSIONNODE_HPP

#include <iostream>
#include <tuple>
#include <functional>
#include <QString>
#include <QLinkedList>
#include "expressionnode.hpp"

class FunctionExpressionNode : public ExpressionNode
{
private:
    typedef std::tuple<QString, std::function<double(long double)>, bool> Function;
    QString m_funcName;
    ExpressionNode& m_argument;
    static QLinkedList<Function> m_funcs;

public:
    FunctionExpressionNode(QString p_funcName, ExpressionNode& p_argument);
    NodeType getType() override;
    double getValue() override;
    static QString getFunctionTokens();
    static void addFunc(QString p_name, std::function<double(long double)> p_func, bool p_builtIn);
    static void initMainFuncs();
};

#endif // FUNCTIONEXPRESSIONNODE_HPP
