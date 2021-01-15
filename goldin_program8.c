/* Seth Goldin
 * COP2220 Intro to Programming in C
 * Program 8 - user defined struct
 */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include <string.h>
#include <stdio.h>
#define SIZE 20

typedef struct {
    char artist[SIZE];
    char songName[SIZE];
    int lengthInSeconds;
    int year;
}song;

//Function Prototypes

// fills the data fields of a song instance
//returns the filled song
song FillSong();

//fills the data fields of a song instance
//by reference using a pointer to a song
void FillSongPtr(song* songPtr);

//fills an array of songs
void FillSongArray(song *arrayS, int* size);

//displays one song
void DisplaySong(song anySong);

int main(){

    //Declare variables
    song mySong1, mySong2, mySong3;
    song playList[SIZE];  //playList
    int cSize;
    int i;

    //Fill structures with a function
    mySong1 = FillSong();
    mySong2 = FillSong();

    //print using display function
    printf("\n---------Display mySong1\n");
    DisplaySong(mySong1);
    printf("\n---------Display mySong2\n");
    DisplaySong(mySong2);

    //Fill structure using pointers and display it
    FillSongPtr(&mySong3);
    printf("\n---------Display mySong3\n");
    DisplaySong(mySong3);

    //Fill the array with the function
    printf("\n---------Fill array playList\n");
    FillSongArray(playList, &cSize);

    //display an array of songs
    printf("\n---------Display array playList\n");
    for (i = 0; i < cSize; i++){
        DisplaySong(playList[i]);
    }
    return 0;
}

//Function Definitions

// fills the data fields of a song instance
//returns the filled song
song FillSong(){
    //Declare local variables
    song tempS;
    //prompt and get information
    printf("\nplease enter the name of your song:  ");
    scanf("%s", tempS.songName);
    //print to check
    printf("Song Name:  %s\n", tempS.songName);

    //prompt and get information
    printf("\nplease enter the artist of your song:  ");
    scanf("%s", tempS.artist);
    //print to check
    printf("Artist:  %s\n", tempS.artist);

    //prompt and get information
    printf("\nplease enter the length of your song (in seconds):  ");
    scanf("%d", &tempS.lengthInSeconds);
    printf("Length (in seconds):  %d\n", tempS.lengthInSeconds);

    //prompt and get information
    printf("\nplease enter the year the song was released:  ");
    scanf("%d", &tempS.year);
    printf("Year:  %d\n", tempS.year);
    return tempS;
}



//displays one song
void DisplaySong(song anySong){
    printf("\n\nName:  %s\n", anySong.songName);
    printf("Artist:  %s\n", anySong.artist);
    printf("Length (in seconds):  %d\n", anySong.lengthInSeconds);
    printf("Year released:  %d\n", anySong.year);
}


//fills the data fields of a song instance
//by reference using a pointer to a song
void FillSongPtr(song* songPtr){
    //prompt and get information
    printf("\nplease enter the name of your song:  ");
    scanf("%s", (*songPtr).songName);

    //prompt and get information
    printf("\nplease enter the artist of your song:  ");
    scanf("%s", songPtr->artist);

    //prompt and get information
    printf("\nplease enter the length (in seconds) of your song:  ");
    scanf("%d", &(*songPtr).lengthInSeconds);

    //prompt and get information
    printf("\nplease enter the year the song was released:  ");
    scanf("%d", &(*songPtr).year);
}


//fills an array of songs
void FillSongArray(song *arrayS, int* size){
    int i;
    //prompt the user
    printf("\nEnter the number of songs:  ");
    scanf("%d", size);

    //print to check
    printf("Size:  %d\n", *size);

    for (i = 0; i < *size; i++){
        printf("enter song name:  ");
        scanf("%s", arrayS[i].songName);

        printf("enter artist:  ");
        scanf("%s", arrayS[i].artist);

        printf("enter length (in seconds):  ");
        scanf("%d", &arrayS[i].lengthInSeconds);

        printf("enter year released:  ");
        scanf("%d", &arrayS[i].year);
    }
}
