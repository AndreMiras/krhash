#include "AlgoMd4.h"

class HashType
{
public:
    QCryptographicHash::Algorithm method;
    union {
        MD4_CTX md4Context;
    };
};


AlgoMd4::AlgoMd4() : AbstractAlgo() 
{
    ht = new HashType;
    MD4_Init(&ht->md4Context);
    hashResult.resize(16); // Takes a while, change it after
    // testResult = new unsigned char[16];
}

/*
QByteArray AlgoMd4::hash(const QByteArray & data) const
{
    QByteArray ba;
    time_t t1, t2;
    time(&t1);
    for (int i=0; i < 10000000; ++i)
        ba = QCryptographicHash::hash(data, QCryptographicHash::Md4);
    time(&t2);
    //diff_time(t2,t1);
    std::cout << "t1: " << t1 << std::endl;
    std::cout << "t2: " << t2 << std::endl;
    std::cout << "t2 - t1: " << t2 - t1 << std::endl;
    exit(0);
    return QCryptographicHash::hash(data, QCryptographicHash::Md4);
}
*/

QByteArray AlgoMd4::hash(const QByteArray & data) const
{
    MD4_Init(&ht->md4Context);
    MD4_Update(&ht->md4Context, (const unsigned char *)data.constData(), data.length());
    MD4_Final((unsigned char *)hashResult.data(), &ht->md4Context);
    return hashResult;
}

// unsigned char * AlgoMd4::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoMd4::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoMd4::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 32)
        return FALSE;
    return TRUE;
}


