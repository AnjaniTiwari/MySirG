#include <stdio.h>
#include <stdlib.h>
// Q1.
void days_in_month(int month)
{
    switch (month)
    {
    case 2:
        printf("28 Days");
        break;
    
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("31 Days");
        break;
    
    case 4:
    case 6:    
    case 9:
    case 11:
        printf("30 Days");
        break;
    
    default:
        printf("Invalid Month.");
    
    }
}

// Q2
void manu()
{
    int exit_flag = 0, value = 0, n1, n2;
    float f1, f2;
    while (!exit_flag)
    {
        printf("\n1.Addition\n");
        printf("2.Subtraction\n");
        printf("3.Multiplication\n");
        printf("4.Division\n");
        printf("5.Exit\n");

        printf("Enter your option: ");
        scanf("%d", &value);

        switch (value)
        {
        case 1:
            printf("Enter a two no: ");
            scanf("%d%d", &n1, &n2);
            printf("%d + %d = %d", n1, n2, n1 + n2);
            break;
        case 2:
            printf("Enter a two no: ");
            scanf("%d%d", &n1, &n2);
            printf("%d - %d = %d", n1, n2, n1 - n2);
            break;
        case 3:
            printf("Enter a two no: ");
            scanf("%d%d", &n1, &n2);
            printf("%d * %d = %d", n1, n2, n1 * n2);
            break;
        case 4:
            printf("Enter a two no: ");
            scanf("%f%f", &f1, &f2);
            printf("%.2f / %.2f = %.2f", f1, f2, f1 / f2);
            break;
        case 5:
            exit_flag = 1;
            break;
        default:
            printf("Invalid Option.");
        }
    }
}

// Q3
void weekday(int num)
{
    switch (num)
    {
    case 1:
        printf("Monday.");
        break;
    case 2:
        printf("Tuesday.");
        break;
    case 3:
        printf("Wednesday");
        break;
    case 4:
        printf("Thursday.");
        break;
    case 5:
        printf("Friday.");
        break;
    case 6:
        printf("Saturday");
        break;
    case 7:
        printf("Sunday");
        break;
    default:
        printf("Invalid weekday.");
    }
}

// Q4
void manu2()
{
    int flag = 0, n1, n2, n3, value;

    while (!flag)
    {
        printf("\n1.Check isosceles triangle or not.\n");
        printf("2.Check rightangle triangle or not.\n");
        printf("3.Check equilateral triangle or not.\n");
        printf("4.exit.\n");

        printf("Enter your option: ");
        scanf("%d", &value);

        switch (value)
        {
        case 1:
            printf("Enter three no: ");
            scanf("%d%d%d", &n1, &n2, &n3);
            if(n1+n2>n3 && n2+n3>n1 && n1+n3>n2) {
                if (n1 == n2 || n1 == n3 || n2 == n3)
                    printf("This is isosceles triangle sides.\n");
                else
                    printf("This is not isosceles triangle sides.\n");
            }
            else
                printf("Not valid triangle.\n");
            break;

        case 2:
            printf("Enter three no: ");
            scanf("%d%d%d", &n1, &n2, &n3);

            if(n1+n2>n3 && n2+n3>n1 && n1+n3>n2) { 
                if (n1 * n1 == (n2 * n2) + (n3 * n3))
                    printf("Rightangle triangle.\n");
                else if (n2 * n2 == (n1 * n1) + (n3 * n3))
                    printf("Rightangle triangle.\n");
                else if (n3 * n3 == (n1 * n1) + (n2 * n2))
                    printf("Rightangle triangle.\n");
                else
                    printf("Not Rightangle triangle.\n");
            }
            else
                printf("Not valid triangle.\n");
            break;

        case 3:
            printf("Enter three no: ");
            scanf("%d%d%d", &n1, &n2, &n3);

            if(n1+n2>n3 && n2+n3>n1 && n1+n3>n2) { 
                if (n1 == n2 && n2 == n3)
                    printf("This is equilateral triangle sides.\n");
                else
                    printf("This is not equilateral triangle sides.\n");
            }
            else
                printf("Not valid triangle.\n");

            break;

        case 4:
            flag = 1;
            break;

        default:
            printf("Invalid option.");
        }
    }
}

//Q5

void Q5(int value) {
    switch(value) {
        case 1:
            printf("Good");
            break;
        case 2:
            printf("Better");
            break;
        case 3:
            printf("Best");
            break;
        default:
            printf("Invalid");
    }

}

//Q6
void Q6() {
    int marks;
    printf("Enter your marks: ");
    scanf("%d", &marks);
    switch (marks)
    {
    case 90 ... 100:
        printf("Grade A");
        break;
    case 80 ... 89:
        printf("Grade B");
        break;
    case 70 ... 79:
        printf("Grade C");
        break;
    case 60 ... 69:
        printf("Grade D");
        break;
    case 50 ... 59:
        printf("Grade E");
        break;
    case 0 ... 49:
        printf("Grade F");
        break;
    default:
        printf("Invaild Marks.");
    }
}

//Q7
void Q7() {
    int choice, n1, sum;
    while(1) {
        printf("\n1.Factorial of a number.\n");
        printf("2.Check Even or Odd\n");
        printf("3.Sum of First N natural numbers.\n");
        printf("4.Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter a number: ");
            scanf("%d", &n1);
            sum = 1;
            for(int i = n1; i > 1; --i)
                sum*=i;
            printf("Factorial of %d is %d", n1, sum);
            break;
        case 2:
            printf("Enter a number: ");
            scanf("%d", &n1);
            if(n1&1)
                printf("%d is Odd number.", n1);
            else
                printf("%d is Even number.", n1);
            break;
        case 3:
            printf("Enter a number: ");
            scanf("%d", &n1);
            sum = 0;
            for(int i = 1; i <= n1; ++i)
                sum+=i;
            printf("Sum of first %d natural no is %d", n1, sum);
            break;
        default:
            exit(0);
        }
    }

}

//Q8
void Q8() {
    char ch;
    printf("Enter any charactor: ");
    scanf("%c", &ch);

    switch(ch) {
        case 'A' ... 'Z':
            printf("Uppercase alphabet.");
            break;
        case 'a' ... 'z':
            printf("Lowercase alphabet.");
            break;
        default :
            printf("Special charactor.");
    }

}

//Q9
void Q9() {
    char ch;
    printf("Enter any charactor: ");
    scanf("%c", &ch);

    switch(ch) {
        case 'A': case 'a': case 'E': case 'e':
        case 'I': case 'i': case 'O': case 'o':
        case 'U': case 'u':
            printf("Vowel");
            break;
        case 'B' ... 'D': case 'F' ... 'H':
        case 'J' ... 'N': case 'P' ... 'T': 
        case 'V' ... 'Z': 
        case 'b' ... 'd': case 'f' ... 'h': 
        case 'j' ... 'n': case 'p' ... 't': 
        case 'v' ... 'z':
            printf("Consonant.");
            break;
        default :
            printf("Special charactor.");
    }

}

//Q10
void LCM() {
    int n1, n2;
    printf("Enter two number: ");
    scanf("%d%d", &n1, &n2);
    int i = 2, sum = 1;
    while(n1 != 1 || n2 != 1) {
        if(n1%i != 0 && n2%i != 0) {
            ++i;
            continue;
        }    
        if(n1%i == 0) {
            n1/=i;
        }
        if(n2%i == 0)
            n2/=i;
        sum*=i;
    }
    printf("LCM is %d", sum);
}

void digit_sum() {
    int n1, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &n1);
    
    while(n1 != 0) {
        sum+=(n1%10);
        n1/=10;
    }
    printf("Digit sum is %d", sum);
}

void cuboid() {
    int n1, n2, n3;
    printf("Enter sides of cuboid: ");
    scanf("%d%d%d", &n1, &n2, &n3);
    
    printf("volume of cuboid %d", n1*n2*n3);

}

void is_prime() {
    int n1, i;
    printf("Enter a number: ");
    scanf("%d", &n1);
    
    for(i = 2; i <= n1/2; ++i) {
        if(n1%i == 0)
            break;
    }

    if(n1 > 1 && i > n1/2)
        printf("%d is prime number.\n", n1);
    else
        printf("%d is not prime number.\n", n1);
}

void Q10() {
    int choice, n1, n2, sum;
    while(1) {
        printf("\n1.LCM of two numbers.\n");
        printf("2.Sum of the digits of a number\n");
        printf("3.Volume of a cuboid.\n");
        printf("4.Check Prime no.\n");
        printf("5.Exit.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                LCM();
                break;
            case 2:
                digit_sum();
                break;
            case 3:
                cuboid();
                break;
            case 4:
                is_prime();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }

    }

}

int main()
{
    system("clear");
    Q10();

    printf("\n");
    return 0;
}