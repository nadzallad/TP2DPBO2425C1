//Janji
Saya Nadzalla Diva Asmara Sutedja dengan Nim 2408095 mengerjakan TP2 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahan-Nya maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan

//gambar desain diagram hubungan

<img width="307" height="730" alt="image" src="https://github.com/user-attachments/assets/55c351f7-c99c-4738-87f3-b8e03df8580f" />

//Penjelasan Atribut
Produk { id_produk, asal_produk, harga }
Elektronik { lokasi_penyimpanan, nama, merk }
Televisi { ukuran, stok, tahun_produksi }
Televisi { ukuran, stok, tahun_produksi, gambar} //hanya untuk php

Hubungan relasi mengenai desain toko elektronik dimulai dari class Produk-Elektronik-Televisi. Pada class produk saya membuat atribut umum yanng berisi id produk, asal produk, dan harga produk dimana atribut atribut ini bersifat umum dan dapat digunakan oleh semua jenis produk, kemudian kelas tersebut memiliki kelas turunan yang bernama class elektronik yang memiliki atribut lokasi penyimmpanan, nama, dan merk dari produk elektronik dimana atribut ini relevan dengan produk elektronik namun belum mengarah ke jenis produk elektronik tertentu. Kemudian class turunan class elektronik yang menjelaskan barang elektronik tersebut dengan lebih spesifik yaitu class Televisi yanng memeiliki atribut lebih spesifik dari barang elektronik televisi yaitu ukuran layar, stok dan tahun produksi serta tambahan gambar untuk program php.

//Penjelasan Method

Menggunakan constructor untuk menginisialisasi nilai, meggunakan getter unutk mengambil data dan menggunakan setter untuk mengubah data.

//Alur Program
1. Pada tahap pertama user akan diberikan menu dan dipersilahkan untuk memilih program mana yang akan dijalankan. Terdapat 3 program yang dapat dijalankan dengan pilihan angka untuk menambah(1), menampilkan(2), dan keluar dari program(3).
2. Setelah User memilih program apa yang akan dijalankan maka selanjutnya user akan diberikan tahap lanjutan dari hasil pilihan tersebut. Jika user memilih untuk menambah data maka selanjutnya secara bertahap user akan diminta untuk mengisi id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk, ukuran, stok, tahun_produksi serta gambar (khusus program php). 
3. Jika user telah memasukan input data untuk menambah data baru, jika berhasil akan ada pemberitahuan bahwa data berhasil dimasukan. Jika user memilih unntuk menampilkan data setelah memilih program data produk dengan tabel dinamis akan terlihat.

//Dokumentasi Program
1. CPP : https://github.com/user-attachments/assets/30cadf29-a262-4db5-b4fc-f9aba5e053ac
2. Python : https://github.com/user-attachments/assets/519bb665-534e-4956-80a4-a3c353e60fd6
3. Java :
4. PHP
