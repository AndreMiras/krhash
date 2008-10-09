#include "CommonAttack.h"

CommonAttack::CommonAttack() : AbstractAttack()
{
    cpt = 0;
}

CommonAttack::~CommonAttack()
{
    qDebug() << "CommonAttack::Destruct";
}

void CommonAttack::run()
{
    cpt = currentString->total();
    time = new QTime();
    time->start();
    // perf improvement
    // FIXME[cleaning/performances]: should avoid stop test and use QThread properly instead
    qDebug() << "cpt: " << cpt;
    while (!this->empty() && cpt > 0 && !stop)
    {
        if(this->contains(algo->hash(&++*currentString)))
            this->addFoundHash(*currentString);
        cpt--;
    }
}

int CommonAttack::getAdvancement() const
{
    return (int(100.0 * ( float(currentString->total() - cpt) / float(currentString->total()) ))); 
}

// TODO: better having an average rate or a *realtime* ?
int CommonAttack::getHashRate() const
{
    int hashRate = 1000 * ( (currentString->total() - cpt) / time->elapsed());
    qDebug("Hash rate: %i h/s", hashRate);
    return hashRate; 
}
