// //1.Write a recursion function to calculate factorial of n.
// #include <stdio.h>
// int factorial(int num) {
//     if(num == 0)
//         return 1;
//     return num * factorial(num-1);

// }

// #include <stdio.h>
// int main()
// {
//     int num;
//     system("clear");
    
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     printf("%d factorial = %d", num, factorial(num));
//     printf("\n");
//     return 0;
// }

//2.Write a recursive function to print first n natural num.
#include <stdio.h>

void natural_num(int num) {
    if(num > 0) {
        natural_num(num - 1);
        printf("%d ", num);
    }
}

int main() {
    system("clear");
    int num;
    printf("Enter a num: ");
    scanf("%d", &num);
    natural_num(num);
    printf("\n");
    return 0;
}