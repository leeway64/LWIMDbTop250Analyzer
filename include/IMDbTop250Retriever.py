import yaml
import sys

from imdb import Cinemagoer


if __name__ == "__main__":
    if len(sys.argv) != 2:
        raise RuntimeError("Incorrect number of arguments! Provide the path where you want the data file to go.")
    
    
    path = f'{sys.argv[1]}'

    print("Retrieving IMDb Top 250 data")
        
    
    # A dictionary containing information about IMDb's top 250 user-rated movies
    top_250_formatted = dict()

    # Instantiate a Cinemagoer class
    cinema = Cinemagoer()
    top250 = cinema.get_top250_movies()


    for i in range(len(top250)):  # Iterate through all 250 movies
        movie = dict()
        movie['title'] = top250[i]['title']
        movie['year'] = top250[i]['year']
        ID = top250[i].movieID

        movie_info = cinema.get_movie(ID)
        movie['genres'] = movie_info['genres']
        
        cast_list = []
        for cast_member in movie_info['cast']:
            cast_list.append(cast_member['name'])

        movie['cast'] = cast_list
        
        movie['rating'] = movie_info['rating']
        
        top_250_formatted[str(i + 1)] = movie
        
        # I need to write to the file continually inside this for loop, because otherwise a timeout error will occur
        with open(path, 'w') as file:
            yaml.dump(top_250_formatted, file)
    
    print("Data retrieval finished")

