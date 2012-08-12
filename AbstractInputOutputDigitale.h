#ifndef D_AbstractInputOutputDigitale_H
#define D_AbstractInputOutputDigitale_H

///////////////////////////////////////////////////////////////////////////////
//
//  AbstractInputOutputDigitale is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////

#include <QMetaType>
#include <QObject>
#include <QString>

class AbstractInputOutputDigitale : public QObject
{
    Q_OBJECT

public:
    explicit AbstractInputOutputDigitale(QObject *parent = NULL);
    virtual ~AbstractInputOutputDigitale();

    virtual bool isInput() = 0;
    virtual void value(int);
    virtual int value();
    
    enum TipoDigitale {
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
    };
    
    virtual TipoDigitale type() = 0;
    virtual void type (TipoDigitale) = 0;
    
    virtual bool canChangeType() = 0;
    virtual bool canChangeTypeIn (TipoDigitale) = 0;
    
    virtual void name (const QString &) = 0;
    virtual QString name () const = 0;
    
signals:
    void valueChanged(int);
    void nameChanged(QString);
    void typeChanged(AbstractInputOutputDigitale::TipoDigitale);

private:

    AbstractInputOutputDigitale(const AbstractInputOutputDigitale&);
    AbstractInputOutputDigitale& operator=(const AbstractInputOutputDigitale&);

    bool m_value;
};

Q_DECLARE_METATYPE(AbstractInputOutputDigitale::TipoDigitale)

#endif  // D_AbstractInputOutputDigitale_H
