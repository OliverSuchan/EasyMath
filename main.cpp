#include "mainwindow.hpp"
#include <QApplication>
#include "parser.hpp"
#include "tokenizer.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    FunctionExpressionNode::initMainFuncs();
    Parser p = Parser();
    Tokenizer t = Tokenizer();
    t.tokenize("cos(2)");
    std::cout << p.parse(t.getTokens()).getValue() << std::endl;
    return a.exec();
}
