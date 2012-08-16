#include <QDebug>
#include <QFile>
#include "typeio.h"

QList<SingleTypeIO *> TypeIO::m_list;

TypeIO::TypeIO()
{
}

TypeIO::~TypeIO()
{
    clear();
}

bool TypeIO::init(const QDomDocument & doc)
{
    clear();
    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            SingleTypeIO *single = new SingleTypeIO;
            single->load(e);
            m_list.append(single);
        }
        n = n.nextSibling();
    }

    return true;
}

void TypeIO::clear ()
{
    qDebug() << __FILE__ << __LINE__ << __func__;
    while (!m_list.isEmpty())
        delete m_list.takeFirst();
}

bool TypeIO::init(const QString &nomeFile)
{
    QDomDocument doc("mydocument");
    QFile file(nomeFile);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "File \"" << nomeFile << "\" error: " << file.errorString();
        return false;
    }
    QString errorMessage;
    int errorLine;
    int errorColumn;

    if (!doc.setContent(&file, &errorMessage, &errorLine, &errorColumn)) {
        file.close();
        qDebug() << "File \"" << nomeFile << " error: " << errorMessage << " in " << errorLine << ":" << errorColumn;
        return false;
    }
    file.close();

    return init(doc);
}


