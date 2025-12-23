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
bool isEmptyEvent(ListEvent LE);         
adrEvent newEvent(Event x);             
void insertFirstEvent(ListEvent &LE, adrEvent E);
void insertLastEvent(ListEvent &LE, adrEvent E);
bool isEventIDUsed(ListEvent LE, string id);
adrEvent searchEvent(ListEvent LE, string id);
void deleteFirstEvent(ListEvent &LE);
void deleteLastEvent(ListEvent &LE);
bool deleteEvent(ListEvent &LE, string id);
int countEvent(ListEvent LE);
void showAllEvent(ListEvent LE);

#endif
