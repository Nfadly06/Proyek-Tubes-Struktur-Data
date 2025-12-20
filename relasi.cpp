#include "relasi.h"
#include <iostream>
using namespace std;

void createRelasiList(ListRelasi &LR) {
    LR.first = NULL;
}

adrRelasi newRelasi(adrEvent E, adrPeserta P) {
    adrRelasi R = new elRelasi;
    R->E = E;
    R->P = P;
    R->next = NULL;
    return R;
}

void insertRelasi(ListRelasi &LR, adrRelasi R) {
    if (LR.first == NULL) {
        LR.first = R;
    } else {
        adrRelasi Q = LR.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

void showPesertaByEvent(ListRelasi LR, adrEvent E) {
    adrRelasi R = LR.first;
    while (R != NULL) {
        if (R->E == E) {
            cout << "ID   : " << R->P->info.idPeserta << endl;
            cout << "Nama : " << R->P->info.nama << endl;
            cout << "------------------" << endl;
        }
        R = R->next;
    }
}

/* HAPUS PESERTA DARI EVENT BERDASARKAN ID PESERTA */
void deletePesertaFromEvent(ListRelasi &LR, adrEvent E, string idPeserta) {
    adrRelasi R = LR.first;
    adrRelasi prev = NULL;

    while (R != NULL) {
        if (R->E == E && R->P->info.idPeserta == idPeserta) {
            if (prev == NULL) {
                LR.first = R->next;
            } else {
                prev->next = R->next;
            }
            delete R;
            return;
        }
        prev = R;
        R = R->next;
    }
}

/* HITUNG JUMLAH PESERTA PER EVENT */
int countPesertaByEvent(ListRelasi LR, adrEvent E) {
    int count = 0;
    adrRelasi R = LR.first;
    while (R != NULL) {
        if (R->E == E) {
            count++;
        }
        R = R->next;
    }
    return count;
}
