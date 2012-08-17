#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "helper.h"
#include "concretedigitalio.h"

static QString nomeSetGood = "1234567890123456";
static QString nomeSetBad  = "12345678901234567";


class TestConcreteDigitalIO: public QObject
{
    Q_OBJECT
public:
    void GetSingleValue (int val)
    {
        inputDigitale->value(val);
        int result = inputDigitale->value();
        QCOMPARE(val, result);
    }

    void CheckEmitEqualZero (int val)
    {
        inputDigitale->value(val);
        QSignalSpy spy(inputDigitale, SIGNAL(valueChanged(int)));

        inputDigitale->value(val);
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
        inputDigitale = new ConcreteDigitalIO(parente);
    }
    void cleanup()
    {
        delete inputDigitale;
        delete parente;
    }

    void create()
    {
        int result = inputDigitale->getType();
        QCOMPARE(-1, result);
    }



    /* INIZIO VALUE */
    void GetValueAtStart()
    {
        int result = inputDigitale->value();
        QCOMPARE(0, result);
    }

    void SetValueOn()
    {
        QSignalSpy spy(inputDigitale, SIGNAL(valueChanged(int)));
        inputDigitale->value(1);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::Int);
        QVERIFY(arguments.at(0).toInt() == 1); // verify the first argument
    }

    void SetValueOff()
    {
        inputDigitale->value(1);
        QSignalSpy spy(inputDigitale, SIGNAL(valueChanged(int)));
        inputDigitale->value(0);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::Int);
        QVERIFY(arguments.at(0).toInt() == 0); // verify the first argument
    }

    void SetStrangeValue()
    {
        {
            QSignalSpy spy(inputDigitale, SIGNAL(valueChanged(int)));
            inputDigitale->value(-1);
            QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
        }

        {
            QSignalSpy spy(inputDigitale, SIGNAL(valueChanged(int)));
            inputDigitale->value(2);
            QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 1 time
        }
    }

    void GetValue()
    {
        int result = inputDigitale->value();
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
        inputDigitale->setType(Generico_Input_NO);
        QSignalSpy spy(inputDigitale, SIGNAL(typeChanged(int)));
        inputDigitale->setType(Generico_Input_NC);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time
        inputDigitale->setType(Generico_Input_NC);
        QCOMPARE(spy.count(), 1); // non deve aumentare rispetto all'ultimo spy.count()

        inputDigitale->setType(Generica_Uscita_NC);
        QCOMPARE(spy.count(), 1); // non deve aumentare rispetto all'ultimo spy.count()
    }
    /* FINE TYPE */







    /* INIZIO NAME */
    void GetNameAtStart()
    {
        QCOMPARE(QString(""), inputDigitale->name());
    }

    void SetName()
    {
        inputDigitale->setType(Generico_Input_NO);
        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));
        inputDigitale->name(nomeSetGood);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::String);
        QVERIFY(arguments.at(0).toString() == nomeSetGood); // verify the first argument
    }

    void GetName()
    {
        inputDigitale->setType(Generico_Input_NO);
        inputDigitale->name(nomeSetGood);
        QCOMPARE(nomeSetGood, inputDigitale->name());
    }

    void SetNameTooLong()
    {
        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));
        inputDigitale->name(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    void SetNameNotChange()
    {
        inputDigitale->setType(Generico_Input_NO);
        inputDigitale->name(nomeSetGood);

        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));
        inputDigitale->name(nomeSetBad);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time

        QCOMPARE(nomeSetGood, inputDigitale->name());
    }

    void SetNameSameName()
    {
        inputDigitale->name(nomeSetGood);
        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));
        inputDigitale->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
    }

    void SetNameFeedBack()
    {
        inputDigitale->setType(FeedBack);
        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));

        inputDigitale->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
        QCOMPARE(QString("FeedBack"), inputDigitale->name());
    }

    void SetNameSabotaggio()
    {
        inputDigitale->setType(Sabotaggio);
        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));

        inputDigitale->name(nomeSetGood);
        QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
        QCOMPARE(QString("Sabotaggio"), inputDigitale->name());
    }
    /* FINE NOME */

    void TestNumeroIO ()
    {
        QCOMPARE((quint8)0, inputDigitale->getNumero());
        inputDigitale->setNumero((quint8)1);
        QCOMPARE((quint8)1, inputDigitale->getNumero());
    }

private:
    ConcreteDigitalIO *inputDigitale;
    QObject *parente;
};

QTTESTUTIL_REGISTER_TEST(TestConcreteDigitalIO);
#include "TestConcreteDigitalIO.moc"

