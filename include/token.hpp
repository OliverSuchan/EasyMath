#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <QString>

class Token
{

public:
    enum Type
    {
        EPSILON, PLUSMINUS, MULTDIV, RAISED, FUNCTION, OPEN_BRACKET, CLOSE_BRACKET, NUMBER, VARIABLE
    };

    Token();
    Token(Type p_token, QString p_sequence);
    Type m_token;
    QString m_sequence;
    void assign(Token p_token);
};

#endif // TOKEN_HPP
