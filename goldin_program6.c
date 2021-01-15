/*COP 2220  (program6.c)
 Seth Goldin 11/8/20 */

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes
void Greeting(void); //SAME AS PROGRAM 5
//welcome the user to the coffee shop
void OptionListPtr(char* choicePtr);
//input: the "address of" the choice
//Display the program choices (S, O, B, A, Q)
//ask for the choice – scan the value into choiceptr -- scanf(" %c",choicePtr)
void ProcessOptionPtr(char choice, double* balancePtr);
//input: the value of the user's choice and "the address of" the balance
//update the "value at" balancePtr after any transaction
void DisplayMenu(); //SAME AS PROGRAM 5
//displays the beverage/food options and prices
void OrderPricePtr(double* pricePtr);
//input: the "address of" the price
//declare, ask, and get the item number from the user
//determine the price and assign the price to the "value at" pricePtr
void ViewBalance(double balance); //SAME AS PROGRAM 5
//input: the balance in the account
//displays the current account balance of user
void ReloadPtr(double *balancePtr);
//input: "the address of" the balance
//declare, ask, and get the amount to add
//add the amount to the "value at" balancePtr
int CheckForEnoughMoney(double balance, double price); //SAME AS PROGRAM 5
//input: the account balance and the item price
//return 1 if the balance is enough

int main(){
    char choiceInMain;
    double balance = 5.00;

    Greeting();

    OptionListPtr(&choiceInMain);
    choiceInMain = tolower(choiceInMain);

    while (choiceInMain != 'q'){
        ProcessOptionPtr(choiceInMain, &balance);
        OptionListPtr(&choiceInMain);
        choiceInMain = tolower(choiceInMain);
    }

    printf("\nHave a great day!");
    return 0;
}

// welcome the user to the coffee shop
void Greeting(){
    printf("\nWelcome to the Coffee Express \nWe serve delicious coffee and snacks!\n");
}

// display the program options, get the users selection
void OptionListPtr(char* choicePtr){
    printf("\n********************************************************"
           "\nWhat would you like to do?"
           "\nPlease select from the following options:\n"
           "\n'S' to view the snack and beverages available for purchase"
           "\n'O' to order coffee or a snack"
           "\n'B' to view your account balance"
           "\n'A' to add money to your account"
           "\n'Q' to Quit"
           "\nEnter your selection: ");
    scanf(" %c", choicePtr);
}

// display a message based on the input: the user's choice (S,O,B, or A)
void ProcessOptionPtr(char choice, double* balancePtr){
    double price;
    // print a message, view the balance, display the menu (snack and coffee choices), complete the order only if there is enough money
    if (choice == 's'){
        printf("\nHere are the snacks:");
        DisplayMenu();
    } else if (choice == 'o'){
        printf("\nMake an order (select a number):\n");
        ViewBalance(*balancePtr);
        OrderPricePtr(&price);
        if (CheckForEnoughMoney(*balancePtr, price) == 1){
            // avoid printing if an invalid item was selected
            if((*balancePtr - price) != *balancePtr){
                printf("\nEnjoy your purchase!\n");
            }
            *balancePtr -= price;
        }
        else{
            printf("\nYou do not have enough money, select item 'A'\n");
        }
    }  else if (choice == 'b'){
        printf("\nHere is your account balance:\n");
        ViewBalance(*balancePtr);
    } else if (choice == 'a'){
        printf("\nAdd money to the account\n");
        ViewBalance(*balancePtr);
        ReloadPtr(balancePtr);
        ViewBalance(*balancePtr);
    } else {
        printf("\nThat is not a valid option\n");
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


//displays the current account balance of user
void ViewBalance(double balance){
    printf("Your current balance is $%.2f\n", balance);
}

// determine the price of the item
void OrderPricePtr(double* pricePtr){
    int itemNumber;
    printf("\nEnter your selection (1-7):");
    scanf("%d", &itemNumber);
    *pricePtr = 0.0;
    //returns the price of the item
    switch (itemNumber) {
        case 1:
            printf("\nYou selected Hot Coffee, the price is $2.35\n");
            *pricePtr = 2.35;
            break;
        case 2:
            printf("\nYou selected Iced coffee, the price is $2.35\n");
            *pricePtr = 2.35;
            break;
        case 3:
            printf("\nYou selected Hot Latte, the price is $4.68\n");
            *pricePtr = 4.68;
            break;
        case 4:
            printf("\nYou selected Iced Latte, the price is $4.68\n");
            *pricePtr = 4.68;
            break;
        case 5:
            printf("\nYou selected Butter Croissant, the price is $3.50\n");
            *pricePtr = 3.50;
            break;
        case 6:
            printf("\nYou selected Almond Croissant, the price is $4.50\n");
            *pricePtr = 4.50;
            break;
        case 7:
            printf("\nYou selected Blueberry Muffin Top, the price is $3.25\n");
            *pricePtr = 3.25;
            break;
        default:
            printf("\nThere is no item with that number\n");
    }
}

// check if account balance can cover price
int CheckForEnoughMoney(double balance, double price){
    if(balance >= price){
        //return 1 if the balance is enough to cover the price
        return 1;
    } else {
        //return 0 if it is not enough
        return 0;
    }
}

// add more money to balance
void ReloadPtr(double* balancePtr){
    double deposit;
    printf("\nEnter the amount you want to add: \n");
    scanf("%lf", &deposit);
    *balancePtr = *balancePtr + deposit;
}



