QT += core
QT -= gui

CONFIG += c++11

TARGET = ncrParse
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    ncr.cpp

HEADERS += \
    ncr.h
