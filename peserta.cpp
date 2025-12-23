#include "peserta.h"
using namespace std;

/*
========================================================
    IMPLEMENTASI LIST PESERTA (CHILD)
    Mewakili List Child pada Model MLL Tipe B
========================================================
*/

/* ================= CREATE LIST ================= */
// Membuat list peserta kosong
void createPesertaList(ListPeserta &LP) {
    LP.first = NULL;
}

// Mengecek apakah list kosong
bool isEmptyPeserta(ListPeserta LP) {
    return LP.first == NULL;
}

/* ================= CREATE NODE ================= */
// Membuat node peserta baru
adrPeserta newPeserta(Peserta x) {
    adrPeserta P = new elPeserta;
    P->info = x;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

/* ================= INSERT LAST (DLL) ================= */
// Sesuai spesifikasi: Insert Child dilakukan di elemen terakhir
void insertLastPeserta(ListPeserta &LP, adrPeserta P) {
    if (isEmptyPeserta(LP)) {
        LP.first = P;
    } else {
        adrPeserta Q = LP.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
        P->prev = Q;
    }
}

/* ================= VALIDASI ID PESERTA ================= */
// Mengecek apakah ID Peserta sudah digunakan
bool isPesertaIDUsed(ListPeserta LP, string id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.idPeserta == id) return true;
        P = P->next;
    }
    return false;
}

/* ================= SEARCH ================= */
// Mencari peserta berdasarkan ID
// Sesuai spesifikasi: Find Child by ID
adrPeserta searchPesertaByID(ListPeserta LP, string id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.idPeserta == id) return P;
        P = P->next;
    }
    return NULL;
}

// Mencari peserta berdasarkan Nama
// Sesuai spesifikasi: Find Child by Nama
adrPeserta searchPesertaByName(ListPeserta LP, string nama) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.nama == nama) return P;
        P = P->next;
    }
    return NULL;
}

/* ================= DELETE CHILD ================= */
// Menghapus peserta berdasarkan ID
// Sesuai spesifikasi Delete Child (nanti dikaitkan hapus relasi)
bool deletePesertaByID(ListPeserta &LP, string id) {
    adrPeserta P = searchPesertaByID(LP, id);
    if (P == NULL) return false;

    if (P->prev != NULL)
        P->prev->next = P->next;
    else
        LP.first = P->next;

    if (P->next != NULL)
        P->next->prev = P->prev;

    delete P;
    return true;
}

// Menghapus peserta berdasarkan Nama (versi lama diperbaiki dan dipertahankan)
bool deletePesertaByName(ListPeserta &LP, string nama) {
    adrPeserta P = searchPesertaByName(LP, nama);
    if (P == NULL) return false;

    if (P->prev != NULL)
        P->prev->next = P->next;
    else
        LP.first = P->next;

    if (P->next != NULL)
        P->next->prev = P->prev;

    delete P;
    return true;
}

/* ================= COUNT ================= */
// Menghitung jumlah peserta
int countPeserta(ListPeserta LP) {
    int count = 0;
    adrPeserta P = LP.first;

    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

/* ================= SHOW ALL PESERTA ================= */
// Menampilkan seluruh data peserta
// Sesuai spesifikasi Show List Child + jumlah event nanti terkait relasi
void showAllPeserta(ListPeserta LP) {
    if (isEmptyPeserta(LP)) {
        cout << "Tidak ada data peserta." << endl;
        return;
    }

    adrPeserta P = LP.first;
    int nomor = 1;

    while (P != NULL) {
        cout << "Peserta #" << nomor++ << endl;
        cout << "ID Peserta    : " << P->info.idPeserta << endl;
        cout << "Nama          : " << P->info.nama << endl;
        cout << "Telepon       : " << P->info.telepon << endl;
        cout << "Jenis Kelamin : " << P->info.jenisKelamin << endl;
        cout << "Jenis Peserta : " << P->info.jenisPeserta << endl;
        cout << "----------------------------" << endl;
        P = P->next;
    }
}
