#include <stdio.h>
#include "Assignment-14-function.c"
//Q1
int lcm(int n1, int n2) {
    int d = 2, lcm = 1, flag;
    while(n1 != 1 || n2 != 1) {
        if(n1%d == 0) {
            n1/=d;
            flag = 1;
        }
        if(n2%d == 0) {
            n2/=d;
            flag = 1;
        }
        if(flag) {
            lcm*=d;
            flag = 0;
        }
        else
            ++d;
    }
    return lcm;
}

//2nd option
int lcm2(int n1, int n2) {
    for(int lcm = n1>n2?n2:n1; lcm <= n1*n2; lcm++)
        if(lcm%n1 == 0 && lcm%n2 == 0)
            return lcm;
}
//Q2
int hcf(int n1, int n2) {
    int d = n1 > n2 ? n2 : n1;
    do {
        if(n1%d == 0 && n2%d == 0)
            return d;
    } while(--d != 1);
    return d;
}

//Q3
int is_prime(int num) {
    int d = num/2;
    while(d > 1) {
        if(num%d == 0)
            return 0;
        d--;
    }
    return 1;
}

//Q4
int next_prime(int num) {
    int prime = num;
    while(!is_prime(++prime));
    return prime;
}

//Q5
void n_prime(int num) {
    int prime = 2;
    do {
        printf("%d ", prime);
        prime = next_prime(prime);
    } while(--num);
}

//Q6
void between_prime(int n1, int n2) {
    int prime = n1;
    while((prime = next_prime(prime)) < n2) {
            printf("%d ", prime);
    }
}

//Q7 
void n_fibonacci_series(int num) {
    int first = 1, second = 0, current;
    while(num){
        current = first+second;
        printf("%d ", current);
        first = second;
        second = current;
        num--;
    }
}

//Q8
void pascal_triangle(int n) {
    int flag, r;
    for(int i  = 1; i <= n; ++i) {
        flag = 1;
        r = 0;
        for(int j = 1; j <= (2*n)-1; ++j) {
            if(j >= n+1-i && j <= n-1+i) {
                if(flag) {
                    printf("%3d", combination(i-1, r++));
                    flag = 0;
                }
                else {
                    printf("   ");
                    flag = 1;
                }
            }
            else
                printf("   ");
        }
        printf("\n");
    }
}

//Q9
int is_armstrong_num(int num) {
    int n1 = num, n2 = 0, digit_count = 0, n3, i, n4 = 0, n5 = 0;
    while(n1) {
        digit_count++;
        n1/=10;
    }
    n1 = num;
    while(n1) {
        n3 = n1%10;
        i = 1;
        n4 = 1;
        while(i++ <= digit_count)
            n4*=n3; 
        n5+=n4;
        n1/=10;
    }
    if(n5 == num)
        return 1;
    else
        return 0;
}

int next_armstrong_num(int num) {
    while(!is_armstrong_num(++num));
    return num;
}

void between_armstrong(int n1, int n2) {
    int arm_no = n1;
    while((arm_no = next_armstrong_num(arm_no)) < n2) {
        printf("%d ", arm_no);
    }
}

//Q10
// int factorial(int num) {
//     int fact = 1;
//     while(num > 1) {
//         fact*=num;
//         --num;
//     }
//     return fact;
// }

int sum_of_the_series(int n) {
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        sum+=factorial(i)/i;
    }
    return sum;
}

int main()
{
    system("clear");
    // printf("LCM %d", LCM(6, 8));
    // printf("HCF %d", HCF(15, 16));
    int n = 5;
    // printf("%d is %s", n, is_prime(n) ? "Prime number." : "Not Prime number."); 
    // printf("%d ", next_prime(n));
    // n_prime(n);
    // between_prime(7, 23);
    // n_fibonacci_series(10);
    pascal_triangle(5);
    // between_armstrong(-1, 20);
    // printf("%d ", sum_of_the_series(5));
    printf("\n");
    return 0;
}