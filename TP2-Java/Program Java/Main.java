// Main.java
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static final ArrayList<Televisi> dataTelevisi = new ArrayList<>();
    private static final Scanner scanner = new Scanner(System.in);

    //hardcode data awal
    public static void main(String[] args) {
        // Inisialisasi 5 objek awal
        dataTelevisi.add(new Televisi("P001", "Jepang", 8500000, "Gudang Utama - Rak A1", "Bravia X90J", "Sony", "55 inci", 15, 2015));
        dataTelevisi.add(new Televisi("P002", "Korea", 12000000, "Gudang Utama - Rak A2", "QLED Q80A", "Samsung", "65 inci", 10, 2021));
        dataTelevisi.add(new Televisi("P003", "Tiongkok", 5500000, "Gudang Cabang - Rak B1", "Smart TV 4K", "Xiaomi", "50 inci", 25, 2023));
        dataTelevisi.add(new Televisi("P004", "Jepang", 7250000, "Gudang Cabang - Rak B2", "LED TV", "Sharp", "43 inci", 30, 2024));
        dataTelevisi.add(new Televisi("P005", "Korea", 9800000, "Gudang Utama - Rak C1", "OLED C1", "LG", "55 inci", 8, 2025));

        while (true) {
            tampilkanMenu();
            String pilihan = scanner.nextLine();

            switch (pilihan) {
                //menambahkan data
                case "1":
                    tambahData();
                    break;
                //menampilkan data
                case "2":
                    tampilkanData();
                    break;
                //keluar program
                case "3":
                    System.out.println("Terima kasih, program selesai.");
                    return;
                default:
                    System.out.println("Pilihan tidak valid. Silakan coba lagi.");
            }
        }
    }

    //menampilkan pilihan program
    public static void tampilkanMenu() {
        System.out.println("\n--- Menu Utama ---");
        System.out.println("1. Tambah Data Televisi");
        System.out.println("2. Tampilkan Semua Data");
        System.out.println("3. Keluar");
        System.out.print("Pilih menu (1/2/3): ");
    }

    //menambahkan data produk baru
    public static void tambahData() {
        System.out.println("\n--- Tambah Data Televisi Baru ---");
        try {
            System.out.print("Masukkan ID Produk: ");
            String id_produk = scanner.nextLine();

            for (Televisi tv : dataTelevisi) {
                if (tv.getId_produk().equals(id_produk)) {
                    System.out.println("\n❌ ID Produk '" + id_produk + "' sudah ada. Gunakan ID lain.");
                    return;
                }
            }

            //input data baru
            System.out.print("Masukkan Asal Produk: ");
            String asal_produk = scanner.nextLine();
            System.out.print("Masukkan Harga (Rp): ");
            double harga = Double.parseDouble(scanner.nextLine());
            System.out.print("Masukkan Lokasi Penyimpanan Barang: ");
            String lokasi_penyimpanan = scanner.nextLine();
            System.out.print("Masukkan Nama Televisi: ");
            String nama = scanner.nextLine();
            System.out.print("Masukkan Merek: ");
            String merk = scanner.nextLine();
            System.out.print("Masukkan Ukuran (contoh: 55 inci): ");
            String ukuran = scanner.nextLine();
            System.out.print("Masukkan Stok: ");
            int stok = Integer.parseInt(scanner.nextLine());
            System.out.print("Masukkan Tahun Produksi: ");
            int tahun_produksi = Integer.parseInt(scanner.nextLine());

            Televisi tvBaru = new Televisi(id_produk, asal_produk, harga, lokasi_penyimpanan, nama, merk, ukuran, stok, tahun_produksi);
            dataTelevisi.add(tvBaru);
            System.out.println("\nData televisi berhasil ditambahkan!");
        } catch (NumberFormatException e) {
            System.out.println("\nInput tidak valid. Pastikan harga dan stok adalah angka.");
        }
    }

      public static void tampilkanData() {
        //jika data kosong, eror handling
        if (dataTelevisi.isEmpty()) {
            System.out.println("\nBelum ada data televisi.");
            return;
        }

        // Tentukan panjang maksimum untuk setiap kolom
        int maxId = "ID Produk".length();
        int maxAsal = "Asal Produk".length();
        int maxHarga = "Harga (Rp)".length();
        int maxLokasi = "Lokasi Penyimpanan".length();
        int maxNama = "Nama".length();
        int maxMerk = "Merek".length();
        int maxUkuran = "Ukuran".length();
        int maxStok = "Stok".length();
        int maxTahun = "Tahun Produksi".length();

        // Cari panjang string terpanjang di setiap kolom
        for (Televisi tv : dataTelevisi) {
            maxId = Math.max(maxId, tv.getId_produk().length());
            maxAsal = Math.max(maxAsal, tv.getAsal_produk().length());
            maxHarga = Math.max(maxHarga, String.format("%,.0f", tv.getHarga()).length());
            maxLokasi = Math.max(maxLokasi, tv.getLokasi_penyimpanan().length());
            maxNama = Math.max(maxNama, tv.getNama().length());
            maxMerk = Math.max(maxMerk, tv.getMerk().length());
            maxUkuran = Math.max(maxUkuran, tv.getUkuran().length());
            maxStok = Math.max(maxStok, String.valueOf(tv.getStok()).length());
            maxTahun = Math.max(maxTahun, String.valueOf(tv.getStok()).length());
        }

        // Hitung total lebar tabel untuk garis
        int totalWidth = maxId + maxAsal + maxHarga + maxLokasi + maxNama + maxMerk + maxUkuran + maxStok + maxTahun + (9 * 3 + 1);
        
        System.out.println("\n" + "=".repeat(totalWidth));
        System.out.printf("%" + (totalWidth / 2 + 10) + "s\n", "DATA LENGKAP TELEVISI"); // Posisi judul agar ditengah
        System.out.println("=".repeat(totalWidth));

        // Cetak header tabel dengan lebar dinamis
        System.out.println("-".repeat(totalWidth));
        System.out.printf("| %-" + maxId + "s | %-" + maxAsal + "s | %-" + maxHarga + "s | %-" + maxLokasi + "s | %-" + maxNama + "s | %-" + maxMerk + "s | %-" + maxUkuran + "s | %-" + maxStok + "s | %-" + maxTahun + "s |\n",
            "ID Produk", "Asal Produk", "Harga (Rp)", "Lokasi Penyimpanan", "Nama", "Merek", "Ukuran", "Stok", "Tahun Produksi");

        // Cetak data setiap objek dengan lebar dinamis
        System.out.println("-".repeat(totalWidth));
        for (Televisi tv : dataTelevisi) {
            System.out.printf("| %-" + maxId + "s | %-" + maxAsal + "s | %" + maxHarga + ".0f | %-" + maxLokasi + "s | %-" + maxNama + "s | %-" + maxMerk + "s | %-" + maxUkuran + "s | %-" + maxStok + "d | %-" + maxTahun + "d |\n",
                tv.getId_produk(),
                tv.getAsal_produk(),
                tv.getHarga(),
                tv.getLokasi_penyimpanan(),
                tv.getNama(),
                tv.getMerk(),
                tv.getUkuran(),
                tv.getStok(),
                tv.getTahunProduksi());
                System.out.println("-".repeat(totalWidth));
        }
        System.out.println("=".repeat(totalWidth));
    }
}