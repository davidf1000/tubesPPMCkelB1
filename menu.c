/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok          : 1
* Hari dan Tanggal  : Kamis, 29 Maret 2018
* Asisten (NIM)     : Akmal Narendra Sakti (13217034)
* Nama File         : menu.c
* Deskripsi         : Implementasi prcedure menu
*/

#include <stdio.h>
#include <stdlib.h>
#include "Cetak_Seed.h"

void menu(void)
{
    /* VARIABLE LOCAL */
    char pilihan;
    char reinput; // (bool (Y/N))
    char namafile[20];
            // Asumsi maks. namafile sepanjang 20 karakter
            // tanpa spasi

    /* ALGORITMA */
    // Menghapus console
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
        printf("Masukan nama file :");
        scanf("%s", namafile);

        // Procedure cetak Seed

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
                printf("Cetak tick");

            } else if (pilihan == '2')
            {
                // -> Procedure animate
                printf("Cetak animate");
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

    return;
}

int main()
{
    menu();

    return 0;
}
