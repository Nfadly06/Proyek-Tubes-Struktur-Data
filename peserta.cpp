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

}

void deletePeserta(ListPeserta &LP, string nama) {

}

void showAllPeserta(ListPeserta LP) {

}

