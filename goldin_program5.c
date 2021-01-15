/*COP 2220  (program5.c)
 Seth Goldin 10/18/20 */

#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower function

// function prototypes
void Greeting(void);
//welcome the user to the coffee shop
char OptionList();
//Display the program choices (S, O, B, A, Q)
//declare, ask, get, and return the users choice
double ProcessOption(char choice, double balance);
//input: the user's choice and the account balance
//return the updated balance
void DisplayMenu();
//displays the beverage/food options and prices
double OrderPrice();
//declare, ask, and get the item number from the user
//determine and return the price of the item
void ViewBalance(double balance);
//input: the balance in the account
//displays the current account balance of user
double Reload(double balance);
//input: the current balance in the account
//declare, ask, and get the amount to add
//add the amount to the local copy of the balance and return the new balance
int CheckForEnoughMoney(double balance, double price);
//input: the account balance and the item price
//return 1 if the balance is enough to cover the price
//return 0 if it is not enough

int main(){
    char choiceInMain;
    double balance;

    printf("Getting your account balance updated from the accountBalance.txt file\n");
    FILE *inp = fopen("accountBalance.txt", "r");
    if (inp){
        fscanf(inp, "%lf", &balance);
        fclose(inp);
    } else {
        printf("\nError when attempting to open file\n");
    }

    // greet the user
    Greeting();
    // call OptionList
    choiceInMain = OptionList();

    while (choiceInMain != 'q'){
        //call ProcessOption and pass the choiceInMain and balance
        balance = ProcessOption(choiceInMain, balance);
        // call OptionList
        choiceInMain = OptionList();
    }
    printf("\nUpdating your account balance in the accountBalance.txt file\n");
    FILE *out = fopen("accountBalance.txt", "w");
    if (out){
        fprintf(out, "%.2f", balance);
        fclose(out);
    } else {
        printf("\nError when attempting to open file\n");
    }

    //Say goodbye to the user
    printf("\nHave a great day!");
    return 0;
}

// welcome the user to the coffee shop
void Greeting(){
    printf("\nWelcome to the Coffee Express \nWe serve delicious coffee and snacks!\n");
}

// display the program options, declare, get and return the users selection
char OptionList(){
    char userInput;
    printf("\n********************************************************"
           "\nWhat would you like to do?"
           "\nPlease select from the following options:\n"
           "\n'S' to view the snack and beverages available for purchase"
           "\n'O' to order coffee or a snack"
           "\n'B' to view your account balance"
           "\n'A' to add money to your account"
           "\n'Q' to Quit"
           "\nEnter your selection: ");
    scanf(" %c", &userInput);
    // change the input to lowercase
    return tolower(userInput);
}

// display a message based on the input: the user's choice (S,O,B, or A), return balance
double ProcessOption(char choice, double balance){
    // print a message, view the balance, display the menu (snack and coffee choices), complete the order only if there is enough money
    if (choice == 's'){
        printf("\nHere are the snacks:");
        DisplayMenu();
    } else if (choice == 'o'){
        printf("\nMake an order (select a number):\n");
        ViewBalance(balance);
        double orderPrice = OrderPrice();
        if (CheckForEnoughMoney(balance, orderPrice) == 1){
            // avoid printing if an invalid item was selected
            if((balance - orderPrice) != balance){
                printf("\nEnjoy your purchase!\n");
            }
            balance -= orderPrice;
        }
        else{
            printf("\nYou do not have enough money, select item 'A'\n");
        }
    }  else if (choice == 'b'){
        printf("\nHere is your account balance:\n");
        ViewBalance(balance);
    } else if (choice == 'a'){
        printf("\nAdd money to the account\n");
        ViewBalance(balance);
        balance = Reload(balance);
        ViewBalance(balance);
    } else {
        printf("\nThat is not a valid option\n");
    }
    return balance;
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

// determine and return the price of the item
double OrderPrice(){
    int itemNumber;
    printf("\nEnter your selection (1-7):");
    scanf("%d", &itemNumber);
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
            printf("\nThere is no item with that number\n");
    }
    return price;
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
double Reload(double balance){
    double deposit;
    printf("\nEnter the amount you want to add: ");
    scanf("%lf", &deposit);
    return balance + deposit;
}



