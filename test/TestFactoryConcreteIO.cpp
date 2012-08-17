#include <QtTest/QtTest>
#include "QtTestUtil/QtTestUtil.h"

#include "factoryconcreteio.h"

class TestFactoryConcreteIO: public QObject
{
    Q_OBJECT
public:

private slots:
    void initTestCase ()
    {
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

    void CheckGoodTagName ()
    {
        QDomElement domElement = doc.createElement (getTagName());
        AbstractIO *result = FactoryConcreteIO(domElement);
        QVERIFY(result == NULL);
    }

    void CheckBadTagName()
    {
        QDomElement domElement = doc.createElement ("badName");
        AbstractIO *result = FactoryConcreteIO(domElement);
        QVERIFY(result == NULL);
    }


private:
    QDomDocument doc;
};

QTTESTUTIL_REGISTER_TEST(TestFactoryConcreteIO);
#include "TestFactoryConcreteIO.moc"



