#include <iostream>
#include "Subclass.hpp"


Subclass::Subclass(){}

void Subclass::message(Success s)
{
    if (s == Success::success)
    {
        std::cout << "IMDb Top 250 analyzed successfully" << std::endl;        
    }
}

