#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Q1
char* input_string() {
    char ch;
    char* str = NULL, *temp = NULL;
    int slen = 0;
    printf("Enter text: ");
    while(1) {
        ch = getchar();
        if(ch == '\n' || ch == '\r')
            break;
        slen++;
        temp = (char*)realloc(str, slen+1);
        if(temp)
            str = temp;
        str[slen-1] = ch;
    }
    str[slen] = '\0';
    return str;
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
    return (Student**)calloc(sizeof(Student*), size);
}

//Q10
Team** team_arr(int size) {
    return (Team**)calloc(sizeof(Team*), size);
}

//Q11
void driver() {
    Team t_arr[3];
    int i, j;
    for(i = 0; i < 3; ++i) {
        printf("\nTeam : %d", i+1);
        for(j = 0; j < 2; ++j) {
            printf("\nEnter student rollno, name and college:");
            scanf("%d", &t_arr[i].s[j].rollno);
            getchar();
            fgets(t_arr[i].s[j].name, sizeof(t_arr[i].s[j].name), stdin);
            t_arr[i].s[j].name[strlen(t_arr[i].s[j].name)-1] = '\0';
            getchar();
            fgets(t_arr[i].s[j].college, sizeof(t_arr[i].s[j].college), stdin);
            t_arr[i].s[j].college[strlen(t_arr[i].s[j].college)-1] = '\0';
        }
    }

    printf("\n");

    for(i = 0; i < 3; ++i) {
        printf("\nTeam : %d", i+1);
        for(j = 0; j < 2; ++j) {
            printf("\nRollno %d Name %s College %s\n", t_arr[i].s[j].rollno, 
                                                     t_arr[i].s[j].name, 
                                                     t_arr[i].s[j].college);
        }
        printf("\n\n");
    }
}

int main() {
    system("clear");
    
    char* temp = input_string();
    printf("%s", temp);
    free(temp);

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

    // driver();

    printf("\n");
    return 0;
}