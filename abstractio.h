#ifndef ABSTRACTIO_H
#define ABSTRACTIO_H

///////////////////////////////////////////////////////////////////////////////
//
//  AbstractIO is responsible for ...
//
///////////////////////////////////////////////////////////////////////////////

#include <QObject>
#include <QString>

#include "typeio.h"

class AbstractIO : public QObject
{
    Q_OBJECT

public:
    explicit AbstractIO(QObject *parent = NULL);
    virtual ~AbstractIO();

    virtual void value(const int &) = 0;
    virtual int value() const = 0;

    virtual int getType() const { return m_type ? m_type->value() : -1; }
    virtual void setType (const int &t);

    virtual void name (const QString &);
    virtual QString name () const;

    virtual quint8 getNumero() const { return m_numero; }
    virtual void setNumero(const quint8 &);

signals:
    void valueChanged(int);
    void nameChanged(QString);
    void typeChanged(int);

private:
    SingleTypeIO * m_type;
    quint8 m_numero;

    AbstractIO(const AbstractIO&);
    AbstractIO& operator=(const AbstractIO&);
};

#endif // ABSTRACTIO_H
