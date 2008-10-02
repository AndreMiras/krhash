#include "AlgoMd2.h"

class HashType
{
public:
    QCryptographicHash::Algorithm method;
    union {
        MD2_CTX md2Context;
    };
};


AlgoMd2::AlgoMd2() : AbstractAlgo() 
{
    ht = new HashType;
    MD2_Init(&ht->md2Context);
    // FIXME[cleaning]: probably not the good way
    hashResult.resize(16);
}

QByteArray AlgoMd2::hash(const QByteArray* data) const
{
    MD2_Init(&ht->md2Context);
    MD2_Update(&ht->md2Context, (const unsigned char *)data->constData(), data->length());
    MD2_Final((unsigned char *)hashResult.data(), &ht->md2Context);
    return hashResult;
}

// unsigned char * AlgoMd2::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoMd2::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoMd2::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 32)
        return FALSE;
    return TRUE;
}

