/*
 * TODO:
 *      - Rework on the conception, this class shouldn't not be dependent of Attack.
 *      - Should really use a hashManager Class or something then you can Add some hash before
 *          attack has been set
 *      - expand the QListWidgetItem vertically when resizing the window
 *      - Action, for instance :
 *          - Select :
 *              - all
 *              - cracked
 *              - uncracked
 *          - Export :
 *              - selected
 *          - Remove :
 *              - selected
 *              - support supp key as well
 *
 *
 */



#ifndef HASHLISTWIDGET_H
#define HASHLISTWIDGET_H

#include <QWidget>
#include <QListWidget>

#include "AbstractAttack.h"

#include <iostream>

class QListWidgetItem;
class QFile;
class QAction;
class QShortcut;

class HashListWidget : public QListWidget
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
    void removeHash(const QByteArray & hash);
    void markHashFound(const QByteArray & hash);
    void removeSelectedHashes();
    void removeAllHashes();

signals:
    void hashAdded();
    void hashRemoved();

protected:
    void contextMenuEvent(QContextMenuEvent *event);


private:
    AbstractAttack* attack;
    QListWidgetItem* hashItem;

    QAction* removeSelectedHashesAct;
    QAction* removeAllHashesAct;
//    QAction* removeCrackedHashesAct;
//    QAction* removeUnCrackedHashesAct;
    QShortcut* removeSelectedHashesShortcut;
    
    void createActions();

    QListWidgetItem* createHashItem(const QByteArray & hash);

    // cracked green, not yet blue (, nop at all red ?)
    // Can't I just edit text as well instead of recreate a new item ..? crap!
    void markHashItem(const QByteArray & hash, bool cracked = false);

};

#endif

