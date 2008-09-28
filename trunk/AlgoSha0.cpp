#include "AlgoSha0.h"

class HashType
{
public:
    QCryptographicHash::Algorithm method;
    union {
        SHA_CTX shaContext;
    };
};


AlgoSha0::AlgoSha0() : AbstractAlgo() 
{
    ht = new HashType;
    SHA_Init(&ht->shaContext);
    // FIXME[cleaning]: probably not the good way
    hashResult.resize(20);
    finalTest = new unsigned char[20];
}


QByteArray AlgoSha0::hash(const QByteArray* data) const
{
    SHA_Init(&ht->shaContext);
    SHA_Update(&ht->shaContext, (const unsigned char *)data->constData(), data->length());
    SHA_Final((unsigned char *)hashResult.data(), &ht->shaContext);
    return hashResult;
}

// unsigned char * AlgoSha::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoSha::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoSha0::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 40)
        return FALSE;
    return TRUE;
}

