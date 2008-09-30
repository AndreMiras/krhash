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
    appendAll();

}


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
    
    while (!inStream->atEnd()) 
        dic->append(inStream->readLine(75).toAscii());
    file->seek(0);
}

// QByteArray MetaString2::operator++()
MetaString2 & MetaString2::operator++()
{
    // FIXME[cleaning/performance]: disgusting
    this->clear();
    this->append(dic->takeFirst());
    return *this;
}


double MetaString2::computeTotal() const
{
    return dic->size();
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

