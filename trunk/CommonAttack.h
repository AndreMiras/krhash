/*
 * TODO:
 *          Construct currentString by default to avoid segfault if not configured
 *
 *
 * NOTE:    Let you crack a list of hash
 *
 */


#ifndef COMMONATTACK_H_
#define COMMONATTACK_H_

#include "AbstractAttack.h"
#include "AbstractAlgo.h"
#include "AlgoMd5.h"
// #include "MetaString.h"
#include "AbstractString.h"

#include <iostream>

#include <QString>
#include <QList>
#include <QByteArray>

class CommonAttack : public AbstractAttack
{

public:
    CommonAttack();
    ~CommonAttack();


    /*
     * TODO:
     *          - Add found hashes in a List which is accessible by the interface
     *          - emit when this method is done (using QThread stuffs ?)
     *          - "/" operator takes a long time, find something else
     * Note:
     *          Could also use an iterator to know when to stop e.g. metaString->ifNext()
     *
     *
     */
    // should be protected
    void run();
    // void stop();


protected:
    AbstractString* currentString;
    

private:
    // Dynamique linkage speed diff test
    inline QByteArray hash(const QByteArray & data) const
    // inline QByteArray hash(const char * data) const
    { return NULL; return QCryptographicHash::hash(data, QCryptographicHash::Md5); }

//    AbstractAlgo *algo;
    QString charset;
//    MetaString currentString;
    
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
//QByteArray CommonAttack::nextStringFromDic {}
//QByteArray CommonAttack::nextString() {}
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

};

#endif /*COMMONATTACK_H_*/

