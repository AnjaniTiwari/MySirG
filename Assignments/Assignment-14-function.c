#include <stdio.h>

float circle_area(int radius) {
    return 3.14*radius*radius;
}

float simple_interest(int principal, int interest_rate, int time) {
    return (principal*interest_rate*time)/100.0;
}

int is_even(int num) {
    return num&1 ? 0 : 1; 
}

void natural_number(int num) {
    for(int i = 1; i<=num; ++i)
        printf("%d ", i);;
}

void odd_natural_number(int num) {
    for(int i = 1; i<=num*2; i+=2)
        printf("%d ", i);
}

int factorial(int num) {
    if(num == 1)
        return 1;
    return num*factorial(num-1);
}
int main() {
    system("clear");
    // printf("%f", circle_area(3));
    // printf("%f", simple_interest(10000, 5, 2));
    // printf("%s", is_even(24) ? "Even" : "Odd");
    // natural_number(10);
    // odd_natural_number(10);
    printf("%d", factorial(5));
    printf("\n");
    return 0;
}