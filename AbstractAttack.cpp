#include "AbstractAttack.h"


AbstractAttack::AbstractAttack(AbstractAlgo * algo) : QList<QByteArray>()
{
    this->setAlgo(algo);
    advancement = 0;
    stop = false;
}

AbstractAttack::~AbstractAttack()
{
    std::cout << "AbstractAttack::Destruct" << std::endl;
}


void AbstractAttack::addHash(const QByteArray & hash)
{
    // Then we avoid to transform hash before compare them which is faster for cracking
    std::cout << "AbstractAttack::addHash(): " << qPrintable(QString(hash)) << std::endl;
    this->append(algo->formatHash(hash));
}

void AbstractAttack::addHash(const QList<QByteArray> & hashList)
{
    for (int i=0; i < hashList.size(); ++i)
        this->addHash(hashList.at(i));
}


int AbstractAttack::indexOfHash(const QByteArray & hash) const
{
    int i = this->size() - 1;
    while ( (i >= 0) && (this->at(i) != hash) )
        --i;
    return i;
}


void AbstractAttack::addFoundHash(const QString & plainText)
{
    // FIXME[cleaning]: warning: taking address of temporary
    this->removeHash(algo->hash(&plainText.toAscii()));
//    foundHash.append(plainText);
    foundHash.insert(algo->hashHumanReadable(&plainText.toAscii()), plainText);
    emit hashFound(algo->hashHumanReadable(&plainText.toAscii()));
    emit hashFound();
}

/*
void AbstractAttack::showFound() const
{
    std::cout << "Found hash: " << foundHash.size() << std::endl;
    for (int i=0; i < foundHash.size(); ++i)
        std::cout << qPrintable(foundHash.at(i)) << " : " 
                    << qPrintable(QString(algo->hashHumanReadable(foundHash.at(i).toAscii()))) << std::endl;
}
*/

void AbstractAttack::showFound() const
{
    QHashIterator<QString, QString> i(foundHash);
    while (i.hasNext())
    {
        i.next();
        std::cout << qPrintable(i.key()) << " : " 
                    << qPrintable(i.value()) << std::endl;
    }
}

void AbstractAttack::setAlgo(AbstractAlgo * algo)
{
    this->algo = algo;
}

void AbstractAttack::stopAttack()
{
    stop = true;
}

QByteArray AbstractAttack::getPlain(const QByteArray & hash) const
{
    return foundHash.value(QString(hash)).toAscii();
}

QList<QByteArray> AbstractAttack::notFound() const
{
    QList<QByteArray> tmpHashList;
    for (int i=0; i < this->size(); i++)
        tmpHashList.append(algo->unFormatHash(this->at(i)));
    return tmpHashList;
}
