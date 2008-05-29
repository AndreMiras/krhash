/*
 * TODO:
 *      - QGroupBox constructor reading
 *
 *
 */

#ifndef INFOWIDGET_H
#define INFOWIDGET_H
#include <QWidget>
#include <QFile>

#include "AbstractAttack.h"

#include <iostream>
//#include <QGroupBox>

class QGroupBox;
class QLabel;
class QVBoxLayout;
class QGridLayout;

class InfoWidget : public QWidget
{
    Q_OBJECT

public:
    InfoWidget(QWidget *parent = 0);
    void updateView();
    QSize sizeHint();

public slots:
    void addHash();
    void hashFound();
    void setAdvancement(int advancement);

private:
    int numbOfHash;
    int numbOfHashFound;

    QGroupBox* infoGroupBox;
//    QVBoxLayout *vbox;
    QGridLayout *vbox;
    QLabel* algoLabel;
    QLabel* algoValueLabel;
    QLabel* methodLabel;
    QLabel* methodValueLabel;
    QLabel* totalHashLabel;
    QLabel* totalHashValueLabel;
    QLabel* foundHashLabel;
    QLabel* foundHashValueLabel;
    QLabel* advancementLabel;
    QLabel* advancementValueLabel;


    void createInfoWidget();
    void init();

};

#endif

