#include <stdio.h>
#include <string.h>

//Q1
typedef struct {
    int id;
    char name[20];
    float salary;
}employee;

//Q2
void input_employee_data(employee* emp) {
    printf("Enter employee id : ");
    scanf("%d", &emp->id);
    getchar();
    printf("\nEnter employee name: ");
    fgets(emp->name, sizeof(emp->name)-1, stdin);
    emp->name[strlen(emp->name)-1] = '\0';
    printf("\nEnter employee salary: ");
    scanf("%f", &emp->salary);
}

//Q3
void display_employee_data(employee* emp) {
    printf("Id : %d\nName : %s\nsalary : %.3f\n", emp->id, emp->name, emp->salary);
}

//Q4
void highest_salary(employee* emp, int n) {
    int max = 0;
    for(int i = 0; i < n-1; ++i) {
        if(emp[max].salary < emp[i+1].salary)
            max = i+1;
    }
    printf("%d %s %.2f highest salary\n", emp[max].id, emp[max].name, emp[max].salary);
} 
void input(employee* emp, int n) {
    for(int i = 0; i < n; ++i) {
        printf("\nEmployee %d detail.\n", i+1);
        input_employee_data(&emp[i]);
    }
}

//Q5
void sort_salary(employee* emp, int n) {
    int i, j;
    employee temp;
    for(i = 0; i < n-1; ++i) {
        for(j = i; j < n-1-i; ++j) {
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

int main() {
    system("clear");
    employee emp[5];
    // input_employee_data(&e1);
    // display_employee_data(&e1);
    input(emp, 5);
    sort_salary(emp, 5);
    return 0;
}