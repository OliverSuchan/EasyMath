#include "parser.hpp"

ExpressionNode &Parser::expression()
{
   ExpressionNode& expr = signedTerm();
   return sumOp(expr);
}

ExpressionNode &Parser::signedTerm()
{
    if(m_lookAhead.m_token == Token::PLUSMINUS)
    {
        bool positive = m_lookAhead.m_sequence == "+";
        nextToken();
        ExpressionNode& expr = term();
        if(positive)
            return expr;
        else
            return *(new AdditionExpressionNode(expr, false));
    }
    return term();
}

ExpressionNode &Parser::sumOp(ExpressionNode& p_expr)
{
    if(m_lookAhead.m_token == Token::PLUSMINUS)
    {
        AdditionExpressionNode* sum;
        if(p_expr.getType() == ExpressionNode::ADDITION_NODE)
            sum = dynamic_cast<AdditionExpressionNode*>(&p_expr);
        else
            sum = new AdditionExpressionNode(p_expr, true);

        bool positive = m_lookAhead.m_sequence == "+";
        nextToken();
        ExpressionNode& expr = term();
        sum->add(expr, positive);
        return sumOp(*sum);
    }

    return p_expr;
}

ExpressionNode &Parser::term()
{
    ExpressionNode& expr = factor();
    return termOp(expr);
}

ExpressionNode &Parser::factor()
{
    ExpressionNode& a = argument();
    return factorOp(a);
}

ExpressionNode &Parser::termOp(ExpressionNode &p_expr)
{
    if(m_lookAhead.m_token == Token::MULTDIV)
    {
        MultiplicationExpressionNode* prod;

        if(p_expr.getType() == ExpressionNode::MULTIPLICATION_NODE)
            prod = dynamic_cast<MultiplicationExpressionNode*>(&p_expr);
        else
            prod = new MultiplicationExpressionNode(p_expr, true);

        bool positive = m_lookAhead.m_sequence == "*";
        nextToken();
        ExpressionNode& expr = signedFactor();
        prod->add(expr, positive);
        return termOp(*prod);
    }

    return p_expr;
}

ExpressionNode &Parser::factorOp(ExpressionNode &p_expr)
{
    if(m_lookAhead.m_token == Token::RAISED)
    {
        nextToken();
        ExpressionNode& exponent = signedFactor();
        return *(new ExponentiationExpressionNode(p_expr, exponent));
    }
    return p_expr;
}

ExpressionNode &Parser::signedFactor()
{
    if(m_lookAhead.m_token == Token::PLUSMINUS)
    {
        bool positive = m_lookAhead.m_sequence == "+";
        nextToken();
        ExpressionNode& expr = factor();
        if(positive)
            return expr;
        else
            return *(new AdditionExpressionNode(expr, false));
    }

    return factor();
}

ExpressionNode &Parser::argument()
{
   if(m_lookAhead.m_token == Token::FUNCTION)
   {
       QString funcName = m_lookAhead.m_sequence;
       nextToken();
       ExpressionNode& expr = argument();
       return *(new FunctionExpressionNode(funcName, expr));
   }
    else if(m_lookAhead.m_token == Token::OPEN_BRACKET)
    {
        nextToken();
        ExpressionNode& expr = expression();
        if(m_lookAhead.m_token != Token::CLOSE_BRACKET)
            std::cerr << "Expected: ')' got: '" << m_lookAhead.m_sequence.toStdString() << "'" << std::endl;
        else
        {
            nextToken();
            return expr;
        }
    }

    return value();
}

ExpressionNode &Parser::value()
{
    if(m_lookAhead.m_token == Token::NUMBER)
    {
        ExpressionNode* expr = new ConstantExpressionNode(m_lookAhead.m_sequence);
        nextToken();
        return *expr;
    }

    if(m_lookAhead.m_token ==  Token::VARIABLE)
    {
        ExpressionNode* expr = new VariableExpressionNode(m_lookAhead.m_sequence);
        nextToken();
        return *expr;
    }

    if(m_lookAhead.m_token == Token::EPSILON)
        std::cerr << "Unexpected end of input" << std::endl;
    else
        std::cerr << "Unexpected symbol: " << m_lookAhead.m_sequence.toStdString() << std::endl;
}

void Parser::nextToken()
{
    m_tokens.pop_front();
    if(m_tokens.isEmpty())
        m_lookAhead.assign(Token());
    else
        m_lookAhead.assign(m_tokens.first());
}

Parser::Parser()
{

}

ExpressionNode &Parser::parse(QLinkedList<Token> p_tokens)
{
    m_tokens.clear();
    for(QLinkedList<Token>::iterator it = p_tokens.begin(); it != p_tokens.end(); it++)
        m_tokens.append(*it);
    std::copy(p_tokens.begin(), p_tokens.end(), m_tokens.begin());
    m_lookAhead.assign(m_tokens.first());


    ExpressionNode& expr = expression();

    if(m_lookAhead.m_token != Token::EPSILON)
        std::cerr << "Unexpected symbol " << m_lookAhead.m_sequence.toStdString() << " found" << std::endl;

    return expr;
}


