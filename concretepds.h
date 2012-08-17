#ifndef CONCRETEPDS_H
#define CONCRETEPDS_H

#include <QObject>

class ConcretePds : public QObject
{
    Q_OBJECT
public:
    explicit ConcretePds(QObject *);

    virtual void setName (const QString &);
    virtual QString getName () const;

    virtual quint16 getAddress() const { return m_address; }
    virtual void setAddress(const quint16 &);

signals:
    void nameChanged(QString);

protected:
    quint16 m_address;    
};

#endif // CONCRETEPDS_H
