#include "BruteForceAttack.h"

//  FIXME:  shouldn't create a MetaString here
//          allow a setter instead?
BruteForceAttack::BruteForceAttack() : CommonAttack()
{
    std::cout << "BruteForceAttack::Construct" << std::endl;
    std::cout << "BruteForceAttack::Construct[Done]" << std::endl;

    currentString = new MetaString();
}


BruteForceAttack::~BruteForceAttack()
{
    std::cout << "BruteForceAttack::Destruct" << std::endl;
}



