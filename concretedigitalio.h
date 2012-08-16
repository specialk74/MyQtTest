#ifndef CONCRETEDIGITALIO_H
#define CONCRETEDIGITALIO_H

#include "abstractio.h"

class ConcreteDigitalIO : public AbstractIO
{
public:
    explicit ConcreteDigitalIO(QObject *parent);

    virtual void value(const int &);
    virtual int value() const;

protected:
    bool m_value;
};

#endif // CONCRETEDIGITALIO_H
