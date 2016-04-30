# Munoz_CSCI2270_FinalProject
###Project	Summary
The program creates playlists of songs of different genres of music with songs the user inputs. The user can add a song by inputing the title and genre of music it is
considered to be, based on the user's judgement.The user can also deltes songs, delete an entire playlist or delete all playlists. The user can also
print out all the songs in one playlist, all playlists, or specific information about a single song. The program works by creating an array of linked lists. Currently there
is no order to the linked list(which acts like the playlist) but I plan on adding some kind of order based on user input.
###How	to	Run
If you are looking at this before I am able to get a zipped folder of the files unfortunately it's sort of a pain to get this working. You will have to either create a new project with the main and Playlist class files or copy and paste the code from these files into a new project. You can get the Playlist.h file from the include folder and the Playlist.cpp from the src folder.
###Dependencies
N/A
###System	Requirements
This code should run for any machine running CodeBlocks.
###Group	Members
This is a solo project.
###Contributors
N/A
###Open	issues/bugs
I still have to implement more user safe guards(prevents the code from running if the user inputs an invalid value) There is
also an issue with the delete destructor where sometimes add then imediately deleting a song causes a seg fault upon exiting program.
I'm sure there are other issues similar to this that I have yet to weed out. Also, any recomendations on how to organize the play lists 
are welcome!
