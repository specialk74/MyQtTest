#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "InputDigitale.h"

static AbstractInputOutputDigitale::TipoDigitale listaTipiConsentiti[] = {
    AbstractInputOutputDigitale::Generico_Input_NO,
    AbstractInputOutputDigitale::Regolazione_Impulsiva,
    AbstractInputOutputDigitale::Pulsante,
    AbstractInputOutputDigitale::Crepuscolare,
    AbstractInputOutputDigitale::Anemometro,
    AbstractInputOutputDigitale::Pluviometro,
    AbstractInputOutputDigitale::Termostato,
    AbstractInputOutputDigitale::Inseritore_NO,
    AbstractInputOutputDigitale::Presenza_Rete,

    // Tipologia ingressi NC
    AbstractInputOutputDigitale::Generico_Input_NC,
    AbstractInputOutputDigitale::Radar,
    AbstractInputOutputDigitale::Magneti_Serramenti,
    AbstractInputOutputDigitale::Inseritore_NC,
    AbstractInputOutputDigitale::Sistema_Sicurezza,
    AbstractInputOutputDigitale::Assenza_Rete,
};

static AbstractInputOutputDigitale::TipoDigitale listaTipiNonConsentiti[] = {
    AbstractInputOutputDigitale::Radar_service_B,
    AbstractInputOutputDigitale::Radar_media_sens,
    AbstractInputOutputDigitale::Radar_alta_sens,

    // Tipologia ingressi Analogici
    AbstractInputOutputDigitale::Generico_Input_Analogico,
    AbstractInputOutputDigitale::Sensore_Temperatura_Service,
    AbstractInputOutputDigitale::Sensore_Luce_Service,

    AbstractInputOutputDigitale::Ingresso_Controllo_Carichi,

    // Tipologia Uscite NO
    AbstractInputOutputDigitale::Generica_Uscita_NO,
    AbstractInputOutputDigitale::Luce_Presa,
    AbstractInputOutputDigitale::Elettrovalvola,
    AbstractInputOutputDigitale::Motori_Uscita,
    AbstractInputOutputDigitale::Suonerie,
    AbstractInputOutputDigitale::Antifurto_NC,

    // Tipologia Uscite NC
    AbstractInputOutputDigitale::Generica_Uscita_NC,

    // Tipologia Uscite Analogiche
    AbstractInputOutputDigitale::Generica_Uscita_Analogica,
    AbstractInputOutputDigitale::Led_Alta_Luminosita,

    // Controllo Carichi
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv1,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv2,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv3,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv4,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv5,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv6,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv7,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv8,

    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv1,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv2,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv3,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv4,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv5,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv6,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv7,
    AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv8,
};

static QString nomeSetGood = "1234567890123456";
static QString nomeSetBad  = "12345678901234567";


class TestInputDigitale: public QObject
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
    void init()
    {
        inputDigitale = new InputDigitale();
    }
    void cleanup()
    {
        delete inputDigitale;
    }

    void create()
    {
        bool result = inputDigitale->isInput();
        QVERIFY(result == true);
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
    void CheckCanChange()
    {
        bool result = inputDigitale->canChangeType();
        QCOMPARE(true, result);
    }

    void SetTipoConsentito()
    {
        qDebug() << __LINE__;
        qRegisterMetaType<AbstractInputOutputDigitale::TipoDigitale>("TipoDigitale");
        qDebug() << __LINE__;
        QSignalSpy spy(inputDigitale, SIGNAL(typeChanged(AbstractInputOutputDigitale::TipoDigitale)));
        QList<QVariant> arguments;

        for (unsigned int idx = 0; idx < (sizeof(listaTipiConsentiti)/sizeof(AbstractInputOutputDigitale::TipoDigitale)); ++idx)
        {
            // Controllo se funziona il "posso cambiare in"
            {
                bool result = inputDigitale->canChangeTypeIn(listaTipiConsentiti[idx]);
                QCOMPARE(true, result);
            }

            if (listaTipiConsentiti[idx] != inputDigitale->getType())
            {
                inputDigitale->setType(listaTipiConsentiti[idx]);
                QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time
                arguments = spy.takeFirst();
                qDebug() << __LINE__;
                QVERIFY(arguments.at(0).userType() == qMetaTypeId<AbstractInputOutputDigitale::TipoDigitale>());
                qDebug() << __LINE__;
                AbstractInputOutputDigitale::TipoDigitale result = arguments.at(0).value<AbstractInputOutputDigitale::TipoDigitale>();
                qDebug() << __LINE__;
                QVERIFY(result == listaTipiConsentiti[idx]); // verify the first argument

                // Controllo che mantenga il tipo passato
                AbstractInputOutputDigitale::TipoDigitale tipo = inputDigitale->getType();
                QCOMPARE(tipo, listaTipiConsentiti[idx]);

                // Se risetto lo stesso tipo, deve ritornarmi zero
                inputDigitale->setType(listaTipiConsentiti[idx]);
                QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
            }
            else
            {
                inputDigitale->setType(listaTipiConsentiti[idx]);
                QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
            }
        }
    }

    void SetTipoNonConsentito()
    {
        for (unsigned int idx = 0; idx < (sizeof(listaTipiNonConsentiti)/sizeof(AbstractInputOutputDigitale::TipoDigitale)); ++idx)
        {
            {
                bool result = inputDigitale->canChangeTypeIn(listaTipiNonConsentiti[idx]);
                QCOMPARE(false, result);
            }

            {
                QSignalSpy spy(inputDigitale, SIGNAL(typeChanged(AbstractInputOutputDigitale::TipoDigitale)));
                inputDigitale->setType(listaTipiNonConsentiti[idx]);
                QCOMPARE(spy.count(), 0); // make sure the signal was emitted exactly 0 time
            }
        }
    }

    void CheckSignalValueWhenChangeTipo()
    {
        inputDigitale->setType(AbstractInputOutputDigitale::Generico_Input_NO);
        QSignalSpy spy(inputDigitale, SIGNAL(typeChanged(AbstractInputOutputDigitale::TipoDigitale)));
        inputDigitale->setType(AbstractInputOutputDigitale::Radar);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time
    }
    /* FINE TYPE*/






    /* INIZIO NAME */
    void GetNameAtStart()
    {
        QCOMPARE(QString(""), inputDigitale->name());
    }

    void SetName()
    {
        QSignalSpy spy(inputDigitale, SIGNAL(nameChanged(QString)));
        inputDigitale->name(nomeSetGood);
        QCOMPARE(spy.count(), 1); // make sure the signal was emitted exactly 1 time

        QList<QVariant> arguments = spy.takeFirst();
        QVERIFY(arguments.at(0).type() == QVariant::String);
        QVERIFY(arguments.at(0).toString() == nomeSetGood); // verify the first argument
    }

    void GetName()
    {
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

private:
    InputDigitale *inputDigitale;
};

QTTESTUTIL_REGISTER_TEST(TestInputDigitale);
#include "TestInputDigitale.moc"