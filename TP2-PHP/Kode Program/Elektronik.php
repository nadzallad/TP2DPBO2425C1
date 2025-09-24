<?php
require_once 'Produk.php';

class Elektronik extends Produk {
    protected $lokasi_penyimpanan;
    protected $nama;
    protected $merk;

    public function __construct($id_produk, $asal_produk, $harga, $lokasi_penyimpanan, $nama, $merk) {
        parent::__construct($id_produk, $asal_produk, $harga);
        $this->lokasi_penyimpanan = $lokasi_penyimpanan;
        $this->nama = $nama;
        $this->merk = $merk;
    }

    //getter methods
    public function getLokasiPenyimpanan() {
        return $this->lokasi_penyimpanan;
    }

    public function getNama() {
        return $this->nama;
    }

    public function getMerk() {
        return $this->merk;
    }


}
