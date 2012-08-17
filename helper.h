#ifndef HELPER_H
#define HELPER_H

#include <QMap>
#include <QObject>
#include <QString>
#include <QtXml>
#include <QVariant>

int CheckLenName16Char (QObject &, QString const &);

enum MyProperty {
    PROPERTY_TYPE,
};

enum ValueTypeIO {
    // Tipologia ingressi NO
    Generico_Input_NO = 0,
    Regolazione_Impulsiva,
    Pulsante,
    Crepuscolare,
    Anemometro,
    Pluviometro,
    Termostato,
    Inseritore_NO,
    Presenza_Rete,

    // Tipologia ingressi NC
    Generico_Input_NC = 10,
    Radar,
    Magneti_Serramenti,
    Inseritore_NC,
    Sistema_Sicurezza,
    Radar_service_B, // (solo PDS6)
    Radar_media_sens, // (solo PDS6)
    Radar_alta_sens, // (solo PDS6)
    Assenza_Rete,

    // Tipologia ingressi Analogici
    Generico_Input_Analogico = 20,
    Sensore_Temperatura_Service,
    Sensore_Luce_Service,

    Ingresso_Controllo_Carichi = 60,

    // Tipologia Uscite NO
    Generica_Uscita_NO = 30,
    Luce_Presa,
    Elettrovalvola,
    Motori_Uscita,
    Suonerie,
    Antifurto_NC,

    // Tipologia Uscite NC
    Generica_Uscita_NC = 36,

    // Tipologia Uscite Analogiche
    Generica_Uscita_Analogica = 40,
    Led_Alta_Luminosita,

    // Controllo Carichi
    Uscita_Controllo_Carichi_Liv1 = 61,
    Uscita_Controllo_Carichi_Liv2,
    Uscita_Controllo_Carichi_Liv3,
    Uscita_Controllo_Carichi_Liv4,
    Uscita_Controllo_Carichi_Liv5,
    Uscita_Controllo_Carichi_Liv6,
    Uscita_Controllo_Carichi_Liv7,
    Uscita_Controllo_Carichi_Liv8,

    Uscita_Controllo_Carichi_ManLiv1 = 71,
    Uscita_Controllo_Carichi_ManLiv2,
    Uscita_Controllo_Carichi_ManLiv3,
    Uscita_Controllo_Carichi_ManLiv4,
    Uscita_Controllo_Carichi_ManLiv5,
    Uscita_Controllo_Carichi_ManLiv6,
    Uscita_Controllo_Carichi_ManLiv7,
    Uscita_Controllo_Carichi_ManLiv8,

    FeedBack = 100,
    Sabotaggio

};

const char * getMyProperty (const MyProperty &);

enum EnumAddress {
    INVALID_ADDRESS,
    REGULAR_ADDRESS,
    BROADCAST_ADDRESS
};

EnumAddress CheckAddress (const quint16 &);

void setString (QObject *obj, const QDomElement &element, const char *attribute);
bool setInt (QObject *obj, const QDomElement &element, const char *attribute);
bool setBool (QObject *obj, const QDomElement &element, const char *attribute);
int readInt (const QObject *obj,const char *attribute);
QString readString (const QObject *obj, const char *attribute);
bool readBool (const QObject *obj, const char *attribute);

#endif // HELPER_H
