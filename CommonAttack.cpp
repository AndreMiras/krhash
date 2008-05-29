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
    std::cout << "CommonAttack::run()" << std::endl;
    int cpt = currentString->total();
    while (!this->empty() && cpt > 0)
    {
        if(this->indexOfHash(algo->hash(++*currentString)) != -1)
        {
            this->addFoundHash(QString(*currentString));
        }
        // FIXME[perfance]: division takes a lot of time
        // emit takes as well but it's just called 10 times
        if ( cpt % (currentString->total() / 100) == 0 )
        {
            emit advancementChanged(++advancement);
            std::cout << "CommonAttack::run(), currentString: " 
                        << qPrintable(QString(*currentString)) << std::endl;
        }
        cpt--;
    }
    std::cout << "CommonAttack::run() Done!" << std::endl;
}


