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
     *          a LM hash is 16 bytes
     *          I also want it all lower case
     */
    virtual bool isValid(const QByteArray & hash) const;


protected:
    

private:

    /*
     * turns a 56 bit key into the 64 bit, odd parity key and sets the key.
     * The key schedule ks is also set.
     */
    void setup_des_key(unsigned char* key_56, des_key_schedule & ks) const;

};

#endif /*ALGOLM_H_*/

