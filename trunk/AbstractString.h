/*
 * Class which allow to compute a String easly
 * TODO:
 *      - Implement charset setting, constructor...
 *      - qSort() charset to find char++ easily
 *      - minValue shoud be a attribut more than a method which takes time 
 *      - default constructor, default values...
 *
 */

#ifndef ABSTRACTSTRING_H_
#define ABSTRACTSTRING_H_

#include <iostream>
#include <stdio.h>
#include <string>

#include <QByteArray>
#include <QString>

using namespace std;

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
     *
     */
    AbstractString();
    // FIXME[cleaning]: can remove below
    // AbstractString(const char * str);
    // AbstractString(const QByteArray & other);
   
    ~AbstractString();

    virtual AbstractString & operator++() = 0;
    // FIXME: gcc error on ubuntu
    // invalid abstract return type for member function ...
    // because the following virtual functions are pure within
    // AbstractString operator++(int);

//    virtual void setup(const QString & str) = 0;

    virtual double computeTotal() const = 0;

    /*
     * TODO: better to have it as const (faster) so maybe computedTotal() after construct
     *          then we can call total() which only return computedTotal attribute
     */
    double total();

//  INFO: not needed anymore
//    virtual void generatedFrom(const QByteArray) = 0;
//    virtual void startAt(int) = 0;
//    virtual void stopAt(int) = 0;

protected:
    double computedTotal;

};

#endif /*ABSTRACTSTRING_H_*/

