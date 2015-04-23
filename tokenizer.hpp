#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <iostream>
#include <QLinkedList>
#include <QRegularExpression>
#include "token.hpp"

class Tokenizer
{
private:
    class TokenInfo
    {
    public:
        const QRegularExpression m_regExp;
        const Token::Type m_token;
        TokenInfo(QRegularExpression p_regExp, Token::Type p_token);
    };
    QLinkedList<TokenInfo> m_tokenInfos;
    QLinkedList<Token> m_tokens;

public:
    Tokenizer();
    void add(QString p_pattern, Token::Type p_token);
    void tokenize(QString p_str);
    QLinkedList<Token> getTokens();
};

#endif // TOKENIZER_HPP
