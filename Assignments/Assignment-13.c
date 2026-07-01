#include <stdio.h>

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
            }
            else
                printf("This is not isosceles triangle sides.\n");
            break;

        case 2:
            printf("Enter three no: ");
            scanf("%d%d%d", &n1, &n2, &n3);
            if (n1 > n2)
            {
                if (n1 * n1 == (n2 * n2) + (n3 * n3))
                    printf("Rightangle triangle.\n");
                else
                    printf("Not Rightangle triangle.\n");
            }
            else if (n2 >= n3)
            {
                if (n2 * n2 == (n1 * n1) + (n3 * n3))
                    printf("Rightangle triangle.\n");
                else
                    printf("Not Rightangle triangle.\n");
            }
            else
            {
                if (n3 * n3 == (n1 * n1) + (n2 * n2))
                    printf("Rightangle triangle.\n");
                else
                    printf("Not Rightangle triangle.\n");
            }
            break;

        case 3:
            printf("Enter three no: ");
            scanf("%d%d%d", &n1, &n2, &n3);
            if (n1 == n2 && n2 == n3)
                printf("This is equilateral triangle sides.\n");
            else
                printf("This is not equilateral triangle sides.\n");
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

int main()
{
    system("clear");
    manu2();

    printf("\n");
}