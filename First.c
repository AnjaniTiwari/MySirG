/*
#include <stdio.h>
#include <unistd.h>
int main() {
    system("clear");
    // int z = 10;
    // for(int i = 0; i <= 100; i+=10) {
    //     printf("\rProgress: %d%%#", i);
    //     fflush(stdout);
    //     sleep(1);
    // }
    // printf("Welcome\bStudents\n");
    // printf("z = %d\n", z);

    // int a = 5, b = 6;
    // printf("%d %d\n", a, b);
    // printf("a=%d and b=%d\n", a, b);
    // printf("a=%d & b=%d\n", a, b);
    // printf("value of a is %d and value of b us %d\n", a, b);
    // printf("sum of %d and %d is %d\n", a, b, a+b);
    // printf("%d + %d = %d\n", a, b, a+b);

    int a, b;

    printf("Enter two integer:");
    scanf("%d %d", &a, &b);
    printf("sum of %d and %d is %d\n", a, b, a+b);

    printf("\n");
    return 0;
}

//Assignment 1: Input and Output in C Language
#include <stdio.h>
#define PI 3.14
int main() {
    system("clear");
    int n1, n2;
    printf("Hello Student\n");
    printf("Hello\nStudent\n");
    printf("\"MySirG\"\n");
    printf("\\n\n");
    printf("\\r\n");
    printf("\"Teacher\'s Day\"\n");
    
    printf("Enter two numbers: ");
    scanf("%d%d", &n1, &n2);
    printf("Sum of %d and %d is %d\n", n1, n2, n1+n2);

    printf("Enter number: ");
    scanf("%d", &n1);
    printf("Square of %d is %d\n", n1, n1*n1);

    printf("Enter length and breadth of rectangle: ");
    scanf("%d%d", &n1, &n2);
    printf("length %d and breadth %d rectangle area %d\n", n1, n2, n1*n2);

    printf("Enter radius of cricle: ");
    scanf("%d", &n1);
    printf("Area of cricle is %d having the radius %f\n", n1, PI*(n1*n1));



    printf("\n");
    return 0;
}


//Assignment 2: More on printf and scanf
#include <stdio.h>
#define PI 3.14
int main() {
    system("clear");

    int n1, n2, n3;
    printf("Enter three numbers:");
    scanf("%d%d%d", &n1, &n2, &n3);
    float average = (n1+n2+n3)/3.0; 
    printf("Average is %f\n", average);

    printf("Enter cricle radius:");
    scanf("%d", &n1);
    float circumference =  2*PI*n1;
    printf("Circumference : %f\n", circumference);   

    int principal_amount, rate_of_interest, time;
    printf("Enter principle amount:");
    scanf("%d", &principal_amount);
    
    printf("\nEnter rate of interest (%% per year):");
    scanf("%d", &rate_of_interest);

    printf("\nEnter time (year):");
    scanf("%d", &time);
    
    float simple_interest = (principal_amount*rate_of_interest*time)/100.0;
    printf("simple interest: %f\n", simple_interest);

    int length, breadth, height, area;

    printf("Enter length and breadth and height of cuboid:");
    scanf("%d%d%d", &length, &breadth, &height);

    area = length*breadth*height;
    printf("Area of cuboid %d\n", area);

    int selling_price, cost_price, sell_bananas;
    float cost_of_banana, selling_price_of_banana;  
    printf("Enter cost price of banana per dozer: ");
    scanf("%d", &cost_price);
    printf("\nEnter how many bananas you sell and selling price: ");
    scanf("%d%d", &sell_bananas, &selling_price);
    cost_of_banana = cost_price/12.0f;
    selling_price_of_banana = selling_price/sell_bananas;
    
    if(selling_price_of_banana > cost_of_banana) 
        printf("profit %f", (selling_price_of_banana-cost_of_banana)*sell_bananas);
    else
        printf("loss %f", (cost_of_banana-selling_price_of_banana)*sell_bananas);

    char ch;
    printf("Enter any charector:");
    scanf(" %c", &ch);
    printf("ASCII Code %d\n", ch);

    printf("Enter ASCII Code Range(0-255):");
    scanf(" %d", &ch);
    printf("ASCII Code %d charector %c\n", ch, ch);

    char ch2, ch3;
    printf("Enter any 3 charector:");
    scanf(" %c %c %c", &ch, &ch2, &ch3);
    printf("ASCII Codes %d %d %d\n", ch, ch2, ch3);

    int dd, mm, yyyy;
    printf("Enter date format DD/MM/YYYY:");
    scanf("%d/%d/%d", &dd, &mm, &yyyy);
    printf("Day-%d, Month-%d, Year-%d\n", dd, mm, yyyy);

    int HH, MM;
    printf("Enter Time format HH:MM:");
    scanf("%d:%d", &HH, &MM);
    printf("%d hour, %d minute\n", HH, MM);

    printf("\n");
    return 0;
}
*/

/*
#include <stdio.h>
int main() {
    system("clear");
    int x = 4, y = 56;

    printf("x = %d y = %d\n", x, y);
    // int z = x;
    x = x+y;
    y = x-y;
    x = x-y;
    printf("x = %d y = %d\n", x, y);

    x>0 ? printf("%d is positive.\n", x):printf("%1q    qd is non-positive.\n", x);

    printf("\n");
    return 0;
}
*/

//Assignment 3 Operators 

// #include <stdio.h>
// int main() {
//     system("clear");
    
    // 1.
    // printf("size of a charector constant %d\n", sizeof('A'));
    
    // 2.
    // printf("size of a real constant %d\n", sizeof(3.14));

    // 3.
    // char ch;
    // ch = 'A';
    // printf("charector constant %c\n", ch);
    // ch++;
    // printf("charector constant %c\n", ch);

    // 4.
    // int num;
    // printf("Enter any number: ");
    // scanf("%d", &num);
    // printf("Unit digit: %d\n", num%10);

    // 5.
    // int num;
    // printf("Enter any number: ");
    // scanf("%d", &num);
    // // num-=num%10;
    // printf("Without Unit digit: %d\n", num/10);

    // 6.
    // int x = 10, y = 11;

    // printf("x = %d y = %d\n", x, y);
    // x+=y;
    // y=x-y;
    // x-=y; 
    // printf("x = %d y = %d\n", x, y);

    // 7.
    // int x = 12, y = 6;

    // printf("x = %d y = %d\n", x, y);
    // // x+=y;
    // // y-=x;
    // // x+=y;
    // // y=~y;
    // // y++;
    // x = x*y;
    // y = x/y;
    // x = x/y;

    // printf("x = %d y = %d\n", x, y);

    // 8.
    // int x = 9, y = 78;

    // printf("x = %d y = %d\n", x, y);

    // x = x^y;
    // y = x^y;
    // x = x^y;
    
    // printf("x = %d y = %d\n", x, y);

    // printf("\n");
    // return 0;

    // 9.
//     int x = 1, y = 2;

//     printf("x = %d y = %d\n", x, y);
//     // y = x+y, x = y-x, y = y-x;
//     x = x+y-(y=x);
//     printf("x = %d y = %d\n", x, y);

//     printf("\n");
//     return 0;
// }


//Assignment 4 More operators
/*
#include <stdio.h>
int main() {
    system("clear");
    
    // 1.
    // int x = 2315101;
    // int sum = 0;
    // while(x) {
    //     sum+=x%10;
    //     x/=10;
    // }
    // printf("%d ", sum);

    // 2.
    // printf("%d", '+');

    // 3
    // int i = 10;
    // char ch = 'A';
    // float f = 3.14;
    // double du = 3.4156778;
    
    // printf("size of int : %d\n", sizeof(i));
    // printf("size of int : %d\n", sizeof(ch));
    // printf("size of int : %d\n", sizeof(f));
    // printf("size of int : %d\n", sizeof(du));

    // 4
    // int x = 2345;
    // // x-=x%10;
    // x = x/10*10;
    // printf("%d", x);

    //5
    // int x,y;
    // printf("Enter a number: ");
    // scanf("%d", &x);
    
    // printf("Enter a digit: ");
    // scanf("%d", &y);
    
    // x*=10;
    // x+=y;
    // x = x*10+y;
    // printf("%d", x);


    // 5
    // float inrRate = 84.23, inr, usd;
    // printf("Enter a number: ");
    // scanf("%f", &inr);
    // usd = inr/inrRate;
    // printf("In USD %f", usd);

    // 6
    // int num;
    // printf("Enter a number: ");
    // scanf("%d", &num);
    
    // int remender = (num%10)*100;
    // num = remender + (num/10);
    
    // printf("%d", num);

    // 7
    // int x;
    // x = 10>8>4;
    // printf("%d", x);

    // 8
    // int x;
    // x = !2>-2;
    // printf("%d", x);

    // 8
    // int x;
    // x = 3<0&&5>0;
    // printf("%d", x);

    printf("\n");
    return 0;
}
*/

//Assignment 5

#include <stdio.h>

//1.
//int main() {
//	int num;
//	printf("Enter a number: ");
//	scanf("%d", &num);
//	if(num > 0)
//		printf("Positive.");
//	else
//		printf("Non-Positive.");
//	getch();
//	return 0;
//}


////2.
//int main() {
//	int num;
//	printf("Enter a number: ");
//	scanf("%d", &num);
//	if(num%5 == 0)
//		printf("%d is divisible by 5.", num);
//	else
//		printf("%d is not divisible by 5.", num);
//	getch();
//	return 0;
//}

////3.
//int main() {
//	int num;
//	printf("Enter a number: ");
//	scanf("%d", &num);
//	if(num%2 == 0)
//		printf("%d is even no.", num);
//	else
//		printf("%d is odd no.", num);
//	getch();
//	return 0;
//}

// //4.
// int main() {
// 	int num;
//     int val;
// 	printf("Enter a number: ");
// 	scanf("%d", &num);
// 	//first method
// //	val = num/2;
// //	if(val == num*2)
// //		printf("%d is even no.", num);
// //	else
// //		printf("%d is odd no.", num);
// 	//second method
// 	if((num&1) == 0)
// 		printf("%d is even no.", num);
// 	else
// 		printf("%d is odd no.", num);
// 	getch();
// 	return 0;
// }

// //5.
// int main() {
//     system("clear");
// 	int num;
//     int digit_count = 0;
// 	printf("Enter a number: ");
// 	scanf("%d", &num);
// 	while(num > 0) {
//         ++digit_count;
//         num/=10;
//     }
//     printf("digit count %d", digit_count);
//     printf("\n");
// 	return 0;
// }

// //6.
// int main() {
//     system("clear");
// 	int num1, num2;
// 	printf("Enter two numbers: ");
// 	scanf("%d%d", &num1, &num2);
// 	if(num1 > num2)
//         printf("grater no %d", num1);
//     else if(num1 < num2)
//         printf("grater no %d", num2);
//     else 
//         printf("No %d", num1);
//     printf("\n");
// 	return 0;
// }

// //7.
// int main() {
//     system("clear");
// 	int num1, num2;
// 	printf("Enter two numbers: ");
// 	scanf("%d%d", &num1, &num2);
// 	if(num1 > num2)
//         printf("grater no %d", num1);
//     else if(num1 < num2)
//         printf("grater no %d", num2);
//     else 
//         printf("No %d", num1);
//     printf("\n");
// 	return 0;
// }

// //8.
// int main() {
//     system("clear");
//     int a, b, c;
// 	printf("Enter two numbers: ");
// 	scanf("%d%d%d", &a, &b, &c);
    
// 	int d = (b*b)-(4*a*c);

//     if(d > 0)
//         printf("%d Real and distinct root.", d);
//     else if(d == 0)
//         printf("%d Real and equal root.", d);
//     else
//         printf("%d Imaginary (complex)roots", d);
//     printf("\n");
// 	return 0;
// }

// //9.
// int main() {
//     system("clear");
//     int year;
// 	printf("Enter any year: ");
// 	scanf("%d", &year);
    
//     if(year%100) {
//         if(year%4)
//             printf("%d is non-leap year.", year);    
//         else
//             printf("%d is the leap year.", year);
//     }
//     else {
//         if(year%400)
//             printf("%d is the non-leap year.", year);
//         else    
//             printf("%d is the leap year.", year);
//     }
//     printf("\n");
// 	return 0;
// }

// //10.
// int main() {
//     system("clear");
//     int n1, n2, n3;
// 	printf("Enter three no: ");
// 	scanf("%d%d%d", &n1, &n2, &n3);
    
//     if(n1 >= n2 && n1 >= n3)
//         printf("%d is grater.", n1);
//     else if(n2 >= n3)
//         printf("%d is grater.", n2);
//     else
//         printf("%d is grater.", n3);
//     printf("\n");
// 	return 0;
// }

// Iterative Control instructions
// //1.
// int main() {
//     system("clear");
//     int i = 1;
//     while(i++ <= 5)
//         printf("Hello\n");
//     printf("\n");
// 	return 0;
// }

// //2.
// int main() {
//     system("clear");
//     int i = 1;
//     while(i <= 10)
//         printf("%d ", i++);
//     printf("\n");
// 	return 0;
// }

// //3.
// int main() {
//     system("clear");
//     int i = 1, n;
//     printf("Enter any natural no: ");
//     scanf("%d", &n);
//     if(n > 0) 
//         while(i <= n)
//             printf("%d ", i++);
//     else
//         printf("%d is not a natural no", n);
//     printf("\n");
// 	return 0;
// }

//Assignment 6 : More on Decision Control Statements
// //1.
// int main() {
//     system("clear");
//     int no, digit_count = 0;
//     printf("Enter a no: ");
//     scanf("%d", &no);
//     while(no) {
//         no/=10;
//         digit_count++;
//     }
//     printf("digit count %d", digit_count);
//     printf("\n");
// 	return 0;
// }

// //2.
// int main() {
//     system("clear");
//     int cost_price, selling_price;
//     printf("Enter cost price and selling price :\n");
//     scanf("%d%d", &cost_price, &selling_price);
//     float pl_price = selling_price-cost_price;
//     float parcentage = (pl_price/(float)cost_price)*100.0f;
//     printf("Profit and loss parcentage : %2.2f%%", parcentage);
//     printf("\n");
// 	return 0;
// }

// //3.
// int main() {
//     system("clear");
//     int s1, s2, s3, s4, s5;
//     printf("Enter 5 subject masks:\n");
//     scanf("%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5);
//     if(s1 >= 33 && s2 >= 33 && s3 >= 33 && s4 >= 33 && s5 >= 33)
//         printf("Result : Pass.\n");
//     else
//         printf("Result : Fail.\n");
//         printf("\n");
// 	return 0;
// }

// //4.
// int main() {
//     system("clear");
//     char ch = 'z';
//     scanf("%c", &ch);
//     if(ch >= 'A' && ch <= 'Z')
//         printf("Uppercase %c", ch);
//     else if(ch >= 'a' && ch <= 'z')
//         printf("Lowercase %c", ch);
//     else
//         printf("Not a alphabet %c", ch);
//     printf("\n");
// 	return 0;
// }

// //5.
// int main() {
//     system("clear");
//     int num;
//     scanf("%d", &num);
//     if(num%2 == 0 && num%3 == 0)
//         printf("%d is divisible by 2 and 3", num);
//     else
//         printf("%d is not divisible by 2 and 3", num);
//     printf("\n");
// 	return 0;
// }

// //6.
// int main() {
//     system("clear");
//     int num;
//     scanf("%d", &num);
//     if(num%7 == 0)
//         printf("%d is divisible by 7", num);
//     else if(num%3 == 0)
//         printf("%d is divisible by 3", num);
//     else
//         printf("%d is not divisible by 7 and 3", num);
//     printf("\n");
// 	return 0;
// }

// //7.
// int main() {
//     system("clear");
//     int num;
//     scanf("%d", &num);
//     if(num == 0)
//         printf("%d is zero", num);
//     else if(num > 0)
//         printf("%d is positive", num);
//     else
//         printf("%d is negative", num);
//     printf("\n");
// 	return 0;
// }

// //8.
// int main() {
//     system("clear");
//     char ch = '9';
//     scanf("%c", &ch);
//     if(ch >= 'A' && ch <= 'Z')
//         printf("Uppercase %c", ch);
//     else if(ch >= 'a' && ch <= 'z')
//         printf("Lowercase %c", ch);
//     else if(ch >= '0' && ch <= '9')
//         printf("digit %c", ch);
//     else 
//         printf("special charector %c", ch);
//     printf("\n");
// 	return 0;
// }

// //9.
// int main() {
//     system("clear");
//     int s1, s2, s3;
//     scanf("%d%d%d",&s1, &s2, &s3);
//     if(s1+s2 > s3 && s2+s3 > s1 && s3+s1 > s2)
//         printf("Valid Triangle.");
//     else 
//         printf("Not Valid Triangle.");
//     printf("\n");
// 	return 0;
// }

// //10.
// int main() {
//     system("clear");
//     int month;
//     scanf("%d",&month);
//     if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
//         printf("31 days.");
//     else if(month == 2)
//         printf("28 or 29 days.");
//     else 
//         printf("30 days.");
//     printf("\n");
// 	return 0;
// }

//loop practice
//1.
// int main() {
//     system("clear");
//     int num, chance = 1;
//     do {
//         printf("Enter any even num: ");
//         scanf("%d",&num);
//         if((num&1) == 0) {
//             printf("You Win.\n");
//             break;
//         }
//     }while(++chance <= 3);
    
//     if(chance == 4)
//         printf("Game Over.\n");    


//     printf("\n");
// 	return 0;
// }

// //2
// int main() {
//     system("clear");
//     int n1, sum = 0;
//     printf("Enter two number:");
// 	do {
// 		scanf("%d", &n1);
// 		if(n1 == 0)
// 			break;
// 		sum+=n1;
// 	} while(1);
//     	printf("%d\n", sum);
//         printf("\n");
// 	return 0;
// }

// //3.
// int main() {
//     system("clear");
//     for(int i = 1; i<=5; ++i) {
//         for(int j = 1; j<=5; ++j) {
//             if(j <= 6-i)
//                 printf("*");
//             else    
//                 printf(" ");
//         }
//         printf("\n");
//     }
//     printf("\n");
// 	return 0;
// }

//Assignment no 7
// //1.
// int main() {
//     system("clear");
//     for(int i = 1; i<=5; ++i) {       
//         printf("MySirG\n");
//     }
//     printf("\n");
// 	return 0;
// }

// //2.
// int main() {
//     system("clear");
//     for(int i = 1; i<=10; ++i) {       
//         printf("%d ", i);
//     }
//     printf("\n");
// 	return 0;
// }

// //3.
// int main() {
//     system("clear");
//     for(int i = 1; i<=10; ++i) {       
//         printf("%d ", 11-i);
//     }
//     printf("\n");
// 	return 0;
// }

// //4.
// int main() {
//     system("clear");
//     // for(int i = 1; i<=20; ++i)       
//     //     if(i&1)
//     //         printf("%d ", i);
//     for(int i = 1; i <= 19; i+=2)
//         printf("%d ", i);
//     printf("\n");
// 	return 0;
// }

// //5.
// int main() {
//     system("clear");
//     // for(int i = 1; i<=20; ++i)       
//     //     if(i&1)
//     //         printf("%d ", 22-i);
//     // for(int i = 1; i<=20; i+=2)       
//     //     printf("%d ", 20-i);
//     for(int i = 1; i<=10; ++i)       
//         // printf("%d ", (20-i)-(i-1));
//         printf("%d ", 21-2*i);
//     printf("\n");
// 	return 0;
// }

// //6.
// int main() {
//     system("clear");
//     // for(int i = 1; i<=20; ++i)       
//     //     if((i&1) == 0)
//     //         printf("%d ", i);
//     // for(int i = 2; i<=20; i+=2)       
//     //     printf("%d ", i);
//     for(int i = 1; i<=10; ++i)       
//         printf("%d ", 2*i);
//     printf("\n");
// 	return 0;
// }

// //7.
// int main() {
//     system("clear");
//     // for(int i = 1; i<=20; ++i)       
//     //     if((i&1) == 0)
//     //         printf("%d ", 22-i);
//     // for(int i = 2; i<=20; i+=2)       
//     //     printf("%d ", 22-i);
//     for(int i = 1; i<=10; ++i)       
//         printf("%d ", 22-(2*i));
//         printf("\n");
// 	return 0;
// }

// //8.
// int main() {
//     system("clear");
//     for(int i = 1; i<=10; ++i)       
//         printf("%d ", i*i);
//     printf("\n");
// 	return 0;
// }

// //9.
// int main() {
//     system("clear");
//     for(int i = 1; i<=10; ++i)       
//         printf("%d ", i*i*i);
//     printf("\n");
// 	return 0;
// }

// //10.
// int main() {
//     system("clear");
//     for(int i = 1; i<=10; ++i)       
//         printf("5 * %d = %d", i, 5*i);
//     printf("\n");
// 	return 0;
// }

// Assignment - 8 More on iterative Control Statements
// 1.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     while(n) {
//         printf("MySirG\n");
//         n--;
//     }
//     return 0;
// }

// //2.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", i);
//     return 0;
// }

// //3.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", n+1-i);
//     printf("\n");
//     return 0;
// }


// //4.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", 2*i-1);
//     printf("\n");
//     return 0;
// }

// //5.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", 2*(n-i)+1);
//     printf("\n");
//     return 0;
// }

// //6.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", 2*i);
//     printf("\n");
//     return 0;
// }

// //7.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", 2*(n-i)+2);
//     printf("\n");
//     return 0;
// }

// //8.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", i*i);
//     printf("\n");
//     return 0;
// }

// //9.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i)
//         printf("%d ", i*i*i);
//     printf("\n");
//     return 0;
// }

// //10.
// int main() {
//     system("clear");
//     int n;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= 10; ++i)
//         printf("%d * %d  = %d\n",n, i, n*i);
//     printf("\n");
//     return 0;
// }

//Assignment - 9 Use any loop

// //.1
// int main() {
//     system("clear");
//     int n, sum = 0;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i) {
//         printf("%d ", i);
//         sum+=i;
//         }
//     printf("sum %d \n",sum);
//     printf("\n");
//     return 0;
// }

// //.2
// int main() {
//     system("clear");
//     int n, sum = 0;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i) {
//         printf("%d ", i*2);
//         sum+=(2*i);
//     }
//     printf("sum %d \n",sum);
//     printf("\n");
//     return 0;
// }

// //.3
// int main() {
//     system("clear");
//     int n, sum = 0;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i) {
//         printf("%d ", 2*i-1);
//         sum+=(2*i-1);
//     }
//     printf("sum %d \n",sum);
//     printf("\n");
//     return 0;
// }

// //.4
// int main() {
//     system("clear");
//     int n, sum = 0;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i) {
//         printf("%d ", i*i);
//         sum+=(i*i);
//     }
//     printf("sum %d \n",sum);
//     printf("\n");
//     return 0;
// }

// //.5
// int main() {
//     system("clear");
//     int n, sum = 0;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i) {
//         printf("%d ", i*i*i);
//         sum+=(i*i*i);
//     }
//     printf("sum %d \n",sum);
//     printf("\n");
//     return 0;
// }

// //6.
// int main() {
//     system("clear");
//     int n, sum = 1;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     for(int i = 1; i <= n; ++i) {
//         printf("%d ", n-i+1);
//         sum*=(n-i+1);
//     }
//     printf("sum %d \n",sum);
//     printf("\n");
//     return 0;
// }

// //7.
// int main() {
//     system("clear");
//     int n, digit_count = 0;
//     printf("Enter a num: ");
//     scanf("%d", &n);
//     while(n) {
//         digit_count++;
//         n/=10;
//     }
//     printf("digit count %d \n",digit_count);
//     printf("\n");
//     return 0;
// }

//8.
int main() {
    system("clear");
    int n, digit_count = 0;
    printf("Enter a num: ");
    scanf("%d", &n);
    if(n%2)
    printf("digit count %d \n",digit_count);
    printf("\n");
    return 0;
}