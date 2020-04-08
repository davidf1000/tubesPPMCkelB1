#include "mainalgorithm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa, 4 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : mainalgorithm.c
* Deskripsi : Algoritma utama 
*/


int main()
{
    int row_in=30; // inputan 
    int col_in=30; // inputan
    int n;
    int **grid; 
    grid=read(row_in,col_in); // ambil txt seed terus masukin ke 2d array grid

    //Display pertama kali
    displayGen(grid,row_in,col_in);

    scanf("%d",&n);
    while(n!=99)
    {
    // update gen , display gen yang udah diupdate, loop 
    nextGen(grid,row_in,col_in);
    displayGen(grid,row_in,col_in);
    scanf("%d",&n);
    }


    return 0;
}