#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <functional>
#include <nlohmann/json.hpp>

using namespace std;

/*
 * страна и дата создания киноленты, студия, которая вела съёмки, автор сценария, режиссёр и продюсер киноленты.
 * Обязательно добавьте информацию обо всех главных действующих лицах и тех актёрах, которые их сыграли.
 *
*/

struct Movie {
    string name;
    string the_slogan;
    string date;

    vector<string> country;
    vector<string> genre;


    vector<string> _director;
    vector<string> _the_script;
    vector<string> _producer;
    string _operator;

    map<string, string> actors_and_roles;

    string age;
};

void The_Gentlemen(Movie &movie) {
    movie.name = "The Gentlemen";
    movie.the_slogan = "Criminal. Class";
    movie.date = "3.12.2019";

    movie.country = {"UK", "USA"};
    movie.genre = {"crime", "comedy", "action movie"};


    movie._director = {"Guy Ritchie"};
    movie._the_script = {"Guy Ritchie", "Ivan Atkinson", "Marne Davis"};
    movie._producer = {"Matthew Anderson", "Ivan Atkinson", "Bill Block"};
    movie._operator = "Alan Stewart";

    if (!movie.actors_and_roles.empty()) movie.actors_and_roles.clear();
    movie.actors_and_roles.insert(pair<string, string>("Matthew McConaughey", "Michael Pearson"));
    movie.actors_and_roles.insert(pair<string, string>("Charlie Hunnamb", "Ray"));
    movie.actors_and_roles.insert(pair<string, string>("Henry Golding", "Dry Eye"));
    movie.actors_and_roles.insert(pair<string, string>("Hugh Grant", "Fletcher"));
    movie.actors_and_roles.insert(pair<string, string>("Michelle Dockery", "Rosalind Pearson"));
    movie.actors_and_roles.insert(pair<string, string>("Jeremy Strong", "Matthew"));
    movie.actors_and_roles.insert(pair<string, string>("Eddie Marsan", "Big Dave"));
    movie.actors_and_roles.insert(pair<string, string>("Jason Wong", "Phuc"));
    movie.actors_and_roles.insert(pair<string, string>("Colin Farrell", "Coach"));
    movie.actors_and_roles.insert(pair<string, string>("Lyne Renee", "Jackie"));
    movie.actors_and_roles.insert(pair<string, string>("Tom Wu", "Lord George"));

    movie.age = "18+";
}

void Interstellar(Movie &movie) {
    movie.name = "Interstellar";
    movie.the_slogan = "Humanity's next step will be the greatest";
    movie.date = "26.10.2014";

    movie.country = {"USA", "UK", "Canada"};
    movie.genre = {"fiction", "drama", "adventure"};


    movie._director = {"Christopher Nolan"};
    movie._the_script = {"Jonathan Nolan", "Christopher Nolan"};
    movie._producer = {"Christopher Nolan", "Linda Obst", "Emma Thomas"};
    movie._operator = "Hoyte Van Hoytema";

    if (!movie.actors_and_roles.empty()) movie.actors_and_roles.clear();
    movie.actors_and_roles.insert(pair<string, string>("Matthew McConaughey", "Cooper"));
    movie.actors_and_roles.insert(pair<string, string>("Anne Hathaway", "Brand"));
    movie.actors_and_roles.insert(pair<string, string>("Jessica Chastain", "Murph"));
    movie.actors_and_roles.insert(pair<string, string>("Michael Caine", "Professor Brand"));
    movie.actors_and_roles.insert(pair<string, string>("David Gyasi", "Romilly"));
    movie.actors_and_roles.insert(pair<string, string>("Wes Bentley", "Doyle"));
    movie.actors_and_roles.insert(pair<string, string>("Matt Damon", "Mann"));
    movie.actors_and_roles.insert(pair<string, string>("Topher Grace", "Getty"));
    movie.actors_and_roles.insert(pair<string, string>("Casey Affleck", "Tom"));

    movie.age = "16+";
}

void Pulp_Fiction(Movie &movie) {
    movie.name = "Pulp Fiction";
    movie.the_slogan = "Just because you are a character doesn't mean you have character";
    movie.date = "21.05.1994";

    movie.country = {"USA"};
    movie.genre = {"crime", "drama"};


    movie._director = {"Quentin Tarantino"};
    movie._the_script = {"Quentin Tarantino", "Roger Avery"};
    movie._producer = {"Lawrence Bender", "Danny DeVito", "Richard N. Gladstein"};
    movie._operator = "Andrzej Sekula";

    if (!movie.actors_and_roles.empty()) movie.actors_and_roles.clear();
    movie.actors_and_roles.insert(pair<string, string>("John Travolta", "Vincent Vega"));
    movie.actors_and_roles.insert(pair<string, string>("Samuel L. Jackson", "Jules Winnfield"));
    movie.actors_and_roles.insert(pair<string, string>("Bruce Willis", "Butch Coolidge"));
    movie.actors_and_roles.insert(pair<string, string>("Uma Thurman", "Mia Wallace"));
    movie.actors_and_roles.insert(pair<string, string>("Ving Rhames", "Marsellus Wallace"));
    movie.actors_and_roles.insert(pair<string, string>("Tim Roth", "Pumpkin"));
    movie.actors_and_roles.insert(pair<string, string>("Harvey Keitel", "The Wolf"));
    movie.actors_and_roles.insert(pair<string, string>("Quentin Tarantino", "Jimmie"));
    movie.actors_and_roles.insert(pair<string, string>("Peter Greene", "Zed"));

    movie.age = "18+";
}

void Se7en(Movie &movie) {
    movie.name = "Se7en";
    movie.the_slogan = "He fancied himself a God and began to punish ...";
    movie.date = "15.09.1995";

    movie.country = {"USA"};
    movie.genre = {"thriller", "drama", "crime", "detective"};


    movie._director = {"David Fincher"};
    movie._the_script = {"Andrew Kevin Walker"};
    movie._producer = {"Stephen Brown", "Phyllis Carlisle", "William S. Gerrity"};
    movie._operator = "Darius Honji";

    if (!movie.actors_and_roles.empty()) movie.actors_and_roles.clear();
    movie.actors_and_roles.insert(pair<string, string>("Brad Pitt", "Mills"));
    movie.actors_and_roles.insert(pair<string, string>("Morgan Freeman", "Somerset"));
    movie.actors_and_roles.insert(pair<string, string>("Gwyneth Paltrow", "Tracy"));
    movie.actors_and_roles.insert(pair<string, string>("Kevin Spacey", "John Doe"));
    movie.actors_and_roles.insert(pair<string, string>("John C. McGinley", "California"));
    movie.actors_and_roles.insert(pair<string, string>("Richard Schiff", "Mark Swarr"));
    movie.actors_and_roles.insert(pair<string, string>("Richard Roundtree", "Talbot"));

    movie.age = "18+";
}

void John_Wick(Movie &movie) {
    movie.name = "John Wick";
    movie.the_slogan = "It's better not to touch him";
    movie.date = "19.09.2014";

    movie.country = {"USA", " China"};
    movie.genre = {"action", "thriller", "crime"};


    movie._director = {"Chad Stahelski", "David Leitch"};
    movie._the_script = {"Derek Kolstad"};
    movie._producer = {"Basil Ivanik", "David Leitch", "Eva Longoria"};
    movie._operator = "Jonathan Sat down";

    if (!movie.actors_and_roles.empty()) movie.actors_and_roles.clear();
    movie.actors_and_roles.insert(pair<string, string>("Keanu Reeves", "John Wick"));
    movie.actors_and_roles.insert(pair<string, string>("Michael Nyqvist", "Viggo Tarasov"));
    movie.actors_and_roles.insert(pair<string, string>("Alfie Allen", "Iosef Tarasov"));
    movie.actors_and_roles.insert(pair<string, string>("Willem Dafoe", "Marcus"));
    movie.actors_and_roles.insert(pair<string, string>("Adrianne Palicki", "Ms. Perkins"));
    movie.actors_and_roles.insert(pair<string, string>("John Leguizamo", " Aurelio"));
    movie.actors_and_roles.insert(pair<string, string>("Ian McShane", "Winston"));

    movie.age = "16+";
}

void writeJSON(nlohmann::json &_json, Movie &movie) {
    _json = {
            {"Name",     movie.name},
            {"Slogon",   movie.the_slogan},
            {"Date",     movie.date},
            {"Country",  movie.country},
            {"Gerne",    movie.genre},
            {"Director", movie._director},
            {"Script",   movie._the_script},
            {"Producer", movie._producer},
            {"Operator", movie._operator},
            {"Actors",   movie.actors_and_roles},
            {"Age",      movie.age}
    };
}

void write_in_file(Movie &film, nlohmann::json &movie_json, const function<void(Movie &)> &func, string _name) {
    func(film);
    writeJSON(movie_json, film);

    ofstream file(_name + ".json");
    file << movie_json;
    file.close();
}

Movie readJSON(ifstream &file) {
    nlohmann::json _json;
    file >> _json;
    Movie film;

    film.name = _json["Name"];
    film.the_slogan = _json["Slogon"];
    film.date = _json["Date"];
    film.country = _json["Country"];
    film.genre = _json["Gerne"];
    film._director = _json["Director"];
    film._the_script = _json["Script"];
    film._producer = _json["Producer"];
    film._operator = _json["Operator"];
    film.actors_and_roles = _json["Actors"];
    film.age = _json["Age"];

    return film;
}

pair<string, Movie> fillKinopoisk(string _name) {
    ifstream file(_name + ".json");
    if (file.is_open()) {
        Movie film = readJSON(file);
        file.close();
        return pair<string, Movie>(film.name, film);
    }
}

int main() {

    // Задание 1
    Movie film;
    nlohmann::json movie_json;

    write_in_file(film, movie_json, The_Gentlemen, "the_gentlemen");
    write_in_file(film, movie_json, Interstellar, "interstellar");
    write_in_file(film, movie_json, Pulp_Fiction, "pulp_fiction");
    write_in_file(film, movie_json, Se7en, "se7en");
    write_in_file(film, movie_json, John_Wick, "john_wick");//*/


    // Задание 2
    Movie movie;
    map<string, Movie> kinopoisk;
    kinopoisk.insert(fillKinopoisk("the_gentlemen"));
    kinopoisk.insert(fillKinopoisk("interstellar"));
    kinopoisk.insert(fillKinopoisk("pulp_fiction"));
    kinopoisk.insert(fillKinopoisk("se7en"));
    kinopoisk.insert(fillKinopoisk("john_wick"));

    cout << "Enter actor name: ";
    string str;
    getline(cin, str);


    for (map<string, Movie>::iterator it = kinopoisk.begin(); it != kinopoisk.end(); it++) {
        for (map<string, string>::iterator i = it->second.actors_and_roles.begin();
             i != it->second.actors_and_roles.end(); i++) {
            if (i->first == str) {
                cout << it->first << endl;
                cout << "\tRole: " << i->second << endl;
                break;
            }
        }
    }


    kinopoisk.clear();
    return 0;
}
