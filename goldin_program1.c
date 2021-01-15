/* COP 2220 first program (program1.c) */
/* Seth Goldin | 9/7/20 */
#include <stdio.h>

int main() {
    // initialize integer to contain date
    int dateNum;
    // welcome user
    printf("Hello\n");
    // ask user to enter the date
    printf("Enter the day of the month (1 through 31)\n");
    // scan in user input and assign to date integer
    scanf("%d", &dateNum);
    // print date with user input
    printf("Today is September %d", dateNum);
    return 0;
}
