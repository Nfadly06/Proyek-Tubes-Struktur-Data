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
bool isEmptyRelasi(ListRelasi LR);              
adrRelasi newRelasi(adrEvent E, adrPeserta P);  


void insertRelasi(ListRelasi &LR, adrRelasi R);

bool isRelated(ListRelasi LR, adrEvent E, adrPeserta P);


void showPesertaByEvent(ListRelasi LR, adrEvent E);
void showEventByPeserta(ListRelasi LR, adrPeserta P);
void showAllEventWithPeserta(ListRelasi LR);
void showAllPesertaWithEvent(ListRelasi LR);
void deletePesertaFromEvent(ListRelasi &LR, adrEvent E, string idPeserta);
void deleteRelasiByEvent(ListRelasi &LR, adrEvent E);
void deleteRelasiByPeserta(ListRelasi &LR, adrPeserta P);
int countPesertaByEvent(ListRelasi LR, adrEvent E);
int countEventByPeserta(ListRelasi LR, adrPeserta P);
int countChildWithoutParent(ListPeserta LP, ListRelasi LR);
int countParentWithoutChild(ListEvent LE, ListRelasi LR);

bool editRelasi(ListRelasi &LR, adrEvent oldE, string idPeserta, adrEvent newE);

#endif
