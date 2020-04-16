#include "mainalgorithm.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Kamis, 16 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : main.c
* Deskripsi : Algoritma utama 
*/


int main()
{
    /*
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
    */

    /* VARIABLE LOCAL */
    char pilihan;
    char reinput; // (bool (Y/N))
    int row_in; 
    int col_in; 
    int n, i;
    char namafile[50];
            // Asumsi maks. namafile sepanjang 50 karakter
            // tanpa spasi

    /* ALGORITMA */
    // Menghapus console
    do
    {
        printf("================== GAME OF LIFE ==================\n\n");
        printf("Sebuah permainan simulasi pola\n");
        printf("Game ini dimainkan oleh 0 pemain, hanya bergantung\n");
        printf("pada input pola awal. Program akan meminta file \n");
        printf("eksternal berisi pola yang disebut seed.\n\n");
        printf("==================================================\n");
        // Input file pola
        printf("Masukan nama file :");
        scanf("%s", namafile);

        // Procedure cetak Seed
        int **grid=newSeed(&row_in,&col_in,namafile);
        displayGen(grid,row_in,col_in);
        
        // Menu pilihan
        do
        {
            printf("== Menu pilihan ==\n");
            printf(" 1. Tick    (mencetak next pattern 1 kali)\n");
            printf(" 2. Animate (mencetak next pattern N kali)\n");
            printf(" 3. Quit    (ganti seed / keluar)\n");
            printf("Masukan angka pilihan :");
            scanf(" %c", &pilihan);

            if(pilihan == '1')
            {
                nextGen(grid,row_in,col_in);
                displayGen(grid,row_in,col_in);
            } else if (pilihan == '2')
            {
                // -> Procedure animate
                printf("Masukkan banyak n iterasi :");
                scanf("%d", &n);
                for (i=0;i<n;i++) {
                    nextGen(grid,row_in,col_in);
                    displayGen(grid,row_in,col_in);
                }
            } else if (pilihan == '3')
            {

            } else
            {
                printf("Input salah !\n");
            }
        } while (pilihan != '3');

        // Menu quit
        printf("Apakah anda akan memasukan file seed baru (Y/N)? ");
        scanf(" %c", &reinput);

    }while(reinput == 'Y');

    printf("Menutup program...\n");
    printf("Terima kasih !\n");
    
    return 0;
}
