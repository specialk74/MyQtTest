#ifndef CONCRETEANALOGIO_H
#define CONCRETEANALOGIO_H

#include "abstractio.h"

class ConcreteAnalogIO : public AbstractIO
{
public:
    explicit ConcreteAnalogIO(QObject *parent);

    virtual void value(const int &);
    virtual int value() const;

protected:
    quint16 m_value;
};

#endif // CONCRETEANALOGIO_H
