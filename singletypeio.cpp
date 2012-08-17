#include "helper.h"
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

    setString(this, element, getAttributeNome());

    if (!setInt (this, element, getAttributeValue()))
        return false;

    if (!setBool (this, element, getAttributeInput()))
        return false;

    if (!setBool (this, element, getAttributeDigital()))
        return false;

    if (!setInt (this, element, getAttributeGroup()))
        return false;

    if (!setBool (this, element, getAttributeCanChangeName()))
        return false;

    return true;
}

QString SingleTypeIO::nome() const
{
    return readString(this, getAttributeNome());
}

int SingleTypeIO::value() const
{
    return readInt(this, getAttributeValue());
}

bool SingleTypeIO::isInput() const
{
    return readBool(this, getAttributeInput());
}

bool SingleTypeIO::isDigital() const
{
    return readBool(this, getAttributeDigital());
}

int SingleTypeIO::group() const
{
    return readInt(this, getAttributeGroup());
}

bool SingleTypeIO::canChangeName() const
{
    return readBool(this, getAttributeCanChangeName());
}
