<?php
require_once 'Televisi.php';
session_start();


// Inisialisasi data default jika belum ada
if (!isset($_SESSION['data_televisi'])) {
    $_SESSION['data_televisi'] = [
        new Televisi("P001", "Jepang", 8500000, "Gudang Utama - Rak A1", "Bravia X90J", "Sony", "55 inci", 15, 2015, "Bravia X90J.jpg"),
        new Televisi("P002", "Korea", 12000000, "Gudang Utama - Rak A2", "QLED Q80A", "Samsung", "65 inci", 10, 2021, "QLED Q80A.jpg"),
        new Televisi("P003", "Tiongkok", 5500000, "Gudang Cabang - Rak B1", "Smart TV 4K", "Xiaomi", "50 inci", 25, 2023, "Smart TV 4K.jpg"),
        new Televisi("P004", "Jepang", 7250000, "Gudang Cabang - Rak B2", "LED TV", "Sharp", "43 inci", 30, 2024, "LED TV.jpg"),
        new Televisi("P005", "Korea", 9800000, "Gudang Utama - Rak C1", "OLED C1", "LG", "55 inci", 8, 2025, "OLED C1.jpg"),
    ];
}

$errors = [];
$success = false;
$gambar = ""; // variabel gambar default

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $id = trim($_POST['id_produk']);
    $asal = trim($_POST['asal_produk']);
    $harga = $_POST['harga'];
    $lokasi = trim($_POST['lokasi_penyimpanan']);
    $nama = trim($_POST['nama']);
    $merk = trim($_POST['merk']);
    $ukuran = trim($_POST['ukuran']);
    $stok = $_POST['stok'];
    $tahun_produksi = $_POST['tahun_produksi'];

    // Cek unique ID
    foreach ($_SESSION['data_televisi'] as $tv) {
        if ($tv->getIdProduk() === $id) {
            $errors[] = "ID Produk '$id' sudah digunakan.";
            break;
        }
    }

    if (!is_numeric($harga) || !is_numeric($stok) || !is_numeric($tahun_produksi)) {
        $errors[] = "Harga, stok, dan tahun produksi harus berupa angka yang valid.";
    }

    // Upload gambar
    if (isset($_FILES['gambar']) && $_FILES['gambar']['error'] === UPLOAD_ERR_OK) {
        $tmp_name = $_FILES['gambar']['tmp_name'];
        $filename = basename($_FILES['gambar']['name']);
        $target_dir = "uploads/";

        if (!is_dir($target_dir)) {
            mkdir($target_dir, 0777, true);
        }

        // Buat nama file unik supaya tidak overwrite
        $target_file = $target_dir . uniqid() . "_" . preg_replace('/\s+/', '_', $filename);

        if (move_uploaded_file($tmp_name, $target_file)) {
            $gambar = $target_file;
        } else {
            $errors[] = "Gagal mengupload gambar.";
        }
    } else {
        $errors[] = "Gambar harus diupload.";
    }

    if (empty($errors)) {
        $tv = new Televisi($id, $asal, (float)$harga, $lokasi, $nama, $merk, $ukuran, (int)$stok, (int)$tahun_produksi, $gambar);
        $_SESSION['data_televisi'][] = $tv;
        $success = true;
    }
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Data Televisi</title>
    <style>
        body { font-family: Arial, sans-serif; padding: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 20px; }
        table, th, td { border: 1px solid #000; text-align: center; }
        th, td { padding: 10px; }
        .error { color: red; margin-bottom: 10px; }
        .success { color: green; margin-bottom: 10px; }
        img { max-width: 100px; max-height: 70px; }
    </style>
</head>
<body>

<h2>Tambah Data Televisi</h2>

<?php
if ($success) echo "<div class='success'>Data berhasil ditambahkan.</div>";
foreach ($errors as $e) echo "<div class='error'>❌ $e</div>";
?>
<!--input data produk baru -->
<form method="POST" enctype="multipart/form-data">
    <label>ID Produk: <input type="text" name="id_produk" required></label><br><br>
    <label>Asal Produk: <input type="text" name="asal_produk" required></label><br><br>
    <label>Harga (Rp): <input type="number" name="harga" required></label><br><br>
    <label>Lokasi Penyimpanan: <input type="text" name="lokasi_penyimpanan" required></label><br><br>
    <label>Nama Televisi: <input type="text" name="nama" required></label><br><br>
    <label>Merek: <input type="text" name="merk" required></label><br><br>
    <label>Ukuran: <input type="text" name="ukuran" required></label><br><br>
    <label>Stok: <input type="number" name="stok" required></label><br><br>
    <label>Tahun Produksi: <input type="number" name="tahun_produksi" required></label><br><br>
    <label>Gambar Televisi: <input type="file" name="gambar" accept="image/*" required></label><br><br>
    <button type="submit">Tambah</button>
</form>

<h2>Data Televisi</h2>
<table>
    <tr>
        <!--tabel -->
        <th>ID Produk</th>
        <th>Asal</th>
        <th>Harga</th>
        <th>Lokasi</th>
        <th>Nama</th>
        <th>Merk</th>
        <th>Ukuran</th>
        <th>Stok</th>
        <th>Tahun Produksi</th>
        <th>Gambar</th>
    </tr>
    <?php foreach ($_SESSION['data_televisi'] as $tv): ?>
    <tr>
        <td><?= htmlspecialchars($tv->getIdProduk()) ?></td>
        <td><?= htmlspecialchars($tv->getAsalProduk()) ?></td>
        <td>Rp <?= number_format($tv->getHarga(), 0, ',', '.') ?></td>
        <td><?= htmlspecialchars($tv->getLokasiPenyimpanan()) ?></td>
        <td><?= htmlspecialchars($tv->getNama()) ?></td>
        <td><?= htmlspecialchars($tv->getMerk()) ?></td>
        <td><?= htmlspecialchars($tv->getUkuran()) ?></td>
        <td><?= htmlspecialchars($tv->getStok()) ?></td>
        <td><?= htmlspecialchars($tv->getTahunProduksi()) ?></td>
        <td>
            <?php if ($tv->getGambar()): ?>
                <?php 
                    // Tangani path gambar:
                    $imgPath = $tv->getGambar();
                    // Jika data default (gambar cuma nama file), tambahkan 'uploads/' 
                    if (strpos($imgPath, 'uploads/') !== 0) {
                        $imgPath = 'uploads/' . $imgPath;
                    }
                ?>
                <img src="<?= htmlspecialchars(rawurlencode($imgPath)) ?>" alt="Gambar Televisi">
            <?php else: ?>
                -
            <?php endif; ?>
        </td>
    </tr>
    <?php endforeach; ?>
</table>

</body>
</html>
