#include "MainWindow.h"

#include <QtGui>

MainWindow::MainWindow()
{
    this->attack = NULL;
    this->algo = NULL;

    elaspedTime = new QTime();
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    infoLabel = new QLabel();
    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    hashListWidget = new HashListWidget(this);

    infoWidget = new InfoWidget(this);
    configAttackDialog = new ConfigAttackDialog(this);

//    infoWidget->setFixedSize(200, 200);

    createPushButtons();
    createAddSingleHashLayout();
    createConnections();

    QGridLayout *mainLayout = new QGridLayout;
    QHBoxLayout *vertLayout = new QHBoxLayout;
//    layout->setMargin(5);

    mainLayout->addWidget(addSingleHashGroupBox, 0, 0, 1, 1);
    mainLayout->addWidget(hashListWidget, 1, 0, 3, 1);
    mainLayout->addWidget(infoWidget, 1, 1, 3, 2);
    mainLayout->addWidget(toggleCrackingButton, 4, 1, 1, 2);
/*
    mainLayout->addWidget(hashListWidget, 1, 0, 4, 1);
    mainLayout->addWidget(infoWidget, 1, 1, 3, 2);
*/
//    mainLayout->setColumnStretch(1, 10);
//    mainLayout->setColumnStretch(1, 10);

    widget->setLayout(mainLayout);

    createActions();
    createMenus();

    // FIXME[cleaning]: should use some var/const
    setWindowTitle(tr("KrHash 0.2"));

//    resize(minimumSizeHint());
    // TODO: should be expensible later
    setFixedSize(minimumSizeHint());
    init();
}

void MainWindow::init()
{
//   QSettings settings("u54", "KrHash");
    createAttack();
}

void MainWindow::setDefaultSettings()
{
    QSettings settings("u54", "KrHash");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
}

void MainWindow::openHashFile()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
// fileName = QFileDialog::getOpenFileName(this,
//             tr("Open Hash File"), "", tr("Hash Files (*.txt)"));
    QString fileName = QFileDialog::getOpenFileName(this,
                         tr("Open File"), QDir::currentPath(), tr("Text Files (*.txt)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        hashListWidget->addHashFromFile(file);
         
         /*
         if (file.isNull())
         {
             QMessageBox::information(this, tr("Import hash list"),
                                      tr("Cannot load %1.").arg(fileName));
             return;
         }
         // imageLabel->setPixmap(QPixmap::fromImage(image));
         */
         // updateActions();

     }
}

void MainWindow::saveHashToFile()
{
    QString filename = QFileDialog::getSaveFileName(this,
                        tr("Save File"), QDir::currentPath(), tr("Text (*.txt)"));
    QFile file(filename);
    // TODO: release a signal on error
    if (!file.open(QFile::WriteOnly | QFile::Truncate))
         return;
    QTextStream out(&file);
    QHash<QString, QString> foundHash = attack->getFound();
    QHashIterator<QString, QString> i(foundHash);
    while (i.hasNext())
    {
        i.next();
        out << i.key() << " : " << i.value() << endl;
    }
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::openConfigAttackDialog()
{
    configAttackDialog->exec();
}

void MainWindow::attackFinished()
{
    toggleCrackingButton->setText(tr("Start"));
    qDebug("Time elapsed: %i ms", elaspedTime->elapsed());
}

void MainWindow::toggleCracking()
{
    if(!attack->isRunning())
    {
    /*
     * recreate Attack to create a new MetaString if not MetaString2 (for instance) will
     * resume its state in the dictionary instead of restarting from the begining
     *
     */
        createAttack();
        toggleCrackingButton->setText(tr("Stop"));
        elaspedTime->restart();
        attack->start();
    }
    else
    {
        std::cout << "Stop cracking" << std::endl;
        toggleCrackingButton->setText(tr("Start"));
        // FIXME[cleaning]: use quit() and QEventLoop instead
        // attack->quit();
        // attack->terminate();
        attack->stopAttack();
    }
}

void MainWindow::appendHash()
{
    if (!addHashLineEdit->text().isEmpty())
        hashListWidget->addHash(addHashLineEdit->text().toAscii());
}

void MainWindow::createConnections()
{
    connect(toggleCrackingButton, SIGNAL(clicked()), this, SLOT(toggleCracking()));
    connect(addHashLineEdit, SIGNAL(returnPressed()), this, SLOT(appendHash()));
    connect(addHashButton, SIGNAL(clicked()), this, SLOT(appendHash()));
    connect(hashListWidget, SIGNAL(hashAdded()), infoWidget, SLOT(addHash()));
    connect(configAttackDialog, SIGNAL(accepted()), this, SLOT(createAttack()));
}

void MainWindow::createAttack()
{
    QSettings settings("u54", "KrHash");
    QString methodSett = settings.value("Method", "Brut Force").toString();
    QString algoSett = settings.value("Algo", "Md5").toString();

    // FIXME: use Class::type with this switch (See tablet Example "case QEvent::TabletPress:")
    QList<QByteArray> tmpHashList;
    if ( (attack != NULL) && (! attack->empty()))
    {
        std::cout << "Reconstructing using uncracked" << std::endl;
        tmpHashList += attack->notFound();
    }

    // FIXME: use a switch case instead
    if (methodSett == "Brut Force")
        attack = new BrutForceAttack();
    else if (methodSett == "Dictionary")
        attack = new DictionaryAttack();
    else
        qWarning("Unrecognized Method Setting");

    /*
     * FIXME[cleaning]: should define algo once in some file
     *
     *
     *
     *
     */
    if (algoSett == "Md2")
        algo = new AlgoMd2();
    else if (algoSett == "Md4")
        algo = new AlgoMd4();
    else if (algoSett == "Md5")
        algo = new AlgoMd5();
    else if (algoSett == "Sha0")
        algo = new AlgoSha0();
    else if (algoSett == "Sha1")
        algo = new AlgoSha1();
    else if (algoSett == "Double Md5")
        algo = NULL;
    else if (algoSett == "Windows LM")
        algo = new AlgoLm();
    else if (algoSett == "Windows NTLM")
        algo = new AlgoNtlm();
    else
        qWarning("Unrecognized Algo Setting");

    attack->setAlgo(algo);
    hashListWidget->setAttack(attack);
    attack->addHash(tmpHashList);

    // FIXME: should it really be here?
//    infoWidget->setAdvancement();
    infoWidget->updateView();
        
/*
    switch (method)
    {
       case "test":
           NULL;
       break;

       case "test2":
           NULL;
       break;
    }
*/

    connect(attack, SIGNAL(hashFound()), infoWidget, SLOT(hashFound()));
    connect(attack, SIGNAL(hashFound(QByteArray)), hashListWidget, SLOT(markHashFound(QByteArray)));
    connect(attack, SIGNAL(advancementChanged(int)), infoWidget, SLOT(setAdvancement(int)));
    connect(attack, SIGNAL(hashRateChanged(int)), infoWidget, SLOT(setHashRate(int)));
    connect(attack, SIGNAL(finished()), this, SLOT(attackFinished()));
}


void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openHashFileAct);
    fileMenu->addAction(saveHashToFileAct);
//    fileMenu->addAction(openDictionaryFileAct);
    fileMenu->addAction(exitAct);

    configMenu = menuBar()->addMenu(tr("&Config"));
    configMenu->addAction(configAttackAct);
}


void MainWindow::createActions()
{
    openHashFileAct = new QAction(tr("&Open hash file..."), this);
    openHashFileAct->setShortcut(tr("Ctrl+H"));
    openHashFileAct->setStatusTip(tr("Open an existing file"));
    connect(openHashFileAct, SIGNAL(triggered()), this, SLOT(openHashFile()));

    saveHashToFileAct = new QAction(tr("Save Cracked As..."), this);
    // saveHashToFileAct->setStatusTip(tr("Open an existing file"));
    // TODO: connect to the right slot
    connect(saveHashToFileAct, SIGNAL(triggered()), this, SLOT(saveHashToFile()));
    // FIXME[cleaning]: remove the lines below
/*
    openDictionaryFileAct = new QAction(tr("&Open dictionary file..."), this);
    openDictionaryFileAct->setShortcut(tr("Ctrl+O"));
    openDictionaryFileAct->setStatusTip(tr("Open an existing file"));
    connect(openDictionaryFileAct, SIGNAL(triggered()), this, SLOT(open()));
*/

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    configAttackAct = new QAction(tr("Attack"), this);
    connect(configAttackAct, SIGNAL(triggered()), this, SLOT(openConfigAttackDialog()));
}

void MainWindow::createAddSingleHashLayout()
{
    addSingleHashGroupBox = new QGroupBox(tr("Add Single Hash"));
    QHBoxLayout *layout = new QHBoxLayout;

    addHashLineEdit = new QLineEdit();
    addHashLineEdit->setFixedWidth(250);
    // testing purpose
//    addHashLineEdit->setText("df5ea29924d39c3be8785734f13169c6"); // blabla
    addHashButton = new QPushButton(tr("&Add"));

    layout->addWidget(addHashLineEdit);  
    layout->addWidget(addHashButton);
    addSingleHashGroupBox->setFixedSize(350, 70);
    addSingleHashGroupBox->setLayout(layout);
}


void MainWindow::createPushButtons()
{
    toggleCrackingButton = new QPushButton(tr("&Start"));
    // quitButton = new QPushButton(tr("Quit"));
    // quitButton->setAutoDefault(false);    
}


void MainWindow::selectMode(int nMode)
{

}


