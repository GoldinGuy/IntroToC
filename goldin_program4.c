/*COP 2220  (program4.c)
 Seth Goldin 10/13/20 */

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

// function prototypes

void Greeting(); //welcome the user to the coffee shop

char OptionList(); //display the program options, declare, get and return the users selection

void ProcessOption(char choice); // display a message based on the input: the user's choice (S,O,B, or A)

void DisplayMenu(); // display beverage/food options and prices

int main(){
    char choiceInMain;

    // greet the user
    Greeting();
    // call OptionList
    choiceInMain = OptionList();
    // change the choiceInMain to lowercase //INITIALIZATION
    choiceInMain = tolower(choiceInMain);

    while (choiceInMain != 'q'){
        //call ProcessOption and pass the choiceInMain
        ProcessOption(choiceInMain);
        // call OptionList
        choiceInMain = OptionList();
        // change the choiceInMain to lowercase //UPDATE
        choiceInMain = tolower(choiceInMain);
    }
    //Say goodbye to the user
    printf("\nHave a great day!");
    return 0;
}

// welcome the user to the coffee shop
void Greeting(){
    printf("Welcome to the Coffee Express \nWe serve delicious coffee and snacks!\n");
}

// display the program options, declare, get and return the users selection
char OptionList(){
    char userInput;
    printf("\n********************************************************"
           "\nWhat would you like to do?"
           "\nPlease select from the following options:"
           "\n'S' to view the snack and beverages available for purchase"
           "\n'O' to order coffee or a snack"
           "\n'B' to view your account balance"
           "\n'A' to add money to your account"
           "\n'Q' to Quit"
           "\nEnter your selection: ");
    scanf(" %c", &userInput);
    return userInput;
}

// display a message based on the input: the user's choice (S,O,B, or A)
void ProcessOption(char choice){
    // print a message, view the balance, display the menu (snack and coffee choices), complete the order only if there is enough money
    printf("\n----------------------------------\n");
    if (choice == 's'){
        printf("Display the menu");
        DisplayMenu();
    } else if (choice == 'o'){
        printf("Complete an order if there is enough money\n");
    }  else if (choice == 'b'){
        printf("Display the account balance\n");
    } else if (choice == 'a'){
        printf("Add money to the account\n");
    } else {
        printf("That is not a valid option\n");
    }

}

// display beverage/food options and prices
void DisplayMenu(){
    printf("\n-----------------------------------------"
           "\nHere are the coffee and snack options:"
           "\n1. Hot coffee $2.35"
           "\n2. Iced coffee $2.35"
           "\n3. Hot Latte $4.68"
           "\n4. Iced Latte $4.68"
           "\n5. Butter Croissant $3.50"
           "\n6. Almond Croissant $4.50"
           "\n7. Blueberry muffin top $3.25\n");
}