#include <iostream>
#include <yaml-cpp/yaml.h>

#include "AnalyzerFunctions.hpp"


int main()
{
    const YAML::Node IMDbInfo = YAML::LoadFile("IMDBTop250.yaml");
    
    std::vector<std::string> genres_list{};
    std::vector<double> ratings_list{};
    std::vector<int> years_list{};
    std::vector<std::string> cast_list{};
    
    for (const auto& movie: IMDbInfo)
    {
        for (const auto& genre: movie.second["genres"])
        {
            genres_list.push_back(genre.as<std::string>());
        }
        
        for (const auto& cast_member: movie.second["cast"])
        {
            cast_list.push_back(cast_member.as<std::string>());
        }
        
        ratings_list.push_back(movie.second["rating"].as<double>());
        years_list.push_back(movie.second["year"].as<int>());
    }


    std::unordered_map<int, int> decades_count= AnalyzerFunctions::count_decades(years_list);
    std::unordered_map<std::string, int> genres_count = AnalyzerFunctions::count_genres(genres_list);
    std::unordered_map<double, int> ratings_count = AnalyzerFunctions::count_ratings(ratings_list);
    std::unordered_map<std::string, int> cast_count = AnalyzerFunctions::count_cast(cast_list);

    

    for (auto [key, value]: decades_count)
    {
        std::cout << key << " " << value << std::endl;
    }

    for (auto [key, value]: genres_count)
    {
        std::cout << key << " " << value << std::endl;
    }

    for (auto [key, value]: ratings_count)
    {
        std::cout << key << " " << value << std::endl;
    }

    for (auto [key, value]: cast_count)
    {
        
        if (value >= 2)
        {
            std::cout << key << " " << value << std::endl;
        }
    }

    Base * b = new Base();
    Base * sub = new Subclass();

    std::string movie_recommendation = "Check out \"Everything Everywhere All at Once\"! ";
    movie_recommendation += "This is one of the best movies that I've seen in a long time.\n";
    movie_recommendation += "Directed by Daniels\n";
    movie_recommendation += "Starring Michelle Yeoh, Stephanie Hsu, and Ke Huy Quan";
    
    setInfo(b, movie_recommendation);


    Success S = Success::success;
    b->message(S);
    std::cout << getInfo(b) << std::endl;
    sub->message(S);
        
    return 0;
}

