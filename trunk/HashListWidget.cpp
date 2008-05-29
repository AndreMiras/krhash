#include "HashListWidget.h"

#include <QtGui>


HashListWidget::HashListWidget(QWidget *parent) : QWidget(parent)
{
    std::cout << "HashListWidget::Construct" << std::endl;
    attack = NULL;
    createListWidget();
//    setEnabled(false);
}

HashListWidget::~HashListWidget()
{
    std::cout << "HashListWidget::Destruct" << std::endl;
}

void HashListWidget::setAttack(AbstractAttack* _attack)
{
    this->attack = _attack;
    setEnabled(true);
}

/*
QSize HashListWidget::sizeHint()
{
    return QSize(250, 250);
}
*/

void HashListWidget::createListWidget()
{
    hashList = new QListWidget(this);
    hashList->setMinimumSize(QSize(350, 100));
//    hashList->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    
}

QListWidgetItem* HashListWidget::createHashItem(const QByteArray & hash)
{
    hashItem = new QListWidgetItem(QString(hash));
    hashItem->setText(QString(hash));
    hashItem->setBackground(QBrush(QColor(Qt::blue)));
    return hashItem;
}

/*
void HashListWidget::markHashFound(const QByteArray & hash)
{
    int i = hashList->count() - 1;
    while ( (i >= 0) && (hashList->item(i)->text() != hash) )
        i--;
    hashList->item(i)->setBackground(QBrush(QColor(Qt::green)));
}
*/

void HashListWidget::markHashFound(const QByteArray & hash)
{
    int i = hashList->count() - 1;
    while ( (i >= 0) && (hashList->item(i)->text() != hash) )
        i--;
// Items removed from a list widget will not be managed by Qt, and will need to be deleted manually.
    hashList->takeItem(i);
    hashList->insertItem(i, tr(hash) + tr(" : ") + tr(attack->getPlain(hash)));
    hashList->item(i)->setBackground(QBrush(QColor(Qt::green)));
}

void HashListWidget::markHashItem(const QByteArray & hash, bool cracked)
{

}

void HashListWidget::addHash(const QByteArray & hash)
{
    std::cout << ">Trying to add: " << qPrintable(QString(hash));
    if (this->attack->isValid(hash))
    {
        std::cout << " [ok]" << std::endl;
        this->hashList->addItem(createHashItem(hash));
        this->attack->addHash(hash);
        emit hashAdded();
    }
    else
        std::cout << " [error]" << std::endl;
}


void HashListWidget::addHashFromFile(QFile & hashFile)
{
//     if (!hashFile.open(QFile::ReadOnly | QFile::Text))
//         return false;

    hashFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&hashFile);
    while (!in.atEnd())
        this->addHash(in.readLine().toAscii());

//    return TRUE; 
}


