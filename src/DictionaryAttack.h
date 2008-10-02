/*
 * TODO:    
 *
 * NOTE:    Let you crack a list of hash
 *          What better ?:
 *              - set the dict (path/to/file) at the construct time (so it will be when everything
 *                  configured and then the user click "start")
 *              - set the dic with setDictionary() (so I'll need a bool the say "can start now
 *                  cause everything is ok")
 *
 */


#ifndef DICTIONARYATTACK_H_
#define DICTIONARYATTACK_H_

#include "CommonAttack.h"
#include "MetaString2.h"

class DictionaryAttack : public CommonAttack
{

public:
    DictionaryAttack();
    ~DictionaryAttack();

};

#endif /*DICTIONARYATTACK_H_*/

