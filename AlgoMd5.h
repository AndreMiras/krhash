/*
 * TODO:
 *      - use cryptdll.dll on windows
 *
 * READ:
 *      - http://wiki.qtcentre.org/index.php?title=Cryptography
 */


#ifndef ALGOMD5_H_
#define ALGOMD5_H_

#include "AbstractAlgo.h"

#include <QByteArray>
#include <QCryptographicHash>

#include <openssl/md5.h>

#include <iostream>


class HashType;

class AlgoMd5 : public AbstractAlgo
{

public:
    AlgoMd5();

    QByteArray hash(const QByteArray* data) const;
    // inline QByteArray hash(const QByteArray & data) const

    // unsigned char * AlgoMd5::hashSpeed(const QByteArray & data) const;

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
    //unsigned char finalTest[16];
    unsigned char* finalTest;
    HashType *ht;
    // unsigned char * testResult; // convert test

};

#endif /*ALGOMD5_H_*/

