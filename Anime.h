#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Anime {
private:
    // attributes of anime
    string title;
    vector<string> genres;
    int airDate;
    int episodes;
    int members;
    double score;
    int popularity;
    int ranking;

public:
    // constructors
    Anime();
    Anime(string title, vector<string> genres, int airDate, int episodes, int members, int popularity, int ranking, double score);

    // destructor
    ~Anime();

    // copy assignment operator
    Anime& operator=(const Anime& rhs);

    // getters
    string GetTitle();
    vector<string> GetGenres();
    int GetAirDate();
    int GetEpisodes();
    double GetScore();
    int GetPopularity();
    int GetRanking();
};

Anime::Anime() {
    title = "Toni Toni Choppa's Misadventures!";
    airDate = 4000;
    episodes = 123;
    members = 0;
    ranking = 1000000;
    score = 0;
    popularity = 1000000;
}

Anime::Anime(string _title, vector<string> _genres, int _airDate, int _episodes, int _members, int _popularity, int _ranking, double _score) {
    title = _title;
    genres = _genres;
    airDate = _airDate;
    episodes = _episodes;
    members = _members;
    ranking = _ranking;
    score = _score;
    popularity = _popularity;
}

Anime& Anime::operator=(const Anime& rhs) {
    if (this != &rhs) {
        this->title = rhs.title;
        this->genres = rhs.genres;
        this->airDate = rhs.airDate;
        this->episodes = rhs.episodes;
        this->members = rhs.members;
        this->popularity = rhs.popularity;
        this->ranking = rhs.ranking;
        this->score = rhs.score;
    }
    return *this;
}

Anime::~Anime() {
    this->title = "";
    this->genres.clear();
    this->airDate = 0;
    this->episodes = 0;
    this->members = 0;
    this->popularity = 0;
    this->ranking = 0;
    this->score = 0;
}

string Anime::GetTitle() {
    return title;
}

vector<string> Anime::GetGenres() {
    return genres;
}

int Anime::GetAirDate() {
    return airDate;
}

int Anime::GetEpisodes() {
    return episodes;
}

double Anime::GetScore() {
    return score;
}

int Anime::GetPopularity() {
    return popularity;
}

int Anime::GetRanking() {
    return ranking;
}
