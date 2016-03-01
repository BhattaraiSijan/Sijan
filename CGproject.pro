TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
LIBS+=-lglut
LIBS+=-lGL
LIBS+=-lGLU
SOURCES += main.cpp \
    display.cpp \
    basic2D.cpp \
    matrix.cpp \
    basic3D.cpp \
    transformation3D.cpp \
    vector.cpp \
    loader.cpp \
    color.cpp

HEADERS += \
    display.h \
    basic2D.h \
    basic3D.h \
    matrix.h \
    transformation3D.h \
    vector.h \
    loader.h \
    color.h \
    event.h
