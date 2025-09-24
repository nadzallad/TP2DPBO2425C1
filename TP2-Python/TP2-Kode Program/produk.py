
class Produk:
    def __init__(self, id_produk, asal_produk, harga):
        # Atribut menggunakan underscore untuk menandakan "protected"
        self._id_produk = id_produk
        self._asal_produk = asal_produk
        self._harga = harga

    # Getter methods
    def get_id_produk(self):
        return self._id_produk

    def get_asal_produk(self):
        return self._asal_produk

    def get_harga(self):
        return self._harga
