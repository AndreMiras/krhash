/*
 * NOTE:    Let you crack a list of hash
 *          As we could use different attack Dic, Brut Force, Meet In The Middle and so one
 *          it's interesting to have an AbstractAttack Class and redefine some methods
 *
 *
 */


#ifndef ABSTRACTATTACK_H_
#define ABSTRACTATTACK_H_

#include "AbstractAlgo.h"

#include <iostream>

#include <QThread>
#include <QString>
#include <QList>
#include <QSet>
#include <QHash>
#include <QByteArray>
#include <QTimer>


class AbstractAttack : public QThread, public QSet<QByteArray>
{
    Q_OBJECT

public:

AbstractAttack(AbstractAlgo * algo = NULL);
virtual ~AbstractAttack();


// TODO:  some protected stop/resume methods
// void stop();

/*
 * Note:    virtual cause I use fromHex() which is convenient for md5 hash only
 * 
 */
void addHash(const QByteArray & hash);

/*
 * TODO:    
 *          - Take care of bool return (red color for wrong ones ?)
 */
void addHash(const QList<QByteArray> & hashList);


inline void removeHash(const QByteArray & hash)
// { this->remove(algo->formatHash(hash)); }
{ this->remove(hash); }
/*
{
    if (this->remove(algo->formatHash(hash)))
        std::cout << "[" << qPrintable(QString(hash)) << "]"
        << " removed!" << std::endl;
    else
        std::cout << "Error while trying to remove ["
        << qPrintable(QString(hash)) << "]" << std::endl;
        
}
*/

/*
 * Note:    For debugging purpose
 *
 */
void showFound() const;


QHash<QString, QString> getFound() const;
QSet<QString> getNotFound() const;
QHash<QString, QString> getAll() const;

inline bool isValid(const QByteArray & hash) const
{ return (this->algo->isValid(hash) && !this->contains(this->algo->formatHash(hash))); }


void setAlgo(AbstractAlgo * algo);

/*
 * Return the cracked plain text value of the hash if exist (bug else :p)
 * FIXME:   should it be virtual ?
 */
QByteArray getPlain(const QByteArray & hash) const;

void stopAttack();

QList<QByteArray> notFound() const;

/*
 * Return {"Cracking", "Stoped", "..." }
 *
 */
// QString currentStatus() const;


signals:
    void hashFound(QByteArray hash);
    void hashFound();
    void advancementChanged(int advancement) const;
    void hashRateChanged(int rate) const;

protected:
    // FIXME[cleaning/performance]: should use QThread and QEventLoop instead
    bool stop; // stop the loop
    int advancement;
    AbstractAlgo* algo;


    virtual void run() = 0;

    QByteArray text; // debugging speed
    char * hTest; // debugging speed

//    QList<QString> foundHash;
    /*
     *
     * Note:    (key, value) == (hash, plainText)
     *
     *          Normally the key should be reference an unique value
     *          and we know that a hash could have many colision so it's not
     *          unique for a value. Then the value should be the key cause
     *          it reference one and only one hash.
     *          But as this tool is not looking for more than one colision
     *          and we need to find the value for a hash, it's more logic to
     *          use hash as a key and plainText as value.
     *
     *
     */
    QHash<QString, QString> foundHash;

protected slots:
    /*
     *
     * Note:    As this method is not called often it could
     *          use bigs objects like QString
     *          is that the best implementation (emit signal) ?
     *
     */
    void addFoundHash(const QString & plainText);


private:
    QTimer* advancementTimer;
    virtual int getAdvancement() const;
    virtual int getHashRate() const;

private slots:
    void updateAdvancement() const;
    void updateHashRate() const;
};

#endif /*ABSTRACTATTACK_H_*/

