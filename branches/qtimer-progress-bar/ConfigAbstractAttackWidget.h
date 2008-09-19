/*
 * TODO:
 *      slot acceptConfig() -> create the attack object:w
 *      Fuck I should really do a mother class for all the config Widgets
 *
 */

#ifndef CONFIGABSTRACTATTACKWIDGET_H
#define CONFIGABSTRACTATTACKWIDGET_H
#include <QWidget>

#include "AbstractAttack.h"

#include <iostream>
//#include <QGroupBox>


class ConfigAbstractAttackWidget : public QWidget
{
    Q_OBJECT

public:
//    ConfigAbstractAttackWidget(AbstractAttack* attack, AbstractAlgo* algo, QWidget* parent = 0);
    ConfigAbstractAttackWidget(QWidget* parent = 0);
    virtual void writeSettings() = 0;

//public slots:

signals:
    void accepted();

private:

};

#endif

