/*
 * TODO:
 *      - algo should determine method which should determine configAttackWidget
 *      - rejected call algo/method destructor ?
 *      - everything should be created once "accept" has been clicked,
 *          not before
 *
 *
 */

#ifndef CONFIGATTACKDIALOG_H
#define CONFIGATTACKDIALOG_H

#include <QDebug>
#include <QDialog>

#include "ConfigBruteForceWidget.h"
#include "ConfigAbstractAttackWidget.h"
#include "ConfigDictionaryWidget.h"

//#include <QGroupBox>

// class QGroupBox;
class QLabel;
class QHBoxLayout;
class QVBoxLayout;
class QGridLayout;
class QComboBox;
class QPushButton;
class QStackedWidget;

class ConfigAttackDialog : public QDialog
{
    Q_OBJECT

public:
    ConfigAttackDialog(QWidget* parent = 0);

public slots:
    void accept(); // For tests

private:
    QList<ConfigAbstractAttackWidget*>* configMethodWidgetList;

    QStackedWidget *stackedWidget;
    QWidget* top;
    QWidget* middle;
    QWidget* bottom;
    QHBoxLayout* topHLayout;
    QHBoxLayout* acceptRejectHLayout;
    QVBoxLayout* mainVLayout;
//    QGridLayout* gbox;
    QLabel* algoLabel;
    QLabel* methodLabel;
    QComboBox* algoCombobox;
    QComboBox* methodCombobox;
    QPushButton* acceptButton;
    QPushButton* cancelButton;

    void createConfigAttackDialog();
    void createConnections();

    // FIXME: verify NULL pointers
    void writeSettings();
};

#endif
