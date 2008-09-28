/*
 * TODO:
 *      - use cryptdll.dll on windows
 */


#ifndef ALGOMD2_H_
#define ALGOMD2_H_

#include "AbstractAlgo.h"

#include <QByteArray>
#include <QString>

#include <QCryptographicHash>

#include <openssl/md2.h>

#include <iostream>


class HashType;

class AlgoMd2 : public AbstractAlgo
{

public:
    AlgoMd2();

    QByteArray hash(const QByteArray* data) const;

    // unsigned char * AlgoMd2::hashSpeed(const QByteArray & data) const;

    inline QByteArray hashHumanReadable(const QByteArray* data) const
    { return this->hash(data).toHex(); }
    // { return data.toHex(); }
    

    inline QByteArray formatHash(const QByteArray & hash) const
    { return QByteArray::fromHex(hash); }

    inline QByteArray unFormatHash(const QByteArray & hash) const
    { return hash.toHex(); }

    /*
     * TODO:    Use Qt provided method
     *          imrpove that tests
     */
    virtual bool isValid(const QByteArray & hash) const;


protected:
    

private:
    QByteArray hashResult;
    HashType *ht;

};

#endif /*ALGOMD2_H_*/

