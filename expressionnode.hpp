#ifndef EXPRESSIONNODE
#define EXPRESSIONNODE

class ExpressionNode
{
public:
    enum NodeType
    {
        VARIABLE_NODE, CONSTANT_NODE, ADDITION_NODE, MULTIPLICATION_NODE, EXPONENTIATION_NODE, FUNCTION_NODE
    };
    virtual NodeType getType() = 0;
    virtual double getValue() = 0;
    virtual ~ExpressionNode() {}
};

#endif // EXPRESSIONNODE

