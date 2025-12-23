#include <iostream>
#include <string>
#include <iomanip>
#include "event.h"
#include "peserta.h"
#include "relasi.h"

using namespace std;

void printLine(int width) {
    cout << setfill('-') << setw(width) << "-" << setfill(' ') << endl;
}

void printCenter(string text, int width) {
    int pad = (width - text.length()) / 2;
    cout << setw(pad) << " " << text << setw(pad) << " ";
    if ((int)text.length() % 2 != width % 2) cout << " ";
}

void printHeader(string title) {
    printLine(70);
    cout << "|";
    printCenter(title, 66);
    cout << "|" << endl;
    printLine(70);
}

/* ====================== MENU EVENT ====================== */
void menuEvent(ListEvent &LE, ListPeserta &LP, ListRelasi &LR, adrEvent E) {
    int pilih;
    do {
        printHeader("MENU EVENT");
        cout << "Event : " << E->info.namaEvent << endl;
        cout << "Jumlah Peserta : " << countPesertaByEvent(LR, E) << endl;
        cout << "1. Lihat Data Event\n";
        cout << "2. List Peserta\n";
        cout << "3. Tambah Peserta ke Event\n";
        cout << "4. Hapus Peserta dari Event\n";
        cout << "5. Kembali\n";
        cout << "Pilih (1/2/3/4/5): ";
        cin >> pilih;

        if (pilih == 1) {
            printHeader("DETAIL EVENT");
            cout << left << setw(20) << "ID Event" << ": " << E->info.idEvent << endl;
            cout << left << setw(20) << "Nama Event" << ": " << E->info.namaEvent << endl;
            cout << left << setw(20) << "Lokasi" << ": " << E->info.lokasi << endl;
            cout << left << setw(20) << "Tanggal" << ": " << E->info.tanggal << endl;
            cout << left << setw(20) << "Jam" << ": " << E->info.jam << endl;
            cout << left << setw(20) << "Harga" << ": " << E->info.hargaTiket << endl;
            printLine(70);
        }
        else if (pilih == 2) {
            printHeader("LIST PESERTA DALAM EVENT");
            cout << left << setw(5) << "No"
                 << setw(15) << "ID Peserta"
                 << setw(20) << "Nama"
                 << setw(15) << "Telepon"
                 << endl;
            printLine(70);

            adrRelasi R = LR.first;
            int no = 1;
            while (R != NULL) {
                if (R->E == E) {
                    cout << left << setw(5) << no++
                         << setw(15) << R->P->info.idPeserta
                         << setw(20) << R->P->info.nama
                         << setw(15) << R->P->info.telepon
                         << endl;
                }
                R = R->next;
            }
            printLine(70);
        }
        else if (pilih == 3) {
            Peserta data;
            printHeader("TAMBAH PESERTA BARU");

            cout << "ID Peserta : ";
            cin >> data.idPeserta;
            if (isPesertaIDUsed(LP, data.idPeserta)) {
                cout << "ID peserta sudah digunakan.\n";
                continue;
            }

            cout << "Nama (contoh format: Morgan_Octogramiuss)         : ";
            cin >> data.nama;
            cout << "Telepon (contoh format: 0813215599 / +6281325599) : ";
            cin >> data.telepon;
            cout << "Jenis Kelamin (Pria/Wanita. pilih salah satu)     : ";
            cin >> data.jenisKelamin;
            cout << "Jenis Peserta (Umum/Reguler/VIP tergantung event) : ";
            cin >> data.jenisPeserta;

            adrPeserta P = newPeserta(data);
            insertLastPeserta(LP, P);
            insertRelasi(LR, newRelasi(E, P));

            cout << "Peserta berhasil ditambahkan.\n";
        }
        else if (pilih == 4) {
            string idPeserta;
            printHeader("HAPUS PESERTA DARI EVENT");
            cout << "ID Peserta yang dihapus: ";
            cin >> idPeserta;
            deletePesertaFromEvent(LR, E, idPeserta);
            cout << "Relasi peserta dihapus jika ditemukan.\n";
        }

    } while (pilih != 5);
}

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
        printHeader("MENU UTAMA");
        cout << "1. Pilih Event\n";
        cout << "2. Tambah Event\n";
        cout << "3. Hapus Event\n";
        cout << "4. Tampilkan Semua Event\n";
        cout << "5. Menu Relasi & Analisis Data\n";
        cout << "6. Keluar\n";
        cout << "Pilih (1/2/3/4/5/6): ";
        cin >> pilih;

        if (pilih == 1) {
            if (LE.first == NULL) {
                cout << "Belum ada data event.\n";
                continue;
            }

            printHeader("DAFTAR EVENT");
            cout << left << setw(5) << "No"
                 << setw(15) << "ID Event"
                 << setw(25) << "Nama Event"
                 << setw(10) << "Peserta"
                 << endl;
            printLine(70);

            adrEvent E = LE.first;
            int no = 1;
            while (E != NULL) {
                cout << left << setw(5) << no++
                     << setw(15) << E->info.idEvent
                     << setw(25) << E->info.namaEvent
                     << setw(10) << countPesertaByEvent(LR, E)
                     << endl;
                E = E->next;
            }
            printLine(70);

            string id;
            cout << "Pilih ID Event: ";
            cin >> id;
            adrEvent selected = searchEvent(LE, id);

            if (selected != NULL) {
                menuEvent(LE, LP, LR, selected);
            } else {
                cout << "Event tidak ditemukan.\n";
            }
        }
        else if (pilih == 2) {
            Event data;
            printHeader("TAMBAH EVENT");

            cout << "ID Event (contoh format: A01)           : ";
            cin >> data.idEvent;
            if (isEventIDUsed(LE, data.idEvent)) {
                cout << "ID event sudah digunakan.\n";
                continue;
            }

            cout << "Nama Event (contoh format: comifuro_21) : ";
            cin >> data.namaEvent;
            cout << "Lokasi (contoh format: Ice_BSD_Tangsel) : ";
            cin >> data.lokasi;
            cout << "Tanggal (DD-MM-YYYY)                    : ";
            cin >> data.tanggal;
            cout << "Jam mulai event (contoh format: 12.59)  : ";
            cin >> data.jam;
            cout << "Harga Tiket (contoh format: 100000)     : ";
            cin >> data.hargaTiket;

            insertLastEvent(LE, newEvent(data));
            cout << "Event berhasil ditambahkan.\n";
        }
        else if (pilih == 3) {
            string id;
            printHeader("HAPUS EVENT");
            cout << "ID Event yang dihapus: ";
            cin >> id;

            adrEvent E = searchEvent(LE, id);
            if (E != NULL) {
                removeAllRelasiOfEvent(LR, E);
                deleteEvent(LE, id);
                cout << "Event berhasil dihapus.\n";
            } else {
                cout << "Event tidak ditemukan.\n";
            }
        }
        else if (pilih == 4) {
            if (LE.first == NULL) {
                cout << "Belum ada data event.\n";
            } else {
                printHeader("SEMUA EVENT");
                cout << left << setw(5) << "No"
                     << setw(15) << "ID Event"
                     << setw(25) << "Nama Event"
                     << setw(10) << "Peserta"
                     << endl;
                printLine(70);

                adrEvent E = LE.first;
                int no = 1;
                while (E != NULL) {
                    cout << left << setw(5) << no++
                         << setw(15) << E->info.idEvent
                         << setw(25) << E->info.namaEvent
                         << setw(10) << countPesertaByEvent(LR, E)
                         << endl;
                    E = E->next;
                }
                printLine(70);
            }
        }
        else if (pilih == 5) {
        int pilihR;
        do {
            printHeader("MENU RELASI & ANALISIS DATA");
            cout << "1. Cek apakah peserta terdaftar dalam event tertentu\n";
            cout << "2. Tampilkan Event yang diikuti Peserta tertentu\n";
            cout << "3. Tampilkan seluruh Event beserta Pesertanya\n";
            cout << "4. Tampilkan seluruh Peserta beserta Event yang diikuti\n";
            cout << "5. Hitung jumlah event yang diikuti peserta\n";
            cout << "6. Hitung jumlah peserta yang tidak memiliki event\n";
            cout << "7. Hitung jumlah event yang tidak memiliki peserta\n";
            cout << "8. Edit Relasi (pindah peserta ke event lain)\n";
            cout << "9. Kembali\n";

            cout << "Pilih (1/2/3/4/5/6/7/8/9): ";
            cin >> pilihR;

            if (pilihR == 1) {
                string idE, idP;
                cout << "ID Event : "; cin >> idE;
                cout << "ID Peserta : "; cin >> idP;

                adrEvent E = searchEvent(LE, idE);
                adrPeserta P = searchPesertaByID(LP, idP);

                if (E && P) {
                    if (isRelated(LR, E, P)) cout << "Peserta TERDAFTAR pada event.\n";
                    else cout << "Peserta TIDAK terdaftar pada event.\n";
                } else cout << "Event atau Peserta tidak ditemukan.\n";
            }

            else if (pilihR == 2) {
                string idP;
                cout << "ID Peserta: ";
                cin >> idP;
                adrPeserta P = searchPesertaByID(LP, idP);
                if (P) showEventByPeserta(LR, P);
                else cout << "Peserta tidak ditemukan.\n";
            }

            else if (pilihR == 3) {
                showAllEventWithPeserta(LR);
            }

            else if (pilihR == 4) {
                showAllPesertaWithEvent(LR);
            }

            else if (pilihR == 5) {
                string idP;
                cout << "ID Peserta: ";
                cin >> idP;
                adrPeserta P = searchPesertaByID(LP, idP);
                if (P)
                    cout << "Jumlah Event yang diikuti: "
                        << countEventByPeserta(LR, P) << endl;
                else cout << "Peserta tidak ditemukan.\n";
            }

            else if (pilihR == 6) {
                cout << "Jumlah peserta yang tidak terdaftar event: "
                    << countChildWithoutParent(LP, LR) << endl;
            }

            else if (pilihR == 7) {
                cout << "Jumlah event yang tidak memiliki peserta: "
                    << countParentWithoutChild(LE, LR) << endl;
            }

            else if (pilihR == 8) {
                string oldEid, newEid, idP;
                cout << "ID Event Lama : "; cin >> oldEid;
                cout << "ID Event Baru : "; cin >> newEid;
                cout << "ID Peserta    : "; cin >> idP;

                adrEvent oldE = searchEvent(LE, oldEid);
                adrEvent newE = searchEvent(LE, newEid);

                if (oldE && newE) {
                    if (editRelasi(LR, oldE, idP, newE))
                        cout << "Relasi berhasil diubah.\n";
                    else
                        cout << "Relasi tidak ditemukan.\n";
                } else cout << "Event tidak ditemukan.\n";
            }

        } while (pilihR != 9);
    }

    } while (pilih != 6);


    cout << "Program selesai.\n";
    return 0;
}



