#include "AlgoLm.h"


AlgoLm::AlgoLm() : AbstractAlgo() 
{

}


QByteArray AlgoLm::hash(const QByteArray* data) const
{
    std::cout << "Lm" << std::endl;
    return "hashResult";
}

// unsigned char * AlgoLm::hashSpeed(const QByteArray & data) const { }

/*
QByteArray AlgoLm::hashHumanReadable(const QByteArray & data) const
{
    return this->hash.toHex();
}
*/

bool AlgoLm::isValid(const QByteArray & hash) const
{
    if (hash.isEmpty() || hash.length() != 32)
        return FALSE;
    return TRUE;
}

