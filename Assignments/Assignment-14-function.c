#include <stdio.h>
// Q1
float circle_area(int radius) {
    return 3.14*radius*radius;
}
// Q2
float simple_interest(int principal, int interest_rate, int time) {
    return (principal*interest_rate*time)/100.0;
}
// Q3
int is_even(int num) {
    return num&1 ? 0 : 1; 
}
// Q4
void natural_number(int num) {
    for(int i = 1; i<=num; ++i)
        printf("%d ", i);;
}
//Q5
void odd_natural_number(int num) {
    for(int i = 1; i<=num*2; i+=2)
        printf("%d ", i);
}
//Q6
int factorial(int num) {
    if(num == 1)
        return 1;
    return num*factorial(num-1);
}
//Q7
int combination(int n, int r) {
    int c, j, pair = 0;
    int last_j;
    // x = r&1 ? n-1 : n;
    for(int i = 1; i <= n && n-i >= r-1; ++i) {
        c = 0;
        j = last_j = i;
        while(j <= n) {
            if(c == 0) {
                if(j == n && r%2 != 0)
                    break;
                printf("\n%d ", i);
                j = ++last_j;
                c++;
            }
            printf("%d ", j);
            c++;
            if(c != r) {
                j++;
            }
            else {
                c = 0;
                if(r%2 == 0)
                    j++;
            }
        } 
    }
}


int main() {
    system("clear");
    // printf("%f", circle_area(3));
    // printf("%f", simple_interest(10000, 5, 2));
    // printf("%s", is_even(24) ? "Even" : "Odd");
    // natural_number(10);
    // odd_natural_number(10);
    // printf("%d", factorial(5));
    combination(5, 4);
    printf("\n");
    return 0;
}