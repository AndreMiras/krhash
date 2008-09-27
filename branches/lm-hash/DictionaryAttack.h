/*
 * TODO:    
 *
 *
 *
 * NOTE:    Let you crack a list of hash
 *          What better ?:
 *              - set the dict (path/to/file) at the construct time (so it will be when everything
 *                  configured and then the user click "start")
 *              - set the dic with setDictionary() (so I'll need a bool the say "can start now
 *                  cause everything is ok")
 *
 *
 */


#ifndef DICTIONARYATTACK_H_
#define DICTIONARYATTACK_H_

#include "CommonAttack.h"
#include "AbstractAlgo.h"
#include "MetaString2.h"

#include <iostream>

#include <QString>
#include <QList>
#include <QByteArray>
#include <QSettings>

class DictionaryAttack : /* public AbstractAttack */ public CommonAttack
{

public:
    DictionaryAttack();
//    DictionaryAttack(AbstractAlgo * algo);
    ~DictionaryAttack();

    /*
     * TODO:    - Return value?
     *          - Add found hash in a List which is accessible by the interface
     * NOTE:    Could release signal/emit each hash broken
     *
     */
    // should be private
    // void run();
    // void stop();

    /*
     * 
     * Action:  is this hash valid? if so, then add it
     * TODO:    verify if added already
     * 
     */
    // bool addHash(const QByteArray & hash);
    /*
     *
     * Could be useful in the user interface as well (that why it's not private)
     * Note:    As a hash cannot be added twice we can do a partial scan/look
     *          Of course the hash should exist
     * 
     */
    // inline void removeHash(const QByteArray & hash)
    // { this->removeAt(this->indexOfHash(hash)); }

    /*
     * Note:    For debugging purpose
     *
     */
    // void showFound() const;

protected:

    

private:
//    AbstractAlgo *algo;
//    MetaString2 currentString;
    QList<QString> foundHash;
    
    /*
     * Could be called when trying to add a hash as well 
     * (a hash which is already existing cannot be added)
     */
    // inline bool containsHash(const QByteArray & hash) const
    // { return (this->indexOfHash(hash) != -1); }

    /*
     *
     * Result:  index of hash or -1 if not exist
     *
     */
    // int indexOfHash(const QByteArray & hash) const;


    /*
     *
     * Note:    As these methods are not called often they could
     *          used bigs objects like QString
     *
     */
    // void addFoundHash(const QString & plainText);


    /*
     * NOTE:    Could release/emit signal
     */
//    void hashFound();

    /*
     *
     * Should use a inheritence and mother class for these both (dic/brutforce)
     * as it's two different methods which are doing quiet same thing
     *
     */
//QByteArray DictionaryAttack::nextStringFromDic {}
//QByteArray DictionaryAttack::nextString() {}
    /*
     * Action:  use charset and currentString to compute next string
     *
     *
     */
    
    /*
     *  Slot?
     *
     */
    // void setCurrentString(QByteArray);

    void init();

};

#endif /*DICTIONARYATTACK_H_*/

