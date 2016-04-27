#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream>

using namespace std;

struct Song
{
    string title;//song title
    int genre;//song genre
    double time;//song length
    Song *next;
    Song *prev;

    Song(){};
    Song(string in_title, int in_genre, double in_time)
    {
        title = in_title;
        genre = in_genre;
        time = in_time;
        next = NULL;
        prev = NULL;
    }
};

class Playlist
{
    public:
        Playlist();
        ~Playlist();
        void insertSong(string in_title, int in_genre, double in_length);
        void removeSong(string in_title, int in_genre);
        void displayGenres();
        void deletePlaylist(int in_genre);
        int findGenre(string in_title);
        void findSong(string in_title);
        void printPlaylist(int in_genre);
        double playListDuration(int in_genre);
        string genreConversion(int in_genre);
        void clearPlaylists();

    private:
        static const int numPlaylist = 11;//number of elements in the array of genres
        Song* songList[numPlaylist];
};

#endif // PLAYLIST_H
