#ifndef PESERTA_H
#define PESERTA_H

#include <iostream>
using namespace std;

/*
========================================================
   LIST PESERTA (CHILD)
   MODEL : Doubly Linked List (DLL)
   Sesuai Deskripsi Tugas Besar:
   - Menyimpan data Peserta sebagai Child
   - Digunakan untuk operasi:
        ✔ Insert Child (Peserta) sebagai elemen terakhir
          + Wajib cek agar ID Peserta tidak duplikat
        ✔ Delete Child berdasarkan ID / Nama Peserta
          + Nantinya juga akan menghapus seluruh relasi peserta tsb
        ✔ Find Child
          + Dengan ID Peserta / Nama Peserta
        ✔ Menampilkan seluruh Peserta
          + Menampilkan ID, Nama, Telepon, Jenis Kelamin, Jenis Peserta
        ✔ Menghitung jumlah Peserta (Count Child)
        ✔ Menghitung Child yang tidak memiliki Parent (di relasi)

   Struktur Data Peserta:
        - idPeserta
        - nama
        - telepon
        - jenisKelamin
        - jenisPeserta
========================================================
*/

struct Peserta {
    string idPeserta;
    string nama;
    string telepon;
    string jenisKelamin;
    string jenisPeserta;
};

typedef struct elPeserta *adrPeserta;

struct elPeserta {
    Peserta info;
    adrPeserta prev;
    adrPeserta next;
};

struct ListPeserta {
    adrPeserta first;
};

/* ================= BASIC OPERATION ================= */
void createPesertaList(ListPeserta &LP);     // Membuat list peserta kosong
bool isEmptyPeserta(ListPeserta LP);         // Mengecek apakah list kosong
adrPeserta newPeserta(Peserta x);            // Membuat node peserta baru

/* ================= INSERT CHILD ================= */
// Sesuai spesifikasi → Insert Child dilakukan sebagai elemen terakhir (DLL)
void insertLastPeserta(ListPeserta &LP, adrPeserta P);

/* ================= DELETE CHILD ================= */
// Menghapus peserta berdasarkan ID Peserta
// Sesuai spesifikasi Delete Child + akan dihubungkan penghapusan relasi
bool deletePesertaByID(ListPeserta &LP, string id);

// Menghapus peserta berdasarkan Nama (tetap dipertahankan karena sudah ada)
bool deletePesertaByName(ListPeserta &LP, string nama);

/* ================= SEARCH / VALIDASI ================= */
// Mengecek apakah ID Peserta sudah digunakan
bool isPesertaIDUsed(ListPeserta LP, string id);

// Mencari peserta berdasarkan ID
adrPeserta searchPesertaByID(ListPeserta LP, string id);

// Mencari peserta berdasarkan Nama
adrPeserta searchPesertaByName(ListPeserta LP, string nama);

/* ================= UTILITY ================= */
int countPeserta(ListPeserta LP);     // Menghitung jumlah peserta
void showAllPeserta(ListPeserta LP);  // Menampilkan seluruh data peserta

#endif
