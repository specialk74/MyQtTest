#include "singletypeio.h"

SingleTypeIO::SingleTypeIO ()
{

}

SingleTypeIO::~SingleTypeIO()
{

}

bool SingleTypeIO::load (const QDomElement &element)
{
    if (element.tagName() != getTagName())
        return false;

    if (element.hasAttribute(getAttributeNome()))
    {
        setProperty(getAttributeNome(), element.attribute(getAttributeNome()));
    }

    if (element.hasAttribute(getAttributeValue()))
    {
        int v = element.attribute(getAttributeValue()).toInt();
        if (v < 0)
            return false;
        setProperty(getAttributeValue(), v);
    }

    if (element.hasAttribute(getAttributeInput()))
    {
        int v = element.attribute(getAttributeInput()).toInt();
        if ((v < 0) || (v > 1))
            return false;
        setProperty(getAttributeInput(), v);
    }

    if (element.hasAttribute(getAttributeDigital()))
    {
        int v = element.attribute(getAttributeDigital()).toInt();
        if ((v < 0) || (v > 1))
            return false;
        setProperty(getAttributeDigital(), v);
    }

    if (element.hasAttribute(getAttributeGroup()))
    {
        int v = element.attribute(getAttributeGroup()).toInt();
        if (v < 0)
            return false;
        setProperty(getAttributeGroup(), v);
    }

    if (element.hasAttribute(getAttributeCanChangeName()))
    {
        int v = element.attribute(getAttributeCanChangeName()).toInt();
        if ((v < 0) || (v > 1))
            return false;
        setProperty(getAttributeCanChangeName(), v);
    }

    return true;
}

QString SingleTypeIO::nome() const
{
    if (property(getAttributeNome()).isValid())
    {
        return property(getAttributeNome()).value<QString>();
    }

    return QString("");
}

int SingleTypeIO::value() const
{
    if (property(getAttributeValue()).isValid())
    {
        return property(getAttributeValue()).value<int>();
    }

    return -1;
}

bool SingleTypeIO::isInput() const
{
    if (property(getAttributeInput()).isValid())
    {
        return property(getAttributeInput()).value<bool>();
    }

    return false;
}

bool SingleTypeIO::isDigital() const
{
    if (property(getAttributeDigital()).isValid())
    {
        return property(getAttributeDigital()).value<bool>();
    }

    return false;
}

int SingleTypeIO::group() const
{
    if (property(getAttributeGroup()).isValid())
    {
        return property(getAttributeGroup()).value<int>();
    }

    return -1;
}

bool SingleTypeIO::canChangeName() const
{
    if (property(getAttributeCanChangeName()).isValid())
    {
        return property(getAttributeCanChangeName()).value<bool>();
    }

    return false;
}
