#include <iostream>
#include <yaml-cpp/yaml.h>


// an enum class is like an enum, but strongly typed
enum class Success
{
    success = 0
};


void exitMessage(Success s)
{
    if (s == Success::success)
    {
        std::cout << "IMDb Top 250 analyzed successfully" << std::endl;        
    }
}


int main()
{
    std::cout << "hello world" << std::endl;

    Success S = Success::success;
    exitMessage(S);
    return 0;
}

