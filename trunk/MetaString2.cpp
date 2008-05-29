#include <MetaString2.h>

MetaString2::MetaString2() : AbstractString()
{
    this->dic = new QList<QByteArray>();
    init();
}

// MetaString2::MetaString2() : QByteArray(){ }

// FIXME: this constructor shouldn't exist anymore
// MetaString2::MetaString2(const QString & name) : QByteArray(str) 
// FIXME 2: not needed anymore
/*
MetaString2::MetaString2(const QString & name) : AbstractString()
{
    std::cout << "MetaString2::Constructed[Begin]" << std::endl;
    this->dic = new QList<QByteArray>();
    this->setDictionary(name);
}
*/

void MetaString2::init()
{
    QSettings settings("u54", "KrHash");
    QString dictPath(settings.value("DictPath", "NULL").toString());
    this->setDictionary(dictPath);
//    std::cout << "DictionaryAttack reading config, DictPath: "<< qPrintable(dictPath) << std::endl;

}


// FIXME: generatedFrom() instead, so I can remove this when have time
// FIXME 2: big cleaning cause now using QSettings
// void MetaString2::setup(const QString & fileName)
bool MetaString2::setDictionary(const QString & fileName)
{
    this->file = new QFile(fileName);
    this->file->open(QIODevice::ReadOnly | QIODevice::Text);
    this->inStream = new QTextStream(this->file);
}

MetaString2::~MetaString2()
{
    std::cout << "MetaString2::Destructed:" << std::endl;
}

void MetaString2::appendAll()
{
/*
    QTextStream inStream(&this->file);
    std::cout << "MetaString2::AppendingAll()" << std::endl;
    
    // while (!this->file->atEnd()) 
    while (!in->atEnd()) 
    {
    //      QString line = in.readLine();
        this->dic->append(this->file->readLine());
    }
*/
}

MetaString2 & MetaString2::operator++()
{
    // FIXME[cleaning]: disgusting
    this->clear();
//    this->append(dic->takeFirst());
    this->append(this->inStream->readLine(75));
    return *this;
}


int MetaString2::computeTotal() const
{
/*
    do
    {
        line = stream.readLine();
    } while (!line.isNull());
*/

    int i=0;
    while (!inStream->readLine().isNull())
        ++i;
    file->seek(0);
    return i;
}

void MetaString2::generatedFrom(const QByteArray fileName)
{
    //setup(fileName);
}

void MetaString2::startAt(int line)
{
    std::cout << "Not implemented" << std::endl;
}

void MetaString2::stopAt(int line)
{
    std::cout << "Not implemented" << std::endl;
}

