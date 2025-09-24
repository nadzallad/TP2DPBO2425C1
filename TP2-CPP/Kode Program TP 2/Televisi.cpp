#include <iostream>
#include <string>
#include "Elektronik.cpp" 

// Deklarasi class Televisi yang merupakan turunan (subclass) dari class Elektronik
class Televisi : public Elektronik {
protected:
    std::string ukuran;
    int stok;
    int tahun_produksi;

public:
    // Constructor dengan parameter lengkap untuk menginisialisasi atribut dari Produk, Elektronik, dan Televisi
    Televisi(std::string id_produk, std::string asal_produk, double harga, std::string lokasi_penyimpanan, std::string nama, std::string merk, std::string ukuran, int stok, int tahun_produksi)
        : Elektronik(id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk) {
        this->ukuran = ukuran;
        this->stok = stok;
        this->tahun_produksi = tahun_produksi;
    }

    // Getter methods untuk mendapatkan nilai
    std::string getUkuran() const {
        return ukuran;
    }

    int getStok() const {
        return stok;
    }

    int getTahunProduksi() const {
        return tahun_produksi;
    }

};