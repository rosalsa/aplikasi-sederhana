#include <iostream>

using namespace std;

// Struct untuk menyimpan informasi tugas
struct Tugas {
    string namaTugas;
    string deadline;
    bool selesai;
};

// Fungsi untuk menambahkan tugas
void tambahTugas(Tugas* daftarTugas, int& jumlahTugas) { //pointer *(derefence)mengambil nilai, &(reference) menyimpan alamat
    if (jumlahTugas < 20) { //maksimum 20 tugas
        cout << "Masukkan nama tugas: ";
        cin.ignore(); //agar tidak terjadi buffer saat menginput data
        getline(cin, daftarTugas[jumlahTugas].namaTugas); //untuk membaca string pada inputan
        cout << "Masukkan deadline (tgl-waktu): ";
        getline(cin, daftarTugas[jumlahTugas].deadline);
        daftarTugas[jumlahTugas].selesai = false;
        jumlahTugas++;
    } else {
        cout << "Daftar tugas penuh!" << endl;
    }
}


// Fungsi untuk menampilkan semua tugas
void tampilkanTugas(Tugas* daftarTugas, int jumlahTugas) {
    for (int i = 0; i < jumlahTugas; i++) {
        cout << "Tugas " << i+1 << ": " << daftarTugas[i].namaTugas
             << " | Deadline: " << daftarTugas[i].deadline
             << " | Status: " << (daftarTugas[i].selesai ? "Selesai" : "Belum Selesai") << endl;
    }
}

// Fungsi untuk menandai tugas sebagai selesai
void tandaiSelesai(Tugas* daftarTugas, int jumlahTugas) {
    int nomorTugas;
    cout << "Masukkan nomor tugas yang ingin ditandai selesai: ";
    cin >> nomorTugas;
    if (nomorTugas > 0 && nomorTugas <= jumlahTugas) {
        daftarTugas[nomorTugas-1].selesai = true;
        cout << "Tugas " << nomorTugas << " telah ditandai sebagai selesai." << endl;
    } else {
        cout << "Nomor tugas tidak valid!" << endl;
    }
}


int main() {
    Tugas daftarTugas[20]; //array untuk menampung daftar tugas
    int jumlahTugas = 0;
    int pilihan;

    do {
        cout << endl;
        cout << "===========================" << endl;
        cout << "       Jadwal Tugas        " << endl;
        cout << "===========================" << endl;
        cout << "Menu: " << endl;
        cout << "1. Tambah Tugas" << endl;
        cout << "2. Tampilkan Tugas" << endl;
        cout << "3. Tandai Tugas Selesai" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        //mengeksekusi program
        switch (pilihan) {
            case 1:
                tambahTugas(daftarTugas, jumlahTugas);
                break;
            case 2:
                tampilkanTugas(daftarTugas, jumlahTugas);
                break;
            case 3:
                tandaiSelesai(daftarTugas, jumlahTugas);
                break;
            case 0:
                cout << "Semangat Nugas!!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}