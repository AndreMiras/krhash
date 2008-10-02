/*
 * TODO:
 *      - QGroupBox constructor reading
 *
 *
 */

#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QSettings>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>

#include <iostream>


class InfoWidget : public QWidget
{
    Q_OBJECT

public:
    InfoWidget(QWidget *parent = 0);
    void updateView();
    QSize sizeHint();

public slots:
    void addHash();
    void removeHash(bool wasCracked);
    void hashFound();
    void setAdvancement(int advancement);
    void setHashRate(int rate);

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
    QLabel* hashRateLabel;
    QLabel* hashRateValueLabel;
    QLabel* advancementLabel;
    QLabel* advancementValueLabel;


    void createInfoWidget();
    void init();

};

#endif
