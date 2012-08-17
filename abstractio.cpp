#include "abstractio.h"
#include "helper.h"

AbstractIO::AbstractIO(QObject *parent) : QObject (parent)
{
    m_type = NULL;
    m_numero = 0;
}

AbstractIO::~AbstractIO()
{
}

void AbstractIO::name (const QString & str)
{
    if (m_type && m_type->canChangeName() && (CheckLenName16Char(*this, str)))
    {
        emit nameChanged(str);
    }
}

QString AbstractIO::name() const
{
    if (!objectName().isEmpty())
        return objectName();
    else if (m_type)
        return m_type->nome();

    return QString ("");
}

void AbstractIO::setType (const int &t)
{
    if (getType() == t)
        return;

    if ((m_type == NULL) || TypeIO::canChangeTypeIn(m_type->value(), t))
    {
        m_type = TypeIO::at(t);
        emit typeChanged(t);
    }
}

void AbstractIO::setNumero(const quint8 &n)
{
    m_numero = n;
}
