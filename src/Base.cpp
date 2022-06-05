#include <iostream>
#include <string>

#include "Base.hpp"

Base::Base(){}

std::string getInfo(const Base* b)
{
    return b->info;
}

void setInfo(Base* b, std::string information)
{
    b->info = information;
}

void Base::message(Success s)
{
    if (s == Success::success)
    {
        std::cout << "LWIMDbAnalyzer: A data analysis program that analyzes the top 250 movies from"
        " IMDb\n" << std::endl;     
    }
}

