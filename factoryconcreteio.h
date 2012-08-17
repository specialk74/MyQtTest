#ifndef FACTORYCONCRETEIO_H
#define FACTORYCONCRETEIO_H
#include <QtXml>

class AbstractIO;

static const char * getTagName() { return "io"; }
static const char * getAttributeType() { return "t"; }

AbstractIO * FactoryConcreteIO(const QDomElement &);

#endif // FACTORYCONCRETEIO_H
