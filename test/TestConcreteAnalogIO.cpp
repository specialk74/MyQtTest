#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "helper.h"
#include "concreteanalogio.h"

static QString nomeSetGood = "1234567890123456";
static QString nomeSetBad  = "12345678901234567";


class TestConcreteAnalogIO: public QObject
{
    Q_OBJECT
public:
    void GetSingleValue (int val)
    {
        inputAnalogico->value(val);
        int result = inputAnalogico->value();
        QCOMPARE(val, result);
    }

    void CheckEmitEqualZero (int val)
    {
        inputAnalogico->value(val);
        QSignalSpy spy(inputAnalogico, SIGNAL(valueChanged(int)));

        inputAnalogico->value(val);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }


private slots:
    void initTestCase ()
    {
        bool result = TypeIO::init(":/TypeIO.xml");
        QVERIFY(result == true);
    }

    void init()
    {
        parente = new QObject;
        inputAnalogico = new ConcreteAnalogIO(parente);
    }
    void cleanup()
    {
        delete inputAnalogico;
        delete parente;
    }

    void create()
    {
        int result = inputAnalogico->getType();
        QCOMPARE(-1, result);
    }



    /* INIZIO VALUE */
    void GetValueAtStart()
    {
        int result = inputAnalogico->value();
        QCOMPARE(0, result);
    }

    void SetValueOn()
    {
        QSignalSpy spy(inputAnalogico, SIGNAL(valueChanged(int)));
        inputAnalogico->value(1);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::Int);
        QVERIFY(arguments.at(0).toInt() == 1); // verify the first argument
    }

    void SetValueOff()
    {
        inputAnalogico->value(1);
        QSignalSpy spy(inputAnalogico, SIGNAL(valueChanged(int)));
        inputAnalogico->value(0);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::Int);
        QVERIFY(arguments.at(0).toInt() == 0); // verify the first argument
    }

    void SetStrangeValue()
    {
        {
            QSignalSpy spy(inputAnalogico, SIGNAL(valueChanged(int)));
            inputAnalogico->value(-1);
            QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
        }
    }

    void GetValue()
    {
        int result = inputAnalogico->value();
        if (result == -1)
            QFAIL("result = -1");
    }

    void GetValueOff()
    {
        GetSingleValue(0);
    }

    void GetValueOn()
    {
        GetSingleValue(1);
    }

    void CheckResultWhenValueNotChange()
    {
        CheckEmitEqualZero (0);
        CheckEmitEqualZero (1);
    }
    /* FINE VALUE */




    /* INIZIO TYPE */
    void CheckSignalValueWhenChangeTipo()
    {
        inputAnalogico->setType(Generico_Input_NO);
        QSignalSpy spy(inputAnalogico, SIGNAL(typeChanged(int)));
        inputAnalogico->setType(Generico_Input_NC);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time
        inputAnalogico->setType(Generico_Input_NC);
        QCOMPARE(spy.count(), 1); // non deve aumentare rispetto all'ultimo spy.count()

        inputAnalogico->setType(Generica_Uscita_NC);
        QCOMPARE(spy.count(), 1); // non deve aumentare rispetto all'ultimo spy.count()
    }
    /* FINE TYPE */







    /* INIZIO NAME */
    void GetNameAtStart()
    {
        QCOMPARE(QString(""), inputAnalogico->name());
    }

    void SetName()
    {
        inputAnalogico->setType(Generico_Input_NO);
        QSignalSpy spy(inputAnalogico, SIGNAL(nameChanged(QString)));
        inputAnalogico->name(nomeSetGood);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::String);
        QVERIFY(arguments.at(0).toString() == nomeSetGood); // verify the first argument
    }

    void GetName()
    {
        inputAnalogico->setType(Generico_Input_NO);
        inputAnalogico->name(nomeSetGood);
        QCOMPARE(nomeSetGood, inputAnalogico->name());
    }

    void SetNameTooLong()
    {
        QSignalSpy spy(inputAnalogico, SIGNAL(nameChanged(QString)));
        inputAnalogico->name(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    void SetNameNotChange()
    {
        inputAnalogico->setType(Generico_Input_NO);
        inputAnalogico->name(nomeSetGood);

        QSignalSpy spy(inputAnalogico, SIGNAL(nameChanged(QString)));
        inputAnalogico->name(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time

        QCOMPARE(nomeSetGood, inputAnalogico->name());
    }

    void SetNameSameName()
    {
        inputAnalogico->name(nomeSetGood);
        QSignalSpy spy(inputAnalogico, SIGNAL(nameChanged(QString)));
        inputAnalogico->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    void SetNameFeedBack()
    {
        inputAnalogico->setType(FeedBack);
        QSignalSpy spy(inputAnalogico, SIGNAL(nameChanged(QString)));

        inputAnalogico->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
        QCOMPARE(QString("FeedBack"), inputAnalogico->name());
    }

    void SetNameSabotaggio()
    {
        inputAnalogico->setType(Sabotaggio);
        QSignalSpy spy(inputAnalogico, SIGNAL(nameChanged(QString)));

        inputAnalogico->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
        QCOMPARE(QString("Sabotaggio"), inputAnalogico->name());
    }
    /* FINE NOME */

private:
    ConcreteAnalogIO *inputAnalogico;
    QObject *parente;
};

QTTESTUTIL_REGISTER_TEST(TestConcreteAnalogIO);
#include "TestConcreteAnalogIO.moc"


