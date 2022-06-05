#include "AnalyzerFunctions.hpp"


std::unordered_map<int, int> AnalyzerFunctions::count_decades(std::vector<int> years_list)
{
    std::unordered_map<int, int> decades_count{};
    for (const auto& year: years_list)
    {
        const int decade = (year / 10) * 10;
        if (!decades_count.contains(decade))
        {
            decades_count[decade] = 0;
        }
        ++decades_count[decade];
    }

    
    return decades_count;
}

std::unordered_map<std::string, int> AnalyzerFunctions::count_genres(std::vector<std::string> genres_list)
{
    std::unordered_map<std::string, int> genres_count{};
    
    for (const auto& genre: genres_list)
    {
        if (!genres_count.contains(genre))
        {
            genres_count[genre] = 0;
        }
        ++genres_count[genre];
    }
    
    return genres_count;
}

std::unordered_map<double, int> AnalyzerFunctions::count_ratings(std::vector<double> ratings_list)
{
    std::unordered_map<double, int> ratings_count{};
    
    for (const auto& rating: ratings_list)
    {
        if (!ratings_count.contains(rating))
        {
            ratings_count[rating] = 0;
        }
        ++ratings_count[rating];
    }
    
    return ratings_count;
}

std::unordered_map<std::string, int> AnalyzerFunctions::count_cast(std::vector<std::string> cast_list)
{
    std::unordered_map<std::string, int> cast_count{};
    for (const auto& cast_member: cast_list)
    {
        if (!cast_count.contains(cast_member))
        {
            cast_count[cast_member] = 0;
        }
        ++cast_count[cast_member];
    }
    return cast_count;
}

void AnalyzerFunctions::printHelp()
{
    
}

