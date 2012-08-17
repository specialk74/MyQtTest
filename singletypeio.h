#ifndef SINGLETYPEIO_H
#define SINGLETYPEIO_H

#include <QtXml>

class SingleTypeIO : public QObject
{
public:
    explicit SingleTypeIO ();
    ~SingleTypeIO();

    static const char * getTagName() { return "io"; }
    static const char * getAttributeNome() { return "n"; }
    static const char * getAttributeValue() { return "v"; }
    static const char * getAttributeInput() { return "i"; }
    static const char * getAttributeDigital() { return "d"; }
    static const char * getAttributeGroup() { return "g"; }
    static const char * getAttributeCanChangeName() { return "cn"; }

    bool load (const QDomElement &);
    QString nome() const;
    int value() const;
    bool isInput() const;
    bool isDigital() const;
    int group() const;
    bool canChangeName() const;
};

#endif // SINGLETYPEIO_H
