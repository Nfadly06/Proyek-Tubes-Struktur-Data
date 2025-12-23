#ifndef RELASI_H
#define RELASI_H

#include "event.h"
#include "peserta.h"

/*
========================================================
   LIST RELASI (EVENT ↔ PESERTA)
   MODEL : Singly Linked List berisi pasangan:
            - Pointer ke Event (Parent)
            - Pointer ke Peserta (Child)

   Sesuai deskripsi Tugas Besar, relasi digunakan untuk:
    ✔ Insert element relation
      - Menghubungkan event dengan peserta
    ✔ Delete element relation
      - Menghapus hubungan tanpa menghapus data event/peserta
    ✔ Find apakah parent & child tertentu memiliki relasi
    ✔ Show data child dari parent tertentu
    ✔ Show data parent dari child tertentu
    ✔ Show semua parent beserta semua child nya
    ✔ Show semua child beserta semua parent nya
    ✔ Count jumlah child suatu parent
    ✔ Count jumlah parent suatu child
    ✔ Digunakan saat:
        - Delete parent → semua relasi event dihapus
        - Delete child  → semua relasi peserta dihapus
        - Edit Relasi

========================================================
*/

typedef struct elRelasi *adrRelasi;

struct elRelasi {
    adrEvent E;        // pointer ke Event (Parent)
    adrPeserta P;      // pointer ke Peserta (Child)
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

/* =============== BASIC OPERATION =============== */
void createRelasiList(ListRelasi &LR);          // Membuat list relasi kosong
bool isEmptyRelasi(ListRelasi LR);              // Mengecek list kosong
adrRelasi newRelasi(adrEvent E, adrPeserta P);  // Membuat node relasi baru

/* =============== INSERT RELATION =============== */
// Insert relasi di akhir list
// Sesuai spesifikasi Insert Element Relation
void insertRelasi(ListRelasi &LR, adrRelasi R);

// Mengecek apakah suatu pasangan Event-Peserta sudah punya relasi
bool isRelated(ListRelasi LR, adrEvent E, adrPeserta P);

/* =============== SHOW RELATION DATA =============== */
// Menampilkan seluruh peserta dari event tertentu
// Sesuai spesifikasi: Show Child dari Parent tertentu
void showPesertaByEvent(ListRelasi LR, adrEvent E);

// Menampilkan seluruh event yang diikuti peserta tertentu
// Sesuai spesifikasi: Show Parent dari Child tertentu
void showEventByPeserta(ListRelasi LR, adrPeserta P);

// Menampilkan setiap Event beserta seluruh pesertanya
// Sesuai spesifikasi Show Parent + Child (Relasi)
void showAllEventWithPeserta(ListRelasi LR);

// Menampilkan setiap Peserta beserta event yang diikutinya
// Sesuai spesifikasi Show Child + Parent (Relasi)
void showAllPesertaWithEvent(ListRelasi LR);

/* =============== DELETE RELATION =============== */
// Menghapus relasi spesifik: event tertentu - idPeserta tertentu
void deletePesertaFromEvent(ListRelasi &LR, adrEvent E, string idPeserta);

// Menghapus seluruh relasi milik suatu Event
// Dipakai saat Delete Parent
void deleteRelasiByEvent(ListRelasi &LR, adrEvent E);

// Menghapus seluruh relasi milik suatu Peserta
// Dipakai saat Delete Child
void deleteRelasiByPeserta(ListRelasi &LR, adrPeserta P);

/* =============== COUNT =============== */
// Hitung jumlah peserta suatu event
// Sesuai spesifikasi Count Child dari Parent tertentu
int countPesertaByEvent(ListRelasi LR, adrEvent E);

// Hitung jumlah event yang diikuti peserta
// Sesuai spesifikasi Count Parent dari Child tertentu
int countEventByPeserta(ListRelasi LR, adrPeserta P);
int countChildWithoutParent(ListPeserta LP, ListRelasi LR);
// Hitung jumlah event yang tidak memiliki peserta (Parent tanpa Child)
int countParentWithoutChild(ListEvent LE, ListRelasi LR);

bool editRelasi(ListRelasi &LR, adrEvent oldE, string idPeserta, adrEvent newE);

#endif
