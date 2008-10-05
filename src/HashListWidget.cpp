#include "HashListWidget.h"

#include <QtGui>


// HashListWidget::HashListWidget(QWidget *parent) : QWidget(parent)
HashListWidget::HashListWidget(QWidget *parent) : QListWidget(parent)
{
    attack = NULL;
    // this->setSelectionMode(QAbstractItemView::MultiSelection);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setMinimumSize(QSize(350, 100));
    createActions();
//    setEnabled(false);
}

HashListWidget::~HashListWidget() { }

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

void HashListWidget::createActions()
{
    removeSelectedHashesAct = new QAction(tr("Remove selected hashes"), this);
    removeSelectedHashesShortcut = new QShortcut(QKeySequence(QKeySequence(Qt::Key_Delete)), this);
    removeAllHashesAct = new QAction(tr("Remove all hashes"), this);
    connect(removeSelectedHashesAct, SIGNAL(triggered()), this, SLOT(removeSelectedHashes()));
    connect(removeSelectedHashesShortcut, SIGNAL(activated()), this, SLOT(removeSelectedHashes()));
    connect(removeAllHashesAct, SIGNAL(triggered()), this, SLOT(removeAllHashes()));
}

QListWidgetItem* HashListWidget::createHashItem(const QByteArray & hashHex)
{
    QByteArray hash = QByteArray::fromHex(hashHex);

    hashItem = new QListWidgetItem(hashHex);
    hashItem->setText(hashHex);
    hashItem->setWhatsThis(hashHex.toLower());
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

void HashListWidget::markHashFound(const QByteArray & hashHex, const QByteArray plainText)
{
    int i = this->count() - 1;
    QByteArray hash = QByteArray::fromHex(hashHex);
    // std::cout << "Found (Hex): " << qPrintable(QString(hashHex)) << std::endl;
    // std::cout << "Found (Plain Text): " << qPrintable(QString(attack->getPlain(hash))) << std::endl;

    while ( (i >= 0) && (this->item(i)->whatsThis() != hashHex) )
        i--;
    this->item(i)->setText(hashHex + " : " + plainText);
    this->item(i)->setBackground(QBrush(QColor(Qt::green)));
}

void HashListWidget::markHashItem(const QByteArray & hash, bool cracked)
{

}

void HashListWidget::addHash(const QByteArray & hashHex)
{
    std::cout << ">Trying to add: " << qPrintable(QString(hashHex));
    if (this->attack->isValid(hashHex))
    {
        std::cout << " [ok]" << std::endl;
        this->addItem(createHashItem(hashHex));
        attack->addHash(hashHex);
        emit hashAdded();
    }
    else
        std::cout << " [error]" << std::endl;
}

void HashListWidget::removeHash(const QByteArray & hashHex)
{
    int i = this->count() - 1;
    QByteArray hash = QByteArray::fromHex(hashHex);
    while ( (i >= 0) && (this->item(i)->whatsThis() != hashHex) )
        i--;
    bool wasCracked = (item(i)->whatsThis().toAscii() != item(i)->text());
// FIXME[cleaning]: 'Items removed from a list widget will not be managed by Qt, and will need to be deleted manually'
    this->takeItem(i);
    attack->removeHash(hash);
    emit hashRemoved(wasCracked);
    std::cout << "Trying to remove ["
    << qPrintable(QString(hashHex))
    << "]" << std::endl;
}

void HashListWidget::addHashFromFile(QFile & hashFile)
{
    hashFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream in(&hashFile);
    while (!in.atEnd())
        this->addHash(in.readLine().toAscii());
}


void HashListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(removeSelectedHashesAct);
    menu.addAction(removeAllHashesAct);
    menu.exec(event->globalPos());
}


void HashListWidget::removeSelectedHashes()
{
    std::cout << "Removing Selected Hashes" << std::endl;
    QList<QListWidgetItem*> tmpList = this->selectedItems();
    for (int i = tmpList.count() - 1; i >= 0; --i)
        removeHash(tmpList.at(i)->whatsThis().toAscii());
}

void HashListWidget::removeAllHashes()
{
    std::cout << "Removing All Hashes" << std::endl;
    for (int i = this->count() - 1; i >= 0; --i)
        removeHash(this->item(i)->whatsThis().toAscii());
}
