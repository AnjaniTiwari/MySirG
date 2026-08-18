#include <stdio.h>
#include <string.h>

//Q1
typedef struct {
    int id;
    char name[20];
    float salary;
}Employee;

//Q7
typedef struct {
    int hours, minutes, seconds;
}Time;

//Q8
typedef struct {
    int rollno;
    char name[20];
    int chemistry_marks, mathematics_marks, physics_marks;
}Student;

//Q2
void input_employee_data(Employee* emp) {
    printf("Enter Employee id, name and salary: ");
    scanf("%d", &emp->id);
    getchar();
    fgets(emp->name, sizeof(emp->name)-1, stdin);
    emp->name[strlen(emp->name)-1] = '\0';
    scanf("%f", &emp->salary);
}

//Q3
void display_employee_data(Employee* emp) {
    printf("Id : %d\nName : %s\nsalary : %.3f\n", emp->id, emp->name, emp->salary);
}

//Q4
void highest_salary(Employee* emp, int n) {
    int max = 0;
    for(int i = 0; i < n-1; ++i) {
        if(emp[max].salary < emp[i+1].salary)
            max = i+1;
    }
    printf("%d %s %.2f highest salary\n", emp[max].id, emp[max].name, emp[max].salary);
} 
void input(Employee* emp, int n) {
    for(int i = 0; i < n; ++i) {
        printf("\nEmployee %d detail.\n", i+1);
        input_employee_data(&emp[i]);
    }
}

//Q5
void print_employee(Employee* emp, int n) {
    for(int i = 0; i < n; ++i) {
        display_employee_data(&emp[i]);   
    }
}
void sort_by_salary(Employee* emp, int n) {
    int i, j;
    Employee temp;
    for(i = 0; i < n-1; ++i) {
        for(j = 0; j < n-1-i; ++j) {
            if(emp[j].salary > emp[j+1].salary) {
                temp.id = emp[j].id;
                strcpy(temp.name, emp[j].name);
                temp.salary = emp[j].salary;

                emp[j].id = emp[j+1].id;
                strcpy(emp[j].name, emp[j+1].name);
                emp[j].salary = emp[j+1].salary;

                emp[j+1].id = temp.id;
                strcpy(emp[j+1].name, temp.name);
                emp[j+1].salary = temp.salary;
            }
        }
    }
}

//Q6
void sort_by_name(Employee* emp, int n) {
    int i, j;
    Employee temp;
    for(i = 0; i < n-1; ++i) {
        for(j = 0; j < n-1-i; ++j) {
            if(strcmp(emp[j].name, emp[j+1].name) > 0) {
                temp.id = emp[j].id;
                strcpy(temp.name, emp[j].name);
                temp.salary = emp[j].salary;

                emp[j].id = emp[j+1].id;
                strcpy(emp[j].name, emp[j+1].name);
                emp[j].salary = emp[j+1].salary;

                emp[j+1].id = temp.id;
                strcpy(emp[j+1].name, temp.name);
                emp[j+1].salary = temp.salary;
            }
        }
    }
}

//Q7
void time_difference(Time* t1, Time* t2) {
    Time t;
    if(t2->seconds < t1->seconds) {
        if(t2->minutes <= 0) {
            if(t2->hours <= 0) {
                printf("Difference not possible.\n");
                return;
            }
            t2->hours--;
            t2->minutes = 60;
        }
        else {
            t2->minutes--;
            t2->seconds += 60;
        }
    }
    t.seconds = t2->seconds - t1->seconds;

    if(t2->minutes < t1->minutes) {
        if(t2->hours <= 0) {
            printf("Difference not possible.\n");
            return;
        }
        t2->hours--;
        t2->minutes += 60;
    }
    t.minutes = t2->minutes - t1->minutes;

    if(t2->hours < t1->hours) {
        printf("Difference not possible.\n");
        return;
    }
    t.hours = t2->hours - t1->hours;
    printf("%d : %d : %d\n", t.hours, t.minutes, t.seconds);
}

//Q8
void input_student_details(Student* s) {
    printf("\nEnter Student rollno: ");
    scanf("%d", &s->rollno);
    getchar();
    printf("Enter Student name: ");
    fgets(s->name, 20, stdin);
    s->name[strlen(s->name)-1] = '\0';
    printf("Enter chemistry marks out of 100: ");
    scanf("%d", &s->chemistry_marks);
    printf("Enter mathematics marks out of 100: ");
    scanf("%d", &s->mathematics_marks);
    printf("Enter physics marks out of 100: ");
    scanf("%d", &s->physics_marks);
}

void display_student_details(Student* s) {
    printf("%d - %s\n", s->rollno, s->name);
    printf("Chemistry - %d Mathematics - %d Physics - %d\n", s->chemistry_marks,
                                                           s->mathematics_marks, 
                                                           s->physics_marks);
}

//Q10
void student_percentage(Student* emp, int n) {
    float per;
    for(int i = 0; i < n; ++i) {
        per = (emp[i].chemistry_marks + emp[i].mathematics_marks + emp[i].physics_marks)*(100.0/300.0);
        printf("%d - %s percentage - %.2f%%\n", emp[i].rollno, emp[i].name, per);
    }
}

int main() {
    system("clear");
    Employee emp[5];
    // input_employee_data(&e1);
    // display_employee_data(&e1);
    // input(emp, 3);
    // print_employee(emp, 3);
    // sort_salary(emp, 3);
    // sort_name(emp, 3);
    // printf("\n");
    // print_employee(emp, 3);
    // Time t1, t2;
    // t1.hours = 12;
    // t1.minutes = 29;
    // t1.seconds = 47;

    // t2.hours = 14;
    // t2.minutes = 59;
    // t2.seconds = 37;
    // time_difference(&t1, &t2);

    int i;
    Student s[3];
    for(i = 0; i < 3; ++i) {
        input_student_details(&s[i]);
    }
    
    // for(i = 0; i < 3; ++i) 
    //     display_student_details(&s[i]);

    student_persentage(s, 3);
    return 0;
}