#include <iostream>
#include <string>
#include "Produk.cpp" // Asumsikan file Produk.h sudah dibuat

class Elektronik : public Produk {
protected:
    // Atribut tambahan untuk kelas Elektronik
    std::string lokasi_penyimpanan;
    std::string nama;
    std::string merk;

public:
    // Konstruktor
    Elektronik(std::string id_produk, std::string asal_produk, double harga, std::string lokasi_penyimpanan, std::string nama, std::string merk)
        : Produk(id_produk, asal_produk, harga) { // Memanggil konstruktor kelas induk
        this->lokasi_penyimpanan = lokasi_penyimpanan;
        this->nama = nama;
        this->merk = merk;
    }

    // Getter methods (const)
    std::string getLokasi_penyimpanan() const {
        return lokasi_penyimpanan;
    }

    std::string getNama() const {
        return nama;
    }

    std::string getMerk() const {
        return merk;
    }

};