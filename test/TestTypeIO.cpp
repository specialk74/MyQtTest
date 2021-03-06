#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "helper.h"
#include "typeio.h"

struct SingleTypeIOStruct {
    int value;
    bool input;
    bool digital;
    int group;
    bool canChangeName;
};

static SingleTypeIOStruct lista[] = {
    {Generico_Input_NO, true, true, 1, true},
    {Regolazione_Impulsiva, true, true, 1, true},
    {Pulsante, true, true, 1, true},
    {Crepuscolare, true, true, 1, true},
    {Anemometro, true, true, 1, true},
    {Pluviometro, true, true, 1, true},
    {Termostato, true, true, 1, true},
    {Inseritore_NO, true, true, 1, true},
    {Presenza_Rete, true, true, 1, true},
    {Generico_Input_NC, true, true, 1, true},
    {Radar, true, true, 1, true},
    {Magneti_Serramenti, true, true, 1, true},
    {Inseritore_NC, true, true, 1, true},
    {Sistema_Sicurezza, true, true, 1, true},
    {Radar_service_B, true, true, 2, true},
    {Radar_media_sens, true, true, 2, true},
    {Radar_alta_sens, true, true, 2, true},
    {Assenza_Rete, true, true, 1, true},
    {Generico_Input_Analogico, true, false, 3, true},
    {Sensore_Temperatura_Service, true, false, 4, true},
    {Sensore_Luce_Service, true, false, 5, true},
    {Ingresso_Controllo_Carichi, true, false, 3, true},
    {Generica_Uscita_NO, false, true, 6, true},
    {Luce_Presa, false, true, 6, true},
    {Elettrovalvola, false, true, 6, true},
    {Motori_Uscita, false, true, 6, true},
    {Suonerie, false, true, 6, true},
    {Antifurto_NC, false, true, 6, true},
    {Generica_Uscita_NC, false, true, 6, true},
    {Generica_Uscita_Analogica, false, false, 7, true},
    {Led_Alta_Luminosita, false, false, 8, true},
    {Uscita_Controllo_Carichi_Liv1, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv2, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv3, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv4, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv5, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv6, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv7, false, true, 6, true},
    {Uscita_Controllo_Carichi_Liv8, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv1, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv2, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv3, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv4, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv5, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv6, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv7, false, true, 6, true},
    {Uscita_Controllo_Carichi_ManLiv8, false, true, 6, true},
    {FeedBack, true, true, 9, false},
    {Sabotaggio, true, true, 10, false}
};

class TestTypeIO: public QObject
{
    Q_OBJECT
public:    
    void printError(SingleTypeIO *single, SingleTypeIOStruct *singleStruct)
    {
        bool fail = false;
        QString message;
        if (single->nome() == "")
        {
            message.append(QString("Value: %1 Name: empty | ").arg(single->value()));
            fail = true;
        }

        if (single->isInput() != singleStruct->input)
        {
            message.append(QString(" | Input: %1 %2 | ").arg(single->isInput()).arg(singleStruct->input));
            fail = true;
        }

        if (single->isDigital() != singleStruct->digital)
        {
            message.append(QString(" | Digital: %1 %2 | ").arg(single->isDigital()).arg(singleStruct->digital));
            fail = true;
        }

        if (single->group() != singleStruct->group)
        {
            message.append(QString(" | Group: %1 %2 | ").arg(single->group()).arg(singleStruct->group));
            fail = true;
        }

        if (single->canChangeName() != singleStruct->canChangeName)
        {
            message.append(QString(" | CanChangeName: %1 %2 | ").arg(single->canChangeName()).arg(singleStruct->canChangeName));
            fail = true;
        }

        if (fail)
        {
            qDebug() << "Nome: "<< single->nome();
            qDebug() << message;
            QFAIL("Error");
        }
    }

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
    void cleanupTestCase ()
    {
        TypeIO::clear();
    }

    void CheckXmlValue()
    {
        int count = sizeof(lista)/sizeof(lista[0]);
        QCOMPARE(count, TypeIO::size());
        for (int idx = 0; idx < count; ++idx)
        {
            SingleTypeIO *single = TypeIO::at(lista[idx].value);
            if (single == NULL)
            {
                QString msgError = QString("single == NULL : idx: %1").arg(lista[idx].value);
                QFAIL(msgError.toLatin1());
            }

            printError (single, &lista[idx]);
        }
    }

    void TestCanChangeIn ()
    {
        bool result = TypeIO::canChangeTypeIn (Generico_Input_NO, Regolazione_Impulsiva);
        QCOMPARE(true, result);
        result = TypeIO::canChangeTypeIn (Generico_Input_NO, Led_Alta_Luminosita);
        QCOMPARE(false, result);
        result = TypeIO::canChangeTypeIn (Generico_Input_NO, Generica_Uscita_NO);
        QCOMPARE(false, result);
    }
};

QTTESTUTIL_REGISTER_TEST(TestTypeIO);
#include "TestTypeIO.moc"
