#include "relasi.h"
#include <iostream>
using namespace std;

void createRelasiList(ListRelasi &LR) {
    LR.first = NULL;
}

bool isEmptyRelasi(ListRelasi LR) {
    return LR.first == NULL;
}

adrRelasi newRelasi(adrEvent E, adrPeserta P) {
    adrRelasi R = new elRelasi;
    R->E = E;
    R->P = P;
    R->next = NULL;
    return R;
}

void insertRelasi(ListRelasi &LR, adrRelasi R) {
    if (isEmptyRelasi(LR)) {
        LR.first = R;
    } else {
        adrRelasi Q = LR.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = R;
    }
}

bool isRelated(ListRelasi LR, adrEvent E, adrPeserta P) {
    adrRelasi R = LR.first;
    while (R != NULL) {
        if (R->E == E && R->P == P) {
            return true;
        }
        R = R->next;
    }
    return false;
}

void showPesertaByEvent(ListRelasi LR, adrEvent E) {
    adrRelasi R = LR.first;
    bool found = false;

    while (R != NULL) {
        if (R->E == E) {
            found = true;
            cout << "ID   : " << R->P->info.idPeserta << endl;
            cout << "Nama : " << R->P->info.nama << endl;
            cout << "------------------" << endl;
        }
        R = R->next;
    }

    if (!found) {
        cout << "Tidak ada peserta pada event ini." << endl;
    }
}

void showEventByPeserta(ListRelasi LR, adrPeserta P) {
    adrRelasi R = LR.first;
    bool found = false;

    while (R != NULL) {
        if (R->P == P) {
            found = true;
            cout << "ID Event   : " << R->E->info.idEvent << endl;
            cout << "Nama Event : " << R->E->info.namaEvent << endl;
            cout << "------------------" << endl;
        }
        R = R->next;
    }

    if (!found) {
        cout << "Peserta ini belum mengikuti event apapun." << endl;
    }
}

void showAllEventWithPeserta(ListRelasi LR) {
    adrRelasi R = LR.first;

    if (R == NULL) {
        cout << "Belum ada relasi event - peserta." << endl;
        return;
    }

    while (R != NULL) {
        cout << "Event: " << R->E->info.namaEvent << " | Peserta: " << R->P->info.nama << endl;
        R = R->next;
    }
}

void showAllPesertaWithEvent(ListRelasi LR) {
    adrRelasi R = LR.first;

    if (R == NULL) {
        cout << "Belum ada relasi peserta - event." << endl;
    }

    while (R != NULL) {
        cout << "Peserta: " << R->P->info.nama << " | Event: " << R->E->info.namaEvent << endl;
        R = R->next;
    }
}

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
        }
        prev = R;
        R = R->next;
    }
}

void deleteRelasiByEvent(ListRelasi &LR, adrEvent E) {
    adrRelasi R = LR.first;
    adrRelasi prev = NULL;

    while (R != NULL) {
        if (R->E == E) {
            adrRelasi temp = R;
            if (prev == NULL) {
                LR.first = R->next;
            } else {
                prev->next = R->next;
            }
            R = R->next;
            delete temp;
        } else {
            prev = R;
            R = R->next;
        }
    }
}

void deleteRelasiByPeserta(ListRelasi &LR, adrPeserta P) {
    adrRelasi R = LR.first;
    adrRelasi prev = NULL;

    while (R != NULL) {
        if (R->P == P) {
            adrRelasi temp = R;
            if (prev == NULL) {
                LR.first = R->next;
            } else {
                prev->next = R->next;
            }
            R = R->next;
            delete temp;
        } else {
            prev = R;
            R = R->next;
        }
    }
}

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

int countEventByPeserta(ListRelasi LR, adrPeserta P) {
    int count = 0;
    adrRelasi R = LR.first;

    while (R != NULL) {
        if (R->P == P) count++;
        R = R->next;
    }

    return count;
}
int countChildWithoutParent(ListPeserta LP, ListRelasi LR) {
    int count = 0;
    adrPeserta P = LP.first;

    while (P != NULL) {
        bool punyaParent = false;
        adrRelasi R = LR.first;

        while (R != NULL) {
            if (R->P == P) {
                punyaParent = true;
                break;
            }
            R = R->next;
        }

        if (!punyaParent) {
            count++;
        }
        P = P->next;
    }
    return count;
}
int countParentWithoutChild(ListEvent LE, ListRelasi LR) {
    int count = 0;
    adrEvent E = LE.first;

    while (E != NULL) {
        bool punyaChild = false;
        adrRelasi R = LR.first;

        while (R != NULL) {
            if (R->E == E) {
                punyaChild = true;
                break;
            }
            R = R->next;
        }

        if (!punyaChild) {
            count++;
        }
        E = E->next;
    }

    return count;
}
bool editRelasi(ListRelasi &LR, adrEvent oldE, string idPeserta, adrEvent newE) {
    adrRelasi R = LR.first;

    while (R != NULL) {
        if (R->E == oldE && R->P->info.idPeserta == idPeserta) {
            R->E = newE;
            return true;
        }
        R = R->next;
    }
    return false;
}


