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
