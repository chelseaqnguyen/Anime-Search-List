#pragma once
#include "Anime.h"
#include <fstream>
#include <sstream>
#include <regex>

// loads in values from dataset
void Load(vector<Anime>& list1, vector<Anime>& list2)
{
    ifstream inFile;

    inFile.open("animes.csv");

    if (inFile.is_open()) {
        string lineByLine;
        getline(inFile, lineByLine);

        while (getline(inFile, lineByLine)) {
            istringstream stream0(lineByLine);

            // Parses for the title of the anime
            string title;

            getline(stream0, title, ',');


            // Parses for all genres for a given anime (Format: ['genre-0', 'genre-1', 'genre-2', ... , 'genre-N'])
            string genres;
            regex containsAlpha = regex("[a-zA-Z]*");

            getline(stream0, genres, ']');

            // input stream: ['genre-0', 'genre-1', 'genre-2', ... , 'genre-N']
            istringstream stream1(genres);
            vector<string> totalGenres;
            string genreName;
            string throwAway;
            string genre;

            // 'genre-0', 'genre-1', 'genre-2', ... , 'genre-N']
            getline(stream1, throwAway, '[');

            while (getline(stream1, genreName, ',')) {
                // input stream: 'genre-i'
                istringstream stream3(genreName);

                getline(stream3, throwAway, '\''); // genre-i'
                getline(stream3, genre, '\''); // genre-i

                if (regex_match(genre, containsAlpha) == 1) {
                    totalGenres.push_back(genre);
                }
            }

            getline(stream0, throwAway, ',');


            // gets the initial airdate for a given anime
            string date;
            string airDate;
            int year;
            regex format2 = regex("^[0-9]*[-][a-zA-Z]{3}[-][0-9]{2}$");
            regex format1 = regex("^[\"][a-zA-Z\\s]{4}[0-9]*$");
            regex format1_2 = regex("^[\"][a-zA-Z]{3}$");

            getline(stream0, date, ',');

            if (regex_match(date, format1) == 1 || regex_match(date, format1_2) == 1) {
                getline(stream0, date, '"');
                istringstream stream5(date);

                getline(stream5, throwAway, ' ');
                getline(stream5, airDate, ' ');
                getline(stream5, throwAway);

                year = stoi(airDate);

                getline(stream0, throwAway, ',');
            }
            else if (regex_match(date, format2) == 1) {
                istringstream stream4(date);

                getline(stream4, throwAway, '-');
                getline(stream4, throwAway, '-');
                getline(stream4, airDate);

                year = stoi(airDate);

                if (year >= 0 && year < 23) {
                    year = year + 2000;
                }
                else {
                    year = year + 1900;
                }
            }
            else {
                year = 4000;
            }


            // get the episode count for a given anime
            string strEpisodes;
            int episodes;

            getline(stream0, strEpisodes, ',');

            if (!strEpisodes.empty()) {
                episodes = stoi(strEpisodes);
            }
            else {
                episodes = 0;
            }


            // gets the amount of members following a given anime
            string strMembers;
            int members;

            getline(stream0, strMembers, ',');
            members = stoi(strMembers);


            // gets the popularity ranking of a given anime
            string strPopularity;
            int popularity;

            getline(stream0, strPopularity, ',');

            if (!strPopularity.empty()) {
                popularity = stoi(strPopularity);
            }
            else {
                popularity = 2000000;
            }


            // gets the score ranking of a given anime
            string strRanking;
            int ranking;

            getline(stream0, strRanking, ',');

            if (!strRanking.empty()) {
                ranking = stoi(strRanking);
            }
            else {
                ranking = 2000000;
            }


            // gets the score/rating of a given anime
            string strScore;
            double score;

            getline(stream0, strScore, ',');
            score = stof(strScore);

            Anime anime = Anime(title, totalGenres, year, episodes, members, popularity, ranking, score);

            list1.push_back(anime);
            list2.push_back(anime);
        }
    }

    // closes file
    inFile.close();
}