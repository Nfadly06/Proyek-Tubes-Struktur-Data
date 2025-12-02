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
    adrPeserta next;
};

struct ListPeserta {
    adrPeserta first;
};

void createPesertaList(ListPeserta &LP);
adrPeserta newPeserta(Peserta x);
void insertLastPeserta(ListPeserta &LP, adrPeserta P);
void deletePeserta(ListPeserta &LP, string nama);
bool isPesertaIDUsed(ListPeserta LP, string id);

void showAllPeserta(ListPeserta LP);

#endif
