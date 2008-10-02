#include "AlgoSha1.h"

class HashType
{
public:
    QCryptographicHash::Algorithm method;
    union {
        SHA_CTX sha1Context;
    };
};


AlgoSha1::AlgoSha1() : AbstractAlgo() 
{
    ht = new HashType;
    SHA_Init(&ht->sha1Context);
    // FIXME[cleaning]: probably not the good way
    hashResult.resize(20);
    finalTest = new unsigned char[20];
}


QByteArray AlgoSha1::hash(const QByteArray* data) const
{
    SHA1_Init(&ht->sha1Context);
    SHA1_Update(&ht->sha1Context, (const unsigned char *)data->constData(), data->length());
    SHA1_Final((unsigned char *)hashResult.data(), &ht->sha1Context);
    return hashResult;
}

// unsigned char * AlgoSha::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoSha::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoSha1::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 40)
        return FALSE;
    return TRUE;
}

