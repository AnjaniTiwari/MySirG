//Assignment 12 

//1.
//       *       
//     * * *     
//   * * * * *   
// * * * * * * *
void f1() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 7; ++j) {
            if(j >= 5-i && j <= 3+i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

//2.
// * * * * * * * 
//   * * * * *   
//     * * *     
//       *   
void f2() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 7; ++j) {
            if(j >= i && j <= 8-i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

//3.
//       *       
//     *   *     
//   *   *   *   
// *   *   *   * 
void f3() {
    int flag;
    for(int i = 1; i <= 4; ++i) {
        flag = 1;
        for(int j = 1; j <= 7; ++j) {
            if(j >= 5-i && j <= 3+i && flag) {
                printf("* ");
                flag = 0;
            }
            else {
                printf("  ");
                flag = 1;
            }
        }
        printf("\n");
    }
}

//4.
//       1       
//     1 2 1     
//   1 2 3 2 1   
// 1 2 3 4 3 2 1 
void f4() {
    int k, z;
    for(int i = 1; i <= 4; ++i) {
        k = 1;
        for(int j = 1; j <= 7; ++j) {
            if(j >= 5-i && j <= 3+i) {
                printf("%d ", k);
                j < 4 ? ++k : --k;

            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

//5.
// * * * * * * * 
//   * * * * *   
//     * * *     
//       *   
void f5() {
    char ch;
    for(int i = 1; i <= 4; ++i) {
        ch = 'A';
        for(int j = 1; j <= 7; ++j) {
            if(j >= i && j <= 8-i)
                printf("%c ", ch++);
            else
                printf("  ");
        }
        printf("\n");
    }
}

//6.
// A B C D C B A 
//   A B C B A   
//     A B A     
//       A   
void f6() {
    int k, flag;
    for(int i = 1; i <= 5; ++i) {
        k = 1;
        flag = 1;
        for(int j = 1; j <= 9; ++j) {
            if(j >= 6-i && j <= 4+i && flag) {
                printf("%d ", k);
                flag = 0;
                if(j < 5)
                 ++k;
                else 
                    --k;
            }
            else {
                printf("  ");
                flag = 1;
            }
        }
        printf("\n");
    }
}

#include <stdio.h>
int main() {
    system("clear");
    f6();
    printf("\n");
    return 0;
}
