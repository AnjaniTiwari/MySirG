#include <stdio.h>

//Q1
void n_natural_num(int num) {
    if(num > 1) {
        n_natural_num(num-1);
    }
    printf("%d ", num);
}

//Q2
void n_natural_num_reverse(int num) {
    printf("%d ", num);
    if(num > 1) {
        n_natural_num_reverse(num-1);
    }
}

//Q3
void n_odd_natural_num(int num) {
    if(num > 1) {
        n_odd_natural_num(num-1);
    }
    printf("%d ", (num*2)-1);    
}

//Q4
void n_odd_natural_num_reverse(int num) {
    printf("%d ", (num*2)-1);    
    if(num > 1) {
        n_odd_natural_num_reverse(num-1);
    }
}

//Q5
void n_even_natural_num(int num) {
    if(num > 1)
        n_even_natural_num(num-1);
    printf("%d ", num*2);
}

//Q6
void n_even_natural_num_reverse(int num) {
    printf("%d ", num*2);
    if(num > 1)
        n_even_natural_num_reverse(num-1);
}

//Q7
void first_n_natural_num_squares(int num) {
    if(num > 1)
        first_n_natural_num_squares(num-1);
    printf("%d ", num*num);
}

//Q8
void print_binary(int num) {
    if(num > 1)
        print_binary(num/2);
    printf("%d ", num%2);
}

//Q9 
void print_octal(int num) {
    if(num > 1)
        print_octal(num/8);
    printf("%d ", num%8);
}

//Q10
void number_reverse(int num) {
    printf("%d ", num%10);
    if(num > 9)
        number_reverse(num/10);
}

int main()
{
    system("clear");
    // n_natural_num(10);
    // n_natural_num_reverse(5);
    // n_odd_natural_num(10);
    // n_odd_natural_num_reverse(10);
    // n_even_natural_num(4);
    // n_even_natural_num_reverse(7);
    // first_n_natural_num_squares(4);
    // print_binary(11);
    // print_octal(11);
    number_reverse(1291);
    printf("\n");
    return 0;
}