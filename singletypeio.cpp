#include "singletypeio.h"

SingleTypeIO::SingleTypeIO ()
{
}

SingleTypeIO::~SingleTypeIO()
{
}




bool SingleTypeIO::setBool (const QDomElement &element, const char *attribute)
{
    if (element.hasAttribute(attribute))
    {
        int v = element.attribute(attribute).toInt();
        if ((v < 0) || (v > 1))
            return false;

        setProperty(attribute, v);
    }

    return true;
}

bool SingleTypeIO::setInt (const QDomElement &element, const char *attribute)
{
    if (element.hasAttribute(attribute))
    {
        int v = element.attribute(attribute).toInt();
        if (v < 0)
            return false;

        setProperty(attribute, v);
    }

    return true;
}

void SingleTypeIO::setString (const QDomElement &element, const char *attribute)
{
    if (element.hasAttribute(attribute))
    {
        setProperty(getAttributeNome(), element.attribute(attribute));
    }
}





bool SingleTypeIO::load (const QDomElement &element)
{
    if (element.tagName() != getTagName())
        return false;

    setString(element, getAttributeNome());

    if (!setInt (element, getAttributeValue()))
        return false;

    if (!setBool (element, getAttributeInput()))
        return false;

    if (!setBool (element, getAttributeDigital()))
        return false;

    if (!setInt (element, getAttributeGroup()))
        return false;

    if (!setBool (element, getAttributeCanChangeName()))
        return false;

    return true;
}




bool SingleTypeIO::readBool (const char *attribute) const
{
    if (property(attribute).isValid())
    {
        return property(attribute).value<bool>();
    }

    return false;
}

QString SingleTypeIO::readString (const char *attribute) const
{
    if (property(attribute).isValid())
    {
        return property(attribute).value<QString>();
    }

    return QString("");
}

int SingleTypeIO::readInt (const char *attribute) const
{
    if (property(attribute).isValid())
    {
        return property(attribute).value<int>();
    }

    return -1;
}




QString SingleTypeIO::nome() const
{
    return readString(getAttributeNome());
}

int SingleTypeIO::value() const
{
    return readInt(getAttributeValue());
}

bool SingleTypeIO::isInput() const
{
    return readBool(getAttributeInput());
}

bool SingleTypeIO::isDigital() const
{
    return readBool(getAttributeDigital());
}

int SingleTypeIO::group() const
{
    return readInt(getAttributeGroup());
}

bool SingleTypeIO::canChangeName() const
{
    return readBool(getAttributeCanChangeName());
}
