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
        QCOMPARE(QString(""), concretePds->name());
    }

    void SetName()
    {
        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->name(nomeSetGood);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::String);
        QVERIFY(arguments.at(0).toString() == nomeSetGood); // verify the first argument
    }

    void GetName()
    {
        concretePds->name(nomeSetGood);
        QCOMPARE(nomeSetGood, concretePds->name());
    }

    void SetNameTooLong()
    {
        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->name(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    void SetNameNotChange()
    {
        concretePds->name(nomeSetGood);

        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->name(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time

        QCOMPARE(nomeSetGood, concretePds->name());
    }

    void SetNameSameName()
    {
        concretePds->name(nomeSetGood);
        QSignalSpy spy(concretePds, SIGNAL(nameChanged(QString)));
        concretePds->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    /* FINE NOME */

private:
    ConcretePds *concretePds;
    QObject *parente;
};

QTTESTUTIL_REGISTER_TEST(TestConcretePds);
#include "TestConcretePds.moc"


