#include "ConfigDictionaryWidget.h"

#include <QtGui>


ConfigDictionaryWidget::ConfigDictionaryWidget(QWidget* parent) : ConfigAbstractAttackWidget(parent)
{
    createConfigDictionaryWidget();

    connect(browseButton, SIGNAL(clicked()), this, SLOT(openDictionaryFile())); 
    connect(this, SIGNAL(pathSelected(QString)), pathToFileLineEdit, SLOT(setText(QString))); 
    browseButton = new QPushButton(tr("Browse"));
}

void ConfigDictionaryWidget::createConfigDictionaryWidget()
{
    QSettings settings("u54", "KrHash");
    configGroupBox = new QGroupBox(tr("Config Dictionary Method"), this);
    browseButton = new QPushButton(tr("Browse"));
    locationLabel = new QLabel(tr("Location:"));

    QString pathToFileString(settings.value("DictPath", "Select a path").toString());
    pathToFileLineEdit = new QLineEdit(pathToFileString);
    charsetHBoxLayout = new QHBoxLayout();
    charsetHBoxLayout->addWidget(locationLabel);
    charsetHBoxLayout->addWidget(pathToFileLineEdit);
    charsetHBoxLayout->addWidget(browseButton);

    configGroupBox->setLayout(charsetHBoxLayout);
    // should be set by inheritance, because ConfigBrutForceW use the same value
    setMinimumSize(300, 200);
//    setFixedSize(300, 300);
//    configGroupBox->setFixedSize(QSize(300, 100));
    resize(minimumSizeHint());
}

void ConfigDictionaryWidget::openDictionaryFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), QDir::currentPath(), tr("Text Files (*.txt)"));
    if (!fileName.isEmpty())
       emit pathSelected(fileName);
}

// WARNING: see the MetaString.h Warning about setters methods calling order
void ConfigDictionaryWidget::writeSettings()
{
    QSettings settings("u54", "KrHash");
    settings.setValue("DictPath", pathToFileLineEdit->text());
}


