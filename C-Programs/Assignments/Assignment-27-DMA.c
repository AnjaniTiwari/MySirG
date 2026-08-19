#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Q1
char* store_string(char* str) {
    int len = strlen(str);
    char* temp = (char*)calloc(sizeof(char), len+1);
    if(temp)
        strcpy(temp, str);
    return temp;
}

//Q2
void input_values() {
    int n, i, average = 0;
    printf("How many values you want to enter: ");
    scanf("%d", &n);
    if(n > 0) {
        int* value = (int*)calloc(sizeof(int), n);
        for(i = 0; i < n; ++i) {
            printf("\nEnter %d value: ", i+1);
            scanf("%d", value+i);
        }
        printf("\nYour all values.\n");
        for(i = 0; i < n; ++i) { 
            printf("%d ", value[i]);
            average+=value[i];
        }
        printf("\nAverage of this values %d", average/n);
        printf("\nSum of %d numbers is %d", n, average); //Q3
        free(value);
    }
}

//Q3
void sum_of_n_numbers() {
    int n, i, sum = 0;
    printf("How many numbers you want to enter: ");
    scanf("%d", &n);
    if(n > 0) {
        int* value = (int*)malloc(sizeof(int)*n);
        for(i = 0; i < n; ++i) {
            printf("\nEnter %d value: ", i+1);
            scanf("%d", value+i);
        }
        printf("\nYour all numbers.\n");
        for(i = 0; i < n; ++i) { 
            printf("%d ", value[i]);
            sum+=value[i];
        }
        printf("\nSum of %d numbers is %d", n, sum); 
        free(value);
    }
}

//Q4
int* marge_arr(int* arr1, int arr1_size, int* arr2, int arr2_size) {
    int* arr = (int*)calloc(sizeof(int), arr1_size+arr2_size);
    int i, j = 0;
    if(arr) {
        for(i = 0; i < arr1_size; ++i) 
            arr[j++] = arr1[i]; 
        for(i = 0; i < arr2_size; ++i) 
            arr[j++] = arr2[i]; 
    }
    return arr;
}

//Q5
typedef struct {
    char name[20];
    int rollno;
    char college[30];
} Student;
typedef struct {
    Student s[2];
} Team;

//Q6
Student* create_student(char* name, int rollno, char* college) {
    Student* s = (Student*)malloc(sizeof(Student));
    strcpy(s->name, name);
    s->rollno = rollno;
    strcpy(s->college, college);
    return s;
}

//Q7
Team* create_team(Student* s1, Student* s2) {
    Team* t = (Team*)malloc(sizeof(Team));
    strcpy(t->s[0].name, s1->name);
    t->s[0].rollno = s1->rollno;
    strcpy(t->s[0].college, s1->college);

    strcpy(t->s[1].name, s2->name);
    t->s[1].rollno = s2->rollno;
    strcpy(t->s[1].college, s2->college);
    return t;
}

//Q8
void display_student(Student* s) {
    printf("Rollno: %d Name: %s College: %s\n", s->rollno, s->name, s->college);
}

void display_team(Team* t) {
    display_student(&t->s[0]);
    display_student(&t->s[1]);
}

//Q9
Student** student_arr(int size) {
    return (Student**)calloc(sizeof(Student), size);
}

int main() {
    system("clear");
    
    // char str[20];
    // printf("Enter string: ");
    // fgets(str, sizeof(str)-1, stdin);
    // str[strlen(str)-1] = '\0';
    // char* temp = store_string(str);
    // printf("%s", temp);
    // free(temp);

    // input_values();

    // int arr1[] = {1, 2, 3};
    // int arr2[] = {4, 5};
    // int arr1_size = sizeof(arr1)/sizeof(arr1[0]); 
    // int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    // int* arr = marge_arr(arr1, arr1_size, arr2, arr2_size);
    // if(arr) {
    //     for(int i = 0; i < arr1_size+arr2_size; ++i)
    //         printf("%d ", arr[i]);
    //     free(arr);
    // }


    printf("\n");
    return 0;
}