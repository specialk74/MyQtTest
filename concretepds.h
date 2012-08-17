#ifndef CONCRETEPDS_H
#define CONCRETEPDS_H

#include <QObject>

class ConcretePds : public QObject
{
    Q_OBJECT
public:
    explicit ConcretePds(QObject *);

    virtual void name (const QString &);
    virtual QString name () const;

signals:
    void nameChanged(QString);

};

#endif // CONCRETEPDS_H
