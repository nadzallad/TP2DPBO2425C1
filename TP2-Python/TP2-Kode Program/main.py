
from tabulate import tabulate
from televisi import Televisi

# List untuk menyimpan semua objek Televisi
data_televisi = []


def tampilkan_data():
    """Menampilkan semua data televisi dalam tabel dengan garis per kolom."""
    if not data_televisi:
        print("\nBelum ada data televisi.")
        return

    data_list = []
    for tv in data_televisi:
        data_list.append([
            tv.get_id_produk(),
            tv.get_asal_produk(),
            f"{tv.get_harga():,}",
            tv.get_lokasi_penyimpanan(),
            tv.get_nama(),
            tv.get_merk(),
            tv.get_ukuran(),
            tv.get_stok(),
            tv.get_tahun()
        ])

    headers = ["ID Produk", "Asal Produk", "Harga (Rp)", "Lokasi Penyimpanan", 
               "Nama", "Merek", "Ukuran", "Stok", "Tahun Produksi"]

    # Buat string tabel
    table_str = tabulate(data_list, headers=headers, tablefmt="grid", stralign="center")
    
    # Hitung panjang baris terpanjang
    max_width = max(len(line) for line in table_str.splitlines())

    # Cetak header dinamis
    print("\n" + "=" * max_width)
    print("DATA LENGKAP TELEVISI".center(max_width))
    print("=" * max_width)
    print(table_str)
    print("=" * max_width)

# Menambahkan data produk baru 
def tambah_data():
    """Menerima input dari user untuk menambahkan data televisi baru."""
    print("\n--- Tambah Data Televisi Baru ---")
    try:
        id_produk = input("Masukkan ID Produk: ")

        #cek apakah id sudah ada 
        for tv in data_televisi:
            if tv.get_id_produk() == id_produk:
                print(f"\n❌ ID Produk '{id_produk}' sudah ada. Gunakan ID lain.")
                return
            
        #input data batu
        asal_produk = input("Masukkan Asal Produk: ")
        harga = float(input("Masukkan Harga (Rp): "))
        lokasi_penyimpanan = input("Masukkan Lokasi Penyimpanan Barang: ")
        nama = input("Masukkan Nama Televisi: ")
        merk = input("Masukkan Merek: ")
        ukuran = input("Masukkan Ukuran (contoh: 55 inci): ")
        stok = int(input("Masukkan Stok: "))
        tahun_produksi = int(input("masukan tahun produksi:"))

        tv_baru = Televisi(id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk, ukuran, stok, tahun_produksi)
        data_televisi.append(tv_baru)
        print("\nData televisi berhasil ditambahkan!")
    except ValueError:
        print("\nInput tidak valid. Pastikan harga dan stok adalah angka.")

# Tambah 5 objek awal
data_televisi.append(Televisi("P001", "Jepang", 8500000, "Gudang Utama - Rak A1", "Bravia X90J", "Sony", "55 inci", 15, 2015))
data_televisi.append(Televisi("P002", "Korea", 12000000, "Gudang Utama - Rak A2", "QLED Q80A", "Samsung", "65 inci", 10, 2021))
data_televisi.append(Televisi("P003", "Tiongkok", 5500000, "Gudang Cabang - Rak B1", "Smart TV 4K", "Xiaomi", "50 inci", 25, 2023))
data_televisi.append(Televisi("P004", "Jepang", 7250000, "Gudang Cabang - Rak B2", "LED TV", "Sharp", "43 inci", 30, 2024))
data_televisi.append(Televisi("P005", "Korea", 9800000, "Gudang Utama - Rak C1", "OLED C1", "LG", "55 inci", 8, 2025))

# Loop utama untuk menu
while True:
    print("\n--- Menu Utama ---")
    print("1. Tambah Data Televisi")
    print("2. Tampilkan Semua Data")
    print("3. Keluar")
    pilihan = input("Pilih menu (1/2/3): ")

    if pilihan == '1':
        tambah_data()
    elif pilihan == '2':
        tampilkan_data()
    elif pilihan == '3':
        print("Terima kasih, program selesai.")
        exit()
    else:
        print("Pilihan tidak valid. Silakan coba lagi.")