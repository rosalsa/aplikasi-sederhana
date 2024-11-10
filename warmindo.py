print ('==========================')
print ('Selamat Datang di WARMINDO');
print ('==========================\n');

def makanan() :
    print ('---------------Menu Makanan--------------- ')
    print ('     1. Mie Original        Rp. 6.000')
    print ('     2. Mie Nyemek          Rp. 9.000')
    print ('     3. Mie Jahat           Rp. 8.000')
    print ('     4. Mie Seafood         Rp. 12.000')
    print ('     5. Burjo Ketan Hitam   Rp. 5.000')
    print ('     6. Gorengan            Rp. 2.000')

def minuman() :
    print ('---------------Menu Minuman--------------- ')
    print ('     1. Es Teh Manis        Rp. 3.000')
    print ('     2. Teh Botol           Rp. 6.000')
    print ('     3. Kopi Hitam          Rp. 5.000')
    print ('     4. Teh Hangat          Rp. 3.000')
    print ('     5. Pop Ice             Rp. 4.000')

print('\nSilahkan pesan makanan: ')
makanan()
pilih = input('Masukkan pilihan menu (1/2/3/4/5/6) : ')

def pesan_makanan(pilihan):
    if pilihan == '1':
        return 'Mie Original', 6000
    elif pilihan == '2':
        return 'Mie Nyemek', 9000
    elif pilihan == '3':
        return 'Mie Jahat', 8000
    elif pilihan == '4':
        return 'Mie Seafood', 12000
    elif pilihan == '5':
        return 'Burjo Ketan Hitam', 5000
    elif pilihan == '6':
        return 'Gorengan', 2000
    else:
        return 'Menu Tidak Tersedia', 0

print('\nSilahkan pesan minuman: ')
minuman()
pilih_minum = input('Masukkan pilihan menu (1/2/3/4/5) : ')

def pesan_minuman(pilihan):
    if pilihan == '1':
        return 'Es Teh Manis', 3000
    elif pilihan == '2':
        return 'Teh Botol', 6000
    elif pilihan == '3':
        return 'Kopi Hitam', 5000
    elif pilihan == '4':
        return 'Teh Hangat', 3000
    elif pilihan == '5':
        return 'Pop Ice', 4000
    else:
        return 'Menu Tidak Tersedia', 0
    
makanan_terpilih, harga_makanan = pesan_makanan(pilih)
print('\nAnda memesan:', makanan_terpilih)
print('Harga: Rp. ', harga_makanan)
    
minuman_terpilih, harga_minuman = pesan_minuman(pilih_minum)
print('\nAnda memesan:', minuman_terpilih)
print('Harga: Rp. ', harga_minuman)

total_harga = harga_makanan + harga_minuman
uang_pembayaran = int(input('\nMasukkan jumlah uang pembayaran: Rp. '))

kembalian = uang_pembayaran - total_harga

def cetak_struk(makanan_terpilih, harga_makanan, minuman_terpilih, harga_minuman, total_harga, uang_pembayaran, kembalian):
    print('\n\n==================================')
    print('         Struk Total Belanja       ')
    print('==================================')
    print('\nMakanan yang dipesan: ', makanan_terpilih)
    print('Harga Makanan: Rp. {}'.format(harga_makanan))
    print('Minuman yang dipesan: ', minuman_terpilih)
    print('Harga Minuman: Rp. {}'.format(harga_minuman))
    print('\n----------------------------------')
    print('Total Harga: Rp. {}'.format(total_harga))
    print('----------------------------------')
    print('\nUang Pembayaran: Rp. {}'.format(uang_pembayaran))
    print('Kembalian: Rp. {}'.format(kembalian))
    print('\nTerima kasih sudah mampir ke WARMINDO!')

cetak_struk(makanan_terpilih, harga_makanan, minuman_terpilih, harga_minuman, total_harga, uang_pembayaran, kembalian)

cetak_struk = False

while not cetak_struk:
    selesai = input('Apakah pesanan Anda sudah selesai? (ya/tidak): ')
    if selesai.lower() == 'ya':
        print('Terima kasih sudah mampir ke WARMINDO!')
        cetak_struk = True
    elif selesai.lower() == 'tidak':
        print('Silakan lanjutkan pesanan Anda.')
        cetak_struk = False
    else:
        print('Masukan tidak valid. Silakan jawab dengan "ya" atau "tidak".')
