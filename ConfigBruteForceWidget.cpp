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

    // TODO: use QSettings to remember settings
    numericsCheckBox = new QCheckBox(tr("Numerics"));
    alphaLowerCheckBox = new QCheckBox(tr("Alpha Lower"));
    alphaUpperCheckBox = new QCheckBox(tr("Alpha Upper"));
    customCheckBox = new QCheckBox(tr("Custom"));



    charsetLineEdit = new QLineEdit(); // this ?
    charsetLineEdit->setFixedWidth(200);
    // FIXME: take QSettings if set, from default charset if not
    charsetLineEdit->setText("abcdefghijklmnopqrstuvwxyz");
    charsetHBoxLayout = new QHBoxLayout();
    charsetHBoxLayout->addWidget(charsetLabel);
    charsetHBoxLayout->addWidget(charsetLineEdit);
    // charsetWidget->setLayout(charsetHBoxLayout);


    connect(numericsCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));
    connect(alphaLowerCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));
    connect(alphaUpperCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));

    // TODO: use it to set the focus too
    // connect(customCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));
    connect(customCheckBox, SIGNAL(toggled(bool)), charsetLineEdit, SLOT(setEnabled(bool)));

    
    charsetGridLayout = new QGridLayout();
    charsetGridLayout->addWidget(alphaLowerCheckBox, 0, 0);
    charsetGridLayout->addWidget(alphaUpperCheckBox, 0, 1);
    charsetGridLayout->addWidget(numericsCheckBox, 1, 0);
    charsetGridLayout->addWidget(customCheckBox, 1, 1);
    charsetGridLayout->addWidget(charsetLineEdit, 2, 0, 1, 2);

    charsetWidget->setLayout(charsetGridLayout);

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


    charsetCheckBoxLayout = new QGridLayout();

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


void ConfigBruteForceWidget::updateCustom()
{
    std::cout << "ConfigBruteForceWidget::updateCustom" << std::endl;

    charsetLineEdit->clear();

    if (numericsCheckBox->isChecked())
        charsetLineEdit->insert("0123456789");
    if (alphaLowerCheckBox->isChecked())
        charsetLineEdit->insert("abcdefghijklmnopqrstuvwxyz");
    if (alphaUpperCheckBox->isChecked())
        charsetLineEdit->insert("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void ConfigBruteForceWidget::initWidgetStates()
{
    QSettings settings("u54", "KrHash");
}


