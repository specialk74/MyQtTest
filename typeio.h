#ifndef TYPEIO_H
#define TYPEIO_H

#include <QDomDocument>
#include <QMap>
#include <QString>

#include "singletypeio.h"

class TypeIO
{
public:
    TypeIO();
    ~TypeIO();

    static bool init(const QString &);
    static bool init(const QDomDocument &);
    static void clear ();
    static SingleTypeIO *at (int idx) { return m_mapTypeIO[idx]; }
    static int size() { return m_mapTypeIO.size(); }
    static bool canChangeTypeIn (const int& left, const int& right);

private:
    static QMap<int, SingleTypeIO *> m_mapTypeIO;
};

#endif // TYPEIO_H
