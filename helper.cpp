#include "helper.h"

int CheckLenName16Char (QObject const & obj, QString const & str)
{
    if (str.length() > 16)
      return 0;

    if (obj.objectName() == str)
      return 0;

    return 1;
}
