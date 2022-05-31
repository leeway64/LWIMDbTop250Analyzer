#include <iostream>
#include <yaml-cpp/yaml.h>

#include "AnalyzerFunctions.hpp"
#include "Subclass.hpp"

int main()
{
    YAML::Node IMDbInfo = YAML::LoadFile("IMDBTop250.yaml");
    
    std::vector<std::string> genres_list{};
    std::vector<double> ratings_list{};
    std::vector<int> years_list{};
    std::vector<std::string> cast_list{};
    
    for (const auto& movie : IMDbInfo)
    {
        std::cout << movie.first.as<std::string>()<< std::endl;
        for (const auto& genre : movie.second["genres"])
        {
            genres_list.push_back(genre.as<std::string>());
        }
        
        ratings_list.push_back(movie.second["rating"].as<double>());
        std::cout << movie.second["title"].as<std::string>()<< std::endl;
        years_list.push_back(movie.second["year"].as<int>());
    }


    std::unordered_map<int, int> decades_count= AnalyzerFunctions::count_decades(years_list);
    std::unordered_map<std::string, int> genres_count = AnalyzerFunctions::count_genres(genres_list);
    std::unordered_map<double, int> ratings_count = AnalyzerFunctions::count_ratings(ratings_list);
    std::unordered_map<std::string, int> cast_count = AnalyzerFunctions::count_cast(cast_list);


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

