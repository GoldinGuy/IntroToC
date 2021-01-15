#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//Part A

typedef struct {
    char name[30];
    char color[30];
    double pricePerPound;
}fruit;

// Part B

fruit GetFruitInfo(){
    fruit tempFruit;

    printf("Enter the name of the fruit: \n");
    scanf(" %s", tempFruit.name);

    printf("Enter the color of the fruit: \n");
    scanf(" %s", tempFruit.color);

    printf("Enter the price per pound of the fruit: \n");
    scanf("%lf", &tempFruit.pricePerPound);

    return tempFruit;
}

// Additional Main method to run the GetFruitInfo() function and print results
int main(){
    fruit newFruit = GetFruitInfo();

    printf("\nName: %s\n",newFruit.name);
    printf("Color: %s\n",newFruit.color);
    printf("Price: %.2f\n",newFruit.pricePerPound);
    return 0;
}
