

/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa, 4 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : utility.h
* Deskripsi : Header Berisi fungsi-fungsi yang berhubungan dengan pembuatan dynamic array 2D seperti mengalokasi memory , 
*print grid array, Pemindahan  file seed ke array, serta animasi tampilan grid array.
*
*/
int **createArr(int row_in,int col_in);
void displayGen(int **grid,int row,int col,int *count);
int **newSeed(int* matrixRow, int* matrixCol, char filename[50]);
void delay(int n);
void animate(int n, int **grid, int M, int N, int *count);
