#include <stdio.h>

//Q1
void add_matrics(int (*arr1)[3], int size, int (*arr2)[3]) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", arr1[i][j]+arr2[i][j]);
        }
        printf("\n");
    }
}

//Q2
void product_matrics(int (*arr1)[3], int size, int (*arr2)[3]) {
    int sum, k = 0;
    int arr3[3][3] = {'\0'};

    for(int row = 0; row < size; ++row) {
        for(int z = 0; z < size; ++z) {
            for(int column = 0; column < size; ++column) {
                arr3[row][z]+=(arr1[row][column]*arr2[column][z]);
            }
            printf("%d ", arr3[row][z]);
        }
        printf("\n");
    }
}

//Q3
void transpose_matrics(int (*arr1)[3], int size) {
    printf("Before transpose\n");
    int temp;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nAfter transpose\n");
    for(int i = 1; i < size; ++i) {
        for(int j = 0; j < i; ++j) {
            temp = arr1[i][j];
            arr1[i][j] = arr1[j][i];
            arr1[j][i] = temp;
        }
    }
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
}

//Q4
void reset_score_board(int(*board)[4], int total_players) {
    for(int i = 0; i < total_players; ++i)
        for(int j = 0; j < total_players; ++j)
            board[i][j] = -1;
}

void display_score_board(int(*board)[4], int total_players) {
    printf("Player score board\n");
    printf("  ");
    for(int i = 0; i < total_players; ++i) 
        printf("%2c ", 'A'+i);
    printf("\n");
    
    for(int i = 0; i < total_players; ++i) {
        printf("%c ", 'A'+i);
        for(int j = 0; j < total_players; ++j)
            printf("%2d ", board[i][j]);
        printf("\n");
    }
}

void update_score_board(int(*board)[4], int total_players) {
    char p1, p2, flag;
    int result, i, j;
    show_score_board(board, total_players);
    printf("player %c to %c\n", 'A', 'A'+total_players-1);

    printf("Enter which player vs player: ");
    while(getchar() != '\n');
    scanf("%c %c", &p1, &p2);

    printf("Player win 2 drow 1 loss 0.\n");
    for(i = 0; !flag && i < total_players-1; ++i) {
        for(j = i+1; !flag && j < total_players; ++j) {
            if(p1 == 'A'+i && p2 == 'A'+j) {
                printf("Player %c vs Player %c\n", 'A'+i, 'A'+j);
                printf("Enter player %c Result:", 'A'+i);
                scanf("%d", &result); 
                switch(result) {
                    case 0:
                        board[i][j] = 0;
                        board[j][i] = 2;
                        break;
                    case 1:
                        board[i][j] = 1;
                        board[j][i] = 1;
                        break;
                    case 2:
                        board[i][j] = 2;
                        board[j][i] = 0;
                        break;
                    default: 
                        printf("Wrong Result.\n");
                }   
                flag = 1;
            }
        }
    }

    if(!flag) {
        printf("Invaild input.\n");
        printf("Player %c vs Player %c\n", 'A'+i, 'A'+j);
    }
    else
        show_score_board(board, total_players);

}

void score_board(int(*board)[4], int total_players) {
    int i, j, result, flag = 0;
  
    reset_score_board(board, total_players);
    
    printf("Player win 2 drow 1 loss 0.\n");
    for(i = 0; i < total_players-1; ++i) {
        for(j = i+1; j < total_players; ++j) {
            printf("Player %c vs Player %c\n", 'A'+i, 'A'+j);
            printf("Enter player %c Result:", 'A'+i);
            scanf("%d", &result);
            switch(result) {
                case 0:
                    board[i][j] = 0;
                    board[j][i] = 2;
                    break;
                case 1:
                    board[i][j] = 1;
                    board[j][i] = 1;
                    break;
                case 2:
                    board[i][j] = 2;
                    board[j][i] = 0;
                    break;
                default: 
                    printf("Wrong choice.\n");
            }
        }
    }

    while(!flag) {
        printf("\n1.Update score board.\n");
        printf("2.Display score board.\n");
        printf("5.Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &result);
        switch (result) {
            case 1:
                update_score_board(board, total_players);
                break;
            case 2:
                display_score_board(board, total_players);
                break;
            case 3:
                // show_score_board(board, total_players);
                break;
            case 5:
                flag = 1;    
                break;
            default:
                break;
        }
    }
    
}

int main() {
    int size = 3;
    int arr1[3][3] = { {3, 4, 1},  
                       {2, 0, 8}, 
                       {3, 5, 1} };
    
    int arr2[3][3] = { {2, 1, -1}, 
                       {3, 1, 0},
                       {5, 2, 2} };
    
    int total_players = 4;
    int board[total_players][total_players];

    // add_matrics(arr1, size, arr2);
    // product_matrics(arr1, size, arr2);
    // transpose_matrics(arr1, size);
    score_board(board, total_players);
    return 0;
}