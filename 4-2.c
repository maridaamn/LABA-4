#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int row = 0, col = 0, choice;
    int a[100][100];
    printf("Enter number of rows: ");
    while (scanf("%d", &row) != 1  row < 1  row > 100  getchar() != '\n') 
    {
        printf("Enter number of rows: "); //введите кол-во строк
        rewind(stdin);
    }
    printf("Enter number of columns: "); //введите кол-во столбцов 
    while (scanf("%d", &col) != 1  col < 1  col > 100  getchar() != '\n') 
    {
        printf("Enter number of columns: ");
        rewind(stdin);
    }
    printf("Choose array elements:\n1)кandom\n2)ur elements\n");
    while (scanf("%i", &choice) != 1  choice < 1  choice > 2  getchar() != '\n') 
    {
        printf("Choose array elements:\n1)random \n2)ur elements\n");
        rewind(stdin);
    }
    switch (choice)
    {
    case 1:
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                
                a[i][j] = (rand() % 100 - 30);
                printf("%3d ", a[i][j]);
            }
            printf("\n");
        }
        break;

    case 2:
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++) 
            {
                
                while (scanf("%d", &a[i][j]) != 1  getchar() != '\n')
                {
                    printf("Wrong! Try again: ");
                    rewind(stdin);
                }
            }
            printf("\n");
        }
        break;

    }
    int sum = 0;
    int index = 0;
    int flag;
    for (int i = 0; i < row; i++) 
    {
        flag = 1;
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] <= 0) 
            { 
                flag = 0;
            }
            else index = i;
        }
        if (flag == 1) {
            for (int q = 0; q < col; q++) 
            {
                sum += a[index][q];
            }
            break;
        }
    }
    printf("sum = %d\n", sum);

    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < row; j++)
        {
            a[i][j] -= sum;
        }
    }
    for(int j = 0; j < row; j++)
    {
            for (int k = 0; k < col; k++)
            {
                printf("%3d ",  a[j][k]);
            }
            printf("\n");
        }
    
    return 0;
}