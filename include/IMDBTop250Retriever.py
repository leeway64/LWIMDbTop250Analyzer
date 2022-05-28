from imdb import Cinemagoer
import yaml


if __name__ == "__main__":
    top_250_formatted = dict()

    ia = Cinemagoer()
    top250 = ia.get_top250_movies()

    for i in range(len(top250)):
        movie = dict()
        movie['title'] = top250[i]['title']
        movie['year'] = top250[i]['year']
        ID = top250[i].movieID

        movie_info = ia.get_movie(ID)
        movie['genres'] = movie_info['genres']
        movie['rating'] = movie_info['rating']
        
        top_250_formatted[str(i + 1)] = movie
        
        
        with open("IMDBTop250.yaml", 'w') as file:
            yaml.dump(top_250_formatted, file)
        
