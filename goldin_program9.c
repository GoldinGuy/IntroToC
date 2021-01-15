//program 9 (larger program)
//Seth Goldin | 12/1/20 | fall 2020 program 9
//motocross list

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings for Visual Studio compiler
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 50 //size of the list

typedef struct {
    int id;
    int model;
    char brand[SIZE];
    char color[SIZE];
    double dealerCost;
    double customerPrice;
}bike;

//function prototypes

//Greets the user
void Greeting();

//hardcode seven (5) valid records – one argument, the list
void SetInitialRecords(bike list[]);

//runs the menu and gets the user choice
//– no arguments, return a character
char RunMenu();

//prints the contents of the list onto the screen
//– 2 arguments(list and count)
void PrintBikeList(bike list[], int *count);

//adds a bike to the list
//- 2 arguments(list and count)
void AddBike(bike list[], int *count);

//Delete function, this function will be called when the user
//selects D. This function will call the Display Id function and the Search function
//– 2 arguments (list, count), void return type
void DeleteBike(bike list[], int *count);

//displays the ids in the list, gets the id from the user and return it
//– 2 arguments(list and count), returns an integer(id)
int DisplayBikeIDs(bike list[], int *count);

//searches the list by id and returns the index, if there is a match or returns 100
//if there is no match (the maximum size of the list is 25)
// - 3 arguments (list, number of items, id), returns location
int SearchBike(bike list[], int *count, int id);

// clears list when user enters "C"
void ClearList(bike list[], int *count);

int main(){
    //declare the bike list
    bike list[SIZE];
    //declare and initialize count to 0
    int count = 0;
    //character for the menu choice
    char menuChoice;
    //greet the user
    Greeting();
    //fill the array with 5 bikes
    SetInitialRecords(list);
    //set count to 5
    count = 5;
    //begin the do/while loop
    do {
        menuChoice = RunMenu();
        //switch for the selections (P,A,C,D,Q)
        switch(menuChoice){
            case 'P':
                PrintBikeList(list, &count);
                break;
            case 'A':
                AddBike(list, &count);
                break;
            case 'C':
                ClearList(list, &count);
                break;
            case 'D':
                DeleteBike(list, &count);
                break;
            case 'Q':
                printf("\nThank you for using this program! Goodbye.\n");
                break;
            default:
                printf("\nInvalid Input.\n");
        }
    } while (menuChoice != 'Q');
    return 0;
}

//function definitions

//Greets the user
void Greeting(){
    printf("Welcome to the motocross bikes program!\n");
}

//hardcode seven (5) valid records – one argument, the list
void SetInitialRecords(bike list[]){
    // item 1
    list[0].id = 27590;
    list[0].model = 65;
    strcpy(list[0].brand, "General Motorcross");
    strcpy(list[0].color, "Blue");
    list[0].dealerCost = 79.99;
    list[0].customerPrice = 150.75;

    // item 2
    list[1].id = 35463;
    list[1].model = 120;
    strcpy(list[1].brand, "Motorcross Maniacs");
    strcpy(list[1].color, "Red");
    list[1].dealerCost = 69.99;
    list[1].customerPrice = 199.99;

    // item 3
    list[2].id = 28475;
    list[2].model = 25;
    strcpy(list[2].brand, "Psyched For Bikes");
    strcpy(list[2].color, "Grey");
    list[2].dealerCost = 85.99;
    list[2].customerPrice = 125.99;

    // item 4
    list[3].id = 54634;
    list[3].model = 250;
    strcpy(list[3].brand, "Sweet Rides");
    strcpy(list[3].color, "Black");
    list[3].dealerCost = 169.99;
    list[3].customerPrice = 249.99;

    // item 5
    list[4].id = 34643;
    list[4].model = 125;
    strcpy(list[4].brand, "Woah, Man - Bikes");
    strcpy(list[4].color, "Silver");
    list[4].dealerCost = 69.99;
    list[4].customerPrice = 120.55;

}

//runs the menu and gets the user choice
//– no arguments, return a character
char RunMenu(){
    char userInput;
    printf("\n_______ Select an option from the Menu  _______\n");
    printf("(P)....Print the list onto the screen\n""(A)... Add a new entry\n""(C)....Clear all records\n""(D)....Delete an item from the list\n""(Q)....Quit\n");
    scanf(" %c", &userInput);
    return toupper(userInput);
}

//prints the contents of the list onto the screen
//– 2 arguments(list and count)
void PrintBikeList(bike list[], int *count){
    int i;
    for (i = 0; i < *count; i++){
        printf("\nItem %d (index  %d)\n", i + 1, i);
        printf("ID: %d\n", list[i].id);
        printf("Model: %d\n", list[i].model);
        printf("Brand: %s\n", list[i].brand);
        printf("Color: %s\n", list[i].color);
        printf("Dealer Cost: %.2f\n", list[i].dealerCost);
        printf("Customer Price: %.2f\n", list[i].customerPrice);
    }
    if(*count == 0){
        printf("\nList is empty.\n");
    }
}

//adds a bike to the list
//- 2 arguments(list and count)
void AddBike(bike list[], int *count){
    printf("\nAdd a bike to the list:\n");
    printf("Enter Bike ID:\n");
    scanf("%d", &list[*count].id);
    printf("Enter Bike Model #:\n");
    scanf("%d", &list[*count].model);
    printf("Enter Bike Brand:\n");
    scanf(" %s", list[*count].brand);
    printf("Enter Bike Color:\n");
    scanf(" %s", list[*count].color);
    printf("Enter Bike Dealer Cost:\n");
    scanf("%lf", &list[*count].dealerCost);
    printf("Enter Bike Customer Price:\n");
    scanf("%lf", &list[*count].customerPrice);
    printf("\n_______ Successfully added bike! _______\n");

    *count += 1;
}

//Delete function, this function will be called when the user
//selects D. This function will call the Display Id function and the Search function
//– 2 arguments (list, count), void return type
void DeleteBike(bike list[], int *count){
    int id, location;
    //  call the Display Ids function
    id = DisplayBikeIDs(list, count);
    //  print the ID that was returned
    printf("ID selected: %d\n", id);
    //  call the Search function
    location = SearchBike(list, count, id);
    //  print the location that was returned
    printf("location: %d\n", location);

    if(location == 100){
        printf("Bike not found.\n");
    } else {
        int idx = *count - 1;
        list[location] = list[idx];
        *count = idx;
        printf("Bike successfully removed.\n");
    }
}


//displays the ids in the list, gets the id from the user and return it
//– 2 arguments(list and count), returns an integer(id)
int DisplayBikeIDs(bike list[], int *count){
    int i, input;
    printf("IDs in bike list\n");
    for (i = 0; i < *count; i++){
        printf("%d\n", list[i].id);
    }
    printf("Enter an ID: \n");
    scanf("%d", &input);
    return input;
}

//searches the list by id and returns the index, if there is a match or returns 100
//if there is no match (the maximum size of the list is 50)
// - 3 arguments (list, number of items, id), returns location
int SearchBike(bike list[], int *count, int id){
    int i;
    int index = 100;
    for(i = 0; i < *count; i++){
        if(list[i].id == id){
            index = i;
            break;
        }
    }
    return index;
}

// clears list when user enters "C"
void ClearList(bike list[], int *count){
    memset(list, 0, sizeof(bike)* *count);
    *count = 0;
    printf("\nList cleared.\n");
}
