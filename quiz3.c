#include <stdio.h>

double FindQuo(double arg1){
    double num;
    do{
        printf("\nEnter a number: ");
        scanf("%lf", &num);
    } while (num == 0.0);

    if(arg1 >= 0 && num >= 0 || arg1 < 0 && num < 0){
        printf("the result is positive");
    } else {
        printf("the result is negative");
    }
    return (arg1 / num);
}

int main() {
    printf("%f", FindQuo(-4.0));
}
