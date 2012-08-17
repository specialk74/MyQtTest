#include <QtTest/QtTest>
#include "QtTestUtil/QtTestUtil.h"

#include "singletypepds.h"

class TestSingleTypePDS: public QObject
{
    Q_OBJECT
public:

private slots:
    void initTestCase ()
    {
    }

    void init()
    {
        singleType = new SingleTypePDS;
    }
    void cleanup()
    {
        delete singleType;
    }

    void create()
    {
    }

    void CheckGoodTagName ()
    {
        QDomElement domElement = doc.createElement (SingleTypePDS::getTagName());
        int result = singleType->load(domElement);
        QCOMPARE(1, result);
    }

    void CheckBadTagName()
    {
        QDomElement domElement = doc.createElement ("badName");
        int result = singleType->load(domElement);
        QCOMPARE(0, result);
    }

    void SetType()
    {
        int type = 1;
        QDomElement domElement = doc.createElement (SingleTypePDS::getTagName());
        domElement.setAttribute(SingleTypePDS::getAttributeType(), type);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);

        QCOMPARE(type, singleType->getType());

        // Per il tipo del pds abbiamo al massimo 3 bit
        type = 9;
        domElement.setAttribute(SingleTypePDS::getAttributeType(), type);
        result = singleType->load(domElement);
        QCOMPARE(false, result);

        QCOMPARE(-1, singleType->getType());
    }

private:
    SingleTypePDS *singleType;
    QDomDocument doc;
};

QTTESTUTIL_REGISTER_TEST(TestSingleTypePDS);
#include "TestSingleTypePDS.moc"


