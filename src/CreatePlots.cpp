#include <iostream>
#include "Subclass.hpp"

#include <yaml-cpp/yaml.h>


int main()
{
    Base * b = new Base();

    Base * sub = new Subclass();

    Success S = Success::success;
    b->message(S);
    sub->message(S);
    
    
    return 0;
}

