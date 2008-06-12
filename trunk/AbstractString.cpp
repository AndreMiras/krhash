#include <AbstractString.h>


AbstractString::AbstractString() : QByteArray()
{
    std::cout << "AbstractString::Constructed:" << std::endl;
    computedTotal = -1;
}


/*
AbstractString::AbstractString(const char * str) : QByteArray(str)
{
//    this->setup(str);
    computedTotal = -1;
}
*/

// AbstractString::AbstractString(const QByteArray & other) : QByteArray(other) { }


AbstractString::~AbstractString()
{
    std::cout << "AbstractString::Destructed:" << std::endl;
}


int AbstractString::total()
{
    if (computedTotal == -1)
        computedTotal = computeTotal();
    return computedTotal;
}

