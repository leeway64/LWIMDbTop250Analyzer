#include <iostream>
#include <exception>
#include <filesystem>

#include <yaml-cpp/yaml.h>

#include "AnalyzerFunctions.hpp"


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        throw std::invalid_argument("Invalid number of arguments. Run --help for more details.");
    }

    const std::string argument = argv[1];
    const std::filesystem::path input_data_file{ argument };

    if (argument == "--help")
    {
        AnalyzerFunctions::printHelp();
        std::exit(EXIT_SUCCESS);
    }
    else if (!std::filesystem::exists(input_data_file))
    {
        throw std::invalid_argument("Input data file not found.");
    }


    // The new keyword dynamically allocates memory for an object and creates that object. It
    // returns a pointer to that dynamically allocated object.
    Base * b = new Base();
    Base * sub = new Subclass();

    std::string movie_recommendation = "Check out \"Everything Everywhere All at Once\"! ";
    movie_recommendation += "This is one of the best movies that I've seen in a long time.\n";
    movie_recommendation += "\tDirected by Daniels\n";
    movie_recommendation += "\tStarring Michelle Yeoh, Stephanie Hsu, and Ke Huy Quan";
    
    setInfo(b, movie_recommendation);


    Success S = Success::success;
    b->message(S);  // Print intro message
    std::cout << getInfo(b) << std::endl;  // Print movie recommendation
    

    const YAML::Node IMDbInfo = YAML::LoadFile("IMDbTop250.yaml");
    
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

    const int person_min_occurrences = 5;
    std::unordered_map<std::string, int> cast_count = AnalyzerFunctions::count_cast(cast_list);
    // Remove any person who hasn't appeared at least 5 times in the IMDb top 250
    std::erase_if(cast_count, [person_min_occurrences](const auto& elem){
        auto const& [key, value] = elem;
        return value < person_min_occurrences;
    });
    
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
            std::cout << key << " " << value << std::endl;
    }

    sub->message(S);  // Print exit message

    std::exit(EXIT_SUCCESS);
}

