#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int n = 0, choice;
    int a[100][100];
    printf("Enter size of array: ");
    while (scanf("%d", &n) != 1  n < 1  n > 100  getchar() != '\n')
    {
        printf("Enter size of array: ");
        rewind(stdin);
    }
    printf("Choose array elements:\n1)random \n2)ur elements\n");
    while (scanf("%i", &choice) != 1  choice < 1  choice > 2  getchar() != '\n')
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
                
                a[i][j] = (rand() % 100 - 50);
                printf("%3d  ", a[i][j]);
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
                printf("%3d", a[i][j]);
            }
            
        }
        break;
    }
    int sum = 0;
    int q = 0;
    int w = n;
    for (int j = 0; j < n / 2 + 1; j++) 
    {
        for ( ; q < w; q++)
        {
            sum += a[j][q];
        }
        q = 0;
        q += j + 1;
        w -= 1;
    }
    printf("Amount of elements in the first area of the matrix is %d.", sum); //сумма элементов в 1 области
    return 0;
}