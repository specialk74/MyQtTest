#include "factoryconcreteio.h"
#include "concreteanalogio.h"
#include "concretedigitalio.h"

AbstractIO * FactoryConcreteIO(const QDomElement &element)
{
    AbstractIO * abstractIO = NULL;

    if (element.tagName() != getTagName())
        return NULL;

    return abstractIO;
}
