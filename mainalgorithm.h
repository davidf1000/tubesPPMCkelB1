
/* EL2208 Praktikum Pemecahan Masalah dengan C 2019/2020
* MODUL 8 – TUGAS BESAR
* Kelompok : B1
* Hari dan Tanggal : Selasa, 4 April 2020
* Asisten (NIM) : Akmal Narendra Sakti (13213034)
* Nama File : mainalgorithm.h
* Deskripsi : Header yang berisi fungsi-fungsi yang membuat dan mengatur array 2D penyimpanan grid
*             serta algoritma utama untuk mengupdate generasi selanjutnya
*/

//Function list

//Fungsi yang udah fix jadi
void nextGen(int **grid,int M,int N, int *count);
int checkBound(int r,int c,int M,int N);
