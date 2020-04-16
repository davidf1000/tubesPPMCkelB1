#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "utility.h"
#include "mainalgorithm.h"

int **createArr(int row_in,int col_in)
{
 int **grid;
    grid=malloc(row_in*sizeof(int*));
    for (int i = 0; i < row_in; i++)
    {
        grid[i]=malloc(col_in*sizeof(int));
    }
    return grid;
}
void displayGen(int **grid,int row,int col, int *count)
{
    printf("Generation - %d :\n", *count);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 0)
            {
                printf(". ");
            }
            else
            {
                printf("X ");

            }
        }
    printf("\n");
    }
}
int **newSeed(int* matrixRow, int* matrixCol, char filename[50])
{
    char temp[100];
    char eksternal[100]="./seed/";
    strcat(eksternal,filename);
    FILE* stream = fopen(eksternal, "r");
    fgets(temp, 30, stream);
    *matrixRow = atoi(temp);
    fgets(temp, 30, stream);
    *matrixCol = atoi(temp);
    //Buat Dynamic array sebesar dimensi seed
    int **mat=createArr(*matrixRow,*matrixCol);
    for (int i = 0; i < *matrixRow; i++)
    {
        fgets(temp, 100, stream);
        for (int j = 0; j <*matrixCol; j++)
        {
            if(temp[j]=='-')
            {
                mat[i][j] = 0;
            }
            else
            {
                mat[i][j] = 1;
            }
        }
    }
    fclose(stream);
    return mat;
}

void delay(int n){
    clock_t start_time = clock();

    while (clock() < start_time + n);
}

void animate(int n, int **grid, int M, int N, int *count){
    for (int i = 0; i < n; i++){
        system("cls");
        nextGen(grid, M, N, count);
        displayGen(grid, M, N, count);
        delay(200);
    }
}
