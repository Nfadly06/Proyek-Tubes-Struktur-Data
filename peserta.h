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

void createPesertaList(ListPeserta &LP);     
bool isEmptyPeserta(ListPeserta LP);         
adrPeserta newPeserta(Peserta x);            
void insertLastPeserta(ListPeserta &LP, adrPeserta P);
bool deletePesertaByID(ListPeserta &LP, string id);
bool deletePesertaByName(ListPeserta &LP, string nama);
bool isPesertaIDUsed(ListPeserta LP, string id);
adrPeserta searchPesertaByID(ListPeserta LP, string id);
adrPeserta searchPesertaByName(ListPeserta LP, string nama);
int countPeserta(ListPeserta LP);     
void showAllPeserta(ListPeserta LP);  

#endif
