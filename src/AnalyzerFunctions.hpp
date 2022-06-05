#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

#include "Subclass.hpp"

namespace AnalyzerFunctions
{
    std::unordered_map<int, int> count_decades(std::vector<int> years_list);
    
    std::unordered_map<std::string, int> count_genres(std::vector<std::string> genres_list);
    
    std::unordered_map<double, int> count_ratings(std::vector<double> ratings_list);
    
    std::unordered_map<std::string, int> count_cast(std::vector<std::string> cast_list);
    
    void printHelp();
}

