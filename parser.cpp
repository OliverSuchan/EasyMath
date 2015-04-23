#include "parser.hpp"

void Parser::expression()
{
    signedTerm();
    sumOp();
}

void Parser::signedTerm()
{
    if(m_lookAhead.m_token == Token::PLUSMINUS)
        nextToken();
    term();
}

void Parser::sumOp()
{
    if(m_lookAhead.m_token == Token::PLUSMINUS)
    {
        nextToken();
        term();
        sumOp();
    }
}

void Parser::term()
{
    factor();
    termOp();
}

void Parser::factor()
{
    argument();
    factorOp();
}

void Parser::termOp()
{
    if(m_lookAhead.m_token == Token::MULTDIV)
    {
        nextToken();
        signedFactor();
        termOp();
    }
}

void Parser::factorOp()
{
    if(m_lookAhead.m_token == Token::RAISED)
    {
        nextToken();
        signedFactor();
    }
}

void Parser::signedFactor()
{
    if(m_lookAhead.m_token == Token::PLUSMINUS)
        nextToken();
    factor();
}

void Parser::argument()
{
    if(m_lookAhead.m_token == Token::OPEN_BRACKET)
    {
        nextToken();
        expression();
        if(m_lookAhead.m_token != Token::CLOSE_BRACKET)
            std::cerr << "Expected: ')' got: '" << m_lookAhead.m_sequence.toStdString() << "'" << std::endl;
        else
            nextToken();
    }
    else if(m_lookAhead.m_token == Token::FUNCTION)
    {
        nextToken();
        argument();
    }
    else
        value();
}

void Parser::value()
{
    if(m_lookAhead.m_token == Token::NUMBER || m_lookAhead.m_token ==  Token::VARIABLE)
        nextToken();
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

void Parser::parse(QLinkedList<Token> p_tokens)
{
    m_tokens.clear();
    for(QLinkedList<Token>::iterator it = p_tokens.begin(); it != p_tokens.end(); it++)
        m_tokens.append(*it);
    std::copy(p_tokens.begin(), p_tokens.end(), m_tokens.begin());
    m_lookAhead.assign(m_tokens.first());


    expression();

    if(m_lookAhead.m_token != Token::EPSILON)
        std::cerr << "Unexpected symbol " << m_lookAhead.m_sequence.toStdString() << " found" << std::endl;
}


