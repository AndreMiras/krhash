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


void BruteForceAttack::init()
{
    QSettings settings("u54", "KrHash");
    // FIXME: use a defaultCharset() to set the default value
    QString tmpCharset(settings.value("Charset", "abcdefghijklmnopqrstuvwxyz").toString());
    QString tmpFrom(settings.value("From", "0").toInt());
    QString tmpTo(settings.value("To", "6").toInt());
    currentString = new MetaString();
}


