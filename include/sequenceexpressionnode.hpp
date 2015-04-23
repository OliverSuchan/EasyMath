#ifndef SEQUENCEEXPRESSIONNODE_HPP
#define SEQUENCEEXPRESSIONNODE_HPP

#include <QLinkedList>
#include "expressionnode.hpp"
#include "term.hpp"

class SequenceExpressionNode : public ExpressionNode
{
protected:
    QLinkedList<Term> m_terms;

public:
    SequenceExpressionNode();
    SequenceExpressionNode(ExpressionNode &p_expr, bool p_positive);
    void add(ExpressionNode &p_expr, bool p_positive);
};

#endif // SEQUENCEEXPRESSIONNODE_HPP
