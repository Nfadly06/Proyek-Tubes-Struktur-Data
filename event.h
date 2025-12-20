#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

/*
========================================================
   LIST EVENT (PARENT)
   MODEL : Singly Linked List (SLL)
   Sesuai Deskripsi Tugas Besar:
   - Menyimpan data Event sebagai Parent
   - Digunakan untuk operasi:
        ✔ Insert Parent (Event) sebagai elemen terakhir
          + Wajib cek agar ID Event tidak duplikat
        ✔ Delete Parent (Event) berdasarkan ID Event
          + Akan digunakan untuk juga menghapus relasi
        ✔ Find Parent berdasarkan ID Event
          + Menggunakan Sequential Search
        ✔ Menampilkan seluruh data Event (Show All Parent)
          + Menampilkan ID, Nama, Lokasi, Harga, Jam, Tanggal
        ✔ Menghitung jumlah Event yang ada (Count Parent)

   Struktur Data Event:
        - idEvent
        - namaEvent
        - lokasi
        - tanggal
        - jam
        - hargaTiket
========================================================
*/

struct Event {
    string idEvent;
    string namaEvent;
    string lokasi;
    string tanggal;
    string jam;
    int hargaTiket;
};

typedef struct elEvent *adrEvent;

struct elEvent {
    Event info;
    adrEvent next;   // pointer ke node event berikutnya (SLL)
};

struct ListEvent {
    adrEvent first;  // pointer head list
};

// ================= BASIC LIST OPERATION =================
void createEventList(ListEvent &LE);     // Membuat list event kosong
bool isEmptyEvent(ListEvent LE);         // Mengecek apakah list kosong
adrEvent newEvent(Event x);              // Membuat node event baru

// ================= INSERT EVENT =================
// Insert Event sebagai elemen pertama
void insertFirstEvent(ListEvent &LE, adrEvent E);

// Insert Event sebagai elemen terakhir
// Sesuai spesifikasi: Insert element Parent dilakukan sebagai elemen terakhir
void insertLastEvent(ListEvent &LE, adrEvent E);

// ================= SEARCH EVENT =================
// Mengecek apakah ID Event sudah digunakan (untuk validasi input)
bool isEventIDUsed(ListEvent LE, string id);

// Mencari Event berdasarkan ID Event (Sequential Search)
// Sesuai spesifikasi: Find Element Parent berdasarkan ID Event
adrEvent searchEvent(ListEvent LE, string id);

// ================= DELETE EVENT =================
// Menghapus event pertama
void deleteFirstEvent(ListEvent &LE);

// Menghapus event terakhir
void deleteLastEvent(ListEvent &LE);

// Menghapus Event berdasarkan ID Event
// Sesuai spesifikasi: Delete element Parent berdasarkan ID Event
// Return true jika berhasil, false jika tidak ditemukan
bool deleteEvent(ListEvent &LE, string id);

// ================= UTILITY =================
// Menghitung jumlah event yang ada
int countEvent(ListEvent LE);

// Menampilkan seluruh data Event
// Sesuai spesifikasi: Show all data di List Parent
void showAllEvent(ListEvent LE);

#endif
