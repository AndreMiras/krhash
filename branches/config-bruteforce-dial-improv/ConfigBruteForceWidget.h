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
class QGridLayout;
class QLineEdit;
class QSpinBox;
class QCheckBox;

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
    QHBoxLayout* charsetHBoxLayout; // FIXME[cleaning]: not used anymore
    QGridLayout* charsetGridLayout;
    QGridLayout* charsetCheckBoxLayout;
    QWidget* fromToWidget;
    QWidget* charsetWidget;
    QLabel* charsetLabel;
    QLabel* lengthFromLabel;
    QLabel* lengthToLabel;
    QLineEdit* charsetLineEdit;
    QSpinBox* lengthFromSpinBox;
    QSpinBox* lengthToSpinBox;
    QCheckBox* numericsCheckBox;
    QCheckBox* alphaLowerCheckBox;
    QCheckBox* alphaUpperCheckBox;
    QCheckBox* customCheckBox;
    
    void createConfigBruteForceWidget();
    /*
     * set all widget states based on arbitrary default and QSettings
     */
    void initWidgetStates();

private slots:
    /*
     * Update the custom widget whenever a checkbox is hit 
     *
     */
    void updateCustom();
};

#endif

