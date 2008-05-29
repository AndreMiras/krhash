#include "ConfigAttackDialog.h"

#include <QtGui>


ConfigAttackDialog::ConfigAttackDialog(QWidget* parent) : QDialog(parent)
{
//    configMethodWidget = NULL;
    std::cout << "ConfigAttackDialog::Construct()" << std::endl;
    configMethodWidgetList = new QList<ConfigAbstractAttackWidget*>();
    createConfigAttackDialog();
    createConnections();
    std::cout << "ConfigAttackDialog::Construct() End" << std::endl;
}


void ConfigAttackDialog::accept()
{
    std::cout << "Accept()" << std::endl;
    writeSettings();

// FIXME: good way ??
    emit accepted();
    close();
}

void ConfigAttackDialog::writeSettings()
{
    QSettings settings("u54", "KrHash");
    QString sett(algoCombobox->itemText(algoCombobox->currentIndex()));
    std::cout << "Writting Settings: " << qPrintable(sett) << std::endl;
    settings.setValue("Algo", sett);
    sett = methodCombobox->itemText(methodCombobox->currentIndex());
    std::cout << "Writting Settings: " << qPrintable(sett) << std::endl;
    settings.setValue("Method", sett);
    configMethodWidgetList->at(methodCombobox->currentIndex())->writeSettings();
}

void ConfigAttackDialog::createConfigAttackDialog()
{
    QSettings settings("u54", "KrHash");
    algoLabel = new QLabel(tr("Algo:"));
    methodLabel = new QLabel(tr("Method:"));

    algoCombobox = new QComboBox();
    algoCombobox->addItem(tr("Md5"));
    algoCombobox->addItem(tr("Double Md5"));
    algoCombobox->setCurrentIndex
                    (
                       algoCombobox->findText(settings.value("Algo", "Md5").toString())
                    );

    methodCombobox = new QComboBox();
    methodCombobox->addItem(tr("Dictionary"));
    methodCombobox->addItem(tr("Brut Force"));
    methodCombobox->addItem(tr("*Vuln* Based"));
    methodCombobox->setCurrentIndex
                    (
                       methodCombobox->findText(settings.value("Method", "Brut Force").toString())
                    );

//    methodCombobox->setEnabled(false);
//    QList<ConfigAbstractAttackWidget*>* testlist = new QList<ConfigAbstractAttackWidget*>;
//    testlist->append(new ConfigDictionaryWidget());
// FIXME
// configMethodWidgetList = new QList<ConfigAbstractAttackWidget*>;
    configMethodWidgetList->append(new ConfigDictionaryWidget());
    configMethodWidgetList->append(new ConfigBrutForceWidget());
    stackedWidget = new QStackedWidget;
    stackedWidget->addWidget(configMethodWidgetList->at(0));
    stackedWidget->addWidget(configMethodWidgetList->at(1));
    stackedWidget->setCurrentIndex(methodCombobox->currentIndex());
//    stackedWidget->addWidget(new ConfigDictionaryWidget());
//    stackedWidget->addWidget(new ConfigBrutForceWidget());

    acceptButton = new QPushButton(tr("Accept"));
    cancelButton = new QPushButton(tr("Cancel"));


    // FIXME: could be better

    top = new QWidget();
    middle = new QWidget();
    bottom = new QWidget();

    topHLayout = new QHBoxLayout;
    acceptRejectHLayout = new QHBoxLayout;
    mainVLayout = new QVBoxLayout;

    topHLayout->addWidget(algoLabel);
    topHLayout->addWidget(algoCombobox);
    topHLayout->addWidget(methodLabel);
    topHLayout->addWidget(methodCombobox);
    top->setLayout(topHLayout);
    
    acceptRejectHLayout->addWidget(acceptButton);
    acceptRejectHLayout->addWidget(cancelButton);
    bottom->setLayout(acceptRejectHLayout);

    mainVLayout->addWidget(top);
    mainVLayout->addWidget(stackedWidget);
    mainVLayout->addWidget(bottom);

    setLayout(mainVLayout);
    resize(minimumSizeHint());
}

void ConfigAttackDialog::createConnections()
{
    connect(algoCombobox, SIGNAL(currentIndexChanged(int)), this, SLOT(setAlgo(int)));
//    connect(methodCombobox, SIGNAL(currentIndexChanged(int)), this, SLOT(setMethod(int)));
    connect(methodCombobox, SIGNAL(activated(int)), stackedWidget, SLOT(setCurrentIndex(int)));
    connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}



