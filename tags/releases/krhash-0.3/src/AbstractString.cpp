#include <AbstractString.h>


AbstractString::AbstractString() : QByteArray()
{
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


AbstractString::~AbstractString() { }


double AbstractString::total()
{
    if (computedTotal == -1)
        computedTotal = computeTotal();
    return computedTotal;
}

