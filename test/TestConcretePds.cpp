#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "helper.h"
#include "concretepds.h"

static QString nomeSetGood = "1234567890123456";
static QString nomeSetBad  = "12345678901234567";


class TestConcretePds: public QObject
{
    Q_OBJECT
public:

private slots:
    void initTestCase ()
    {
    }

    void init()
    {
        parente = new QObject;
        concretePds = new ConcretePds(parente);
    }
    void cleanup()
    {
        delete concretePds;
        delete parente;
    }

    void create()
    {
    }


    /* INIZIO NAME */
    void GetNameAtStart()
    {
        QCOMPARE(QString(""), concretePds->getName());
    }

    void SetName()
    {
        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->setName(nomeSetGood);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::String);
        QVERIFY(arguments.at(0).toString() == nomeSetGood); // verify the first argument
    }

    void GetName()
    {
        concretePds->setName(nomeSetGood);
        QCOMPARE(nomeSetGood, concretePds->getName());
    }

    void SetNameTooLong()
    {
        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->setName(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    void SetNameNotChange()
    {
        concretePds->setName(nomeSetGood);

        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->setName(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time

        QCOMPARE(nomeSetGood, concretePds->getName());
    }

    void SetNameSameName()
    {
        concretePds->setName(nomeSetGood);
        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->setName(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    /* FINE NOME */

    /* INIZIO ADDRESS */
    void TestSetAddress ()
    {
        quint16 address = 0;
        concretePds->setAddress(address);
        QCOMPARE((quint16)0, concretePds->getAddress());

        address = 0x100;
        concretePds->setAddress(address);
        QCOMPARE((quint16)0, concretePds->getAddress());

        address = 0x001;
        concretePds->setAddress(address);
        QCOMPARE((quint16)0, concretePds->getAddress());

        address = 0x101;
        concretePds->setAddress(address);
        QCOMPARE(address, concretePds->getAddress());

        concretePds->setAddress(0x102);
        QCOMPARE(address, concretePds->getAddress());
    }

    /* FINE ADDRESS */

private:
    ConcretePds *concretePds;
    QObject *parente;
};

QTTESTUTIL_REGISTER_TEST(TestConcretePds);
#include "TestConcretePds.moc"


