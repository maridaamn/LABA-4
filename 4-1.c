#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int n = 0, choice;
    int a[100][100];
    printf("Enter size of array: ");
    while (scanf("%d", &n) != 1  n < 1  n > 100 || getchar() != '\n') 
    {
        printf("Choose size of array: ");
        rewind(stdin);
    }
    printf("Choose array elements:\n1)random\n 2)ur elements\n");
    while (scanf("%i", &choice) != 1  choice < 1  choice > 2 || getchar() != '\n') 
    {
        printf("Choose array elements:\n1)random \n2)ur elements\n");
        rewind(stdin);
    }
    switch (choice)
    {
    case 1:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                a[i][j] = (rand() % 10);
                printf("%d  ", a[i][j]);
            }
            printf("\n");
        }
        break;
    case 2:
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
               
                while (scanf("%d", &a[i][j]) != 1  a[i][j] > 100  a[i][j] < -100 || getchar() != '\n') 
                {
                    printf("Wrong! Try again: ");
                    rewind(stdin);
                }
            }
            printf("\n");
        }
        break;
    }
    int summROW[100], summCOL[100], summDIAG[2];
    for (int i = 0; i < n; i++)
    {
        summDIAG[0] += a[i][i];
        summDIAG[1] += a[(n - 1) - i][(n - 1) - i];
        for (int j = 0; j < n; j++)
        {
            summROW[i] += a[i][j];
            summCOL[i] += a[j][i];
        }
        if (summCOL[i] != summROW[i]) 
        {
            printf("Matrix isn't a magic square.");
            break;
        }
        else if ((i > 0) && (summROW[i] != summROW[i - 1]))
        {
            printf("Matrix isn't a magic square.");
            break;
        }
        else if ((i > 0) && (summCOL[i] != summCOL[i - 1]))
        {
            printf("Matrix isn't a magic square.");
            break;
        }
    }
    if ((summDIAG[0] == summDIAG[1]) && (summCOL[0] == summDIAG[0]))
        printf("Matrix is a magic square!");
    return 0;
}