#include "AbstractInputOutputDigitale.h"
#include "helper.h"

AbstractInputOutputDigitale::AbstractInputOutputDigitale(QObject *parent) : QObject (parent)
{
    m_value = false;
}

AbstractInputOutputDigitale::~AbstractInputOutputDigitale()
{
}

void AbstractInputOutputDigitale::value(int val)
{
    switch (val)
    {
    case 0:
        if (m_value == false)
            return;

        m_value = false;
        break;

    case 1:
        if (m_value == true)
            return;

        m_value = true;
        break;

    default:
        return;
    }

    emit valueChanged(val);
}

int AbstractInputOutputDigitale::value() 
{ 
    return ((m_value == true) ? 1 : 0);
}

void AbstractInputOutputDigitale::name (const QString & str)
{
    if (CheckLenName16Char(*this, str))
    {        
        emit nameChanged(str);
    }
}

QString AbstractInputOutputDigitale::name() const
{
    return objectName();
}

void AbstractInputOutputDigitale::setType (AbstractInputOutputDigitale::TipoDigitale t)
{
    if (canChangeTypeIn(t))
    {
        if (getType() == t)
            return;

        setTypeProtected(t);
    }
}
