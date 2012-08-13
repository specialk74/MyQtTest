#include <QtTest/QtTest>
#include <QDebug>
#include <QSignalSpy>
#include "QtTestUtil/QtTestUtil.h"

#include "helper.h"

static QString nomeSetGood = "1234567890123456";
static QString nomeSetBad  = "12345678901234567";

class TestHelper: public QObject
{
    Q_OBJECT
public:

private slots:
    void init()
    {
        obj = new QObject;
    }
    void cleanup()
    {
        delete obj;
    }

    void create()
    {
    }

    void SetName()
    {
        int result = CheckLenName16Char(*obj, nomeSetGood);
        QCOMPARE(1, result);
        QVERIFY(obj->objectName() == nomeSetGood); // verify the first argument
    }

    void SetNameTooLong()
    {
        int result = CheckLenName16Char(*obj, nomeSetBad);
        QCOMPARE(0, result);
    }

    void SetNameNotChange()
    {
        CheckLenName16Char(*obj, nomeSetGood);
        CheckLenName16Char(*obj, nomeSetBad);

        QCOMPARE(nomeSetGood, obj->objectName());
    }

    void SetNameTwice()
    {
        CheckLenName16Char(*obj, nomeSetGood);
        int result = CheckLenName16Char(*obj, nomeSetGood);
        QCOMPARE(0, result);
    }

private:
    QObject *obj;
};

QTTESTUTIL_REGISTER_TEST(TestHelper);
#include "TestHelper.moc"

