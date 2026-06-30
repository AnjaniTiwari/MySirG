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

// //5.
// A B C D E F G 
//   A B C D E   
//     A B C     
//       A   
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
    char ch;
    for(int i = 1; i <= 4; ++i) {
        ch = 'A'-1;
        for(int j = 1; j <= 7; ++j) {
            if(j >= i && j <= 8-i) {
                j <= 4 ? ch++ : --ch;
                printf("%c ", ch);
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

// //7.
//          1        
//        1   1      
//      1   2   1    
//    1   2   2   1  
//  1   2   3   2   1 
void f7_1() {
    int k, flag, flag2, p_count, n_count;
    for(int i = 1; i <= 5; ++i) {
        flag = 1;
        flag2 = 0;
        k = 0;
        p_count = 0;
        n_count = i%2 ? (i/2)+1 : i/2;
        for(int j = 1; j <= 9; ++j) {
            if(j >= 6-i && j <= 4+i && flag) {
                if(!flag2 && k < n_count) 
                    ++k;
                else if((2*p_count)-i != 0) {
                    --k; 
                    flag2 = 1;
                } 
                printf(" %d", k);
                p_count++;
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

void f7(int line) {
    int k, flag;
    for(int i = 1; i <= line; ++i) {
        flag = 1;
        k = 1;
        for(int j = 1; j <= 2*line-1; ++j) {
            if(j >= line+1-i && j <= line-1+i && flag) {
                printf(" %d", k);
                j < line ? ++k : --k;
                flag = 0;
            }
            else {    
                printf("  ");
                if(j == line) --k;
                flag = 1;
            }
        }
        printf("\n");
    }
}

//8.
// A B C D C B A 
//   A B C B A   
//     A B A     
//       A   
void f8() {
    for(int i = 1; i <= 4; ++i) {
        for(int j = 1; j <= 7; ++j) {
            if(j <= 5-i || j >= 3+i) {
                printf("* ");
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

//9.
// 1 2 3 4 3 2 1 
// 1 2 3   3 2 1 
// 1 2       2 1 
// 1           1  
void f9() {
    int k, flag;
    for(int i = 1; i <= 4; ++i) {
        k  = 0;
        flag = 0;
        for(int j = 1; j <= 7; ++j) {
            if(!flag && k < 4)
                ++k;
            else {
                --k;
                flag = 1;
            }
            if(j <= 5-i || j >= 3+i) {
                printf("%d ", k);
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

//10.
// A B C D C B A 
// A B C   C B A 
// A B       B A 
// A           A  
void f10() {
    char k; 
    int flag;
    for(int i = 1; i <= 4; ++i) {
        k  = 'A'-1;
        flag = 0;
        for(int j = 1; j <= 7; ++j) {
            if(!flag && k < 'A'+3)
                ++k;
            else {
                --k;
                flag = 1;
            }
            if(j <= 5-i || j >= 3+i) {
                printf("%c ", k);
            }
            else
                printf("  ");
        }
        printf("\n");
    }
}

#include <stdio.h>
int main() {
    system("clear");
    f7(10);
    printf("\n");
    return 0;
}
