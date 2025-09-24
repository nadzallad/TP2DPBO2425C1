#include <iostream>
#include <string>

class Produk {
protected:
    // Atribut menggunakan access specifier 'protected'
    std::string id_produk;
    std::string asal_produk;
    double harga;

public:
    // Constructor untuk inisialisasi objek
    Produk(std::string id_produk, std::string asal_produk, double harga) {
        this->id_produk = id_produk;
        this->asal_produk = asal_produk;
        this->harga = harga;
    }

    // Getter methods untuk mengambil data
    std::string getId_produk() const {
        return id_produk;
    }

    std::string getAsal_produk() const {
        return asal_produk;
    }

    double getHarga() const {
        return harga;
    }

};