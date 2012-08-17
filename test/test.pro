# #####################################################################
# Automatically generated by qmake (2.01a) ven ago 10 16:49:21 2012
# #####################################################################
include(QtTestUtil/QtTestUtil.pri)
CONFIG += qt \
    qtestlib \
    debug
QT += xml
TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += . \
    ..

# Input
SOURCES += QtTestUtil/SimpleChecker.cpp \
    ../typeio.cpp \
    ../helper.cpp \
    TestTypeIO.cpp \
    TestHelper.cpp \
    TestSingleTypeIO.cpp \
    ../singletypeio.cpp \
    TestConcreteDigitalIO.cpp \
    ../concretedigitalio.cpp \
    ../abstractio.cpp \
    TestConcreteAnalogIO.cpp \
    ../concreteanalogio.cpp \
    TestConcretePds.cpp \
    ../concretepds.cpp
HEADERS += ../helper.h \
    ../typeio.h \
    ../singletypeio.h \
    ../concretedigitalio.h \
    ../abstractio.h \
    ../concreteanalogio.h \
    ../concretepds.h

# Add an extra 'make check' target.
QMAKE_EXTRA_TARGETS = check
check.commands = \$(MAKE) \
    && \
    ./$(QMAKE_TARGET)

# Cleanup the checker on 'make clean'
QMAKE_CLEAN += $(QMAKE_TARGET)
RESOURCES += ../qresource.qrc
