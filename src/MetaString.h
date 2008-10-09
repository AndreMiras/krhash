/*
 * Class which allow to compute a String easly
 * TODO:
 *      - qSort() charset to find char++ easily
 */

#ifndef METASTRING_H_
#define METASTRING_H_

#include "AbstractString.h"

#include <math.h>

#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QSettings>

using namespace std;

class MetaString : public AbstractString
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
     *      use ptr++ instead of *ptr[++i]
     *
     */
    MetaString & operator++();
    MetaString operator++(int);

//    void setup(const QString & resumeStr);

    double computeTotal() const;


protected:

private:
    // TODO:    Should be const
    // QByteArray defaultCharset;
    // const QByteArray MetaString::defaultCharset = QByteArray("abcdefghijklmnopqrstuvwxyz");
    // static const char defaultCharset[] = "abcdefghijklmnopqrstuvwxyz";
    // int charsetLength;      // limit object access
    QByteArray userCharset;

    char a_minValue;        // faster than call minValue() each time
    bool charsetShorted;    // souldn't have to use this as charset is short when construct this obj

    /*
     * stores all indexes of letter for the current word to limit call of indexOf()
     * for exemple:
     * charset="abcdefghijklmnopqrstuvwxyz"
     * currentWord="blabla"
     * *lastindex = "1,6,0,1,6,0"
     */
    // FIXME[cleaning]: hardcoded value, size of lastIndex should be MaxSizeToCrackValue
    int lastIndex[7];

    /*
     * TODO:    userCharset should be sorted by ascii code
     */
    const char minValue() const;
    char *pData;

    // should be called when using setCharset/setRange... to compute the new default state
    void updateString();
    void setCharset(const QByteArray charset);

    int getMinSize() const;
    int getMaxSize() const;

};

#endif /*METASTRING_H_*/

