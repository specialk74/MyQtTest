#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "typeio.h"

class TestTypeIO: public QObject
{
    Q_OBJECT
public:    

private slots:
    void initTestCase ()
    {
        bool result = TypeIO::init();
        QVERIFY(result == true);
    }

    void init()
    {
    }
    void cleanup()
    {
    }

    void create()
    {
    }

    void GetValueAtStart()
    {
//        bool result = TypeIO::isInput(Generico_Input_NO);
//        QVERIFY(result == true);
    }
};

QTTESTUTIL_REGISTER_TEST(TestTypeIO);
#include "TestTypeIO.moc"
