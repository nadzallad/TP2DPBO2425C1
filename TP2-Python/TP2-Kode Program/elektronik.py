from produk import Produk

class Elektronik(Produk):
    def __init__(self, id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk):
        super().__init__(id_produk, asal_produk, harga)
        self._lokasi_penyimpanan = lokasi_penyimpanan
        self._nama = nama
        self._merk = merk

    # Getter methods
    def get_lokasi_penyimpanan(self):
        return self._lokasi_penyimpanan

    def get_nama(self):
        return self._nama

    def get_merk(self):
        return self._merk

  