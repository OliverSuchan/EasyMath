#include "mainwindow.hpp"
#include <QApplication>
#include "parser.hpp"
#include "tokenizer.hpp"
#include <iostream>
#include "feedforwardnetwork.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    FeedForwardNetwork fnn = FeedForwardNetwork({2, 3, 2, 4});

//    FunctionExpressionNode::initMainFuncs();
//    VariableExpressionNode::initMainVars();
//    Parser p = Parser();
//    Tokenizer t = Tokenizer();
//    t.tokenize("pi");
//    std::cout << p.parse(t.getTokens()).getValue() << std::endl;

//    Matrix<double> m = Matrix<double>(3, 3);
    return a.exec();
}
