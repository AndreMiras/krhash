/*
 * Class which allow to compute a String easly
 * TODO:
 *      - Implement charset setting, constructor...
 *      - qSort() charset to find char++ easily
 *      - minValue shoud be a attribut more than a method which takes time 
 *      - default constructor, default values...
 *
 *
 * WARNING: FIXME
 *      - !! Create a method "reconstruct()" called after we alterate a String
 *          using a setter.
 *          For instance if we change the password range before we change
 *          the userCharset(0) the array will be fill up with the old charset
 *          value which is wrong.
 *          So the "reconstruct()" method should recall all the methods in a right
 *          Order after we changed one of this setters
 *
 *
 */

#ifndef METASTRING_H_
#define METASTRING_H_

#include "AbstractString.h"

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>

#include <QByteArray>
#include <QString>
#include <QSettings>

using namespace std;

class MetaString : /* public QByteArray */  public AbstractString
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

    // FIXME: could find a better conception
//    MetaString(const char* str = "a");
//    MetaString(const char* str);
    MetaString();
//    MetaString(const QByteArray & other);
    
    ~MetaString();

    /*
     * Will be operator++ after
     * Should this kind of method modify the objects or return a new one?
     * Note:
     *      - Have to check if the char exist in the ascii table ?
     *      - Have to work with charset (nextChar(z) -> a)
     *
     * TODO:
     *      - improve the inline method below use attribut for length(), save currentIndexOf....
     * FIXME: first const what for?
     */
    inline const char nextChar(const int ch) const
    { return userCharset.at((1 + this->userCharset.indexOf(ch)) % userCharset.length()); }
    //const char nextChar(const int ch) const;
    
    inline void setCharset(const char * ch)
    { userCharset = ch; }

    /*
     * FIXME:   optimize this method which is too slow
     * TIME: 957ms (28790448 tested)
     *
     */
    MetaString & operator++();
    MetaString operator++(int);

//    void setup(const QString & resumeStr);

    int computeTotal() const;

    // FIXME: private 
    void setCharset(const QByteArray charset);

// TODO: better implementation?
//      using iterators
//      could be private now as I'm now using QSettings
// FIXME: that have no sence, setStart/setStop should be set at the same time only
//          use setRange instead (when have time) !
    void startAt(int charSize);
    void stopAt(int charSize);
    void setCharRange(int from, int to);

protected:

private:
    // TODO:    Should be const
    // QByteArray defaultCharset;
    // const QByteArray MetaString::defaultCharset = QByteArray("abcdefghijklmnopqrstuvwxyz");
    // static const char defaultCharset[] = "abcdefghijklmnopqrstuvwxyz";
    // int charsetLength;      // limit object access
    QByteArray userCharset;

    int minSize;
    int maxSize;

    char a_minValue;        // faster than call minValue() each time
    bool charsetShorted;    // souldn't have to use this as charset is short when construct this obj
    int lastIndex[7];        // limit call of indexOf()

    /*
     * TODO:    defaultCharset should be short and then return the first value
     *
     */
    const char minValue() const;
    char *pData;

    // should be called when using setCharset/setRange... to compute the new default state
    void updateString();
};

#endif /*METASTRING_H_*/

