/*
 * TODO:
 *      - Class/Include cleaning, improve the compilation time using class when possible
 *      - Presentation (Qt Class reference like)
 *
 *
 */


#ifndef FENETREPRINCIPALE_H
#define FENETREPRINCIPALE_H

#include "AbstractAttack.h"
#include "AbstractAlgo.h"
#include "AlgoMd2.h"
#include "AlgoMd4.h"
#include "AlgoMd5.h"
#include "AlgoSha0.h"
#include "AlgoSha1.h"
#include "AlgoLm.h"
#include "AlgoNtlm.h"
#include "BrutForceAttack.h"
#include "DictionaryAttack.h"
#include "HashListWidget.h"
#include "InfoWidget.h"
#include "ConfigAttackDialog.h"

#include <iostream>

#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();


private slots:
    void openHashFile();
    void saveHashToFile();
    void open();
    void openConfigAttackDialog();

/*
 * TODO:
 * Change color of uncracked hash
 * Change status bar as well
 */
    void attackFinished();
//    void toggleCrackingButtonText();
    void toggleCracking();
    void appendHash();
    void selectMode(int);
    void createAttack();


private:
    AbstractAttack* attack;
    AbstractAlgo* algo;
    HashListWidget* hashListWidget;
    InfoWidget* infoWidget;
    ConfigAttackDialog* configAttackDialog;

    QMenu *fileMenu;
    QMenu *configMenu;
    QMenu *algoMenu;
    QMenu *modeMenu;
    QAction *openHashFileAct;
    QAction *saveHashToFileAct;
    // FIXME[cleaning]: not needed anymore
    // QAction *openDictionaryFileAct;
    QAction *exitAct;
    QAction *configAttackAct;
    QAction *modeDictionaryAct;

    QPushButton *toggleCrackingButton;
    QPushButton *addHashButton;
    QLabel *infoLabel;
    QLineEdit *addHashLineEdit;
    QTime* elaspedTime;

    QGroupBox* addSingleHashGroupBox;

    void init();
    void createMenus();
    void createPushButtons();
    void createAddSingleHashLayout();
    void createActions();
    void createConnections();
    void setDefaultSettings();

};

#endif
