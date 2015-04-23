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

SOURCES +=\
    src/additionexpressionnode.cpp \
    src/constantexpressionnode.cpp \
    src/exponentiationexpressionnode.cpp \
    src/functionexpressionnode.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/multiplicationexpressionnode.cpp \
    src/parser.cpp \
    src/sequenceexpressionnode.cpp \
    src/term.cpp \
    src/token.cpp \
    src/tokenizer.cpp \
    src/variableexpressionnode.cpp

HEADERS  += \
    include/additionexpressionnode.hpp \
    include/constantexpressionnode.hpp \
    include/exponentiationexpressionnode.hpp \
    include/expressionnode.hpp \
    include/functionexpressionnode.hpp \
    include/mainwindow.hpp \
    include/multiplicationexpressionnode.hpp \
    include/parser.hpp \
    include/sequenceexpressionnode.hpp \
    include/term.hpp \
    include/token.hpp \
    include/tokenizer.hpp \
    include/variableexpressionnode.hpp

FORMS    += \
    forms/mainwindow.ui

INCLUDEPATH += include
