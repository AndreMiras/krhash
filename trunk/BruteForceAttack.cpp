#include "BrutForceAttack.h"

//  FIXME:  shouldn't create a MetaString here
//          allow a setter instead?
BrutForceAttack::BrutForceAttack() : CommonAttack()
{
    std::cout << "BrutForceAttack::Construct" << std::endl;
    std::cout << "BrutForceAttack::Construct[Done]" << std::endl;

    currentString = new MetaString();
}


BrutForceAttack::~BrutForceAttack()
{
    std::cout << "BrutForceAttack::Destruct" << std::endl;
}


void BrutForceAttack::init()
{
    QSettings settings("u54", "KrHash");
    // FIXME: use a defaultCharset() to set the default value
    QString tmpCharset(settings.value("Charset", "abcdefghijklmnopqrstuvwxyz").toString());
    QString tmpFrom(settings.value("From", "0").toInt());
    QString tmpTo(settings.value("To", "6").toInt());
    currentString = new MetaString();
}


