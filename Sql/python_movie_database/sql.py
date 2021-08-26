import sqlite3
import argparse

class Parser():
    def __init__(self):
        self.parser = self.set_parser()
        self.args = self.parser.parse_args()

    # set parser keywords
    def set_parser(self) -> object:
        parser = argparse.ArgumentParser()
        parser.add_argument('-k', '--keyword', type=str)
        parser.add_argument('-d', '--dbname', type=str)
        return parser

    def get_keyword(self):
        keyword = self.args.keyword
        if keyword is None:
            print("You have to input Keyword")
            exit(0)
        return self.args.keyword

    def get_dbName(self):
        return str(self.args.dbname)

class Actor:
    def __init__(self,key, name=None, cur=None ):
        self.name = name
        self.cur = cur
        self.films = self.get_all_films_from_database(key)
        self.co_stars, self.films_together = self.get_all_costars_from_databse(key)

    def get_name(self):
        return self.name

    def get_all_costars_from_databse(self, key):
        sql_part1 = (
            "  with ActorMV as (                        "
            "          select *                         "
            "          from actor                       "
            "           union                           "
            "           select *                        "
            "           from actress                    "
            "   )                                       "
            "                                           " 
            "                                            "
            "   select a2.name, count(m.title) nr        "
            "   from ActorMV a1, ActorMV a2, movie m     "
            "   where a1.name != a2.name and             "
            "       a1.movie_id = m.mid and              "
            "       a2.movie_id = m.mid and              "
            "       a1.name like '%"
                    )

        sql_part2 = ("%'                "
            "   group by a2.name                         "
            "   order by nr desc, a2.name                "
            "   limit 5;                                 "
                     )
        sql = sql_part1 + key + sql_part2
        #        print(sql)
        co_star = list()
        film_together = list()
        for row in self.cur.execute(sql):
            co_star.append(row[0])
            film_together.append(row[1])
        return co_star, film_together

    def get_all_films_from_database(self, key):
        sql_part1 = (
            "  with ActorMV as (                        "
            "          select *                         "
            "          from actor                       "
            "           union                           "
            "           select *                        "
            "           from actress                    "
            "   )                                       "
            "                                           "
            "   select                                  "
            "   distinct movie.title                    "
            "   from movie join                         "
            "   ActorMV as AC                           "
            "   where                                   "
            "   movie.mid = AC.movie_id                 "
            "   and AC.name like  '%"
        )

        sql_part2 = ("%'" )

        sql = sql_part1 + key + sql_part2
        #        print(sql)
        played_in = list()
        for row in self.cur.execute(sql):
            played_in.append(row[0])
        return played_in

    def print(self):
        print(self.get_name() + ",")
        print("\t PLAYED IN")
        self.print_played_in()
        self.print_co_stars()

    def print_played_in(self):
        for film in self.films:
            print("\t\t" + film)

    def print_co_stars(self):
        print("\t CO-STARS")

        for x in range(len(self.co_stars)):
            print("\t\t" + self.co_stars[x] + "(" + str(self.films_together[x]) + ")")
        pass


class Movie:
    def __init__(self, title="", jahr=None,  genre=None, actores=None, cur=None):
        self.title = title
        self.jahr = jahr
        self.cur=cur
        self.genres = self.get_all_genres_from_database()
        self.movie_actores = self.get_all_actores_from_database()

    def set_title(self, title):
        self.title = title

    def get_title(self):
        return self.title

    def set_genres(self, genre):
        self.genres = genre

    def get_genres(self):
        return self.genres

    def set_actores(self, movie_actores):
        self.movie_actores = movie_actores

    def get_all_genres_from_database(self):

        sql_part1 = ("select g.genre "
                     "from movie join genre g on "
                     "movie.mid = g.movie_id "
                     "where movie.title like '")
        key = str(self.title)
        sql_part2 = ("'"
                     " order by title ")
        sql = sql_part1 + key + sql_part2
        #        print(sql)
        genres = list()
        for row in self.cur.execute(sql):
            genres.append(row[0])
        return genres

    def get_all_actores_from_database(self):

        sql_part1 = (
            "  with ActorMV as (                        "
            "          select *                         "
            "          from actor                       "
            "           union                           "
            "           select *                        "
            "           from actress                    "
            "   )                                       "
            "                                           "
            "   select                                  "
            "   AC.name                    "
            "   from movie join                         "
            "   ActorMV as AC                           "
            "   where                                   "
            "   movie.mid = AC.movie_id                 "
            "   and movie.title like  '%"
        )

        key = str(self.title)
        sql_part2 = ("%'"
                     " order by AC.name limit 5 ")
        sql = sql_part1 + key + sql_part2
        genres = list()
        for row in self.cur.execute(sql):
            genres.append(row[0])
        return genres

    def print(self):
        genres = ""
        for x in self.get_genres():
            genres += x + ","

        print(self.get_title() + "," + str(self.jahr) + "," + genres)
        for movie_ctor in self.movie_actores:
            print("\t" + movie_ctor)

class DB:
    def __init__(self):
        self.parser = Parser()
        self.conn = sqlite3.connect(self.parser.get_dbName())

        if (self.parser.get_dbName() != "./imdb.db"):
            print("gebe den Gesamten Path to Datenbank, falls er in Ordner ist dann tippe ./imdb.db")

        self.cur = self.conn.cursor()

        self.movies = self.get_list_of_movies_depends_on_key(self.parser.get_keyword())

        self.actors = self.get_list_of_actors_depends_on_key(self.parser.get_keyword())

    def print_movies(self):
        print("MOVIES")
        for movie in self.movies:
            movie.print()

    def print_actors(self):
        print("ACTORS")
        for actor in self.actors:
            actor.print()
            """
            actor.set_genres(self.get_all_genres_from_database(title))
            actor.set_actores(self.get_all_actores_from_database(title))
            actor.print()
            """

    def set_movies(self, movies):
        self.movies = movies

    def get_movies(self):
        return self.movies

    def get_list_of_movies_depends_on_key(self, key):
        # ich gehe uber die Filme die dieser voraussetzun erfullel
        # Ich fulle liste mit mid auf.

        sql_part1 = ("select title, year from movie "
                     "where title like '%")
        sql_part2 = ("%'"
                     " order by title ")
        sql = sql_part1 + key + sql_part2
        #        print(sql)
        movies = list()
        for row in self.cur.execute(sql):
            movies.append(Movie(title=row[0], jahr=row[1], cur=self.cur))

        return movies

    def get_list_of_actors_depends_on_key(self, key):
        sql_part1 = (
            "  with ActorMV as (                        "
            "          select *                         "
            "          from actor                       "
            "           union                           "
            "           select *                        "
            "           from actress                    "
            "   )                                       "
            "                                           "
            "   select distinct                                "
            "   AC.name                    "
            "   from ActorMV as AC                           "
            "   where                                   "
            "   AC.name like  '%"
        )

        sql_part2 = ("%'"
                     " order by AC.name limit 5 ")
        sql = sql_part1 + key + sql_part2
        names = list()
        for row in self.cur.execute(sql):
            names.append(Actor(name=str(row[0]), cur=self.cur, key=key))
        return names
