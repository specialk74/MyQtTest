#include <QDebug>
#include <QFile>
#include "typeio.h"

QMap<int, SingleTypeIO *> TypeIO::m_mapTypeIO;

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
            m_mapTypeIO.insert(single->value(), single);
        }
        n = n.nextSibling();
    }

    return true;
}

void TypeIO::clear ()
{
    /*
    while (!m_mapTypeIO.isEmpty())
        delete m_mapTypeIO.takeFirst();
        */
    QMap<int, SingleTypeIO*>::const_iterator i = m_mapTypeIO.constBegin();
    while (i != m_mapTypeIO.constEnd()) {
        delete i.value();
        ++i;
    }
    m_mapTypeIO.clear();
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


bool TypeIO::canChangeTypeIn (const int& left, const int& right)
{
    SingleTypeIO *singleLeft = at(left);
    SingleTypeIO *singleRight = at(right);

    if ((singleLeft == NULL) || (singleRight == NULL))
        return false;

    return (singleLeft->group() == singleRight->group());
}
