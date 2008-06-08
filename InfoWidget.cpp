#include "InfoWidget.h"

#include <QtGui>


InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent)
{
    init();
    createInfoWidget();
}


void InfoWidget::init()
{
    numbOfHash = 0; 
    numbOfHashFound = 0;
}

void InfoWidget::createInfoWidget()
{
//    infoGroupBox = new QGroupBox(this);
    infoGroupBox = new QGroupBox(tr("Infos"), this);
//    infoGroupBox->setTitle("&Infos");
    algoLabel = new QLabel(tr("Algo:"));
    algoValueLabel = new QLabel();
    methodLabel = new QLabel(tr("Method:"));
    methodValueLabel = new QLabel();
    totalHashLabel = new QLabel(tr("Total hash:"));
    totalHashValueLabel = new QLabel("0");
    foundHashLabel = new QLabel(tr("Found hash:"));
    foundHashValueLabel = new QLabel("0");
    hashRateLabel = new QLabel(tr("Hash rate:"));
    hashRateValueLabel = new QLabel();
    hashRateValueLabel->setText("0 h/s");
    advancementLabel = new QLabel(tr("Advancement:"));
    advancementValueLabel = new QLabel();
    advancementValueLabel->setText("0%");

    vbox = new QGridLayout;
    vbox->addWidget(algoLabel, 0, 0);
    vbox->addWidget(algoValueLabel, 0, 1);
    vbox->addWidget(methodLabel, 1, 0);
    vbox->addWidget(methodValueLabel, 1, 1);
    vbox->addWidget(totalHashLabel, 2, 0);
    vbox->addWidget(totalHashValueLabel, 2, 1);
    vbox->addWidget(foundHashLabel, 3, 0);
    vbox->addWidget(foundHashValueLabel, 3, 1);
    vbox->addWidget(hashRateLabel, 4, 0);
    vbox->addWidget(hashRateValueLabel, 4, 1);
    vbox->addWidget(advancementLabel, 5, 0);
    vbox->addWidget(advancementValueLabel, 5, 1);
    infoGroupBox->setLayout(vbox);
//    infoGroupBox->setFixedSize(QSize(300, 100));

//    updateView();
    setMinimumSize(QSize(170, 250));
//    resize(minimumSizeHint());
    
}

QSize InfoWidget::sizeHint()
{
    return QSize(250, 250);
}


void InfoWidget::updateView()
{
    QSettings settings("u54", "KrHash");
    QString algoSett(settings.value("Algo", "None").toString());
    algoValueLabel->setText(algoSett);
    QString methodSett(settings.value("Method", "None").toString());
    methodValueLabel->setText(methodSett);
}

void InfoWidget::addHash()
{
    totalHashValueLabel->setNum(++numbOfHash);
}

void InfoWidget::hashFound()
{
    foundHashValueLabel->setNum(++numbOfHashFound);
}


void InfoWidget::setAdvancement(int advancement)
{
    advancementValueLabel->setText((QString("%1%").arg(advancement)));
}

void InfoWidget::setHashRate(int rate)
{
    hashRateValueLabel->setText((QString("%1 h/s").arg(rate)));
}

