#include "peserta.h"

/* CREATE LIST */
void createPesertaList(ListPeserta &LP) {
    LP.first = NULL;
}

/* CREATE NODE */
adrPeserta newPeserta(Peserta x) {
    adrPeserta P = new elPeserta;
    P->info = x;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

/* INSERT LAST (DLL) */
void insertLastPeserta(ListPeserta &LP, adrPeserta P) {
    if (LP.first == NULL) {
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

/* VALIDASI ID PESERTA */
bool isPesertaIDUsed(ListPeserta LP, string id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.idPeserta == id) {
            return true;
        }
        P = P->next;
    }
    return false;
}

/* DELETE PESERTA BERDASARKAN NAMA (DLL) */
void deletePeserta(ListPeserta &LP, string nama) {
    adrPeserta P = LP.first;

    while (P != NULL && P->info.nama != nama) {
        P = P->next;
    }

    if (P != NULL) {
        if (P->prev != NULL) {
            P->prev->next = P->next;
        } else {
            LP.first = P->next;
        }

        if (P->next != NULL) {
            P->next->prev = P->prev;
        }

        delete P;
    }
}

/* SHOW ALL PESERTA */
void showAllPeserta(ListPeserta LP) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        cout << "ID Peserta    : " << P->info.idPeserta << endl;
        cout << "Nama          : " << P->info.nama << endl;
        cout << "Telepon       : " << P->info.telepon << endl;
        cout << "Jenis Kelamin : " << P->info.jenisKelamin << endl;
        cout << "Jenis Peserta : " << P->info.jenisPeserta << endl;
        cout << "----------------------------" << endl;
        P = P->next;
    }
}
