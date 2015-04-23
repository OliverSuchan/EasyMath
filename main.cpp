#include "mainwindow.hpp"
#include <QApplication>
#include "parser.hpp"
#include "tokenizer.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Parser p = Parser();
    Tokenizer t = Tokenizer();
    t.tokenize("-5+(7*x-3)");
    p.parse(t.getTokens());
    return a.exec();
}
