#include "functionexpressionnode.hpp"

QLinkedList<FunctionExpressionNode::Function> FunctionExpressionNode::m_funcs = QLinkedList<FunctionExpressionNode::Function>();

FunctionExpressionNode::FunctionExpressionNode(QString p_funcName, ExpressionNode &p_argument)
    : m_argument(p_argument)
{
    m_funcName = p_funcName;
}

ExpressionNode::NodeType FunctionExpressionNode::getType()
{
    return FUNCTION_NODE;
}

double FunctionExpressionNode::getValue()
{
    for(QLinkedList<Function>::iterator it = FunctionExpressionNode::m_funcs.begin(); it != FunctionExpressionNode::m_funcs.end(); it++)
    {
        if(std::get<0>(*it) == m_funcName)
        {
            return std::get<1>(*it)(m_argument.getValue());
        }
    }
}

QString FunctionExpressionNode::getFunctionTokens()
{
    QString tok;
    for(QLinkedList<Function>::iterator it = FunctionExpressionNode::m_funcs.begin(); it != FunctionExpressionNode::m_funcs.end(); it++)
    {
        tok += std::get<0>(*it);
        tok += "|";
    }
    return tok.remove(tok.length() - 1, 1);
}

void FunctionExpressionNode::addFunc(QString p_name, std::function<double(long double)> p_func, bool p_builtIn)
{
    for(QLinkedList<Function>::iterator it = FunctionExpressionNode::m_funcs.begin(); it != FunctionExpressionNode::m_funcs.end(); it++)
    {
        if(std::get<0>(*it) == p_name)
        {
            std::cerr << "This functionname is already taken!" << std::endl;
            return;
        }
    }
    FunctionExpressionNode::m_funcs.append(std::make_tuple(p_name, p_func, p_builtIn));
}

void FunctionExpressionNode::initMainFuncs()
{
    addFunc("sin", [](long double arg){return std::sin(arg);}, true);
    addFunc("cos", [](long double arg){return std::cos(arg);}, true);
    addFunc("tan", [](long double arg){return std::tan(arg);}, true);
}

