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

    this->pData = this->data();
    this->pData += this->length() - 1; // at the last element

    // FIXME[cleaning]: hardcoded value   
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
    if ( (i == 0) && (this->at(0) == 'a' ) )
    {
        lastIndex[this->length() - (i+1)] = 1;
        this->prepend(this->a_minValue);
        // this->pData++;
    }
    
    return *this; 
}

/*
MetaString & MetaString::operator++()
{
    // FIXME[performance]: store the current size somewhere
    int i = this->length() - 1;
    int j = 0;
    // int* ptrLastIndex = lastIndex;
    // FIXME[performance]: use something else, cause modulo takes a lot of time
    lastIndex[0] = ( (1 + lastIndex[0]) % userCharset.length() );
    // char newChar = this->userCharset.at(this->lastIndex[0]);
    
    this->data()[i] = userCharset.at(lastIndex[0]);
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
// FIXME[performance]: find something else, cause modulo takes a lot of time
        lastIndex[j] = ( (1 + lastIndex[j]) % userCharset.length() );
        // newChar = userCharset.at(this->lastIndex[j]);
        // *this->pData = userCharset.at(this->lastIndex[j]);
        this->data()[i] = userCharset.at(lastIndex[j]);
        // this->data()[i] = newChar;
    }

     *
     *
     * Note:    is it the best way, have to think about it when not tired
     * TODO:    emit when inserting (for output)
     *          see if at() quicker than an other one
     */
/*
    if ( (i == 0) && (this->at(0) == 'a' ) )
    {
        lastIndex[this->length() - (i+1)] = 1;
        this->prepend(this->a_minValue);
        // this->pData++;
    }
    return *this;
}
*/

double MetaString::computeTotal() const
{
    std::cout << "MetaString::computeTotal(), charsetLength: " << userCharset.length()<< std::endl;
    std::cout << "MetaString::computeTotal(), maxSize: " << getMaxSize() << std::endl;
    std::cout << "MetaString::computeTotal(), minSize: " << getMinSize() << std::endl;
    std::cout << "MetaString::computeTotal(): (" << userCharset.length()
                << "^" << getMaxSize() << ") - ("
                << userCharset.length() << "^" << getMinSize() << ")" << std::endl;
    double iteration = ( pow(userCharset.length(), getMaxSize())
            - pow(userCharset.length(), getMinSize()) );
    std::cout << "MetaString::computeTotal(), iterations: " << iteration << std::endl;
    return iteration;
}

void MetaString::setCharset(const QByteArray charset)
{
    userCharset = QByteArray(charset);
    std::cout << "Charset: " << qPrintable(QString(charset)) << std::endl;
    updateString();
}

int MetaString::getMinSize() const
{
    QSettings settings;
    int min = settings.value("CharsetFrom", 1).toInt();
    std::cout << "min: " << min << std::endl;
    return min;
}

int MetaString::getMaxSize() const
{
    QSettings settings;
    int max = settings.value("CharsetTo", 6).toInt();
    std::cout << "max: " << max << std::endl;
    return max;
}

