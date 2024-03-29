/*
 * Class which allow to compute a String easly based on a dictionary
 * TODO:
 *      - Really not so clean. Clean everything !!
 *      - rework on the conception
 *      - work on performance 
 *
 * Notes:
 *      - what better? read everything then put in a QList<QByteArray> ?
 *         -> don't think so, but for the moment it shoud be ok  let's try it...
 *
 */

#ifndef METASTRING2_H_
#define METASTRING2_H_


#include "AbstractString.h"

#include <QDebug>
#include <QByteArray>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QSettings>


class MetaString2 : public AbstractString
{
public:
    /*
     * Takes a QByteArray to construct currentString and takes QByteArray for the charset
     * used to compute the next String.
     * A default charset could be used if not mentioned
     * 
     * Note: Can use QByteArray QByteArray::number ( int n, int base = 10 ) 
     *
     */
    MetaString2();
//    MetaString2(const QString & name);

    ~MetaString2();


    /*
     * Note:
     *      - Have to check if the char exist in the ascii table ?
     *
     */

    MetaString2 & operator++();
    MetaString2 operator++(int);


    /*
     * a Qt method for that (return number of lines) I guess but didn't find it yet
     */
    double computeTotal() const;

protected:

private:
    QFile* file;
    QList<QByteArray>* dic;
    QTextStream* inStream;

    void appendAll();
    void init();
    // FIXME[cleaning]: the verif should be done before so do really need to return a bool
    bool setDictionary(const QString & name);

};

#endif /*METASTRING2_H_*/
