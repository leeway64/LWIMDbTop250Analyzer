from imdb import Cinemagoer
import yaml


if __name__ == "__main__":
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
        movie['cast'] = movie_info['cast']
        movie['rating'] = movie_info['rating']
        
        top_250_formatted[str(i + 1)] = movie
        
        
        with open("data/IMDBTop250.yaml", 'w') as file:
            yaml.dump(top_250_formatted, file)
        
