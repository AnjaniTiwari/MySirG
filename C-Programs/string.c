#include <stdio.h>
#include <string.h>

int main()
{
    system("clear");
    char str[20] = {'B', 'H', 'O', 'P', 'A', 'L'};
    
    // for(int i = 0; str[i]; ++i)
    //     printf("%c", str[i]);
    
    // int len;
    // for(len = 0; str[len]; ++len);
    
    // printf("%s len = %d", str, len);
    
    // printf("Enter your name: ");
    // scanf("%s", str);
    // gets(str);
    // fgets(str, sizeof(str), stdin);
    // str[strlen(str)-1] = '\0';
    // printf("\"%s\" length is %d", str, strlen(str));

    printf("LCM %d", LCM(6, 8));
    printf("\n");
    return 0;
}