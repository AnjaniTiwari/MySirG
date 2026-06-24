//1.Write a recursion function to calculate factorial of n.
#include <stdio.h>
int factorial(int num) {
    if(num == 2)
        return 2;
    return num * factorial(num-1);

}

int main()
{
    int num;
    system("clear");
    
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%d factorial = %d", num, factorial(num));
    printf("\n");
    return 0;
}

// //1.Write a recursion function to calculate factorial of n.
// #include <stdio.h>
// int main()
// {
//     system("clear");

//     printf("\n");
//     return 0;
// }