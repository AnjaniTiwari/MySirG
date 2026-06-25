//Assignment 11 
// 1.
// // * 
// // * * 
// // * * * 
// // * * * * 
// // * * * * * 
// #include <stdio.h>
// int main() {
//     system("clear");
//     for(int i = 1; i <= 5; ++i) {
//         for(int j = 1; j <= i; ++j) {
//             printf("* ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 2.
// //         * 
// //       * * 
// //     * * * 
// //   * * * * 
// // * * * * * 
// #include <stdio.h>
// int main() {
//     system("clear");
//     for(int i = 1; i <= 5; ++i) {
//         for(int j = 1; j <= 5; ++j) {
//             if(j >= 6-i)
//                 printf("* ");
//             else
//                 printf("  ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 3.
// // * * * * * 
// // * * * *   
// // * * *     
// // * *       
// // * 
// #include <stdio.h>
// int main() {
//     system("clear");
//     for(int i = 1; i <= 5; ++i) {
//         for(int j = 1; j <= 5; ++j) {
//             if(j <= 6-i)
//                 printf("* ");
//             else
//                 printf("  ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 4.
// // * * * * * 
// //   * * * * 
// //     * * * 
// //       * * 
// //         * 
// #include <stdio.h>
// int main() {
//     system("clear");
//     for(int i = 1; i <= 5; ++i) {
//         for(int j = 1; j <= 5; ++j) {
//             if(j >= i)
//                 printf("* ");
//             else
//                 printf("  ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 5.
// // 1 
// // 1 2 
// // 1 2 3 
// // 1 2 3 4 
// // 1 2 3 4 5 
// #include <stdio.h>
// int main() {
//     system("clear");
//     for(int i = 1; i <= 5; ++i) {
//         for(int j = 1; j <= i; ++j) {
//             printf("%d ", j);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 6.
// // 1 
// // 2 1 
// // 3 2 1 
// // 4 3 2 1 
// #include <stdio.h>
// int main() {
//     system("clear");
//     for(int i = 1; i <= 4; ++i) {
//         for(int j = 1; j <= i; ++j) {
//             printf("%d ", i+1-j);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 7.
// // A B C D E 
// //   A B C D 
// //     A B C 
// //       A B 
// //         A 
// #include <stdio.h>
// int main() {
//     system("clear");
//     char ch;
//     for(int i = 1; i <= 5; ++i) {
//         ch = 'A';
//         for(int j = 1; j <= 5; ++j) {
//             if(j >= i)
//                 printf("%c ", ch++);
//             else
//                 printf("  ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 8.
// // 1 
// // 2 3 
// // 4 5 6 
// // 7 8 9 10 
// #include <stdio.h>
// int main() {
//     system("clear");
//     int n = 1;
//     for(int i = 1; i <= 4; ++i) {
//         for(int j = 1; j <= i; ++j) {
//             printf("%d ", n++);
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// // 9.
// // A B C D E 
// //   B C D E 
// //     C D E 
// //       D E 
// //         E 
// #include <stdio.h>
// int main() {
//     system("clear");
//     char ch;
//     for(int i = 1; i <= 5; ++i) {
//         for(int j = 1; j <= 5; ++j) { 
//             if(j >= i)
//                 printf("%c ", '@'+j);
//             else
//                 printf("  ");
//         }
//         printf("\n");
//     }
//     printf("\n");
//     return 0;
// }

// 10.
// * * * * * 
// *       * 
// *       * 
// *       * 
// * * * * * 
#include <stdio.h>
int main() {
    system("clear");
    char ch;
    for(int i = 1; i <= 5; ++i) {
        for(int j = 1; j <= 5; ++j) { 
            if(i == 1 || i == 5 || j == 1 || j == 5)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}