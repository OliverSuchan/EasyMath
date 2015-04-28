#include "mainwindow.hpp"
#include <QApplication>
#include "parser.hpp"
#include "tokenizer.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    FunctionExpressionNode::initMainFuncs();
    VariableExpressionNode::initMainVars();
    Parser p = Parser();
    Tokenizer t = Tokenizer();
    std::cout
    t.tokenize("pi");
    std::cout << p.parse(t.getTokens()).getValue() << std::endl;
    return a.exec();
}
