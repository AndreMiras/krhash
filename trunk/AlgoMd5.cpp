#include "AlgoMd5.h"

class HashType
{
public:
    QCryptographicHash::Algorithm method;
    union {
        MD5_CTX md5Context;
    };
};


AlgoMd5::AlgoMd5() : AbstractAlgo() 
{
    ht = new HashType;
    MD5_Init(&ht->md5Context);
    // FIXME[cleaning]: probably not the good way
    hashResult.resize(16);
    finalTest = new unsigned char[16];
}


QByteArray AlgoMd5::hash(const QByteArray* data) const
{
    MD5_Init(&ht->md5Context);
    MD5_Update(&ht->md5Context, (const unsigned char *)data->constData(), data->length());
    MD5_Final((unsigned char *)hashResult.data(), &ht->md5Context);
//    MD5_Final(finalTest, &ht->md5Context);
    return hashResult;
}

// unsigned char * AlgoMd5::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoMd5::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoMd5::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 32)
        return FALSE;
    return TRUE;
}

