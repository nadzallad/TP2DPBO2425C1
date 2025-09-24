<?php
class Produk {
    protected $id_produk;
    protected $asal_produk;
    protected $harga;

    public function __construct($id_produk, $asal_produk, $harga) {
        $this->id_produk = $id_produk;
        $this->asal_produk = $asal_produk;
        $this->harga = $harga;
    }

    //getter method
    public function getIdProduk() {
        return $this->id_produk;
    }

    public function getAsalProduk() {
        return $this->asal_produk;
    }

    public function getHarga() {
        return $this->harga;
    }

}
