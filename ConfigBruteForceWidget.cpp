#include "ConfigBruteForceWidget.h"

#include <QtGui>


// ConfigBruteForceWidget::ConfigBruteForceWidget(BruteForceAttack* attack, AbstractAlgo* algo, QWidget* parent) : ConfigAbstractAttackWidget(parent)
ConfigBruteForceWidget::ConfigBruteForceWidget(QWidget* parent) : ConfigAbstractAttackWidget(parent)
{
    createConfigBruteForceWidget();
}

void ConfigBruteForceWidget::createConfigBruteForceWidget()
{
    QSettings settings("u54", "KrHash");
    configGroupBox = new QGroupBox(tr("Config Brute Force Method"), this);
    charsetLabel = new QLabel(tr("Charset:"));
    lengthFromLabel = new QLabel(tr("From:"));
    lengthToLabel = new QLabel(tr("To:"));
    fromToWidget = new QWidget();
    charsetWidget = new QWidget();


    charsetLineEdit = new QLineEdit(); // this ?
    charsetLineEdit->setFixedWidth(200);
    // FIXME: take from default charset
    charsetLineEdit->setText("abcdefghijklmnopqrstuvwxyz");
    charsetHBoxLayout = new QHBoxLayout();
    charsetHBoxLayout->addWidget(charsetLabel);
    charsetHBoxLayout->addWidget(charsetLineEdit);
    charsetWidget->setLayout(charsetHBoxLayout);

    lengthFromSpinBox = new QSpinBox(); // '()' =? ''
    lengthFromSpinBox->setMinimum(1);
    lengthFromSpinBox->setMaximum(6);
    lengthFromSpinBox->setValue(settings.value("CharsetFrom", 1).toInt());
    lengthFromSpinBox->setFixedWidth(50);
    lengthToSpinBox = new QSpinBox();
    lengthToSpinBox->setMaximum(7);
    lengthToSpinBox->setValue(settings.value("CharsetTo", 6).toInt());
    lengthToSpinBox->setFixedWidth(50);


    fromToHBoxLayout = new QHBoxLayout();
    fromToHBoxLayout->addWidget(lengthFromLabel);
    fromToHBoxLayout->addWidget(lengthFromSpinBox);
    fromToHBoxLayout->addWidget(lengthToLabel);
    fromToHBoxLayout->addWidget(lengthToSpinBox);
    fromToWidget->setLayout(fromToHBoxLayout);

    // FIXME: VerticalLayout instead
    mainVLayout = new QVBoxLayout();
    mainVLayout->addWidget(charsetWidget);
    mainVLayout->addWidget(fromToWidget);
//    mainVLayout->addWidget(lengthFromLabel, 2, 0);
//    mainVLayout->addWidget(lengthFromSpinBox, 2, 1);
//    mainVLayout->addWidget(lengthToLabel, 2, 2);
//    mainVLayout->addWidget(lengthToSpinBox, 2, 3);

    configGroupBox->setLayout(mainVLayout);
    setMinimumSize(300, 200);
//    setFixedSize(300, 300);
//    configGroupBox->setFixedSize(QSize(300, 100));
    resize(minimumSizeHint());
}

void ConfigBruteForceWidget::writeSettings()
{
    QSettings settings("u54", "KrHash");
    settings.setValue("Charset", charsetLineEdit->text());
    settings.setValue("CharsetFrom", lengthFromSpinBox->value());
    settings.setValue("CharsetTo", lengthToSpinBox->value());
}


