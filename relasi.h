#ifndef RELASI_H
#define RELASI_H

#include "event.h"
#include "peserta.h"

typedef struct elRelasi *adrRelasi;

struct elRelasi {
    adrEvent E;
    adrPeserta P;
    adrRelasi next;
};

struct ListRelasi {
    adrRelasi first;
};

void createRelasiList(ListRelasi &LR);
adrRelasi newRelasi(adrEvent E, adrPeserta P);
void insertRelasi(ListRelasi &LR, adrRelasi R);

void showPesertaByEvent(ListRelasi LR, adrEvent E);
void deletePesertaFromEvent(ListRelasi &LR, adrEvent E, string idPeserta);
int countPesertaByEvent(ListRelasi LR, adrEvent E);
/* TAMBAHAN */
int countPesertaByEvent(ListRelasi LR, adrEvent E);

#endif
