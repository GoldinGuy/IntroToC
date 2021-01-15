/*COP 2220  (program2.c)
Seth Goldin 9/12/20 */

#include <stdio.h>
#include <ctype.h>

int main()
{
	char firstInitial, upperInitial;
	int cupsOfCoffee;
	double priceOfCoffee;

	printf("Hello, my name is Seth, welcome to my coffee calculator. \n");

	printf("\nPlease enter your first initial: \n");
    scanf("%c", &firstInitial);

    upperInitial = toupper(firstInitial);
    printf("You entered %c and your initial in uppercase is %c \n", firstInitial, upperInitial);

    printf("\nHow many cups of coffee do you drink per day? \n");
    scanf("%d", &cupsOfCoffee);

    printf("How much do you spend on a cup of coffee? \n");
    scanf("%lf", &priceOfCoffee);

	printf("\nWow %c! \n", upperInitial);
	printf("You are spending $%.2f per day on %d cups of coffee at $%.2f per cup. \n", (priceOfCoffee * cupsOfCoffee), cupsOfCoffee, priceOfCoffee);

	printf("\nHave a great day, %c!", upperInitial);

	return 0;
}