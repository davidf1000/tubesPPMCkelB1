#include "mainalgorithm.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa, 4 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : main.c
* Deskripsi : Algoritma utama 
*/


int main()
{
    int row_in; 
    int col_in; 
    int n;
    char filename[100];
    printf("Masukkan nama file: "); 
    // Kalau mau reload seed pake 2 baris dibawah 
    // V V V V
    scanf("%s",filename);
    int **grid=newSeed(&row_in,&col_in,filename);

    //Display pertama kali
    displayGen(grid,row_in,col_in);

    // Sementara dibuat kyk gini, selama user gak input 99 bakal terus tick
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