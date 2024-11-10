#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int MAX_MENU = 5;
    string menu[MAX_MENU] = {"Mie Ayam", "Mie Goreng", "Mie Rebus", "Mie Kuah", "Mie Pangsit"};
    int harga[MAX_MENU] = {12000, 11000, 10000, 13000, 15000};
    
    int totalPembelian = 0;

    cout << "Selamat datang di Warmindo!" << endl;

    while (true) {
        cout << "\nDaftar Menu:\n";
        for (int i = 0; i < MAX_MENU; ++i) {
            cout << i + 1 << ". " << setw(15) << left << menu[i] << "Rp " << harga[i] << endl;
        }

        int pilihan;
        cout << "\nPilih menu (1-" << MAX_MENU << ", 0 untuk selesai): ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= MAX_MENU) {
            int jumlah;
            cout << "Jumlah pesanan: ";
            cin >> jumlah;

            totalPembelian += harga[pilihan - 1] * jumlah;

            cout << "Pesanan Anda (" << menu[pilihan - 1] << " x " << jumlah << ") ditambahkan ke keranjang.\n";
        } else if (pilihan == 0) {
            cout << "\nTerima kasih sudah memesan di Warmindo!\n";
            break;
        } else {
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    }

    cout << "\nTotal pembelian: Rp " << totalPembelian << endl;

    return 0;
}