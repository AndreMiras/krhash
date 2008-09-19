#include "CommonAttack.h"

CommonAttack::CommonAttack() : AbstractAttack()
{
    cpt = 0;
}

CommonAttack::~CommonAttack()
{
    std::cout << "CommonAttack::Destruct" << std::endl;
}

void CommonAttack::run()
{
    // double cpt = currentString->total();
    cpt = currentString->total();
    time = new QTime();
    time->start();
    int hashRate;
    // perf improvement
    // FIXME[cleaning/performances]: should avoid stop test and use QThread properly instead
    std::cout << "cpt: " << cpt << std::endl;
    while (!this->empty() && cpt > 0 && !stop)
    {
        if(this->contains(algo->hash(&++*currentString)))
            this->addFoundHash(QString(*currentString));
        cpt--;
    }
}

int CommonAttack::getAdvancement() const
{
    int adv = 100 * ( float(currentString->total() - cpt) / float(currentString->total()) );
    return adv; 
}

int CommonAttack::getHashRate() const
{
    int hashRate = 1000 * ( (currentString->total() - cpt) / time->elapsed());
    qDebug("Hash rate: %i h/s", hashRate);
    return hashRate; 
}

