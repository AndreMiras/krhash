#ifndef ABSTRACTALGO_H_
#define ABSTRACTALGO_H_

class QByteArray;


// Should Crack inherit AbstractAlgo ?
class AbstractAlgo
{

public:
    AbstractAlgo();
    ~AbstractAlgo();
    /*
     * Time:    3732ms (28790448 tested) for dynamically linked NULL function
     *          2908ms (28790448 tested) for pre-linked NULL function
     */
    virtual QByteArray hash(const QByteArray* str) const = 0;
    virtual QByteArray hashHumanReadable(const QByteArray* data) const = 0;
    virtual QByteArray formatHash(const QByteArray & hash) const = 0;
    virtual QByteArray unFormatHash(const QByteArray & hash) const = 0;
    virtual bool isValid(const QByteArray & hash) const = 0;

};

#endif /*ABSTRACTALGO_H_*/
