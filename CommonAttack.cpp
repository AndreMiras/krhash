#include "CommonAttack.h"

CommonAttack::CommonAttack() : AbstractAttack()
{
}

CommonAttack::~CommonAttack()
{
    std::cout << "CommonAttack::Destruct" << std::endl;
}


void CommonAttack::run()
{
    int cpt = currentString->total();
    QTime timer;
    timer.start();
    int hashRate;
    // perf improvement
    int currentStringTotal = currentString->total();
    int currentStringTotalDiv100 = currentStringTotal / 100;
    // FIXME[cleaning/performances]: should avoid stop test and use QThread properly instead
    while (!this->empty() && cpt > 0 && !stop)
    {
        if(this->contains(algo->hash(&++*currentString)))
            this->addFoundHash(QString(*currentString));

        // FIXME[perfance]: division takes a lot of time
        // emit takes as well but it's just called 10 times
        if ( cpt % (currentStringTotalDiv100) == 0 )
        {
            emit advancementChanged(++advancement);
            std::cout << "CommonAttack::run(), currentString: " 
                        << qPrintable(QString(*currentString)) << std::endl;
            if (timer.elapsed() != 0)
            {
                hashRate = 1000 * (currentStringTotalDiv100 / timer.elapsed());
                qDebug("Hash rate: %i h/s", hashRate);
                emit hashRateChanged(hashRate);
                timer.restart();
            }
        }
        cpt--;
    }
}

