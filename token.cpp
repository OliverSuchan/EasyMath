#include "token.hpp"

Token::Token()
    : m_token(Type::EPSILON),
      m_sequence("")
{
}

Token::Token(Type p_token, QString p_sequence)
    : m_token(p_token),
      m_sequence(p_sequence)
{

}

void Token::assign(Token p_token)
{
    m_sequence = p_token.m_sequence;
    m_token = p_token.m_token;
}

