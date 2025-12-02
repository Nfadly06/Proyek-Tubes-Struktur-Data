#include "event.h"
using namespace std;

void createEventList(ListEvent &LE) {
    LE.first = NULL;
}

adrEvent newEvent(Event x) {
    adrEvent E = new elEvent;
    E->info = x;
    E->next = NULL;
    return E;
}

void insertLastEvent(ListEvent &LE, adrEvent E) {
    if (LE.first == NULL) {
        LE.first = E;
    } else {
        adrEvent P = LE.first;
        while (P->next != NULL) {
            P = P->next;
        }
        P->next = E;
    }
}

bool isEventIDUsed(ListEvent LE, string id) {
    adrEvent P = LE.first;
    while (P != NULL) {
        if (P->info.idEvent == id) return true;
        P = P->next;
    }
    return false;
}

adrEvent searchEvent(ListEvent LE, string id) {
    adrEvent P = LE.first;
    while (P != NULL) {
        if (P->info.idEvent == id) return P;
        P = P->next;
    }
    return NULL;
}

void deleteEvent(ListEvent &LE, string id) {
    adrEvent P = LE.first;
    adrEvent prev = NULL;

    while (P != NULL && P->info.idEvent != id) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        if (prev == NULL) {
            LE.first = P->next;
        } else {
            prev->next = P->next;
        }
        delete P;
    }
}

void showAllEvent(ListEvent LE) {
    adrEvent P = LE.first;
    while (P != NULL) {
        cout << "ID Event   : " << P->info.idEvent << endl;
        cout << "Nama Event : " << P->info.namaEvent << endl;
        cout << "Lokasi     : " << P->info.lokasi << endl;
        cout << "Tanggal    : " << P->info.tanggal << endl;
        cout << "Jam        : " << P->info.jam << endl;
        cout << "Harga      : " << P->info.hargaTiket << endl;
        cout << "---------------------------" << endl;
        P = P->next;
    }
}
