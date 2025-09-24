public class Produk {
    // Atribut menggunakan access modifier 'protected'
    protected String id_produk;
    protected String asal_produk;
    protected double harga;

    // Constructor untuk inisialisasi objek
    public Produk(String id_produk, String asal_produk, double harga) {
        this.id_produk = id_produk;
        this.asal_produk = asal_produk;
        this.harga = harga;
    }

    // Getter methods
    public String getId_produk() {
        return id_produk;
    }

    public String getAsal_produk() {
        return asal_produk;
    }

    public double getHarga() {
        return harga;
    }

}