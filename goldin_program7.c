// pluralize program
// Seth Goldin, 11/23/20
// fall 2020 program 7

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h>
#include<ctype.h>
#include<string.h>

// function prototypes go here

// A function that greets the user and gets the first name of the user
void Greeting();
// A function that gets the word from the user and makes a copy of the word
void GetWord(char word[], char plural[]); //character arrays
// changes a string (character array with '\0') to all uppercase
void Uppercaseword(char plural[]);
// A function that determines which rule applies to the word.
void WhichRule(char plural[]);
// 3 more functions, one for each rule - apply the given rule
void RuleOne(char plural[]);
void RuleTwo(char plural[]);
void RuleThree(char plural[]);

int main(){
    // 3 character arrays, size 25: word, plural, name
    char word[25];
    char plural[25];
    char firstname[25];
    // a char for while loop
    char again;
    // call the greeting function to greet and get name
    Greeting(firstname);
    printf("\n----------------------------------------\n");
    // ask and get input, does the user want to enter a (loop initialization)
    printf("%s, \nWould you like to enter a word? Y (YES) or N (NO)?\n", firstname);
    scanf(" %c", &again);
    // begin while loop (loop test)
    while (toupper(again) == 'Y'){
        // Ask, get, and copy the word
        GetWord(word, plural);
        // make the plural word all uppercase letters
        Uppercaseword(plural);
        // determine which rule
        WhichRule(plural);
        printf("\nPrinting both words in the main function:\n\n");
        // print word and plural onto the screen
        printf("Original word: %s \nPlural version: %s", word, plural);
        printf("\n----------------------------------------\n");
        // again? (loop update)
        printf("%s, \nWould you like to enter a word? Y (YES) or N (NO)?\n", firstname);
        scanf(" %c", &again);
    }
    printf("\nThank you for trying out the Pluralizer, %s!\n", firstname);
    return 0;
}

// greets the user and gets name
void Greeting(char name[]) {
    printf("What is your first name?\n");
    scanf(" %s", name);
    printf("*** Welcome to the Pluralizer ***\n");
}
// gets the word from the user and makes a copy
void GetWord(char word[], char plural[]){
    printf("Enter a word:\n");
    scanf(" %s", word);
    strcpy(plural, word);
}

// changes a string (character array with '\0') to all uppercase
void Uppercaseword(char plural[]){
    int i;
    for (i = 0; i < strlen(plural); i++){
        plural[i] = toupper(plural[i]);
    }
}

// determines which rule applies and calls the correct function
void WhichRule(char plural[]){
    char lastLetter = plural[strlen(plural) - 1];
    char secLastLetter = plural[strlen(plural) - 2];

    if (lastLetter == 'Y'){
        printf("\nRule is 1");
        //call the function to apply Rule 1
        RuleOne(plural);
    } else if ((lastLetter == 'S') || (lastLetter == 'X') || (lastLetter == 'Z')){
        printf("\nRule is 2");
        //call the function to apply Rule 2
        RuleTwo(plural);
    } else if (lastLetter == 'H' && (secLastLetter == 'C' || secLastLetter == 'S')){
        printf("\nRule is 2");
        //call the function to apply Rule 2
        RuleTwo(plural);
    } else {
        printf("\nRule is 3");
        //call the function to apply Rule 3
        RuleThree(plural);
    }
}

// Rule1: If the word ends in ‘Y’, remove the ‘Y’ and add “IES”
void RuleOne(char plural[]){
    plural[strlen(plural) - 1] = '\0';
    strcat(plural, "IES");
}

// Rule 2: If the word ends in ‘S’, “CH”, “SH”, ‘X’, or ‘Z’ – add “ES”
void RuleTwo(char plural[]){
   strcat(plural, "ES");
}

// Rule 3: any word that does not fit in Rule 1 or Rule 2 - add "S"
void RuleThree(char plural[]){
   strcat(plural, "S");
}


