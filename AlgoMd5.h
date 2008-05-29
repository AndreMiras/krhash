/*
 *
 *  READ:
 *      - http://wiki.qtcentre.org/index.php?title=Cryptography
 *      - what's faster? using static method or create object ?
 */


#ifndef ALGOMD5_H_
#define ALGOMD5_H_

#include "AbstractAlgo.h"

#include <QByteArray>
#include <QString>
#include <QCryptographicHash>

#include <QTime>

#include <openssl/md5.h>
/*
#include <cryptopp/md5.h>
#include <cryptopp/filters.h>
#include <cryptopp/files.h>
#include <cryptopp/hex.h>
using namespace CryptoPP;
using namespace std;
*/

//#include "md5.h"
#include <iostream>


class HashType;

class AlgoMd5 : public AbstractAlgo
{

public:
    AlgoMd5();

    /*
     * Note:    This method has been remade 'cause loosing time in Qt method
     *          (switch case)
     * Time:    3848 (-3732) (28790448 tested) for MD5_Init() 
     *          4597 (-3732) (28790448 tested) for MD5_Update()
     *          15675 (-3732) (28790448 tested) for MD5_Final()
     *
     *
     */
    QByteArray hash(const QByteArray & data) const;
    // inline QByteArray hash(const QByteArray & data) const
    // { return QCryptographicHash::hash(data, QCryptographicHash::Md5); }

    // unsigned char * AlgoMd5::hashSpeed(const QByteArray & data) const;

    inline QByteArray hashHumanReadable(const QByteArray & data) const
    { return this->hash(data).toHex(); }
    // { return data.toHex(); }
    

    inline QByteArray formatHash(const QByteArray & hash) const
    { return QByteArray::fromHex(hash); }

    inline QByteArray unFormatHash(const QByteArray & hash) const
    { return hash.toHex(); }

    /*
     * TODO:    Use Qt provided method
     *          And finish it :]
     */
    virtual bool isValid(const QByteArray & hash) const;


protected:
    

private:
   // QCryptographicHash hashResult;
    QByteArray hashResult;
    HashType *ht;
    // unsigned char * testResult; // convert test

};

#endif /*ALGOMD5_H_*/

