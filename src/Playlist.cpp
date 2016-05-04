#include "Playlist.h"

Playlist::Playlist()//initializes the array as all NULL
{
    for(int i = 0; i < numPlaylist; i++)
    {
        songList[i] = NULL;
    }
}

Playlist::~Playlist()//deletes all nodes before exiting
{
    clearPlaylists();
}

void Playlist::insertSong(string in_title, int in_genre, double in_length)//creates a new song and places it into the correct genre playlist
{
    if(in_genre > 10 || in_genre < 0)//checks to see if the user inputed a valid genre number
    {
        cout<<"Invalid genre."<<endl;
        return;
    }
    string genreTmp = genreConversion(in_genre);//converts the int genre into a string genre(ex. 0 becomes Alternative Rock)
    if(songList[in_genre] == NULL)//if there are no songs already in the playlist destination add this to the start of the linked list
    {
        songList[in_genre] = new Song(in_title, in_genre, in_length);
        cout<<in_title<<" added to the "<<genreTmp<<" playlist and is the first song."<<endl;
    }
    else//if there are already songs in the list, do this
    {
        Song *tmp = songList[in_genre];//creates a temp pointer that starts are the head of the list
        while(tmp->next)//as long as there is a next value in the list, continue moving down the list
        {
            tmp = tmp->next;
        }
        tmp->next = new Song(in_title, in_genre, in_length);//the loop will exit when there is not a song next and add the new song to the end of the list
        cout<<in_title<<" added to the "<<genreTmp<<" playlist."<<endl;
    }
}

void Playlist::removeSong(string in_title, int in_genre)//deletes a song from a playlist
{
    if(in_genre > 11 || in_genre < 0)//checks to see if the user inputed a valid genre
    {
        cout<<"Invalid genre."<<endl;
        return;
    }
    if(in_genre == 11)//11 means the user does not know what the genre of the song is
    {
        in_genre = findGenre(in_title);//calls a function that searches the lists to find the genre of the song
        if(in_genre == 11)//if the genre is still 11 after searching all elements, the song does not exist
        {
            cout<<"Song not found."<<endl;
            return;
        }
    }

    Song *tmp = songList[in_genre];//creates a temp pointer that points to the start of the playlist
    if(tmp == NULL)//
    {
        cout<<"Song not found."<<endl;
        return;
    }
    else
    {
        while(tmp)//runs through every song in the playlist
        {
            if(tmp->title == in_title)//if a match is found. sets the previous and next values appropriately so the song can be deleted
            {
                if(tmp->prev)
                {
                    tmp->prev->next = tmp->next;
                }
                else
                {
                    songList[in_genre] = tmp->next;
                }

                if(tmp->next)
                {
                    tmp->next->prev = tmp->prev;
                }

                string genreTmp = genreConversion(tmp->genre);//gets the string genre of the song being deleted
                cout<<"Deleted: "<<tmp->title<<" from the "<<genreTmp<<" playlist."<<endl;
                delete tmp;
                return;
            }
            tmp = tmp->next;
        }
    }
}

int Playlist::findGenre(string in_title)
{
    Song *tmp;//creates a temp pointer
    for(int i = 0; i < numPlaylist; i++)//runs through each playlist in the array
    {
        tmp = songList[i];//sets temp to the start of each playlist
        while(tmp)//as long as temp exists
        {
            if(tmp->title == in_title)//if you find a match
            {
                return tmp->genre;//returns the genre of the song
            }
            tmp = tmp->next;
        }
    }
    return 11;//returns 11 if the song is not found
}

void Playlist::displayGenres()//prints out the genre options for the user
{
    cout<<"======Genres======"<<endl;
    cout<<"0. Alternative Rock"<<endl;
    cout<<"1. Blues"<<endl;
    cout<<"2. Country"<<endl;
    cout<<"3. Dubstep"<<endl;
    cout<<"4. ChillStep"<<endl;
    cout<<"5. Dance"<<endl;
    cout<<"6. Hip-Hop"<<endl;
    cout<<"7. Rap"<<endl;
    cout<<"8. Instrumental"<<endl;
    cout<<"9. Pop"<<endl;
    cout<<"10. Unknown"<<endl;
    cout<<endl;
}

void Playlist::deletePlaylist(int in_genre)
{
	Song *p = songList[in_genre];
    Song *head = songList[in_genre];
    string genre = genreConversion(in_genre);
    while(p)
    {
        cout<<"Deleted: "<<p->title<<" from the "<<genre<<" playlist."<<endl;
		p = p->next;
    }
	songList[in_genre] = NULL;
}

void Playlist::printPlaylist(int in_genre)//prints all songs in a playlist
{
    int counter = 1;//used to count the number of songs in a playlist
    Song *tmp = songList[in_genre];//creates a temp pointer that points to the start of the desired playlist
    if(tmp == NULL)//if its NULL the playlist does not yet exist
    {
        cout<<"Playlist is Empty"<<endl;
    }
    else
    {
        double duration = playListDuration(in_genre);//calls a function that calculates the length of the playlist
        cout<<"Playist is "<<duration<<" minutes long and contains:"<<endl;
        while(tmp)//prints out all the songs in the playlist and its info
        {
            cout<<counter<<". "<<tmp->title<<endl;
            counter++;
            tmp = tmp->next;
        }
    }
}

void Playlist::findSong(string in_title)//searches the playlists for a song and prints the information for the song
{
    int genre = findGenre(in_title);//finds the genre of the song(index of the array)
    if(genre == 11)//if the genre is 11 there is no song
    {
        cout<<"Song Not Found"<<endl;
        return;
    }
	else{
		string genreTmp = genreConversion(genre);//converts the genre from an int to a string
		cout<<"Found "<<in_title<<" in the genre of "<<genreTmp<<" and is "<<songList[genre]->time<<" minutes long."<<endl;
	}
		
}

double Playlist::playListDuration(int in_genre)//calculates the length of a playlist
{
    double duration = 0;
    Song *tmp = songList[in_genre];//starts at the beginning of the playlist
    while(tmp)//as long as there are songs left
    {
        duration = duration + tmp->time;//adds up the length of each song
        tmp = tmp->next;
    }
    return duration;
}

string Playlist::genreConversion(int in_genre)//used to convert the int genre into the string genre
{
    if(in_genre == 0)
    {
        return "Alternative Rock";
    }
    else if(in_genre == 1)
    {
        return "Blues";
    }
    else if(in_genre == 2)
    {
        return "Country";
    }
    else if(in_genre == 3)
    {
        return "Dubstep";
    }
    else if(in_genre == 4)
    {
        return "ChillStep";
    }
    else if(in_genre == 5)
    {
        return "Dance";
    }
    else if(in_genre == 6)
    {
        return "Hip-Hop";
    }
    else if(in_genre == 7)
    {
        return "Rap";
    }
    else if(in_genre == 8)
    {
        return "Instrumental";
    }
    else if(in_genre == 9)
    {
        return "Pop";
    }
    else if(in_genre == 10)
    {
        return "Unknown";
    }
}

void Playlist::clearPlaylists()//deletes all songs in the array
{
    for(int i = 0; i < numPlaylist; i++)//runs through each playlist(index) in the array
    {
        delete songList[i];
    }

}
