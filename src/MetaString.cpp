#include <MetaString.h>


static const char defaultCharset[] = "abcdefghijklmnopqrstuvwxyz";


MetaString::MetaString() : AbstractString() 
{
    qDebug() << "MetaString::Constructed[Begin]";
    QSettings settings("u54", "KrHash");
    // const QByteArray MetaString::defaultCharset = QByteArray("abcdefghijklmnopqrstuvwxyz");
    setCharset(settings.value("Charset", defaultCharset).toString().toAscii());

    this->pData = this->data();
    this->pData += this->length() - 1; // at the last element

    // FIXME[cleaning]: hardcoded value   
    for (int i=0; i < 7; ++i)
        this->lastIndex[i] = 0;
}

//MetaString::MetaString(const QByteArray & other) : AbstractString(other) { }

MetaString::~MetaString()
{
    qDebug() << "MetaString::Destructed:";
}

// FIXME: change lastIndex pointer state
void MetaString::updateString()
{
    a_minValue = minValue();
    this->fill(a_minValue, getMinSize());
}

const char MetaString::minValue() const
{
    return userCharset.at(0);
}

// optimized one
MetaString & MetaString::operator++()
{
     // FIXME[performance]: store the current size somewhere
    int i = this->length() - 1;
    int j = 0;
    int* pLastIndex = lastIndex;
    // int* ptrLastIndex = lastIndex;
    // FIXME[performance]: use something else, cause modulo takes a lot of time
    // lastIndex[0] = ( (1 + lastIndex[0]) % userCharset.length() );
    *pLastIndex = ( (1 + *pLastIndex) % userCharset.length() );
    // char newChar = this->userCharset.at(this->lastIndex[0]);
    
    // this->data()[i] = userCharset.at(lastIndex[0]);
    // this->data()[i] = userCharset.at(*pLastIndex);
    this->data()[i] = userCharset.at(*pLastIndex);
    // *this->pData = this->userCharset.at(this->lastIndex[0]);
    
    // char newChar = this->nextChar(this->at(i));
    
    // this->data()[i] = newChar; //intNewChar;
    // while ( (i > 0) & (newChar == this->a_minValue ))
    while ( (i > 0) && (this->constData()[i] == this->a_minValue ))
    // while ( (i > 0) & (*this->pData == this->a_minValue ))
    {
        --i;
        // this->pData--;
        ++j; ++pLastIndex;
        // newChar = this->nextChar(this->at(i));
        // this->data()[i] = newChar; //intNewChar;
// FIXME[performance]: find something else, cause modulo takes a lot of time
        // lastIndex[j] = ( (1 + lastIndex[j]) % userCharset.length() );
        *pLastIndex = ( (1 + *pLastIndex) % userCharset.length() );
        // newChar = userCharset.at(this->lastIndex[j]);
        // *this->pData = userCharset.at(this->lastIndex[j]);
        // this->data()[i] = userCharset.at(lastIndex[j]);
        this->data()[i] = userCharset.at(*pLastIndex);
        // this->data()[i] = newChar;
    }

    /*
     *
     * Note:    is it the best way, have to think about it when not tired
     * TODO:    emit when inserting (for output)
     *          see if at() quicker than an other one
     */
    if ( (i == 0) && (this->at(0) == minValue() ) )
    {
        lastIndex[this->length() - (i+1)] = 1;
        this->prepend(this->a_minValue);
        // this->pData++;
    }
    
    return *this; 
}

// FIXME: this computation is not 100 right
double MetaString::computeTotal() const
{
    qDebug() << "MetaString::computeTotal(), charsetLength: " << userCharset.length();
    qDebug() << "MetaString::computeTotal(), maxSize: " << getMaxSize();
    qDebug() << "MetaString::computeTotal(), minSize: " << getMinSize();
    qDebug() << "MetaString::computeTotal(): (" << userCharset.length()
                << "^" << getMaxSize() << ") - ("
                << userCharset.length() << "^" << getMinSize() << ")";
    double iteration = ( pow(userCharset.length(), getMaxSize())
            - pow(userCharset.length(), getMinSize()) );
    qDebug() << "MetaString::computeTotal(), iterations: " << iteration;
    return iteration;
}

void MetaString::setCharset(const QByteArray charset)
{
    userCharset = QByteArray(charset);
    qDebug() << "Charset: " << qPrintable(QString(charset));
    updateString();
}

int MetaString::getMinSize() const
{
    QSettings settings;
    return settings.value("CharsetFrom", 1).toInt();
}

int MetaString::getMaxSize() const
{
    QSettings settings;
    return settings.value("CharsetTo", 6).toInt();
}

