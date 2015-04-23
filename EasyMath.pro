#-------------------------------------------------
#
# Project created by QtCreator 2015-04-23T16:22:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EasyMath
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    token.cpp \
    tokenizer.cpp \
    parser.cpp \
    constantexpressionnode.cpp \
    variableexpressionnode.cpp \
    term.cpp \
    sequenceexpressionnode.cpp \
    additionexpressionnode.cpp \
    multiplicationexpressionnode.cpp \
    exponentiationexpressionnode.cpp \
    functionexpressionnode.cpp

HEADERS  += mainwindow.hpp \
    token.hpp \
    tokenizer.hpp \
    parser.hpp \
    expressionnode.hpp \
    constantexpressionnode.hpp \
    variableexpressionnode.hpp \
    term.hpp \
    sequenceexpressionnode.hpp \
    additionexpressionnode.hpp \
    multiplicationexpressionnode.hpp \
    exponentiationexpressionnode.hpp \
    functionexpressionnode.hpp

FORMS    += mainwindow.ui
