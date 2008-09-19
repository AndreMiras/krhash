#include "DictionaryAttack.h"

DictionaryAttack::DictionaryAttack() : CommonAttack()
{
    std::cout << "DictionaryAttack::Construct" << std::endl;
    init();
}


DictionaryAttack::~DictionaryAttack()
{
    std::cout << "DictionaryAttack::Destruct" << std::endl;
}


void DictionaryAttack::init()
{
    currentString = new MetaString2();
}


