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

class TestTypeIO: public QObject
{
    Q_OBJECT
public:

private slots:
    void init()
    {
        typeInputDigitale = new TypeIO_Input();
    }
    void cleanup()
    {
        delete typeInputDigitale;
    }

    void create()
    {
        bool result = typeInputDigitale->isInput();
        QVERIFY(result == true);
    }

private:
    TypeIO_Input *typeInputDigitale;
};

QTTESTUTIL_REGISTER_TEST(TestTypeIO);
#include "TestTypeIO.moc"
