#include "Base.hpp"
#include <iostream>

Base::Base(){}

void Base::message(Success s)
{
    if (s == Success::success)
    {
        std::cout << "LWIMDbAnalyzer: A data analysis program that analyzes the top 250 movies from"
        " IMDb\n" << std::endl;     
    }
}

