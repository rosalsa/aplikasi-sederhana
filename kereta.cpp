#include<iostream>
#include<string>

using namespace std;

// Deklarasi fungsi
void tampilkanRute();
void tampilkanJadwal();
void beliTiket();
void tampilkanTiket();

// Deklarasi array untuk menyimpan data
string ruteKereta[] = {"UNPAK - IPB", "UNPAK - UI", "UNPAK - UNPAD"};
string jadwalKereta[] = {"08:00", "12:30", "16:45"};
int hargaEkonomi[] = {100000, 150000, 120000};
int hargaEksekutif[] = {200000, 250000, 220000};
int hargaVIP[] = {300000, 350000, 320000};

// Variabel global untuk menyimpan data tiket yang sudah dibeli
string tiketDibeli[10];
int jumlahTiketDibeli = 0;

int main() {
    int pilihan;

    do {
        // Menu utama
        cout << "=== Aplikasi Kereta Lintas Kampus (KLK) ===" << endl;
        cout << "1. Tampilkan Rute" << endl;
        cout << "2. Tampilkan Jadwal" << endl;
        cout << "3. Beli Tiket" << endl;
        cout << "4. Tampilkan Tiket yang Sudah Dibeli" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                tampilkanRute();
                break;
            case 2:
                tampilkanJadwal();
                break;
            case 3:
                beliTiket();
                break;
            case 4:
                tampilkanTiket();
                break;
            case 0:
                cout << "Terima kasih. Sampai jumpa lagi!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}

void tampilkanRute() {
    cout << "=== Rute Kereta ===" << endl;
    for (int i = 0; i < sizeof(ruteKereta) / sizeof(ruteKereta[0]); i++) {
        cout << i + 1 << ". " << ruteKereta[i] << endl;
    }
}

void tampilkanJadwal() {
    cout << "=== Jadwal Kereta ===" << endl;
    for (int i = 0; i < sizeof(jadwalKereta) / sizeof(jadwalKereta[0]); i++) {
        cout << i + 1 << ". " << jadwalKereta[i] << endl;
    }
}

void beliTiket() {
    int nomorRute, kelas, jumlahTiket;

    // Pilih rute
    tampilkanRute();
    cout << "Pilih nomor rute: ";
    cin >> nomorRute;

    // Pilih kelas
    cout << "Pilih kelas tiket:" << endl;
    cout << "1. Ekonomi" << endl;
    cout << "2. Eksekutif" << endl;
    cout << "3. VIP" << endl;
    cout << "Pilihan Anda: ";
    cin >> kelas;

    // Input jumlah tiket yang akan dibeli
    cout << "Jumlah tiket yang akan dibeli: ";
    cin >> jumlahTiket;

    // Hitung total harga tiket
    int totalHarga = 0;
    switch(kelas) {
        case 1:
            totalHarga = jumlahTiket * hargaEkonomi[nomorRute - 1];
            break;
        case 2:
            totalHarga = jumlahTiket * hargaEksekutif[nomorRute - 1];
            break;
        case 3:
            totalHarga = jumlahTiket * hargaVIP[nomorRute - 1];
            break;
        default:
            cout << "Pilihan kelas tidak valid." << endl;
            return;
    }

    // Simpan data tiket yang sudah dibeli
    tiketDibeli[jumlahTiketDibeli] = "Rute: " + ruteKereta[nomorRute - 1] + ", Jadwal: " + jadwalKereta[nomorRute - 1] + ", Kelas: " + to_string(kelas) + ", Jumlah Tiket: " + to_string(jumlahTiket) + ", Total Harga: " + to_string(totalHarga);
    jumlahTiketDibeli++;

    cout << "Pembelian tiket berhasil!" << endl;
}

void tampilkanTiket() {
    cout << "=== Tiket yang Sudah Dibeli ===" << endl;
    for (int i = 0; i < jumlahTiketDibeli; i++) {
        cout << i + 1 << ". " << tiketDibeli[i] << endl;
    }
}
