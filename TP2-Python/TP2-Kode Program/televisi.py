
from elektronik import Elektronik

class Televisi(Elektronik):
    def __init__(self, id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk, ukuran, stok, tahun_produksi):
        super().__init__(id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk)
        self._ukuran = ukuran
        self._stok = stok
        self._tahun = tahun_produksi

    # Getter methods
    def get_ukuran(self):
        return self._ukuran

    def get_stok(self):
        return self._stok
    
    def get_tahun(self):
        return self._tahun

  