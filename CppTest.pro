# -------------------------------------------------
# Project created by QtCreator 2012-08-10T14:56:04
# -------------------------------------------------
TARGET = CppTest
CONFIG += qt
QT += xml
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    helper.cpp \
    typeio.cpp \
    singletypeio.cpp \
    abstractio.cpp \
    concretedigitalio.cpp \
    concreteanalogio.cpp \
    concretepds.cpp \
    typepds.cpp \
    singletypepds.cpp \
    factoryconcreteio.cpp
HEADERS += mainwindow.h \
    helper.h \
    typeio.h \
    singletypeio.h \
    abstractio.h \
    concretedigitalio.h \
    concreteanalogio.h \
    concretepds.h \
    typepds.h \
    singletypepds.h \
    factoryconcreteio.h
FORMS += mainwindow.ui
OTHER_FILES += TypeIO.xml
RESOURCES += qresource.qrc
