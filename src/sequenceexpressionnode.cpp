#include "sequenceexpressionnode.hpp"

SequenceExpressionNode::SequenceExpressionNode()
{
    m_terms = QLinkedList<Term>();
}

SequenceExpressionNode::SequenceExpressionNode(ExpressionNode &p_expr, bool p_positive)
{
    m_terms = QLinkedList<Term>();
    add(p_expr, p_positive);
}

void SequenceExpressionNode::add(ExpressionNode &p_expr, bool p_positive)
{
    m_terms.append(Term(p_positive, p_expr));
}
