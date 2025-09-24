// main.cpp
#include<bits/stdc++.h>
#include "Televisi.cpp" 

// Fungsi untuk menampilkan semua data televisi
void tampilkanData(const std::vector<Televisi>& dataTelevisi) {
    if (dataTelevisi.empty()) {
        std::cout << "\nBelum ada data televisi." << std::endl;
        return;
    }

    // Hitung lebar maksimum untuk setiap kolom
    int maxId = std::string("ID Produk").length();
    int maxAsal = std::string("Asal Produk").length();
    int maxHarga = std::string("Harga (Rp)").length();
    int maxLokasi = std::string("Lokasi Penyimpanan").length();
    int maxNama = std::string("Nama").length();
    int maxMerk = std::string("Merek").length();
    int maxUkuran = std::string("Ukuran").length();
    int maxStok = std::string("Stok").length();
    int maxTahunProduksi = std::string("Tahun Produksi").length();

    // Cari panjang string terpanjang di setiap kolom dari data
    for (const auto& tv : dataTelevisi) {
        maxId = std::max(maxId, (int)tv.getId_produk().length());
        maxAsal = std::max(maxAsal, (int)tv.getAsal_produk().length());
        std::string hargaStr = std::to_string(static_cast<long long>(tv.getHarga()));
        maxHarga = std::max(maxHarga, (int)hargaStr.length());
        maxLokasi = std::max(maxLokasi, (int)tv.getLokasi_penyimpanan().length());
        maxNama = std::max(maxNama, (int)tv.getNama().length());
        maxMerk = std::max(maxMerk, (int)tv.getMerk().length());
        maxUkuran = std::max(maxUkuran, (int)tv.getUkuran().length());
        maxStok = std::max(maxStok, (int)std::to_string(tv.getStok()).length());
        maxTahunProduksi = std::max(maxTahunProduksi, (int)std::to_string(tv.getTahunProduksi()).length());
    }
    
    // Tambahkan spasi
    maxId += 2;
    maxAsal += 2;
    maxHarga += 2;
    maxLokasi += 2;
    maxNama += 2;
    maxMerk += 2;
    maxUkuran += 2;
    maxStok += 2;
    maxTahunProduksi += 2;

    // Hitung total lebar tabel untuk garis
    int totalWidth = maxId + maxAsal + maxHarga + maxLokasi + maxNama + maxMerk + maxUkuran + maxStok + maxTahunProduksi + (9 * 3);
    
    // Cetak garis atas dan bawah secara dinamis
    std::cout << "\n" << std::string(totalWidth - 17, '=') << std::endl;
    
    // Hitung perataan untuk judul
    int titlePadding = (totalWidth - std::string("DATA LENGKAP TELEVISI").length()) / 2 -10; 
    std::cout << std::string(titlePadding, ' ') << "DATA LENGKAP TELEVISI" << std::endl;
    std::cout << std::string(totalWidth-17, '=') << std::endl;

    // Header tabel
    std::cout << std::string(totalWidth-17, '-') << std::endl;
    std::cout << "| " << std::left << std::setw(maxId - 2) << "ID Produk"
              << " | " << std::left << std::setw(maxAsal - 2) << "Asal Produk"
              << " | " << std::right << std::setw(maxHarga - 2) << "Harga (Rp)"
              << " | " << std::left << std::setw(maxLokasi - 2) << "Lokasi Penyimpanan"
              << " | " << std::left << std::setw(maxNama - 2) << "Nama"
              << " | " << std::left << std::setw(maxMerk - 2) << "Merek"
              << " | " << std::left << std::setw(maxUkuran - 2) << "Ukuran"
              << " | " << std::left << std::setw(maxStok - 2) << "Stok" 
              << " | " << std::left << std::setw(maxTahunProduksi - 2) << "Tahun Produksi" << " |" << std::endl;
    std::cout << std::string(totalWidth-17, '-') << std::endl;

    // Isi tabel
    for (const auto& tv : dataTelevisi) {
        std::cout << "| " << std::left << std::setw(maxId - 2) << tv.getId_produk()
                  << " | " << std::left << std::setw(maxAsal - 2) << tv.getAsal_produk()
                  << " | " << std::right << std::setw(maxHarga - 2) << static_cast<long long>(tv.getHarga())
                  << " | " << std::left << std::setw(maxLokasi - 2) << tv.getLokasi_penyimpanan()
                  << " | " << std::left << std::setw(maxNama - 2) << tv.getNama()
                  << " | " << std::left << std::setw(maxMerk - 2) << tv.getMerk()
                  << " | " << std::left << std::setw(maxUkuran - 2) << tv.getUkuran()
                  << " | " << std::left << std::setw(maxStok - 2) << tv.getStok()
                  << " | " << std::left << std::setw(maxTahunProduksi - 2) << tv.getTahunProduksi() << " |" << std::endl;
                  std::cout << std::string(totalWidth-17, '-') << std::endl;
    }
    std::cout << std::string(totalWidth - 17, '=') << std::endl;
}

// Fungsi untuk menambah data televisi
void tambahData(std::vector<Televisi>& dataTelevisi) {
    std::cout << "\n--- Tambah Data Televisi Baru ---" << std::endl;
    std::string id_produk, asal_produk, lokasi_penyimpanan, nama, merk, ukuran;
    double harga;
    int stok;
    int tahun_produksi;

    std::cout << "Masukkan ID Produk: ";
    std::cin >> id_produk;

    // Cek apakah ID produk sudah ada
    for (const auto& tv : dataTelevisi) {
        if (tv.getId_produk() == id_produk) {
            std::cout << "\n❌ ID Produk '" << id_produk << "' sudah ada. Gunakan ID lain." << std::endl;
            return;
        }
    }

    //innput data data baru
    std::cout << "Masukkan Asal Produk: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
    std::getline(std::cin, asal_produk);
    std::cout << "Masukkan Harga (Rp): ";
    std::cin >> harga;
    std::cout << "Masukkan Lokasi Penyimpanan Barang: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, lokasi_penyimpanan);
    std::cout << "Masukkan Nama Televisi: ";
    std::getline(std::cin, nama);
    std::cout << "Masukkan Merek: ";
    std::getline(std::cin, merk);
    std::cout << "Masukkan Ukuran (contoh: 55 inci): ";
    std::getline(std::cin, ukuran);
    std::cout << "Masukkan Stok: ";
    std::cin >> stok;
    std::cout << "Masukkan Tahun Produksi: ";
    std::cin >> tahun_produksi;

    dataTelevisi.emplace_back(id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk, ukuran, stok, tahun_produksi);
    std::cout << "\nData televisi berhasil ditambahkan!" << std::endl;
}

int main() {
    std::vector<Televisi> dataTelevisi;

    // Inisialisasi 5 objek awal
    dataTelevisi.emplace_back("P001", "Jepang", 8500000, "Gudang Utama - Rak A1", "Bravia X90J", "Sony", "55 inci", 15, 2015);
    dataTelevisi.emplace_back("P002", "Korea", 12000000, "Gudang Utama - Rak A2", "QLED Q80A", "Samsung", "65 inci", 10, 2021);
    dataTelevisi.emplace_back("P003", "Tiongkok", 5500000, "Gudang Cabang - Rak B1", "Smart TV 4K", "Xiaomi", "50 inci", 25, 2023);
    dataTelevisi.emplace_back("P004", "Jepang", 7250000, "Gudang Cabang - Rak B2", "LED TV", "Sharp", "43 inci", 30, 2024);
    dataTelevisi.emplace_back("P005", "Korea", 9800000, "Gudang Utama - Rak C1", "OLED C1", "LG", "55 inci", 8, 2025);

    int pilihan;
    while (true) {
        std::cout << "\n--- Menu Utama ---" << std::endl;
        std::cout << "1. Tambah Data Televisi" << std::endl;
        std::cout << "2. Tampilkan Semua Data" << std::endl;
        std::cout << "3. Keluar" << std::endl;
        std::cout << "Pilih menu (1/2/3): ";
        std::cin >> pilihan;

        switch (pilihan) {
            //menambah produk
            case 1:
                tambahData(dataTelevisi);
                break;
            //menampilkan produk 
            case 2:
                tampilkanData(dataTelevisi);
                break;
            //keluar program
            case 3:
                std::cout << "Terima kasih, program selesai." << std::endl;
                return 0;
            //jika tidak sesuai
            default:
                std::cout << "Pilihan tidak valid. Silakan coba lagi." << std::endl;
        }
    }
    return 0;
}