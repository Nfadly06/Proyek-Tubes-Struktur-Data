#include <iostream>
#include <string>
#include "event.h"
#include "peserta.h"
#include "relasi.h"

using namespace std;

/* MENU EVENT */
void menuEvent(ListEvent &LE, ListPeserta &LP, ListRelasi &LR, adrEvent E) {
    int pilih;
    do {
        cout << "\n===== MENU EVENT =====\n";
        cout << "Event : " << E->info.namaEvent << endl;
        cout << "Jumlah Peserta : " << countPesertaByEvent(LR, E) << endl;
        cout << "1. Lihat Data Event\n";
        cout << "2. List Peserta\n";
        cout << "3. Tambah Peserta ke Event\n";
        cout << "4. Hapus Peserta dari Event\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "\nID Event   : " << E->info.idEvent << endl;
            cout << "Nama Event : " << E->info.namaEvent << endl;
            cout << "Lokasi     : " << E->info.lokasi << endl;
            cout << "Tanggal    : " << E->info.tanggal << endl;
            cout << "Jam        : " << E->info.jam << endl;
            cout << "Harga      : " << E->info.hargaTiket << endl;
        }
        else if (pilih == 2) {
            cout << "\n--- LIST PESERTA ---\n";
            showPesertaByEvent(LR, E);
        }
        else if (pilih == 3) {
            Peserta data;
            cout << "ID Peserta : ";
            cin >> data.idPeserta;
            if (isPesertaIDUsed(LP, data.idPeserta)) {
                cout << "ID peserta sudah digunakan.\n";
                continue;
            }
            cout << "Nama          : ";
            cin >> data.nama;
            cout << "Telepon       : ";
            cin >> data.telepon;
            cout << "Jenis Kelamin : ";
            cin >> data.jenisKelamin;
            cout << "Jenis Peserta : ";
            cin >> data.jenisPeserta;

            adrPeserta P = newPeserta(data);
            insertLastPeserta(LP, P);
            insertRelasi(LR, newRelasi(E, P));

            cout << "Peserta berhasil ditambahkan.\n";
        }
        else if (pilih == 4) {
            string idPeserta;
            cout << "ID Peserta yang dihapus: ";
            cin >> idPeserta;
            deletePesertaFromEvent(LR, E, idPeserta);
            cout << "Relasi peserta dihapus jika ditemukan.\n";
        }


    } while (pilih != 5);
}

/* HAPUS SEMUA RELASI EVENT */
void removeAllRelasiOfEvent(ListRelasi &LR, adrEvent E) {
    adrRelasi curr = LR.first;
    adrRelasi prev = NULL;

    while (curr != NULL) {
        if (curr->E == E) {
            adrRelasi del = curr;
            if (prev == NULL) {
                LR.first = curr->next;
                curr = LR.first;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
            delete del;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

int main() {
    ListEvent LE;
    ListPeserta LP;
    ListRelasi LR;

    createEventList(LE);
    createPesertaList(LP);
    createRelasiList(LR);

    int pilih;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Pilih Event\n";
        cout << "2. Tambah Event\n";
        cout << "3. Hapus Event\n";
        cout << "4. Tampilkan Semua Event\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            if (LE.first == NULL) {
                cout << endl;
                cout << "Belum ada data event.\n";
                continue;
            }
            showAllEvent(LE);
            string id;
            cout << endl;
            cout << "Pilih ID Event: ";
            cin >> id;
            adrEvent E = searchEvent(LE, id);
            if (E != NULL) {
                menuEvent(LE, LP, LR, E);
            } else {
                cout << "Event tidak ditemukan.\n";
            }
        }
        else if (pilih == 2) {
            Event data;
            cout << endl;
            cout << "=== Tambah Event ===" << endl;
            cout << "ID Event : ";
            cin >> data.idEvent;
            if (isEventIDUsed(LE, data.idEvent)) {
                cout << "ID event sudah digunakan.\n";
                continue;
            }

            cout << "Nama Event : ";
            cin >> data.namaEvent;
            cout << "Lokasi     : ";
            cin >> data.lokasi;
            cout << "Tanggal    : ";
            cin >> data.tanggal;
            cout << "Jam        : ";
            cin >> data.jam;
            cout << "Harga      : ";
            cin >> data.hargaTiket;

            insertLastEvent(LE, newEvent(data));
            cout << "Event berhasil ditambahkan.\n";
        }
        else if (pilih == 3) {
            string id;
            cout << endl;
            cout << "ID Event yang dihapus: ";
            cin >> id;
            adrEvent E = searchEvent(LE, id);
            if (E != NULL) {
                removeAllRelasiOfEvent(LR, E);
                deleteEvent(LE, id);
                cout << endl;
                cout << "Event berhasil dihapus.\n";
            } else {
                cout << endl;
                cout << "Event tidak ditemukan.\n";
            }
        }
        else if (pilih == 4) {
            if (LE.first == NULL) {
                cout << "Belum ada data event.\n";
            } else {
                adrEvent E = LE.first;
                while (E != NULL) {
                    cout << endl;
                    cout << "ID Event   : " << E->info.idEvent << endl;
                    cout << "Nama Event : " << E->info.namaEvent << endl;
                    cout << "Jumlah Peserta : "
                         << countPesertaByEvent(LR, E) << endl;
                    cout << "---------------------------\n";
                    E = E->next;
                }
            }
        }

    } while (pilih != 5);

    cout << "Program selesai.\n";
    return 0;
}
