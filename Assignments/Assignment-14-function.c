#include <stdio.h>
// Q1
float circle_area(int radius)
{
    return 3.14 * radius * radius;
}
// Q2
float simple_interest(int principal, float interest_rate, int time)
{
    return (principal * interest_rate * time) / 100.0;
}
// Q3
int is_even(int num)
{
    return num & 1 ? 0 : 1;
}
// Q4
void natural_number(int num)
{
    for (int i = 1; i <= num; ++i)
        printf("%d ", i);
}
// Q5
void odd_natural_number(int num)
{
    for (int i = 1; i <= num * 2; i += 2)
        printf("%d ", i);
}
// Q6
int factorial(int num)
{
    int fact = 1;
    while(num) {
        fact*=num;
        --num;
    }
    return fact;
}

//Q7
int combination(int n, int r) {
    return factorial(n)/ factorial(r) * factorial(n-r);
}

//Q8
int permutation(int n, int r) {
    return factorial(n)/factorial(n-r);
}

//Q9
int is_number_contains_digit(int num, int digit) {
    while(num) {
        if(num%10 == digit)
            return 1;
        num/=10;
    }
    return 0;
}

//Q10
void print_all_prime_factors(int num) {
    int d = 2;
    while(num != 1) {
        if(num%d == 0) {
            printf("%d ", d);
            num/=d;
        }
        else
            d++;
    }
}

int main()
{
    system("clear");
    // printf("%f", circle_area(3));
    // printf("%f", simple_interest(10000, 5, 2));
    // printf("%s", is_even(24) ? "Even" : "Odd");
    // natural_number(10);
    // odd_natural_number(10);
    // printf("%d", factorial(3));
    // printf("%d", combination(3, 2));
    // printf("%d ", permutation(3, 2));
    // printf("%d ", is_number_contains_digit(39871, 2));
    print_all_prime_factors(75);
    printf("\n");
    return 0;
}