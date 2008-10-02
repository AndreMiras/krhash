/*
 * Class that allow to compute a String easly
 * TODO:
 *      - qSort() charset to find char++ easily
 *      - default constructor, default values...
 */

#ifndef ABSTRACTSTRING_H_
#define ABSTRACTSTRING_H_

#include <QByteArray>

class AbstractString : public QByteArray
{
public:
    /*
     * Takes a QByteArray to construct currentString and takes QByteArray for the charset
     * used to compute the next String.
     * A default charset could be used if not mentioned
     * 
     * Note: Can use QByteArray QByteArray::number ( int n, int base = 10 ) 
     *
     *
     */
    AbstractString();
    // AbstractString(const QByteArray & other);
   
    ~AbstractString();

    virtual AbstractString & operator++() = 0;
    // FIXME: gcc error on ubuntu
    // invalid abstract return type for member function ...
    // because the following virtual functions are pure within
    // AbstractString operator++(int);


    virtual double computeTotal() const = 0;

    /*
     * TODO: better to have it as const (faster) so maybe computedTotal() after construct
     *          then we can call total() which only return computedTotal attribute
     */
    double total();

protected:
    double computedTotal;

};

#endif /*ABSTRACTSTRING_H_*/

