#include "event.h"
using namespace std;


void createEventList(ListEvent &LE) {
    LE.first = NULL;
}

bool isEmptyEvent(ListEvent LE) {
    return LE.first == NULL;
}

adrEvent newEvent(Event x) {
    adrEvent E = new elEvent;
    E->info = x;
    E->next = NULL;
    return E;
}

void insertFirstEvent(ListEvent &LE, adrEvent E) {
    if (isEmptyEvent(LE)) {
        LE.first = E;
    } else {
        E->next = LE.first;
        LE.first = E;
    }
}

void insertLastEvent(ListEvent &LE, adrEvent E) {
    if (isEmptyEvent(LE)) {
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

void deleteFirstEvent(ListEvent &LE) {
    if (!isEmptyEvent(LE)) {
        adrEvent P = LE.first;
        LE.first = P->next;
        delete P;
    }
}

void deleteLastEvent(ListEvent &LE) {
    if (!isEmptyEvent(LE)) {
        if (LE.first->next == NULL) {
            deleteFirstEvent(LE);
        } else {
            adrEvent P = LE.first;
            adrEvent Q = NULL;

            while (P->next != NULL) {
                Q = P;
                P = P->next;
            }

            if (Q != NULL) {
                Q->next = NULL;
            }
            delete P;
        }
    }
}


bool deleteEvent(ListEvent &LE, string id) {
    if (isEmptyEvent(LE)) {
        return false;
    }
    adrEvent P = LE.first;
    adrEvent Q = NULL;

    while (P != NULL && P->info.idEvent != id) {
        Q = P;
        P = P->next;
    }

    if (P == NULL) {
        return false; 
    }
    
    if (Q == NULL) {
        LE.first = P->next;
    } else {
        Q->next = P->next;
    }

    delete P;
    return true;
}

int countEvent(ListEvent LE) {
    int count = 0;
    adrEvent P = LE.first;

    while (P != NULL) {
        count++;
        P = P->next;
    }

    return count;
}


void showAllEvent(ListEvent LE) {
    if (isEmptyEvent(LE)) {
        cout << "Tidak ada data event." << endl;
    }

    adrEvent P = LE.first;
    int nomor = 1;

    while (P != NULL) {
        cout << "Event #" << nomor++ << endl;
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


