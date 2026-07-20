#include <stdio.h>

void swap(int *n1, int *n2) {
    int n3 = *n1;
    *n1 = *n2;
    *n2 = n3;
}

void input_1(int *a, int size) {
    for(int i = 0; i < size; ++i)
        a[i] = i+1;
}

void display_1(int *a, int size) {
    for(int i = 0; i < 10; ++i)
        printf("%d ", *(a+i));
}

int length(char* str) {
    int len = 0; 
    while(*(str+len) != '\n')
        len++;
    return len;
}

void input(int **p, int size, int *size_arr) {
    for(int i = 0; i < size; ++i) {
        printf("Enter %d numbers: ", size_arr[i]);
        for(int j = 0; j < size_arr[i]; ++j) {
            scanf("%d", *(p+i)+j); // &p[i][j]
        }
    }
}

void display(int **p, int size, int *size_arr) {
   for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size_arr[i]; ++j) {
            printf("%d ", *(*(p+i)+j)); // p[i][j]
        }
        printf("\n");
    }
}

void f1(int (*x)[2], int size) {
    for(int i = 0; i < size; ++i) {
        printf("\nEnter 2 numbers: ");
        for(int j = 0; j < 2; ++j) {
            scanf("%d", *x+j);
        }
        x++;
    }
}

void f1_display(int (*x)[2], int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < 2; ++j) {
            printf("%d ", *(*x+j));
        }
        x++;
        printf("\n");
    }
}


int main()
{
    system("clear");
    // int n1, n2;
    // int a[10];
    // char str[20];

    // printf("Enter two numbers: ");
    // scanf("%d%d", &n1, &n2);
    // swap(&n1, &n2);
    // printf("n1 = %d n2 = %d", n1, n2);
    // input_1(a, 10);
    // display(a, 10);

    // fgets(str, 20, stdin);
    // printf("len = %d", length(str));

    int a[3], b[2], c[2], d[1];
    int size[4] = {3, 2, 2, 1};
    int *p[4] = {a, b, c, d};
    int x[3][2] = {{1, 2}, {3, 4}, {2, 1}};

    // input(p, 4, size);
    // display(p, 4, size);
    f1(x, 3);
    f1_display(x, 3);
    printf("\n");
    return 0;
}