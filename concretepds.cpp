#include "concretepds.h"
#include "helper.h"

ConcretePds::ConcretePds(QObject *parente) : QObject(parente)
{
    m_address = 0;
}

void ConcretePds::setName (const QString & str)
{
    if (CheckLenName16Char(*this, str))
    {
        emit nameChanged(str);
    }
}

QString ConcretePds::getName() const
{
    return objectName();
}


void ConcretePds::setAddress(const quint16 & address)
{
    if (m_address == 0)
    {
        if (CheckAddress(address) == REGULAR_ADDRESS)
            m_address = address;
    }
}
