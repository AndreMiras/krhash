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


class ConfigAbstractAttackWidget : public QWidget
{
    Q_OBJECT

public:
    ConfigAbstractAttackWidget(QWidget* parent = 0);
    virtual void writeSettings() = 0;

};

#endif
