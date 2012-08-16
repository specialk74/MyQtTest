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
        bool result = TypeIO::init("../TypeIO.xml");
        QVERIFY(result == true);

        result = TypeIO::init(":/TypeIO.xml");
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

};

QTTESTUTIL_REGISTER_TEST(TestTypeIO);
#include "TestTypeIO.moc"
