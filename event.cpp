#include "event.h"
using namespace std;

/*
========================================================
    IMPLEMENTASI LIST EVENT (PARENT)
    Mewakili List Parent pada Model MLL Tipe B
========================================================
*/

// ================== CREATE LIST ==================
// Membuat list event awal (kosong)
void createEventList(ListEvent &LE) {
    LE.first = NULL;
}

// Mengecek apakah list kosong
bool isEmptyEvent(ListEvent LE) {
    return LE.first == NULL;
}

// ================== NEW NODE ==================
// Membuat node event baru berisi data event
adrEvent newEvent(Event x) {
    adrEvent E = new elEvent;
    E->info = x;
    E->next = NULL;
    return E;
}

// ================== INSERT ==================
// Insert event ke bagian awal list
void insertFirstEvent(ListEvent &LE, adrEvent E) {
    if (isEmptyEvent(LE)) {
        LE.first = E;
    } else {
        E->next = LE.first;
        LE.first = E;
    }
}

// Insert event sebagai elemen terakhir
// Sesuai spesifikasi tubes → Insert Parent dilakukan sebagai elemen terakhir
void insertLastEvent(ListEvent &LE, adrEvent E) {
    if (isEmptyEvent(LE)) {
        LE.first = E;
    } else {
        adrEvent P = LE.first;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = E;
    }
}

// ================== SEARCH ==================
// Mengecek apakah suatu ID Event sudah ada
bool isEventIDUsed(ListEvent LE, string id) {
    adrEvent P = LE.first;
    while (P != NULL) {
        if (P->info.idEvent == id) return true;
        P = P->next;
    }
    return false;
}

// Mencari Event berdasarkan ID Event
// Sesuai spesifikasi → Find Element Parent (Sequential Search)
adrEvent searchEvent(ListEvent LE, string id) {
    adrEvent P = LE.first;
    while (P != NULL) {
        if (P->info.idEvent == id) return P;
        P = P->next;
    }
    return NULL;
}

// ================== DELETE ==================
// Menghapus event pertama
void deleteFirstEvent(ListEvent &LE) {
    if (!isEmptyEvent(LE)) {
        adrEvent P = LE.first;
        LE.first = P->next;
        delete P;
    }
}

// Menghapus event terakhir
void deleteLastEvent(ListEvent &LE) {
    if (!isEmptyEvent(LE)) {
        if (LE.first->next == NULL) {
            deleteFirstEvent(LE);
        } else {
            adrEvent P = LE.first;
            adrEvent prev = NULL;

            while (P->next != NULL) {
                prev = P;
                P = P->next;
            }

            if (prev != NULL) prev->next = NULL;
            delete P;
        }
    }
}

// Menghapus Event berdasarkan ID
// Sesuai spesifikasi: Delete element parent berdasarkan ID Event
// Catatan: Setelah ini pada program utama akan dihubungkan
//          untuk juga menghapus seluruh relasi event tersebut
bool deleteEvent(ListEvent &LE, string id) {
    if (isEmptyEvent(LE)) return false;

    adrEvent P = LE.first;
    adrEvent prev = NULL;

    while (P != NULL && P->info.idEvent != id) {
        prev = P;
        P = P->next;
    }

    if (P == NULL) return false; // ID tidak ditemukan

    if (prev == NULL) {
        LE.first = P->next;
    } else {
        prev->next = P->next;
    }

    delete P;
    return true;
}

// ================== COUNT ==================
// Menghitung jumlah event yang ada
int countEvent(ListEvent LE) {
    int count = 0;
    adrEvent P = LE.first;

    while (P != NULL) {
        count++;
        P = P->next;
    }

    return count;
}

// ================== SHOW ==================
// Menampilkan seluruh data event
// Sesuai spesifikasi: Show all data di List Parent
// Menampilkan: ID, Nama, Lokasi, Harga, Tanggal, Jam
void showAllEvent(ListEvent LE) {
    if (isEmptyEvent(LE)) {
        cout << "Tidak ada data event." << endl;
        return;
    }

    adrEvent P = LE.first;
    int nomor = 1;

    while (P != NULL) {
        cout << "Event #" << nomor++ << endl;
        cout << "ID Event   : " << P->info.idEvent << endl;
        cout << "Nama Event : " << P->info.namaEvent << endl;
        cout << "Lokasi     : " << P->info.lokasi << endl;
        cout << "Tanggal    : " << P->info.tanggal << endl;
        cout << "Jam        : " << P->info.jam << endl;
        cout << "Harga      : " << P->info.hargaTiket << endl;
        cout << "---------------------------" << endl;
        P = P->next;
    }
}
