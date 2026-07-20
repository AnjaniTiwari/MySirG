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
int HCF(int num1, int num2, int hcf) {
    hcf = num1 > num2 ? num1 : num2;
    if(hcf%num1 == 0 && hcf%num2 == 0)
        return hcf;
    HCF(num1, num2, hcf+1);
}

int main() {
    system("clear");
    // printf("%d", natural_num_sum(5));
    // printf("%d", natural_odd_num_sum(5));
    // printf("%d", natural_even_num_sum(3));
    // printf("%d", natural_num_squares_sum(3));
    // printf("%d", sum_of_digit(3212));
    // printf("%d", factorial(5));
    printf("%d", HCF(2, 3, 0));
    printf("\n");
    return 0;
}