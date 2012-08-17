#include "helper.h"

static const std::pair<MyProperty, const char *> arr[] = {
    std::pair<MyProperty, const char *>(PROPERTY_TYPE,"Type")
};

static std::map<MyProperty, const char *> my_map(arr, arr + sizeof(arr) / sizeof(arr[0]));

QMap<MyProperty, const char *> m_mapProperty(my_map);

int CheckLenName16Char (QObject & obj, QString const & str)
{
    if (str.length() > 16)
      return 0;

    if (obj.objectName() == str)
      return 0;

    obj.setObjectName(str);
    return 1;
}

const char * getMyProperty (const MyProperty &i)
{
    return m_mapProperty[i];
}

EnumAddress CheckAddress (const quint16 & address)
{
    if (address == 0)
        return INVALID_ADDRESS;

    if (address == 0xFFF)
        return BROADCAST_ADDRESS;

    if ((address & 0xFF) == 0)
        return BROADCAST_ADDRESS;

    if ((address & 0xFF) == 0xFF)
        return BROADCAST_ADDRESS;

    if ((address & 0xF00) == 0)
        return BROADCAST_ADDRESS;

    return REGULAR_ADDRESS;
}

bool readBool (const QObject *obj, const char *attribute)
{
    if (obj && obj->property(attribute).isValid())
    {
        return obj->property(attribute).value<bool>();
    }

    return false;
}

QString readString (const QObject *obj, const char *attribute)
{
    if (obj && obj->property(attribute).isValid())
    {
        return obj->property(attribute).value<QString>();
    }

    return QString("");
}

int readInt (const QObject *obj,const char *attribute)
{
    if (obj && obj->property(attribute).isValid())
    {
        return obj->property(attribute).value<int>();
    }

    return -1;
}

bool setBool (QObject *obj, const QDomElement &element, const char *attribute)
{
    if (element.hasAttribute(attribute))
    {
        int v = element.attribute(attribute).toInt();
        if ((v < 0) || (v > 1))
            return false;

        obj->setProperty(attribute, v);
    }

    return true;
}

bool setInt (QObject *obj, const QDomElement &element, const char *attribute)
{
    if (element.hasAttribute(attribute))
    {
        int v = element.attribute(attribute).toInt();
        if (v < 0)
            return false;

        obj->setProperty(attribute, v);
    }

    return true;
}

void setString (QObject *obj, const QDomElement &element, const char *attribute)
{
    if (element.hasAttribute(attribute))
    {
        obj->setProperty(attribute, element.attribute(attribute));
    }
}
