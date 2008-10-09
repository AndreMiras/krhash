/*
 * Let you crack a list of hash
 *
 */


#ifndef COMMONATTACK_H_
#define COMMONATTACK_H_

#include "AbstractAttack.h"
#include "AbstractString.h"

#include <QDebug>
#include <QTime>

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
     */
    // void stop();


protected:
    AbstractString* currentString;

    void run();
    

private:
    double cpt;
    QTime* time;
    
    /*
     *
     * Result:  index of hash or -1 if not exist
     *
     */
    // int indexOfHash(const QByteArray & hash) const;


    int getAdvancement() const;
    int getHashRate() const;

};

#endif /*COMMONATTACK_H_*/
