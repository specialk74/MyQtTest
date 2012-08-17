#include <QtTest/QtTest>
#include "QtTestUtil/QtTestUtil.h"

#include "singletypeio.h"

class TestSingleTypeIO: public QObject
{
    Q_OBJECT
public:

private slots:
    void initTestCase ()
    {
    }

    void init()
    {
        singleType = new SingleTypeIO;
    }
    void cleanup()
    {
        delete singleType;
    }

    void create()
    {
    }

    void CheckGoodTagName()
    {
        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        int result = singleType->load(domElement);
        QCOMPARE(1, result);
    }

    void CheckBadTagName()
    {
        QDomElement domElement = doc.createElement ("badName");
        int result = singleType->load(domElement);
        QCOMPARE(0, result);
    }

    void SetName()
    {
        QString provaNome = "prova";
        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeNome(), provaNome);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);

        QString resultNome=singleType->nome();
        QCOMPARE(provaNome, resultNome);
    }

    void CheckValore ()
    {
        int valore = singleType->value();
        QCOMPARE(-1, valore);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeValue(), 1);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);

        valore = singleType->value();
        QCOMPARE(1, valore);

        domElement.setAttribute(SingleTypeIO::getAttributeValue(), -1);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckInput ()
    {
        bool input = singleType->isInput();
        QCOMPARE(false, input);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeInput(), 1);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);
        input = singleType->isInput();
        QCOMPARE(true, input);

        domElement.setAttribute(SingleTypeIO::getAttributeInput(), 0);
        result = singleType->load(domElement);
        QCOMPARE(true, result);
        input = singleType->isInput();
        QCOMPARE(false, input);

        domElement.setAttribute(SingleTypeIO::getAttributeInput(), -1);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
        domElement.setAttribute(SingleTypeIO::getAttributeInput(), 2);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckDigital ()
    {
        bool digital = singleType->isDigital();
        QCOMPARE(false, digital);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), 1);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);

        digital = singleType->isDigital();
        QCOMPARE(true, digital);

        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), 0);
        result = singleType->load(domElement);
        QCOMPARE(true, result);

        digital = singleType->isDigital();
        QCOMPARE(false, digital);

        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), -1);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), 2);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckGroup ()
    {
        int valore = singleType->group();
        QCOMPARE(-1, valore);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeGroup(), 1);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);

        valore = singleType->group();
        QCOMPARE(1, valore);

        domElement.setAttribute(SingleTypeIO::getAttributeGroup(), -1);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckChangeName ()
    {
        bool canChangename = singleType->canChangeName();
        QCOMPARE(false, canChangename);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), 1);
        bool result = singleType->load(domElement);
        QCOMPARE(true, result);

        canChangename = singleType->canChangeName();
        QCOMPARE(true, canChangename);

        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), 0);
        result = singleType->load(domElement);
        QCOMPARE(true, result);

        canChangename = singleType->canChangeName();
        QCOMPARE(false, canChangename);

        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), -1);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), 2);
        result = singleType->load(domElement);
        QCOMPARE(false, result);
    }

private:
    SingleTypeIO *singleType;
    QDomDocument doc;
};

QTTESTUTIL_REGISTER_TEST(TestSingleTypeIO);
#include "TestSingleTypeIO.moc"

