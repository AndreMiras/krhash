/*
 * TODO:
 *      - setMaximum/setMinimum for the spinBox should be connected to each other
 *          to avoid From >= To
 *
 *
 *
 */

#ifndef CONFIGBRUTEFORCEWIDGET_H
#define CONFIGBRUTEFORCEWIDGET_H
#include <QWidget>

// #include "AbstractAttack.h"
#include "ConfigAbstractAttackWidget.h"

#include <iostream>
#include <QSettings>

class QGroupBox;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QLineEdit;
class QSpinBox;

class ConfigBruteForceWidget : public ConfigAbstractAttackWidget
{
    Q_OBJECT

public:
//    ConfigBruteForceWidget(AbstractAttack* attack, AbstractAlgo* algo, QWidget* parent = 0);
    ConfigBruteForceWidget(QWidget* parent = 0);

//public slots:
    void writeSettings();


private:
    QGroupBox* configGroupBox;
//    QVBoxLayout *vbox;
    QVBoxLayout* mainVLayout;
    QHBoxLayout* fromToHBoxLayout;
    QHBoxLayout* charsetHBoxLayout;
    QWidget* fromToWidget;
    QWidget* charsetWidget;
    QLabel* charsetLabel;
    QLabel* lengthFromLabel;
    QLabel* lengthToLabel;
    QLineEdit* charsetLineEdit;
    QSpinBox* lengthFromSpinBox;
    QSpinBox* lengthToSpinBox;
    
    void createConfigBruteForceWidget();
};

#endif

