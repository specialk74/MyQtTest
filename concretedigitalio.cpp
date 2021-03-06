#include "concretedigitalio.h"

ConcreteDigitalIO::ConcreteDigitalIO(QObject *parent) : AbstractIO(parent)
{
    m_value = false;
}

void ConcreteDigitalIO::value (const int &val)
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

int ConcreteDigitalIO::value() const
{
    return ((m_value == true) ? 1 : 0);
}
