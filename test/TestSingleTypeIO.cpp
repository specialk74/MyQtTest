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
        singleTypeIO = new SingleTypeIO;
    }
    void cleanup()
    {
        delete singleTypeIO;
    }

    void create()
    {
    }

    void CheckGoodTagName()
    {
        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        int result = singleTypeIO->load(domElement);
        QCOMPARE(1, result);
    }

    void CheckBadTagName()
    {
        QDomElement domElement = doc.createElement ("badName");
        int result = singleTypeIO->load(domElement);
        QCOMPARE(0, result);
    }

    void SetName()
    {
        QString provaNome = "prova";
        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeNome(), provaNome);
        bool result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);

        QString resultNome=singleTypeIO->nome();
        QCOMPARE(provaNome, resultNome);
    }

    void CheckValore ()
    {
        int valore = singleTypeIO->value();
        QCOMPARE(-1, valore);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeValue(), 1);
        bool result = singleTypeIO->load(domElement);        
        QCOMPARE(true, result);

        valore = singleTypeIO->value();
        QCOMPARE(1, valore);

        domElement.setAttribute(SingleTypeIO::getAttributeValue(), -1);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckInput ()
    {
        bool input = singleTypeIO->isInput();
        QCOMPARE(false, input);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeInput(), 1);
        bool result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);
        input = singleTypeIO->isInput();
        QCOMPARE(true, input);

        domElement.setAttribute(SingleTypeIO::getAttributeInput(), 0);
        result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);
        input = singleTypeIO->isInput();
        QCOMPARE(false, input);

        domElement.setAttribute(SingleTypeIO::getAttributeInput(), -1);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
        domElement.setAttribute(SingleTypeIO::getAttributeInput(), 2);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckDigital ()
    {
        bool digital = singleTypeIO->isDigital();
        QCOMPARE(false, digital);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), 1);
        bool result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);

        digital = singleTypeIO->isDigital();
        QCOMPARE(true, digital);

        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), 0);
        result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);

        digital = singleTypeIO->isDigital();
        QCOMPARE(false, digital);

        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), -1);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
        domElement.setAttribute(SingleTypeIO::getAttributeDigital(), 2);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckGroup ()
    {
        int valore = singleTypeIO->group();
        QCOMPARE(-1, valore);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeGroup(), 1);
        bool result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);

        valore = singleTypeIO->group();
        QCOMPARE(1, valore);

        domElement.setAttribute(SingleTypeIO::getAttributeGroup(), -1);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
    }

    void CheckChangeName ()
    {
        bool canChangename = singleTypeIO->canChangeName();
        QCOMPARE(false, canChangename);

        QDomElement domElement = doc.createElement (SingleTypeIO::getTagName());
        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), 1);
        bool result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);

        canChangename = singleTypeIO->canChangeName();
        QCOMPARE(true, canChangename);

        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), 0);
        result = singleTypeIO->load(domElement);
        QCOMPARE(true, result);

        canChangename = singleTypeIO->canChangeName();
        QCOMPARE(false, canChangename);

        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), -1);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
        domElement.setAttribute(SingleTypeIO::getAttributeCanChangeName(), 2);
        result = singleTypeIO->load(domElement);
        QCOMPARE(false, result);
    }

private:
    SingleTypeIO *singleTypeIO;
    QDomDocument doc;
};

QTTESTUTIL_REGISTER_TEST(TestSingleTypeIO);
#include "TestSingleTypeIO.moc"

