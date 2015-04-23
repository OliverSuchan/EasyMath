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
    parser.cpp

HEADERS  += mainwindow.hpp \
    token.hpp \
    tokenizer.hpp \
    parser.hpp \
    expressionnode.hpp

FORMS    += mainwindow.ui
