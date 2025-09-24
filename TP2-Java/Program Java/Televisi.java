public class Televisi extends Elektronik {
    protected String ukuran;
    protected int stok;
    protected int tahun_produksi;

    public Televisi(String id_produk, String asal_produk, double harga, String lokasi_penyimpanan, String nama, String merk, String ukuran, int stok, int tahun_produksi) {
        super(id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk);
        this.ukuran = ukuran;
        this.stok = stok;
        this.tahun_produksi = tahun_produksi;
    }

    // Getter methods
    public String getUkuran() {
        return ukuran;
    }

    public int getStok() {
        return stok;
    }

     public int getTahunProduksi() {
        return tahun_produksi;
    }

}
