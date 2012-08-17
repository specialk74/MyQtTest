#include "helper.h"
#include "singletypepds.h"

SingleTypePDS::SingleTypePDS()
{
}

bool SingleTypePDS::load (const QDomElement &element)
{
    if (element.tagName() != getTagName())
        return false;

    if (!setInt (this, element, getAttributeType()))        
        return false;
    else
    {
        if (getType() > 8)
        {
            setProperty(getAttributeType(), QVariant());
            return false;
        }
    }

    return true;
}

int SingleTypePDS::getType() const
{
    return readInt(this, getAttributeType());
}
