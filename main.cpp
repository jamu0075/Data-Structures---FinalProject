#include <iostream>
#include "Playlist.h"

using namespace std;

int main()
{
    Playlist newPlaylist;//creates a playlist class
    int operation = 0;//used to determine what the user wants to do
    string in_title;//used as an input title for adding/removing/ect.
    int in_genre;//used as an input genre of music
    double in_length;//the length of a song
    string temp;
    bool add;

    while(operation != 7)
    {
        cout<<endl;
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Insert Song"<<endl;
        cout<<"2. Delete Song"<<endl;
        cout<<"3. Find Song Info"<<endl;
        cout<<"4. Print a Playlist"<<endl;
        cout<<"5. Delete a Playlist"<<endl;
        cout<<"6. Clear all Playlists"<<endl;
        cout<<"7. Quit"<<endl;

        cin>>operation;
        cin.ignore(1000, '\n');

        if(operation == 1)//takes user inputs to add a song to a playlist
        {
            cout<<"Enter the song title you want to enter: ";
            getline(cin, in_title);
            newPlaylist.displayGenres();//displays the different genre choices
            cout<<"Enter the genre that best suites your song(enter the number): ";
             //mljunker, changed to while loop to not allow user to input anything but a valid genre number
             //also took out of insert song function
            getline(cin,temp);
            in_genre = atoi(temp.c_str());
            while(in_genre > 10 || in_genre < 0)//checks to see if the user inputed a valid genre number
            {
                cout<<"Invalid genre."<<endl;
                cout<<"Please input valid genre"<<endl;
                getline(cin,temp);
                in_genre = atoi(temp.c_str());
            }
            cout<<"Enter and estimated song length in the format x.xx(0 if you have no clue): ";
            getline(cin,temp);
            //returns false if any letter characters besides "."
            add = newPlaylist.asciicheck(temp);
            if(add){
                in_length = stod(temp.c_str(),NULL);
            }
            else{
                in_length = 0;
                cout<<"That song length was invalid, adding as 0";
            }
            cout<<endl;
            newPlaylist.insertSong(in_title, in_genre, in_length);//calls the insert song function
        }
        else if(operation == 2)//takes a user input for a song to remove
        {
            cout<<"Enter the song you want to remove: ";
            getline(cin, in_title);
            cout<<"Enter the genre the song was entered in, if you don't know enter 11: ";
            cin>>in_genre;
            cout<<endl;
            newPlaylist.removeSong(in_title, in_genre);
        }
        else if(operation == 3)//searches for a song and displays information about the song
        {
            cout<<"Enter the song you want to look up: ";
            getline(cin, in_title);
            cout<<endl;
            newPlaylist.findSong(in_title);
        }
        else if(operation == 4)//displays the songs in a playlist
        {
            newPlaylist.displayGenres();
            cout<<"Enter the playlist you want to see: ";
            cin>>in_genre;
            cout<<endl;
            newPlaylist.printPlaylist(in_genre);
        }
        else if(operation == 5)
        {
            newPlaylist.displayGenres();
            cout<<"Enter the playlist you want to delete: ";
            cin>>in_genre;
            newPlaylist.deletePlaylist(in_genre);
        }
        else if(operation == 6)//deletes all songs in all playlists
        {
            newPlaylist.clearPlaylists();
        }
        else if(operation == 7)
        {
            cout<<"==================="<<endl;
            cout<<"CLEARING PLAYLISTS"<<endl;
            cout<<"==================="<<endl;
        }
    }
}
