/*
 * TODO:
 *      - Rework on the conception, this class shouldn't not be dependent of Attack.
 *      - Should really use a hashManager Class or something then you can Add some hash before
 *          attack has been set
 *      - expand the QListWidgetItem vertically when resizing the window
 *
 * FIXME: should inherit HashList
 *
 *
 */



#ifndef HASHLISTWIDGET_H
#define HASHLISTWIDGET_H

#include <QWidget>

#include "AbstractAttack.h"

#include <iostream>

class QListWidgetItem;
class QFile;
class QListWidget;

class HashListWidget : public QWidget
{
    Q_OBJECT

public:
    HashListWidget(QWidget *parent = 0);
    ~HashListWidget();

    void setAttack(AbstractAttack* attack);
    void addHashFromFile(QFile & hashFile);
//    QSize sizeHint();

public slots:
    void addHash(const QByteArray & hash);
    void markHashFound(const QByteArray & hash);

signals:
    void hashAdded();
    void hashRemoved();


private:
    AbstractAttack* attack;
    QListWidget* hashList;
    QListWidgetItem* hashItem;
    
    void createListWidget();

    QListWidgetItem* createHashItem(const QByteArray & hash);

    // cracked green, not yet blue (, nop at all red ?)
    // Can't I just edit text as well instead of recreate a new item ..? crap!
    void markHashItem(const QByteArray & hash, bool cracked = false);

};

#endif

