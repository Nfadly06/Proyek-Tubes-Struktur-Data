#include "peserta.h"

void createPesertaList(ListPeserta &LP) {
    LP.first = NULL;
}

adrPeserta newPeserta(Peserta x) {
    adrPeserta P = new elPeserta;
    P->info = x;
    P->next = NULL;
    return P;
}

void insertLastPeserta(ListPeserta &LP, adrPeserta P) {
    if (LP.first == NULL) {
        LP.first = P;
    } else {
        adrPeserta Q = LP.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

bool isPesertaIDUsed(ListPeserta LP, string id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.idPeserta == id) return true;
        P = P->next;
    }
    return false;
}

void deletePeserta(ListPeserta &LP, string nama) {
    adrPeserta P = LP.first;
    adrPeserta prev = NULL;

    while (P != NULL && P->info.nama != nama) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        if (prev == NULL) LP.first = P->next;
        else prev->next = P->next;
        delete P;
    }
}

void showAllPeserta(ListPeserta LP) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        cout << "ID Peserta : " << P->info.idPeserta << endl;
        cout << "Nama       : " << P->info.nama << endl;
        cout << "Telepon    : " << P->info.telepon << endl;
        cout << "Jenis Kel  : " << P->info.jenisKelamin << endl;
        cout << "Jenis      : " << P->info.jenisPeserta << endl;
        cout << "---------------------------" << endl;
        P = P->next;
    }
}
