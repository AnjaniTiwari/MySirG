#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct book {
    int bookid;
    char title[20];
    float price;
};

void print_struct(struct book *p) {
    printf("%d %s %.2f\n", p->bookid, p->title, p->price);
}

void input(struct book *p) {
    char buffer[100];
    char* end;

    printf("Enter bookid.\n");
    fgets(buffer, sizeof(buffer), stdin);
    p->bookid = (int)strtol(buffer, &end, 10);
    // scanf("%d", &b3.bookid);
    // while(getchar() != '\n');
    
    printf("Enter title.\n");
    fgets(p->title, 20, stdin);
    p->title[strlen(p->title)-1] = '\0';
    
    printf("Enter price.\n");
    // scanf("%f", &b3.price);
    fgets(buffer, sizeof(buffer), stdin);
    p->price = (float)strtof(buffer, &end);
}

int main() {
    struct book b1 = {1, "C in depth.", 450.0};
    struct book b2;
    struct book b3;
    
    b2.bookid = 2;
    strcpy(b2.title, "C++ in depth.");
    b2.price = 550.0;

    input(&b3);
    print_struct(&b1);
    print_struct(&b2);
    print_struct(&b3);

    return 0;
}