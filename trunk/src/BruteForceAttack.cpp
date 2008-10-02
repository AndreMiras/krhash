#include "BruteForceAttack.h"

//  FIXME:  shouldn't create a MetaString here
//          allow a setter instead?
BruteForceAttack::BruteForceAttack() : CommonAttack()
{
    currentString = new MetaString();
}


BruteForceAttack::~BruteForceAttack() { }
