/*
 * TODO:
 *      - use cryptdll.dll on windows
 *
 * READ:
 *      - http://wiki.qtcentre.org/index.php?title=Cryptography
 */


#ifndef ALGOMD4_H_
#define ALGOMD4_H_

#include "AbstractAlgo.h"

#include <QByteArray>
#include <QString>

#include <QTime>
#include <QCryptographicHash>

// #ifdef _WIN32
// http://source.winehq.org/source/dlls/advapi32/crypt_md4.c
// http://msdn.microsoft.com/en-us/library/bb432605(VS.85).aspx
// #include <QCryptographicHash>
// #include <windows.h>
//#include <wincrypt.h>
// #else
#include <openssl/md4.h>
// #endif

#include <iostream>


class HashType;

class AlgoMd4 : public AbstractAlgo
{

public:
    AlgoMd4();

    QByteArray hash(const QByteArray* data) const;
    // inline QByteArray hash(const QByteArray & data) const
    // { return QCryptographicHash::hash(data, QCryptographicHash::Md4); }

    // unsigned char * AlgoMd4::hashSpeed(const QByteArray & data) const;

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

};

#endif /*ALGOMD4_H_*/

