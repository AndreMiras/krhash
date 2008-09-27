/*
 * Doc:
 *      - http://en.wikipedia.org/wiki/LM_hash
 */


#ifndef ALGOLM_H_
#define ALGOLM_H_

#include "AbstractAlgo.h"

#include <QByteArray>
#include <QString>

#include <openssl/des.h>

#include <iostream>


class AlgoLm : public AbstractAlgo
{

public:
    AlgoLm();

    QByteArray hash(const QByteArray* data) const;


    inline QByteArray hashHumanReadable(const QByteArray* data) const
    { return this->hash(data).toHex(); }
    

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

};

#endif /*ALGOLM_H_*/

