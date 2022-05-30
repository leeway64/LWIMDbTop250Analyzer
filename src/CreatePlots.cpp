#include <iostream>
#include "Subclass.hpp"

#include <yaml-cpp/yaml.h>


int main()
{
    Base * b = new Base();
    Base * sub = new Subclass();

    std::string help_message = "Usage: LWIMDbAnalyzer [PATH TO YAML]";
    setInfo(b, help_message);


    Success S = Success::success;
    b->message(S);
    std::cout << getInfo(b) << std::endl;
    sub->message(S);
        
    return 0;
}

