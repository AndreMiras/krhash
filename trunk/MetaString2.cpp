#include <MetaString2.h>

MetaString2::MetaString2() : AbstractString()
{
    this->dic = new QList<QByteArray>();
    init();
}

// MetaString2::MetaString2() : QByteArray(){ }

void MetaString2::init()
{
    QSettings settings("u54", "KrHash");
    QString dictPath(settings.value("DictPath", "NULL").toString());
    this->setDictionary(dictPath);
    appendAll();

}


bool MetaString2::setDictionary(const QString & fileName)
{
    file = new QFile(fileName);
    file->open(QIODevice::ReadOnly | QIODevice::Text);
    inStream = new QTextStream(file);
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

