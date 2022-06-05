#include <iostream>
#include "Subclass.hpp"


Subclass::Subclass(){}

Subclass::~Subclass(){   
    delete node;
    
    std::cout << "Check out some of my favorite movie-related YouTube channels:" << std::endl;
    std::cout << "\tRed Letter Media: https://www.youtube.com/user/RedLetterMedia" << std::endl;
    std::cout << "\tYourMovieSucksDOTorg: https://www.youtube.com/c/YourMovieSucksDOTorg" << std::endl;
    std::cout << "\tPony Smasher: https://www.youtube.com/sandberganimation (this is David F."
                    "Sandberg's (director of Shazam) YouTube channel)" << std::endl;
    std::cout << "\tLindsay Ellis: https://www.youtube.com/c/LindsayEllisVids" << std::endl;
    std::cout << "\tLessons from the Screenplay: https://www.youtube.com/c/LessonsfromtheScreenplay" << std::endl;
    std::cout << "\tEvery Frame a Painting: https://www.youtube.com/c/everyframeapainting" << std::endl;
}

void Subclass::message(Success s)
{
    if (s == Success::success)
    {
        std::cout << "IMDb Top 250 analyzed successfully" << std::endl;        
    }
}

