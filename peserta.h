#ifndef PESERTA_H
#define PESERTA_H

#include <iostream>
using namespace std;

struct Peserta {
    string idPeserta;
    string nama;
    string telepon;
    string jenisKelamin;
    string jenisPeserta;
};

typedef struct elPeserta *adrPeserta;

struct elPeserta {
    Peserta info;
    adrPeserta prev;
    adrPeserta next;
};

struct ListPeserta {
    adrPeserta first;
};

/* PRIMITIF LIST */
void createPesertaList(ListPeserta &LP);
adrPeserta newPeserta(Peserta x);

/* INSERT */
void insertLastPeserta(ListPeserta &LP, adrPeserta P);

/* DELETE */
void deletePeserta(ListPeserta &LP, string nama);

/* SEARCH / VALIDASI */
bool isPesertaIDUsed(ListPeserta LP, string id);

/* SHOW */
void showAllPeserta(ListPeserta LP);

#endif
