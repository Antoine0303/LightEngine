#include "Data.h"


Data* Data::Get()
{
    static Data mInstance;

    return &mInstance;
}