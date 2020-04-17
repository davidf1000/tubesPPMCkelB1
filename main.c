/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020 
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Kamis, 17 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : main.c
* Deskripsi : Algoritma utama 
*/

#include "mainalgorithm.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* VARIABLE LOCAL */
    char pilihan;
    char reinput; // (bool (Y/N))
    int row_in; 
    int col_in; 
    int n;
    int gen_count = 0;
    char namafile[50];
            // Asumsi maks. namafile sepanjang 50 karakter
            // tanpa spasi

    /* ALGORITMA */
    do
    {
        system("cls");

        printf("================== GAME OF LIFE ==================\n\n");
        printf("Sebuah permainan simulasi pola\n");
        printf("Game ini dimainkan oleh 0 pemain, hanya bergantung\n");
        printf("pada input pola awal. Program akan meminta file \n");
        printf("eksternal berisi pola yang disebut seed.\n\n");
        printf("==================================================\n");
        // Input file pola
        printf("Masukan nama file : ");
        scanf("%s", namafile);

        // Procedure cetak Seed
        int **grid=newSeed(&row_in,&col_in,namafile);
        displayGen(grid,row_in,col_in, &gen_count);

        // Menu pilihan
        do
        {
            printf("== Menu pilihan ==\n");
            printf(" 1. Tick    (mencetak next pattern 1 kali)\n");
            printf(" 2. Animate (mencetak next pattern N kali)\n");
            printf(" 3. Quit    (ganti seed / keluar)\n");
            printf("Masukan angka pilihan : ");
            scanf(" %c", &pilihan);

            if(pilihan == '1')
            {
                nextGen(grid,row_in,col_in, &gen_count);
                displayGen(grid,row_in,col_in, &gen_count);
                printf("\n");
            } else if (pilihan == '2')
            {
                // -> Procedure animate
                printf("Masukkan jumlah n iterasi : ");
                scanf("%d", &n);
                animate(n, grid, row_in, col_in, &gen_count);
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
        gen_count = 0;
    }while((reinput == 'Y') || (reinput == 'y'));

    printf("Menutup program...\n");
    printf("Terima kasih !\n");
    return 0;
}