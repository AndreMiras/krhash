#include "HashListWidget.h"

#include <QtGui>


// HashListWidget::HashListWidget(QWidget *parent) : QWidget(parent)
HashListWidget::HashListWidget(QWidget *parent) : QListWidget(parent)
{
    std::cout << "HashListWidget::Construct" << std::endl;
    attack = NULL;
// TODO: what the best ?  
    // this->setSelectionMode(QAbstractItemView::MultiSelection);
    this->setSelectionMode(QAbstractItemView::ExtendedSelection);
    this->setMinimumSize(QSize(350, 100));
    createActions();
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

void HashListWidget::createActions()
{
    removeSelectedHashesAct = new QAction(tr("Remove selected hashes"), this);
    // FIXME: del shortcut is not working
    removeSelectedHashesAct->setShortcut(Qt::Key_Delete);
    // removeSelectedHashesAct->setShortcut(tr("Del"));
    removeAllHashesAct = new QAction(tr("Remove all hashes"), this);
    // TODO
    connect(removeSelectedHashesAct, SIGNAL(triggered()), this, SLOT(removeSelectedHashes()));
    connect(removeAllHashesAct, SIGNAL(triggered()), this, SLOT(removeAllHashes()));
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
    int i = this->count() - 1;
    while ( (i >= 0) && (this->item(i)->text() != hash) )
        i--;
// Items removed from a list widget will not be managed by Qt, and will need to be deleted manually.
    this->takeItem(i);
    this->insertItem(i, tr(hash) + tr(" : ") + tr(attack->getPlain(hash)));
    this->item(i)->setBackground(QBrush(QColor(Qt::green)));
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
        this->addItem(createHashItem(hash));
        attack->addHash(hash);
        emit hashAdded();
    }
    else
        std::cout << " [error]" << std::endl;
}

void HashListWidget::removeHash(const QByteArray & hash)
{
    int i = this->count() - 1;
    while ( (i >= 0) && (this->item(i)->text() != hash) )
        i--;
// FIXME[cleaning]: 'Items removed from a list widget will not be managed by Qt, and will need to be deleted manually'
    this->takeItem(i);
    attack->removeHash(hash);
    emit hashRemoved();
    std::cout << "Trying to remove ["
    << qPrintable(QString(hash))
    << "]" << std::endl;
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
        removeHash(tmpList.at(i)->text().toAscii());
}

void HashListWidget::removeAllHashes()
{
    std::cout << "Removing All Hashes" << std::endl;
    for (int i = this->count() - 1; i >= 0; --i)
        removeHash(this->item(i)->text().toAscii());
}


