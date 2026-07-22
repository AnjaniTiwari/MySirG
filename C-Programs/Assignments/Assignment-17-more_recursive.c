#include <stdio.h>

//Q1
int natural_num_sum(int num) {
    if(num > 1)
        return num + natural_num_sum(num-1);
    return 1;
}

//Q2
int natural_odd_num_sum(int num) {
    if(num > 1)
        return 2*num-1 + natural_odd_num_sum(num-1);
    return 1;
}

//Q3
int natural_even_num_sum(int num) {
    if(num > 1) 
        return 2*num + natural_even_num_sum(num-1);
    return 2;
}

//Q4
int natural_num_squares_sum(int num) {
    if(num > 1)
        return num*num + natural_num_squares_sum(num-1);
    return 1;
}

//Q5
int sum_of_digit(int num) {
    if(num > 9) 
        return num%10 + sum_of_digit(num/10);
    return num;
}

//Q6
int factorial(int num) {
    if(num > 2)
        return num*factorial(num-1);
    return 2;
}

//Q7
int HCF(int num1, int num2) {
    if(num1 >= num2) {
        if(num2 == 0 || num1%num2 == 0)
            return num2;
        return HCF(num1%num2, num2);
    }
    else { 
        if(num1 == 0 || num2%num1 == 0)
            return num1;
        return HCF(num2%num1, num1);
    }
}

//Q8
int fib(int n) {
    if(n == 0 || n == 1)
        return n;
    return fib(n-2) + fib(n-1);
}
void printFib(int n) {
    if(n == 0)
        printf("%d ", n);
    else {
        printFib(n-1);
        printf("%d ", fib(n));
    }
}

//Q9
int digit_count(int num) {
    if(!num)
        return 0;
    return 1 + digit_count(num/10);
}

//Q10
float power(float num, float p) {
    if(p == 0)
        return 1;
    if(p > 0)
        return num * power(num, p-1);
    else
        return power(num, p+1)/num;
}

int main() {
    system("clear");
    // printf("%d", natural_num_sum(5));
    // printf("%d", natural_odd_num_sum(5));
    // printf("%d", natural_even_num_sum(3));
    // printf("%d", natural_num_squares_sum(3));
    // printf("%d", sum_of_digit(3212));
    // printf("%d", factorial(5));
    // printf("%d", HCF(48, 18));
    // printFib(15);
    // printf("%d", digit_count(123));
    printf("%f", power(2, -2));
    printf("\n");
    return 0;
}