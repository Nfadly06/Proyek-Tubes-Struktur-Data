#include "peserta.h"
using namespace std;

void createPesertaList(ListPeserta &LP) {
    LP.first = NULL;
}

bool isEmptyPeserta(ListPeserta LP) {
    return LP.first == NULL;
}

adrPeserta newPeserta(Peserta x) {
    adrPeserta P = new elPeserta;
    P->info = x;
    P->prev = NULL;
    P->next = NULL;
    return P;
}

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

bool isPesertaIDUsed(ListPeserta LP, string id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.idPeserta == id) return true;
        P = P->next;
    }
    return false;
}

adrPeserta searchPesertaByID(ListPeserta LP, string id) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.idPeserta == id) return P;
        P = P->next;
    }
    return NULL;
}

adrPeserta searchPesertaByName(ListPeserta LP, string nama) {
    adrPeserta P = LP.first;
    while (P != NULL) {
        if (P->info.nama == nama) return P;
        P = P->next;
    }
    return NULL;
}

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

int countPeserta(ListPeserta LP) {
    int count = 0;
    adrPeserta P = LP.first;

    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

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

