#include "AbstractAttack.h"


// AbstractAttack::AbstractAttack(AbstractAlgo * algo) : QList<QByteArray>()
AbstractAttack::AbstractAttack(AbstractAlgo * algo) : QSet<QByteArray>()
{
    this->setAlgo(algo);
    advancement = 0;
    stop = false;
    advancementTimer = new QTimer(this);

    // TODO: put all of that in some updateStatus
    // updateStatus update adv, rate, current string and status
    connect(advancementTimer, SIGNAL(timeout()), this, SLOT(updateAdvancement()));
    connect(advancementTimer, SIGNAL(timeout()), this, SLOT(updateHashRate()));
    connect(this, SIGNAL(started()), advancementTimer, SLOT(start()));
    connect(this, SIGNAL(finished()), advancementTimer, SLOT(stop()));
    // TODO: make this interval configurable using the interface
    advancementTimer->setInterval(5000);
}

AbstractAttack::~AbstractAttack()
{
    std::cout << "AbstractAttack::Destruct" << std::endl;
}

void AbstractAttack::addHash(const QByteArray & hash)
{
    // Then we avoid to transform hash before compare them which is faster for cracking
    std::cout << "AbstractAttack::addHash(): " << qPrintable(QString(hash)) << std::endl;
    this->insert(algo->formatHash(hash));
}

void AbstractAttack::addHash(const QList<QByteArray> & hashList)
{
    for (int i=0; i < hashList.size(); ++i)
        this->addHash(hashList.at(i));
}

void AbstractAttack::addFoundHash(const QString & plainText)
{
    QByteArray baPlainT = plainText.toAscii();
    QByteArray hash = algo->hash(&baPlainT);

    removeHash(hash);
    foundHash.insert(hash, plainText);
    emit hashFound(hash.toHex());
    emit hashFound();
}

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

QHash<QString, QString> AbstractAttack::getFound() const
{
    return foundHash;
}


QSet<QString> AbstractAttack::getNotFound() const
{

}

QHash<QString, QString> AbstractAttack::getAll() const
{

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
    QSet<QByteArray>::const_iterator hash = this->begin();
    for (hash = this->begin(); hash != this->end(); ++hash)
        tmpHashList.append(algo->unFormatHash(*hash));

    return tmpHashList;
}

int AbstractAttack::getAdvancement() const
{
    std::cout << "getAdvancement Not Implemented" << std::endl;
    return 0;
}

int AbstractAttack::getHashRate() const
{
    std::cout << "getHashRate Not Implemented" << std::endl;
    return 0;
}

void AbstractAttack::updateAdvancement() const
{
    emit advancementChanged(getAdvancement());
}

void AbstractAttack::updateHashRate() const
{
    emit hashRateChanged(getHashRate());
}
