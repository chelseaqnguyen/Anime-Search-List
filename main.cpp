#include "Sorting.h"
#include "Anime.h"
#include "Parse.h"
#include "Search.h"
#include <ctime>
#include <iomanip>

int main()
{
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "                          _____                                                     " << endl;
    cout << "                         |_   _|                                                    " << endl;
    cout << "                           | | ___  __ _ _ __ ___                                   " << endl;
    cout << "                           | |/ _ \\/ _` | '_ ` _ \\                                  " << endl;
    cout << "                           | |  __/ (_| | | | | | |                                 " << endl;
    cout << "                           \\_/\\___|\\__,_|_| |_| |_|                                 " << endl;
    cout << "  _____           _   _____           _   _____ _                             _     " << endl;
    cout << " |_   _|         (_) |_   _|         (_) /  __ \\ |                           ( )    " << endl;
    cout << "   | | ___  _ __  _    | | ___  _ __  _  | /  \\/ |__   ___  _ __  _ __   __ _|/ ___ " << endl;
    cout << "   | |/ _ \\| '_ \\| |   | |/ _ \\| '_ \\| | | |   | '_ \\ / _ \\| '_ \\| '_ \\ / _` | / __|" << endl;
    cout << "   | | (_) | | | | |   | | (_) | | | | | | \\__/\\ | | | (_) | |_) | |_) | (_| | \\__ \\" << endl;
    cout << "   \\_/\\___/|_| |_|_|   \\_/\\___/|_| |_|_|  \\____/_| |_|\\___/| .__/| .__/ \\__,_| |___/" << endl;
    cout << "             ___        _                  _____           | |   | | _              " << endl;
    cout << "            / _ \\      (_)                /  ___|          |_|   |_|| |             " << endl;
    cout << "           / /_\\ \\_ __  _ _ __ ___   ___  \\ `--.  ___  __ _ _ __ ___| |__           " << endl;
    cout << "           |  _  | '_ \\| | '_ ` _ \\ / _ \\  `--. \\/ _ \\/ _` | '__/ __| '_ \\          " << endl;
    cout << "           | | | | | | | | | | | | |  __/ /\\__/ /  __/ (_| | | | (__| | | |         " << endl;
    cout << "           \\_| |_/_| |_|_|_| |_| |_|\\___| \\____/ \\___|\\__,_|_|  \\___|_| |_|         " << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    cout << endl;

    cout << "------------------Welcome to Team Toni Toni Choppa's Anime Search!------------------" << '\n';
    cout << '\n' << "Loading in anime dataset now, please wait..." << '\n' << '\n';

    // load in dataset
    vector<Anime> list1, list2;
    Load(list1, list2);

    // display the run times for both radix and quick sort
    cout << "Using radix and quick sort to sort our dataset now, please wait..." << '\n';
    cout << "Time taken to execute (RADIX SORT): ";

    clock_t startRadix = clock();
    RadixSort(list1);
    clock_t endRadix = clock();

    double RADIX_cpu_time_used = ((double)(endRadix - startRadix)) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(8) << RADIX_cpu_time_used << " seconds!" << '\n';
    cout << "Time taken to execute (QUICK SORT): ";

    clock_t startQuick = clock();
    QuickSort(list2, 0, list2.size() - 1);
    clock_t endQuick = clock();

    double QUICK_cpu_time_used = ((double)(endQuick - startQuick)) / CLOCKS_PER_SEC;

    cout << fixed << setprecision(8) << QUICK_cpu_time_used << " seconds!" << '\n';

    // Menu Start
    bool run = true;
    string menuSelection;

    while (run) {
        cout << '\n';
        cout << "-----------------------------------MENU SELECTION-----------------------------------" << "\n";
        cout << "0: Exit" << "\n";
        cout << "1: Search keyword/title" << "\n";
        cout << "2: Search genre" << "\n";
        cout << "3: Search top 5 Anime in a Year" << '\n' << '\n';
        cout << "Select menu option (type 0, 1, 2, or 3): ";
        cin >> menuSelection;
        cout << '\n';

        // Keyword/anime name search into diplaying top 5 anime in user search
        if (menuSelection == "1") {
            string keyword = "";
            vector<Anime> animeWithKW;

            animeWithKW.clear();
            cout << "What keyword/title would you like to search?" << endl;

            cin.ignore();
            getline(cin, keyword);

            animeWithKW = SearchKeyword(keyword, list1);

            if (!animeWithKW.empty()) {
                cout << '\n' << "Finding most popular anime with " << "\"" << keyword << "\"" << "..." << '\n' << '\n';

                for (int i = 0; i < animeWithKW.size(); i++) {
                    cout << "Title: " << animeWithKW[i].GetTitle() << '\n';
                    cout << "   ⭒ Genre(s): ";

                    if (animeWithKW[i].GetGenres().size() != 0) {

                        for (int j = 0; j < animeWithKW[i].GetGenres().size(); j++) {

                            if (j == animeWithKW[i].GetGenres().size() - 1) {
                                cout << animeWithKW[i].GetGenres().at(j) << '\n';

                                break;
                            }
                            cout << animeWithKW[i].GetGenres().at(j) << ", ";
                        }
                    }
                    else {
                        cout << "none found" << '\n';
                    }

                    cout << "   ⭒ Number of Episodes: " << animeWithKW[i].GetEpisodes() << '\n';
                    cout << "   ⭒ Score: " << fixed << setprecision(2) << animeWithKW[i].GetScore() << '\n';
                    cout << "   ⭒ Release Year: " << animeWithKW[i].GetAirDate() << '\n';
                }

            }
            else {
                cout << "No titles available with your search!" << '\n';
            }
        }

            // genre Search into diplaying top 5 anime in the genre
        else if (menuSelection == "2") {
            string genre = "";
            vector<Anime> animeWithKW;

            animeWithKW.clear();

            cout << "What genre would you like to search?" << endl;
            cout << "When searching genre, be sure to capitalize the first letter (i.e. Romance)" << endl;

            cin.ignore();
            getline(cin, genre);

            animeWithKW = SearchGenre(genre, list1);

            if (!animeWithKW.empty()) {
                cout << '\n' << "Finding most popular anime with " << "\"" << genre << "\"" << "..." << '\n' << '\n';

                for (int i = 0; i < animeWithKW.size(); i++) {
                    cout << "Title: " << animeWithKW[i].GetTitle() << '\n';
                    cout << "   ⭒ Genre(s): ";

                    if (animeWithKW[i].GetGenres().size() != 0) {

                        for (int j = 0; j < animeWithKW[i].GetGenres().size(); j++) {

                            if (j == animeWithKW[i].GetGenres().size() - 1) {
                                cout << animeWithKW[i].GetGenres().at(j) << '\n';

                                break;
                            }
                            cout << animeWithKW[i].GetGenres().at(j) << ", ";
                        }
                    }
                    else {
                        cout << "none found" << '\n';
                    }

                    cout << "   ⭒ Number of Episodes: " << animeWithKW[i].GetEpisodes() << '\n';
                    cout << "   ⭒ Score: " << fixed << setprecision(2) << animeWithKW[i].GetScore() << '\n';
                    cout << "   ⭒ Release Year: " << animeWithKW[i].GetAirDate() << '\n';
                }

            }
            else {
                cout << "No titles available with your search!" << '\n';
            }
        }

            // year search into displaying the top 5 aninme in a given year
        else if (menuSelection == "3") {
            regex regexMatch = regex("^[0-9]{4}");
            string year = "";
            vector<Anime> animeWithKW;

            animeWithKW.clear();

            cout << "What year would you like to search?" << endl;

            cin.ignore();
            getline(cin, year);

            if (regex_match(year, regexMatch) == 1) {
                animeWithKW = SearchYear(stoi(year), list1);

                if (!animeWithKW.empty()) {
                    cout << '\n' << "Finding most popular anime with year " << "\"" << year << "\"" << "..." << '\n' << '\n';

                    for (int i = 0; i < animeWithKW.size(); i++) {
                        cout << "Title: " << animeWithKW[i].GetTitle() << '\n';
                        cout << "   ⭒ Genre(s): ";

                        if (animeWithKW[i].GetGenres().size() != 0) {

                            for (int j = 0; j < animeWithKW[i].GetGenres().size(); j++) {

                                if (j == animeWithKW[i].GetGenres().size() - 1) {
                                    cout << animeWithKW[i].GetGenres().at(j) << '\n';

                                    break;
                                }
                                cout << animeWithKW[i].GetGenres().at(j) << ", ";
                            }
                        }
                        else {
                            cout << "none found" << '\n';
                        }

                        cout << "   ⭒ Number of Episodes: " << animeWithKW[i].GetEpisodes() << '\n';
                        cout << "   ⭒ Score: " << fixed << setprecision(2) << animeWithKW[i].GetScore() << '\n';
                        cout << "   ⭒ Release Year: " << animeWithKW[i].GetAirDate() << '\n';
                    }

                }
                else {
                    cout << "No titles available with your search!" << '\n';
                }
            }
            else {
                cout << "ERROR: not a valid year!" << '\n';
            }
        }

            // end the program
        else if (menuSelection == "0") {

            // Admire Choppa and all of his beauty
            cout << "⠀⠀⠀⠀⣀⠀⠀⢠⡀⣤⣀⣤⣄⣀⣠⣤⣤⣄⣴⣀⣤⣶⣶⣶⣤⣤⣤⣤⣴⣴⣶⣶⣶⣶⣠⣤⣀⣀⣤⣶⣦⣖⣶⣖⣄⣀⠤⠂⢤⣠⣤⢀⣀⡀" << endl;
            cout << "⣰⣿⣷⣾⣷⣳⠀⠙⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣾⣳⣿⣿⣿⣷⣿⣿⣿⣶⢿⣿⣿⣿⣿⠀⠀⠈⣾⣻⣿⣿⣾" << endl;
            cout << "⢾⣿⣽⣿⣿⡇⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⡿⡿⣷⢶⣶⣶⣶⣶⡶⣶⣶⣶⣶⣶⣶⣶⣶⣤⣴⡴⡆⢸⣿⣷⣿⡾⠀⠀⠠⣿⣗⣿⢿⡽" << endl;
            cout << "⠙⣿⣟⣿⣿⣿⣂⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣶⢸⣿⣻⣯⣿⣵⣤⣾⣿⣿⣿⣿⠇" << endl;
            cout << "⠀⠙⢿⣟⣻⣿⣿⣿⣿⣿⣿⣻⠯⣷⣟⣿⣿⣿⣟⣗⣷⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣗⣿⣟⣿⣻⣿⣿⡟⠁⠹⠻⣎⣿⣟⣿⣿⣿⣿⣳⡛⠃⠀" << endl;
            cout << "⠀⠀⠈⠛⢻⢿⣿⣿⣿⡞⠋⠀⢰⣿⣿⣿⣿⣷⣿⣿⣾⡿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣟⣿⣿⣿⡻⣿⣿⣗⠇⠰⣠⡴⠊⢓⣶⡷⠿⠛⠋⠉⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠈⠻⣿⣷⣷⣶⣾⣿⣿⣿⣿⣿⡿⣿⣿⡯⣿⣿⠍⠽⡿⡿⣿⠟⠽⣯⢿⣿⣿⣿⣿⣿⣯⠀⢾⣽⣿⣥⣿⣋⣠⣤⡄⡀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⢰⣾⣿⣿⣿⠻⠿⠿⠟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⡀⠀⠈⠛⠉⢀⡴⣾⣿⣽⣿⣿⣿⣿⣽⠀⠏⠙⢉⡙⢓⣛⣻⣿⢿⣿⡃⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⣺⣿⣿⣿⡟⣮⣄⣰⣾⣟⣿⣿⣿⣿⣿⠿⣟⣿⣷⣿⢿⣟⠖⠀⠀⠀⠙⠺⣿⣿⣿⣿⣿⣾⣿⣗⢲⣿⣶⣶⣤⣴⣾⣿⣿⣿⣿⣿⠂⠀⠀" << endl;
            cout << "⠀⠀⠀⠹⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣥⠀⣠⣶⣶⣄⢀⣾⣷⢾⣿⣾⣿⣿⣗⣿⣿⣿⣶⣾⡿⢓⣥⣿⣿⣿⠟⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠑⠿⣿⣿⣿⣿⣯⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣶⣿⣿⣿⣿⡯⠅⡀⣤⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠉⠙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⣍⣭⣬⣭⣭⣭⣽⣯⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⡿⠿⠿⠛⠁⣴⠋⣠⡊⠀⢨⡣⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿⣿⡿⢟⠋⠁⠀⠀⣤⣾⣿⣧⣷⡾⣷⣾⣷⡷⡆" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡿⣻⠏⢇⠸⣿⣿⣿⢛⠻⠟⠝⠟⠫⠻⠛⠉⢿⣿⡿⢗⢠⠁⡰⡠⠊⠀⠀⢀⣾⣿⣿⡿⡿⠛⣛⣿⣿⣿⡿⠁" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣯⠧⠛⠓⠂⠐⠂⠀⠀⠰⠒⠒⠒⠤⠒⠤⠂⠀⠒⠂⢁⣈⠱⠁⠀⠀⠀⣸⡿⠿⠛⠋⠀⢠⠟⣿⠿⠗⠇⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣄⠀⠀⠀⠀⢠⣴⣶⣶⣖⣖⣦⠉⠁⠀⢀⣤⣾⣿⣧⣶⣤⡄⣤⣤⡏⠀⡀⣀⣀⣀⠈⠈⣯⣔⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢙⣳⣦⡄⠀⠈⠋⠻⢿⠿⠛⠁⠀⢀⣤⣾⣿⣿⠛⠁⠀⠈⠀⠀⣻⠶⢿⡿⠿⠿⠿⣶⣶⣾⡋⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣿⣿⣷⣶⣤⣤⣬⣦⣠⣤⣾⡿⠁⠉⣿⣿⣾⣶⣿⣿⣿⣿⣷⣶⣾⣿⣷⣶⠀⣰⣾⣯⣵⡴⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢞⣿⣿⣿⡿⣿⣿⣿⣿⣿⡿⣿⣿⠏⠋⠀⣤⣤⠻⣿⣿⢿⡿⠿⣿⣿⣿⣿⣿⣿⡛⠃⠀⠿⠿⢿⠟⠁⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡾⢫⣾⣿⣟⣷⠚⢃⢐⠟⠙⠂⠀⠈⠀⠀⠐⠋⢁⡀⡺⣟⣿⣻⣆⡀⣾⣿⣿⣿⣃⠙⠳⠶⠶⠖⠐⠒⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⣛⣴⣿⣿⣿⣿⡏⠀⠘⠻⠄⣧⣦⢀⠀⠀⢠⡤⠈⠿⠓⠀⠈⠛⣿⣿⣿⣿⣿⣿⣿⡿⡢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⢀⠺⢥⠏⠁⢸⣿⣯⡝⠀⠀⠀⠀⠀⠀⠀⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣿⣿⣿⣿⣯⠍⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⡠⢊⡁⣾⣏⠀⠀⢻⣿⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡝⣿⣿⣿⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠐⡕⠁⠀⢬⣿⠀⢀⣾⣿⣯⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⢐⡇⣺⢿⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⢳⠂⠀⠀⢙⠋⠀⠸⣿⣿⣿⣷⣤⣶⣴⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣾⣿⣷⣷⣶⡫⣿⠷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⢽⣷⣤⣾⡿⠀⠀⠈⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠉⠟⠃⠀⠀⠀⠠⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⣿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠉⠉⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡻⣯⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⡿⠁⠀⠀⠀⠀⠈⠻⣿⣿⣿⣿⣿⣿⣿⣯⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢛⣿⣿⣿⡿⠿⠿⠃⠀⠀⠀⠀⠀⠀⠀⢻⢿⣿⣟⠛⢛⠛⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡏⢉⠅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢐⣎⠍⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣾⠿⠿⠦⢴⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢈⠵⠒⠂⠅⢂⠤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣾⣿⣿⣿⣿⣦⣄⣀⠐⣷⡧⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣯⣶⣶⣶⠦⣴⣾⣶⣷⠤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
            cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠙⠛⠛⠛⠛⠛⠋⠉⠉⠈⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⠛⠛⠛⠛⠂⠛⠓⠛⠛⠂⠑⠀⠀⠀⠀⠀⠀     " << endl;

            cout << "Thank you for using team Toni Toni Choppa's Anime search! 良い一日を過ごしてください.";
            run = false;
        }
        else {
            cout << "ERROR: Choose a valid menu selection!" << '\n';
        }
    }

    return 0;
}