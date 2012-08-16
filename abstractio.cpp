#include "abstractio.h"
#include "helper.h"

AbstractIO::AbstractIO(QObject *parent) : QObject (parent)
{
    m_type = TypeIO::at(0); // Per default e' un ingresso di Tipo NC
}

AbstractIO::~AbstractIO()
{
}

void AbstractIO::name (const QString & str)
{
    if (m_type->canChangeName() && (CheckLenName16Char(*this, str)))
    {
        emit nameChanged(str);
    }
}

QString AbstractIO::name() const
{
    return objectName();
}

void AbstractIO::setType (const int &t)
{
    if (TypeIO::canChangeTypeIn(m_type->value(), t))
    {
        if (getType() == t)
            return;

        m_type = TypeIO::at(t);
        emit typeChanged(t);
    }
}
