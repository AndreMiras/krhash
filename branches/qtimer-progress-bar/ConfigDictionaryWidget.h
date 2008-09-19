/*
 * TODO:
 *      parent class for all the 'config Widgets'
 *
 *
 */

#ifndef CONFIGDICTIONARYWIDGET_H
#define CONFIGDICTIONARYWIDGET_H
#include <QWidget>

#include "ConfigAbstractAttackWidget.h"

#include <iostream>
//#include <QGroupBox>
class QGroupBox;
class QLabel;
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLineEdit;
class ConfigDictionaryWidget : public ConfigAbstractAttackWidget
{
    Q_OBJECT

public:
    ConfigDictionaryWidget(QWidget* parent = 0);

    void writeSettings();


private:
    QGroupBox* configGroupBox;
    QVBoxLayout* mainVLayout;
    QHBoxLayout* fromToHBoxLayout;
    QHBoxLayout* charsetHBoxLayout;

    QLineEdit* pathToFileLineEdit;
    QPushButton* browseButton;
    QLabel* locationLabel;

    void createConfigDictionaryWidget();

signals:
    void pathSelected(QString pathToFile);

private slots:
    void openDictionaryFile();
};

#endif

