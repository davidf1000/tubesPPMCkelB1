#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NMAX 100
int countRow(char filename[50]);
void Cetak_Seed(char matrix[][NMAX], int* matrixRow, int* matrixCol, char filename[50]);
int countCol(char filename[50]);

void Cetak_Seed(char matrix[][NMAX], int* matrixRow, int* matrixCol, char filename[50])
{
    char temp[100];
    int count = 0, row, col;
    row = countRow(filename);
    col = countCol(filename);   
    *matrixRow = row;
    *matrixCol = col;

    FILE* stream = fopen(filename, "r");
    for (int i = 0; i < row; i++)
    {
        fgets(temp, 100, stream);
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = temp[j];
        }
    }
    
    fclose(stream);
}

int countRow(char filename[50])
{
    char c;
    FILE* stream;
    int count = 0;
    stream = fopen(filename, "r");

    //counting new row
    for (c = getc(stream); c != EOF; c = getc(stream))
    {
        if (c == '\n')
            {
                count++;
            }
    }

    //add new row
    count = count + 1;
    fclose(stream);
    return count;
}
int countCol(char filename[50])
{
    char c, temp[NMAX];
    FILE* stream;
    int count = 0;
    stream = fopen(filename, "r");
    fgets(temp, NMAX, stream);
    count = strlen(temp);
    //that function counted new line too, so
    count = count - 1;
    fclose(stream);
    return count;
}

void printMatrix(char matrix[][NMAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main()
{
    char filename[50];
    char matrix[NMAX][NMAX];
    int matrixRow, matrixCol;

    printf("Masukkan nama file: "); 
    gets(filename);

    Cetak_Seed(matrix, &matrixRow, &matrixCol, filename);
    printf("Row = %d, Col = %d\nMatrix\n", matrixRow, matrixCol);
    printMatrix(matrix, matrixRow, matrixCol);
    return 0;
}