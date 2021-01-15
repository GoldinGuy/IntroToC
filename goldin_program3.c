/*COP 2220  (program3.c) - larger program
Program 3 - Seth Goldin - 9/27/20 */

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

//function prototypes
void Greeting(void);
//welcome the user to the coffee and snack shop

void ViewBalance(double balance);
//display the current account balance

int DisplayMenu();
//display beverage/food options and prices
//asks, gets, and returns the item number

double OrderPrice(int itemNumber);
//input: item number
//returns the price of the item

int CheckForEnoughMoney(double balance, double price);
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough

double Reload(double balance);
//reload the account balance

int main()
{
    // declare variables
    char again = 'y'; //initialize the while loop
    double balanceInMain = 5.00;
    double priceInMain;
    int userInput;

    Greeting();

    while (again == 'y' || again == 'Y') {
        //view the account balance (ViewBalance function call)
        ViewBalance(balanceInMain);
        //display the menu choices and get the itemSelection (DisplayMenu function call)
        userInput = DisplayMenu();
        //get the price (OrderPrice function call)
        priceInMain = OrderPrice(userInput);
        //make a purchase if there is enough money (CheckForEnoughMoney function call)
        if (CheckForEnoughMoney(balanceInMain, priceInMain) == 1){
            balanceInMain -= priceInMain;
            printf("\nEnjoy your purchase!\n");
        }
        else{
            //reload the card if there is not enough money
            printf("\nYou do not have enough money in your account!\n"
                            "You will need to make the selection again after you reload your account\n");
            balanceInMain = Reload(balanceInMain);
        }
        //view the account balance (ViewBalance function call)
        ViewBalance(balanceInMain);
        //another purchase?
        printf("\nWould you like to make another purchase? (y or n)\n");
        scanf(" %c", &again);
    }
    //display remaining account balance (ViewBalance function call)
    ViewBalance(balanceInMain);
    //say goodbye to the user
    printf("Have a great day!");
    return 0;
}

void Greeting(void) {
    //welcome the user to the coffee and snack shop
    printf("Welcome to the Coffee Express\n"
           "We serve delicious coffee and snacks!\n"
           "\nYou will be presented with a list of items and your account balance.\n"
           "Please select the number for the item you wish to purchase.\n"
           "If you do not have enough money to cover the purchase,\n"
           "you will be asked to add money to your account.\n"
           "After adding money to your account, you will need to reselect the item!\n");
}

void ViewBalance(double balance){
    //display the current account balance
    printf("\nYour current balance is $%.2f\n", balance);
}

int DisplayMenu(){
    int userInput;
    //display beverage/food options and prices
    printf("\n-----------------------------------------\n"
           "Here are the coffee and snack options:\n"
           "1. Hot coffee $2.35\n"
           "2. Iced coffee $2.35\n"
           "3. Hot Latte $4.68\n"
           "4. Iced Latte $4.68\n"
           "5. Butter Croissant $3.50\n"
           "6. Almond Croissant $4.50\n"
           "7. Blueberry Muffin Top $3.25\n");
    //asks for item number
    printf("\nEnter your selection (1-7):\n");
    scanf("%d", &userInput);
    // returns the item number
    return userInput;
}


double OrderPrice(int itemNumber){
    double price = 0.0;
    //returns the price of the item
    switch (itemNumber) {
        case 1:
            printf("\nYou selected Hot Coffee, the price is $2.35\n");
            price = 2.35;
            break;
        case 2:
            printf("\nYou selected Iced coffee, the price is $2.35\n");
            price = 2.35;
            break;
        case 3:
            printf("\nYou selected Hot Latte, the price is $4.68\n");
            price = 4.68;
            break;
        case 4:
            printf("\nYou selected Iced Latte, the price is $4.68\n");
            price = 4.68;
            break;
        case 5:
            printf("\nYou selected Butter Croissant, the price is $3.50\n");
            price = 3.50;
            break;
        case 6:
            printf("\nYou selected Almond Croissant, the price is $4.50\n");
            price = 4.50;
            break;
        case 7:
            printf("\nYou selected Blueberry Muffin Top, the price is $3.25\n");
            price = 3.25;
            break;
        default:
            printf("\nThere is no item with that number");
    }
    return price;
}

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
double Reload(double balance){
    double deposit;
    printf("\nEnter the amount you want to add:\n");
    scanf("%lf", &deposit);
    return balance + deposit;
}


