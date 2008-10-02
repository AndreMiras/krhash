#include "AlgoNtlm.h"

class HashType
{
public:
    QCryptographicHash::Algorithm method;
    union {
        MD4_CTX md4Context;
    };
};


AlgoNtlm::AlgoNtlm() : AbstractAlgo() 
{
    ht = new HashType;
    MD4_Init(&ht->md4Context);
    // FIXME[cleaning]: probably not the good way
    // hashResult.resize(16);
}

QByteArray AlgoNtlm::hash(const QByteArray* data) const
{
    int   len = data->size();
    // unsigned char  nt_pw[2*len];
    char  nt_pw[2*len];
    // memset(nt_pw, 0, sizeof(nt_pw));
    bzero(nt_pw, sizeof(nt_pw));
    for (int idx=0; idx < len; idx++)
    {
        nt_pw[2*idx]   = data->at(idx);
        // nt_pw[2*idx+1] = 0;
    }

    unsigned char nt_hpw[21];
    MD4_Init(&ht->md4Context);
    // MD4_Update(&ht->md4Context, (const unsigned char *)data->constData(), data->length());
    MD4_Update(&ht->md4Context, nt_pw, 2*len);
    // MD4_Final((unsigned char *)hashResult.data(), &ht->md4Context);
    MD4_Final(nt_hpw, &ht->md4Context);
    memset(&nt_hpw[16], 0, 5);

    QByteArray ba((char *)nt_hpw);
    // return hashResult;
    return ba;
}

// unsigned char * AlgoNtlm::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoNtlm::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoNtlm::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 32)
        return FALSE;
    return TRUE;
}

