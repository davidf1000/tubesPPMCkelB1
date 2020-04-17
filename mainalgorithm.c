#include "mainalgorithm.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa, 4 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : mainalgorithm.c
* Deskripsi : Header yang berisi fungsi-fungsi yang menghitung dan 
*mengkalkulasikan simulasi iterasi selanjutnya dari sebuah grid.
*
*/
// Mencari generasi selanjutnya
void nextGen(int **grid,int M,int N, int *count) // M row , N collumn
{
    int **future=createArr(M,N);
    // isiArray(future);
    int r,c;
    *count = *count + 1;
    for (int row = 0; row < M ; row++) //row is row
    {
        for (int col = 0; col < N ; col++) // col is collumn
        {
            int neighbour = 0;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    r=i+row;
                    c=j+col;
                    // Kondisi normal
                     if(checkBound(r,c,M,N))
                     {
                    neighbour += grid[r][c];
                     }
                    // Kondisi ujung atas
                }

            }
            //Hitung untuk kasus khusus (yang berada di edge)
            for (int p = -1; p <= 1; p++)
            {
                r=-1;
                c=-1;
                //Ujung atas
                if(row==0)
                {
                    r=M-1;
                    c=p+col;
                }
                // Ujung bawah
                if(row==M-1)
                {
                    r=0;
                    c=p+col;
                }
                if(checkBound(r,c,M,N))
                {
                neighbour += grid[r][c];
                }
            }
            for (int p = -1; p <= 1; p++)
            {
                // Ujung kiri
                r=-1;
                c=-1;
                if(col==0)
                {
                    r=p+row;
                    c=N-1;
                }
                //Ujung kanan
                if(col==N-1)
                {
                    r=p+row;
                    c=0;
                }
                if(checkBound(r,c,M,N))
                {
                neighbour += grid[r][c];
                }
            }

            // Pojok kiri atas
            if(row==0 && col==0)
            {
                neighbour += grid[M-1][N-1];

            }
            //Pojok kiri bawah
            if(row==M-1 && col==0)
            {
                neighbour += grid[0][N-1];

            }
            //Pojok kanan atas
            if(row==0 && col==N-1)
            {
                neighbour += grid[M-1][0];

            }
            //Pojok kanan bawah
            if(row==M-1 && col==N-1)
            {
                neighbour += grid[0][0];

            }
            // The cell needs to be subtracted from
            // its neighbours as it was counted before
            neighbour -= grid[row][col];
            //  printf("%d ",neighbour);
            // Implementing the Rules of Life

            // underpopulation
            if ((grid[row][col] == 1) && (neighbour < 2))
            {
                future[row][col] = 0;

            }

            // overpopulation

            else if ((grid[row][col] == 1) && (neighbour > 4)) 

            {
                future[row][col] = 0;

            }


            // Sel baru
            else if ((grid[row][col] == 0) && (neighbour == 3))
            {
                future[row][col] = 1;

            }

            // Kondisi tidak berubah
            else
            {
                future[row][col] = grid[row][col];

            }

    }
    }
    //Copy array sementara ke array utama
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
           grid[i][j]=future[i][j];
        }

    }

}
// Cek apakah cel yang dicek keluar boundary atau tidak
int checkBound(int r,int c,int M,int N)
{
     return (!(r<0 || r>(M-1) ||c<0 || c>(N-1)));
}
