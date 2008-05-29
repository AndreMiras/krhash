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
    void open();
    void openConfigAttackDialog();
    void startCracking();
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
    QAction *openDictionaryFileAct;
    QAction *exitAct;
    QAction *configAttackAct;
    QAction *algoMd5Act;
    QAction *algoDoubleMd5Act;
    QAction *modeBrutForceAct;
    QAction *modeDictionaryAct;

    QPushButton *startCrackingButton;
    QPushButton *addHashButton;
    QLabel *infoLabel;
    QLineEdit *addHashLineEdit;

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
