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
    std::cout << "AlgoMd5 Constructor: " << std::endl;
    ht = new HashType;
    MD5_Init(&ht->md5Context);
    hashResult.resize(16); // Takes a while, change it after
    // testResult = new unsigned char[16];
}

/*
QByteArray AlgoMd5::hash(const QByteArray & data) const
{
    QByteArray ba;
    time_t t1, t2;
    time(&t1);
    for (int i=0; i < 10000000; ++i)
        ba = QCryptographicHash::hash(data, QCryptographicHash::Md5);
    time(&t2);
    //diff_time(t2,t1);
    std::cout << "t1: " << t1 << std::endl;
    std::cout << "t2: " << t2 << std::endl;
    std::cout << "t2 - t1: " << t2 - t1 << std::endl;
    exit(0);
    return QCryptographicHash::hash(data, QCryptographicHash::Md5);
}
*/

/*
 * Note:    have a look on qcryptographichash.cpp
 *          can avoid 'QCryptographicHash::addData' switch case to improve speed
*/
QByteArray AlgoMd5::hash(const QByteArray & data) const
{
    MD5_Init(&ht->md5Context);
    MD5_Update(&ht->md5Context, (const unsigned char *)data.constData(), data.length());
    MD5_Final((unsigned char *)hashResult.data(), &ht->md5Context);
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



