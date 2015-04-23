#ifndef CONSTANTEXPRESSIONNODE_HPP
#define CONSTANTEXPRESSIONNODE_HPP

#include <QString>
#include "expressionnode.hpp"

class ConstantExpressionNode : public ExpressionNode
{
private:
    double m_value;

public:
    ConstantExpressionNode(double p_value);
    ConstantExpressionNode(QString p_value);
    double getValue() override;
    NodeType getType() override;
};

#endif // CONSTANTEXPRESSIONNODE_HPP
