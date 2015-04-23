#include "tokenizer.hpp"

Tokenizer::Tokenizer()
    : m_tokenInfos(),
      m_tokens()
{
    add("[+-]", Token::PLUSMINUS);
    add("[*/]", Token::MULTDIV);
    add("\\^", Token::RAISED);
    add("\\(", Token::OPEN_BRACKET);
    add("\\)", Token::CLOSE_BRACKET);
    add("[0-9]+", Token::NUMBER);
    add("[a-zA-Z][a-zA-Z0-9_]*", Token::VARIABLE);
}

void Tokenizer::add(QString p_pattern, Token::Type p_token)
{
    m_tokenInfos.append(TokenInfo(QRegularExpression("^(" + p_pattern + ")"), p_token));
}

void Tokenizer::tokenize(QString p_str)
{
    m_tokens.clear();
    QString exp = p_str.replace(" ", "");
    while(exp != "")
    {
        bool match = false;
        for(TokenInfo info : m_tokenInfos)
        {
            QRegularExpressionMatch m = info.m_regExp.match(exp);
            if(m.hasMatch())
            {
                match = true;
                QString tok = m.captured();
                m_tokens.append(Token(info.m_token, tok));
                exp = exp.remove(m.capturedStart(), m.capturedLength());
                break;
            }
        }
        if(!match)
            std::cerr << "Unexpected input string: " << exp.toStdString() << std::endl;
    }
}

QLinkedList<Token> Tokenizer::getTokens()
{
    return m_tokens;
}

Tokenizer::TokenInfo::TokenInfo(QRegularExpression p_regExp, Token::Type p_token)
    : m_regExp(p_regExp),
      m_token(p_token)
{

}
