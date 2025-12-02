#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

struct Event {
    string idEvent;
    string namaEvent;
    string lokasi;
    string tanggal;
    string jam;
    int hargaTiket;
};

typedef struct elEvent *adrEvent;

struct elEvent {
    Event info;
    adrEvent next;
};

struct ListEvent {
    adrEvent first;
};

void createEventList(ListEvent &LE);
adrEvent newEvent(Event x);
void insertLastEvent(ListEvent &LE, adrEvent E);
adrEvent searchEvent(ListEvent LE, string id);
bool isEventIDUsed(ListEvent LE, string id);
void deleteEvent(ListEvent &LE, string id);

void showAllEvent(ListEvent LE);

#endif
