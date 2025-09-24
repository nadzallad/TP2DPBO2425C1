<?php
require_once 'Elektronik.php';

class Televisi extends Elektronik {
    protected $ukuran;
    protected $stok;
    protected $tahun_produksi;
    protected $gambar;  

    public function __construct($id_produk, $asal_produk, $harga, $lokasi_penyimpanan, $nama, $merk, $ukuran, $stok, $tahun_produksi  ,$gambar) {
        parent::__construct($id_produk, $asal_produk, $harga, $lokasi_penyimpanan, $nama, $merk);
        $this->ukuran = $ukuran;
        $this->stok = $stok;
        $this->tahun_produksi = $tahun_produksi;
        $this->gambar = $gambar;
    }

    //getter methods
    public function getUkuran() {
        return $this->ukuran;
    }

    public function getStok() {
        return $this->stok;
    }

    public function getTahunProduksi() {
        return $this->tahun_produksi;
    }

    public function getGambar() {
        return $this->gambar;
    }

    
}
