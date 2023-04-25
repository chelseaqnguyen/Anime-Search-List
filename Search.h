#pragma once
#include "Anime.h"
#include <map>


vector<Anime> SearchKeyword(string word, vector<Anime> list);
vector<Anime> SearchGenre(string genre, vector<Anime> list);
vector<Anime> SearchYear(int year, vector<Anime> list);

vector<Anime> SearchKeyword(string word, vector<Anime> list) {
    vector<Anime> allAnime;
    map<int, Anime> map;
    vector<Anime> top5Anime;

    // first finds all titles that include that passed in string and push into allAnime
    for (int i = 0; i < list.size(); i++) {
        string str = list[i].GetTitle();
        bool isFound = (str.find(word) != string::npos);

        if (isFound) {
            allAnime.push_back(list[i]);
        }
    }

    // map by popularity
    for (auto i : allAnime) {
        map.emplace(i.GetPopularity(), i);
    }

    // push back the top 5 anime with the genre, breaks when size of top5Anime reaches 5
    for (auto i = map.begin(); i != map.end(); i++) {
        if (top5Anime.size() == 5) {
            break;
        }

        top5Anime.push_back(i->second);
    }

    return top5Anime;
}

vector<Anime> SearchGenre(string genre, vector<Anime> list) {
    vector<Anime> allAnimeWithGenre;
    map<int, Anime> mapOfAllWithGenre;
    vector<Anime> top5WithGenre;
    int count = 0;

    // first finds all titles that include that genre
    // and push into allAnimeWithGenre
    for (int i = 0; i < list.size(); i++) {
        vector<string> G = list[i].GetGenres();

        for (int j = 0; j < G.size(); j++) {
            if (G[j] == genre) {
                allAnimeWithGenre.push_back(list[i]);
            }
        }
    }

    // map anime by popularity
    for (int i = 0; i < allAnimeWithGenre.size(); i++) {
        mapOfAllWithGenre[allAnimeWithGenre[i].GetPopularity()] = allAnimeWithGenre[i];
    }

    // push back the top 5 anime with the genre, breaks when count reaches 5
    for (auto i = mapOfAllWithGenre.begin(); i != mapOfAllWithGenre.end(); i++) {
        if (count == 5) {
            break;
        }
        top5WithGenre.push_back(i->second);
        count++;
    }

    return top5WithGenre;
}

vector<Anime> SearchYear(int year, vector<Anime> list) {
    vector<Anime> allAnime;
    map<int, Anime> map;
    vector<Anime> top5Anime;

    // first finds all titles that include the same year
    // and push into allAnime
    for (int i = 0; i < list.size(); i++) {
        int airDate = list[i].GetAirDate();
        if (airDate == year) {
            allAnime.push_back(list[i]);
        }
    }

    // map by popularity
    for (auto i : allAnime) {
        map.emplace(i.GetPopularity(), i);
    }

    // push back the top 5 anime with the genre, breaks when size of top5Anime reaches 5
    for (auto i = map.begin(); i != map.end(); i++) {
        if (top5Anime.size() == 5) {
            break;
        }
        top5Anime.push_back(i->second);
    }

    return top5Anime;
}