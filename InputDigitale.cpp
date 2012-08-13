#include <QVariant>
#include "helper.h"
#include "InputDigitale.h"

InputDigitale::InputDigitale(QObject *parent) : AbstractInputOutputDigitale (parent)
{
  m_tipo = Generico_Input_NO;

  setProperty(getMyProperty(PROPERTY_TYPE), QVariant(AbstractInputOutputDigitale::Generico_Input_NO));

  setObjectName("");
}

InputDigitale::~InputDigitale()
{
}

AbstractInputOutputDigitale::TipoDigitale InputDigitale::getType()
{
    return property(getMyProperty(PROPERTY_TYPE)).value<AbstractInputOutputDigitale::TipoDigitale>();
}

void InputDigitale::setTypeProtected (AbstractInputOutputDigitale::TipoDigitale t)
{
    setProperty(getMyProperty(PROPERTY_TYPE), QVariant(t));
    emit typeChanged(t);
}


bool InputDigitale::canChangeTypeIn (AbstractInputOutputDigitale::TipoDigitale t)
{ 
  switch (t)
  {
    case AbstractInputOutputDigitale::Generico_Input_NO:
       case AbstractInputOutputDigitale::Regolazione_Impulsiva:
       case AbstractInputOutputDigitale::Pulsante:
       case AbstractInputOutputDigitale::Crepuscolare:
       case AbstractInputOutputDigitale::Anemometro:
       case AbstractInputOutputDigitale::Pluviometro:
       case AbstractInputOutputDigitale::Termostato:
       case AbstractInputOutputDigitale::Inseritore_NO:
       case AbstractInputOutputDigitale::Presenza_Rete:

      // Tipologia ingressi NC
       case AbstractInputOutputDigitale::Generico_Input_NC:
       case AbstractInputOutputDigitale::Radar:
       case AbstractInputOutputDigitale::Magneti_Serramenti:
       case AbstractInputOutputDigitale::Inseritore_NC:
       case AbstractInputOutputDigitale::Sistema_Sicurezza:
       case AbstractInputOutputDigitale::Assenza_Rete:       
  break;

  default:
       case AbstractInputOutputDigitale::Radar_service_B:
       case AbstractInputOutputDigitale::Radar_media_sens:
       case AbstractInputOutputDigitale::Radar_alta_sens:

      // Tipologia ingressi Analogici
       case AbstractInputOutputDigitale::Generico_Input_Analogico:
       case AbstractInputOutputDigitale::Sensore_Temperatura_Service:
       case AbstractInputOutputDigitale::Sensore_Luce_Service:

       case AbstractInputOutputDigitale::Ingresso_Controllo_Carichi:
       
      // Tipologia Uscite NO
       case AbstractInputOutputDigitale::Generica_Uscita_NO:
       case AbstractInputOutputDigitale::Luce_Presa:
       case AbstractInputOutputDigitale::Elettrovalvola:
       case AbstractInputOutputDigitale::Motori_Uscita:
       case AbstractInputOutputDigitale::Suonerie:
       case AbstractInputOutputDigitale::Antifurto_NC:

      // Tipologia Uscite NC
       case AbstractInputOutputDigitale::Generica_Uscita_NC:

      // Tipologia Uscite Analogiche
       case AbstractInputOutputDigitale::Generica_Uscita_Analogica:
       case AbstractInputOutputDigitale::Led_Alta_Luminosita:

      // Controllo Carichi
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv1:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv2:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv3:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv4:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv5:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv6:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv7:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_Liv8:

       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv1:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv2:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv3:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv4:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv5:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv6:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv7:
       case AbstractInputOutputDigitale::Uscita_Controllo_Carichi_ManLiv8:
             return false;
    break;
      }  
  
    return true;
}
