// File: Elektronik.java
// Kelas Produk diasumsikan sudah ada dan berada dalam direktori yang sama.
// Jika tidak, perlu diimport.

public class Elektronik extends Produk {
    // Atribut tambahan untuk kelas Elektronik
    protected String lokasi_penyimpanan;
    protected String nama;
    protected String merk;

    // Konstruktor
    public Elektronik(String id_produk, String asal_produk, double harga, String lokasi_penyimpanan, String nama, String merk) {
        // Memanggil konstruktor dari kelas induk (Produk)
        super(id_produk, asal_produk, harga);
        this.lokasi_penyimpanan = lokasi_penyimpanan;
        this.nama = nama;
        this.merk = merk;
    }

    // Getter methods
    public String getLokasi_penyimpanan() {
        return lokasi_penyimpanan;
    }

    public String getNama() {
        return nama;
    }

    public String getMerk() {
        return merk;
    }

}