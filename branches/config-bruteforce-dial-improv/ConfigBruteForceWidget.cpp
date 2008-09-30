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


    connect(numericsCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));
    connect(alphaLowerCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));
    connect(alphaUpperCheckBox, SIGNAL(clicked()), this, SLOT(updateCustom()));
    connect(customCheckBox, SIGNAL(toggled(bool)), this, SLOT(customToggled(bool)));

    
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
    initWidgetStates();
    resize(minimumSizeHint());
}

void ConfigBruteForceWidget::writeSettings()
{
    QSettings settings("u54", "KrHash");
    settings.setValue("Charset", charsetLineEdit->text());
    settings.setValue("CharsetFrom", lengthFromSpinBox->value());
    settings.setValue("CharsetTo", lengthToSpinBox->value());

    settings.setValue("numericsCheckBox", numericsCheckBox->isChecked());
    settings.setValue("alphaLowerCheckBox", alphaLowerCheckBox->isChecked());
    settings.setValue("alphaUpperCheckBox", alphaUpperCheckBox->isChecked());
    settings.setValue("customCheckBoxCheckBox", customCheckBox->isChecked());
}


void ConfigBruteForceWidget::updateCustom()
{
    charsetLineEdit->clear();

    if (numericsCheckBox->isChecked())
        charsetLineEdit->insert("0123456789");
    if (alphaLowerCheckBox->isChecked())
        charsetLineEdit->insert("abcdefghijklmnopqrstuvwxyz");
    if (alphaUpperCheckBox->isChecked())
        charsetLineEdit->insert("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

void ConfigBruteForceWidget::customToggled(bool checked)
{
    numericsCheckBox->setEnabled(not checked);
    alphaLowerCheckBox->setEnabled(not checked);
    alphaUpperCheckBox->setEnabled(not checked);
    charsetLineEdit->setEnabled(checked);
    charsetLineEdit->setFocus();
}

void ConfigBruteForceWidget::initWidgetStates()
{
    QSettings settings("u54", "KrHash");
    numericsCheckBox->setChecked(settings.value("numericsCheckBox", false).toBool());
    alphaLowerCheckBox->setChecked(settings.value("alphaLowerCheckBox", true).toBool());
    alphaUpperCheckBox->setChecked(settings.value("alphaUpperCheckBox", false).toBool());
    customCheckBox->setChecked(settings.value("customCheckBox", false).toBool());
    customToggled(customCheckBox->isChecked());
    updateCustom();
}


