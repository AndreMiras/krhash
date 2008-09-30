/*
 * TODO:    
 *      construct current string by default
 *
 *
 * NOTE:    Let you crack a list of hash
 *
 */


#ifndef BRUTEFORCEATTACK_H_
#define BRUTEFORCEATTACK_H_

#include "CommonAttack.h"
#include "AbstractAlgo.h"
#include "MetaString.h"

#include <iostream>

#include <QString>
#include <QList>
#include <QByteArray>
#include <QSettings>

class BruteForceAttack : /* public AbstractAttack */ public CommonAttack
{

public:
    BruteForceAttack();
//    BruteForceAttack(AbstractAlgo * algo);

    ~BruteForceAttack();

//    setCharset();

    /*
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

//    not needed anymore
//    void setCharset(const QByteArray charset);

// TODO: better implementation?
//      using iterators
// FIXME: that have no sence, setStart/setStop should be set at the same time only
//          use setRange (using QSize) instead (when have time) !
//    void setPasswordMinSize(int size);
//    void setPasswordMaxSize(int size);

protected:

    

private:
    // FIXME?: virtual = 0 in the Abstract Method
    // Needed only if I call it in the constructor of the Abstract class
    // what the best way to param like path to dic or charset or even algo?
    // should use the QSettings in each class
    // void init();

//    AbstractAlgo *algo;
    QString charset;
//    MetaString currentString;
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
     * Should use a inheritence and mother class for these both (dic/bruteforce)
     * as it's two different methods which are doing quiet same thing
     *
     */
//QByteArray BruteForceAttack::nextStringFromDic {}
//QByteArray BruteForceAttack::nextString() {}
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

#endif /*BRUTEFORCEATTACK_H_*/

