#include <iostream>
using namespace std;

// Struct untuk data tiket
struct Tiket {
    string film;
    int harga;
};

// Fungsi untuk menampilkan daftar film beserta harga
void tampilkanDaftarFilm(Tiket daftarFilm[], int jumlahFilm) { //[] tidak di definisakan karena sudah di inisialisasi diluar fungsi
    cout << "\nDaftar Film Yang Tersedia:" << endl;
    for (int i = 0; i < jumlahFilm; i++) {
        cout << i + 1 << ". " << daftarFilm[i].film << " - Rp" << daftarFilm[i].harga << endl; //daftarFilm[i].film, mengakses anggota film dari elemen ke-i dari array daftarFilm
    }
}

int main() {
    const int JUMLAH_FILM = 3;
    Tiket daftarFilm[JUMLAH_FILM] = {{"Sekawan Limo", 35000}, {"Ipar Adalah Maut", 30000}, {"Frozen 3", 40000}};

    int pilihan, jumlahTiket;
    int totalTiket = 0;
    int totalHarga = 0;
    string pesananFilm = "";
    char lanjutPesan;
    
    do {
        tampilkanDaftarFilm(daftarFilm, JUMLAH_FILM);

        cout << "Pilih Film Yang Ingin Ditonton: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= JUMLAH_FILM) {
            cout << "Masukkan Jumlah Tiket Yang Ingin Dibeli: ";
            cin >> jumlahTiket;

            totalTiket += jumlahTiket;
            totalHarga += jumlahTiket * daftarFilm[pilihan - 1].harga;
            pesananFilm += to_string(jumlahTiket) + " Tiket Untuk Film " + daftarFilm[pilihan - 1].film + "\n";
        } else {
            cout << "Film Tidak Valid. Silakan Coba Lagi." << endl;
        }

        // Pengecekan validasi input untuk melanjutkan pemesanan
        do {
            cout << "Apakah Ingin Memesan Tiket Lagi? (Y/T): ";
            cin >> lanjutPesan;
            lanjutPesan = toupper(lanjutPesan); //mengubah huruf kecil jadi besar
            if (lanjutPesan != 'Y' && lanjutPesan != 'T') {
                cout << "Input tidak valid. Silakan masukkan 'Y' untuk Ya atau 'T' untuk Tidak." << endl;
            }
        } while (lanjutPesan != 'Y' && lanjutPesan != 'T');

        cout << "\n==========================================\n";

    } while (lanjutPesan == 'Y');

    if (totalTiket > 0) {
        cout << ":---------------Nota Anda----------------:" << endl;
        cout << pesananFilm;
        cout << "Total Tiket: " << totalTiket << endl;
        cout << "Total Harga: Rp" << totalHarga << endl;
        cout << "\nSelamat Menonton!" << endl;
    }

    cout << "\nTerima Kasih. Telah Berkunjung" << endl;

    return 0;
}