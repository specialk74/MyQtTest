#include "concreteanalogio.h"

ConcreteAnalogIO::ConcreteAnalogIO(QObject *parent) : AbstractIO(parent)
{
    m_value = 0;
}

void ConcreteAnalogIO::value (const int &val)
{
    if ((val >= 0) && (m_value != val))
    {
        m_value = val;
        emit valueChanged(val);
    }
}

int ConcreteAnalogIO::value() const
{
    return (m_value);
}
