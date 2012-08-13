#ifndef HELPER_H
#define HELPER_H

#include <QMap>
#include <QObject>
#include <QString>

int CheckLenName16Char (QObject &, QString const &);

enum MyProperty {
    PROPERTY_TYPE,
};

const char * getMyProperty (const MyProperty &);

#endif // HELPER_H
