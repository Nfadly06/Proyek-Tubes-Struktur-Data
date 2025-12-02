#include <iostream>
#include <string>
#include "event.h"
#include "peserta.h"
#include "relasi.h"

using namespace std;

// Menu khusus untuk satu event
void menuEvent(ListEvent &LE, ListPeserta &LP, ListRelasi &LR, adrEvent E) {
    int pilih;
    do {
        cout << "\n===== MENU EVENT =====\n";
        cout << "Event : " << E->info.namaEvent << " (ID: " << E->info.idEvent << ")\n";
        cout << "1. Lihat Data Event\n";
        cout << "2. List Peserta\n";
        cout << "3. Tambah Peserta ke Event\n";
        cout << "4. Hapus Peserta dari Event (berdasarkan nama)\n";
        cout << "5. Kembali\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "\n--- DATA EVENT ---\n";
            cout << "ID Event   : " << E->info.idEvent << endl;
            cout << "Nama Event : " << E->info.namaEvent << endl;
            cout << "Lokasi     : " << E->info.lokasi << endl;
            cout << "Tanggal    : " << E->info.tanggal << endl;
            cout << "Jam        : " << E->info.jam << endl;
            cout << "Harga      : " << E->info.hargaTiket << endl;

        } else if (pilih == 2) {
            cout << "\n--- PESERTA DI EVENT ---\n";
            showPesertaByEvent(LR, E);

        } else if (pilih == 3) {
            cout << "\n--- TAMBAH PESERTA KE EVENT ---\n";
            Peserta data;
            cout << "ID Peserta     : "; cin >> data.idPeserta;

            if (isPesertaIDUsed(LP, data.idPeserta)) {
                cout << "ID peserta sudah digunakan.\n";
                continue;
            }

            cout << "Nama           : "; cin >> data.nama;
            cout << "Telepon        : "; cin >> data.telepon;
            cout << "Jenis Kelamin  : "; cin >> data.jenisKelamin;
            cout << "Jenis Peserta  : "; cin >> data.jenisPeserta;

            adrPeserta P = newPeserta(data);
            insertLastPeserta(LP, P);

            adrRelasi R = newRelasi(E, P);
            insertRelasi(LR, R);

            cout << "Peserta berhasil ditambahkan ke event.\n";

        } else if (pilih == 4) {
            cout << "\n--- HAPUS PESERTA DARI EVENT ---\n";
            string nama;
            cout << "Masukkan nama peserta yang ingin dihapus dari event: ";
            cin >> nama;

            // hapus relasi yang menghubungkan peserta dengan event ini
            deletePesertaFromEvent(LR, E, nama);
            cout << "Jika peserta ditemukan, relasi telah dihapus.\n";

        } else if (pilih == 5) {
            // kembali
        } else {
            cout << "Pilihan tidak dikenali. Silakan coba lagi.\n";
        }

    } while (pilih != 5);
}

// Fungsi bantu untuk menghapus semua relasi yang berkaitan dengan sebuah event
void removeAllRelasiOfEvent(ListRelasi &LR, adrEvent E) {
    adrRelasi curr = LR.first;
    adrRelasi prev = NULL;
    while (curr != NULL) {
        if (curr->E == E) {
            adrRelasi toDelete = curr;
            if (prev == NULL) {
                LR.first = curr->next;
                curr = LR.first;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
            delete toDelete;
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

    // contoh data awal (opsional)
    Event e1 = {"E1", "Konser Musik", "Jakarta", "01-12-2025", "19:00", 150000};
    Event e2 = {"E2", "Seminar AI", "Bandung", "05-12-2025", "09:00", 50000};
    insertLastEvent(LE, newEvent(e1));
    insertLastEvent(LE, newEvent(e2));

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
            cout << "\n--- LIST EVENT ---\n";
            showAllEvent(LE);
            cout << "Masukkan ID Event yang ingin dipilih: ";
            string idEv; cin >> idEv;

            adrEvent E = searchEvent(LE, idEv);
            if (E != NULL) {
                menuEvent(LE, LP, LR, E);
            } else {
                cout << "Event tidak ditemukan.\n";
            }

        } else if (pilih == 2) {
            cout << "\n--- TAMBAH EVENT ---\n";
            Event data;
            cout << "ID Event : "; cin >> data.idEvent;
            if (isEventIDUsed(LE, data.idEvent)) {
                cout << "ID event sudah digunakan.\n";
                continue;
            }
            cout << "Nama Event : "; cin >> data.namaEvent;
            cout << "Lokasi     : "; cin >> data.lokasi;
            cout << "Tanggal    : "; cin >> data.tanggal;
            cout << "Jam        : "; cin >> data.jam;
            cout << "Harga Tiket: "; cin >> data.hargaTiket;

            insertLastEvent(LE, newEvent(data));
            cout << "Event berhasil ditambahkan.\n";

        } else if (pilih == 3) {
            cout << "\n--- HAPUS EVENT ---\n";
            cout << "Masukkan ID Event yang ingin dihapus: ";
            string idEv; cin >> idEv;

            adrEvent E = searchEvent(LE, idEv);
            if (E == NULL) {
                cout << "Event tidak ditemukan.\n";
            } else {
                // hapus semua relasi yang berkaitan dengan event ini
                removeAllRelasiOfEvent(LR, E);
                // hapus node event
                deleteEvent(LE, idEv);
                cout << "Event dan relasinya telah dihapus.\n";
            }

        } else if (pilih == 4) {
            cout << "\n--- SEMUA EVENT ---\n";
            showAllEvent(LE);

        } else if (pilih == 5) {
            // keluar
        } else {
            cout << "Pilihan tidak dikenali. Silakan coba lagi.\n";
        }

    } while (pilih != 5);

    cout << "Program selesai.\n";
    return 0;
}
