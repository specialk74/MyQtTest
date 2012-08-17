#ifndef SINGLETYPEPDS_H
#define SINGLETYPEPDS_H

#include <QtXml>

class SingleTypePDS : public QObject
{
public:
    explicit SingleTypePDS();
    static const char * getTagName() { return "pds"; }
    static const char * getAttributeType() { return "t"; }

    bool load (const QDomElement &element);

    int getType() const;
};

#endif // SINGLETYPEPDS_H
