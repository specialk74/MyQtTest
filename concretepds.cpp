#include "concretepds.h"
#include "helper.h"

ConcretePds::ConcretePds(QObject *parente) : QObject(parente)
{
}

void ConcretePds::name (const QString & str)
{
    if (CheckLenName16Char(*this, str))
    {
        emit nameChanged(str);
    }
}

QString ConcretePds::name() const
{
    return objectName();
}
