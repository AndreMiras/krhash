#include <MetaString.h>


static const char defaultCharset[] = "abcdefghijklmnopqrstuvwxyz";
// static const char defaultCharset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";



// MetaString::MetaString(const char * str) : QByteArray(str) 
// this is shit, just remove this parameter
//MetaString::MetaString(const char * str) : AbstractString(str) 
MetaString::MetaString() : AbstractString() 
{
    std::cout << "MetaString::Constructed[Begin]" << std::endl;
    QSettings settings("u54", "KrHash");
    // const QByteArray MetaString::defaultCharset = QByteArray("abcdefghijklmnopqrstuvwxyz");
    setCharset(settings.value("Charset", defaultCharset).toString().toAscii());
//    userCharset = QByteArray(defaultCharset);
    // charsetLength = userCharset.length();
//    this->a_minValue = minValue();
    startAt(settings.value("CharsetFrom", 0).toInt());
    stopAt(settings.value("CharsetTo", 6).toInt());
    //this->fill('a', 1);

    this->pData = this->data();
    this->pData += this->length() - 1; // at the last element

    // FIXME:    size of lastIndex should be MaxSizeToCrackValue
    for (int i=0; i < 7; ++i)
        this->lastIndex[i] = 0;
}

//MetaString::MetaString(const QByteArray & other) : AbstractString(other) { }

MetaString::~MetaString()
{
    std::cout << "MetaString::Destructed:" << std::endl;
}

// FIXME: change lastIndex pointer state
void MetaString::updateString()
{
    a_minValue = minValue();
    this->fill(a_minValue, minSize);
    std::cout << "MetaString::updateString a_minValue: " << a_minValue << std::endl;
    std::cout << "MetaString::updateString minSize: " << minSize << std::endl;
}

const char MetaString::minValue() const
{
    return userCharset.at(0);
}

MetaString & MetaString::operator++()
{
    int i = this->length() - 1;
    int j = 0;
    this->lastIndex[0] = ( (1 + this->lastIndex[0]) % userCharset.length() );
    // char newChar = this->userCharset.at(this->lastIndex[0]);
    
    this->data()[i] = this->userCharset.at(this->lastIndex[0]);
    // *this->pData = this->userCharset.at(this->lastIndex[0]);
    
    // char newChar = this->nextChar(this->at(i));
    
    // this->data()[i] = newChar; //intNewChar;
    // while ( (i > 0) & (newChar == this->a_minValue ))
    while ( (i > 0) && (this->constData()[i] == this->a_minValue ))
    // while ( (i > 0) & (*this->pData == this->a_minValue ))
    {
        --i;
        // this->pData--;
        ++j;
        // newChar = this->nextChar(this->at(i));
        // this->data()[i] = newChar; //intNewChar;
        this->lastIndex[j] = ( (1 + this->lastIndex[j]) % userCharset.length() );
        // newChar = userCharset.at(this->lastIndex[j]);
        // *this->pData = userCharset.at(this->lastIndex[j]);
        this->data()[i] = userCharset.at(this->lastIndex[j]);
        // this->data()[i] = newChar;
    }

    /*
     *
     * Note:    is it the best way, have to think about it when not tired
     * TODO:    emit when inserting (for output)
     *          see if at() quicker than an other one
     */
    if ( (i == 0) && (this->at(0) == 'a' ) )
    {
        lastIndex[this->length() - (i+1)] = 1;
        this->prepend(this->a_minValue);
        // this->pData++;
    }
    return *this;
}

int MetaString::computeTotal() const
{
//    return pow(userCharset.length(), maxSize);
    std::cout << "MetaString::computeTotal()" << std::endl;
    std::cout << "MetaString::computeTotal(), charsetLength: " << userCharset.length()<< std::endl;
    std::cout << "MetaString::computeTotal(), maxSize: " << maxSize << std::endl;
    std::cout << "MetaString::computeTotal(), minSize: " << minSize << std::endl;
    
    int iteration = ( pow(userCharset.length(), maxSize)
            - pow(userCharset.length(), minSize) );
    std::cout << "MetaString::computeTotal(), iterations: " << iteration << std::endl;
    return iteration;
}

void MetaString::setCharset(const QByteArray charset)
{
    userCharset = QByteArray(charset);
    updateString();
//    std::cout << "newCharset:" << qPrintable(QString(charset)) << std::endl;
}

void MetaString::startAt(int charSize)
{
    if (charSize == 0)
        minSize = 1;
    else
        minSize = charSize;
//    std::cout << "startAt: " << minSize << std::endl;
    updateString();
}

void MetaString::stopAt(int charSize)
{
    this->maxSize = charSize;
    updateString();
    std::cout << "stopAt: " << charSize << std::endl;
}

void MetaString::setCharRange(int from, int to)
{
    startAt(from);
    stopAt(to);
}

