/*
 * TODO:
 *      - use cryptdll.dll on windows
 *
 * READ:
 *      - http://wiki.qtcentre.org/index.php?title=Cryptography
 */


#ifndef ALGOSHA0_H_
#define ALGOSHA0_H_

#include "AbstractAlgo.h"

#include <QByteArray>
#include <QCryptographicHash>

#include <openssl/sha.h>

#include <iostream>


class HashType;

class AlgoSha0 : public AbstractAlgo
{

public:
    AlgoSha0();

    QByteArray hash(const QByteArray* data) const;
    // inline QByteArray hash(const QByteArray & data) const
    // { return QCryptographicHash::hash(data, QCryptographicHash::Sha); }

    // unsigned char * AlgoSha::hashSpeed(const QByteArray & data) const;

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
   // QCryptographicHash hashResult;
    QByteArray hashResult;
    //unsigned char finalTest[16];
    unsigned char* finalTest;
    HashType *ht;
    // unsigned char * testResult; // convert test

};

#endif /*ALGOSHA0_H_*/

