#include <stdio.h>
#include <ctype.h>

int main() {
    char letter;
    char upperLetter;
    char lowerLetter;
    double input;
    double result;

    printf("Input a letter from the keyboard\n");
    scanf("%c", &letter);

    printf("Input a double value from the keyboard\n");
    scanf("%lf", &input);

    upperLetter = toupper(letter);
    lowerLetter = tolower(letter);
    printf("Letter is uppercase: %c and lowercase: %c \n", upperLetter, lowerLetter);

    result = input * 1.609;
    printf("Input: %f when multiplied by 1.609 is result: %f\n", input, result);
    return 0;
}
