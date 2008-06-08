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
#include <QString>

#include <QTime>
#include <QCryptographicHash>

//#ifdef _WIN32
// http://source.winehq.org/source/dlls/advapi32/crypt_md5.c
// http://msdn.microsoft.com/en-us/library/bb432605(VS.85).aspx
// #include <QCryptographicHash>
// #include <windows.h>
//#include <wincrypt.h>
//#else
#include <openssl/md5.h>
//#endif

#include <iostream>


class HashType;

class AlgoMd5 : public AbstractAlgo
{

public:
    AlgoMd5();

    QByteArray hash(const QByteArray* data) const;
    // inline QByteArray hash(const QByteArray & data) const
    // { return QCryptographicHash::hash(data, QCryptographicHash::Md5); }

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
   // QCryptographicHash hashResult;
    QByteArray hashResult;
    HashType *ht;
    // unsigned char * testResult; // convert test

};

#endif /*ALGOMD5_H_*/

