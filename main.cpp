#include "bst.h"

void tampilkanMenu() {
    cout << "\n========================================" << endl;
    cout << "FrozenApp - Manajemen Stok Frozen Food" << endl;
    cout << "========================================" << endl;
    cout << "1. Tambah Produk Baru" << endl;
    cout << "2. Tampilkan Semua Produk" << endl;
    cout << "3. Cari Produk" << endl;
    cout << "4. Ubah Data Produk" << endl;
    cout << "5. Hapus Produk" << endl;
    cout << "6. Cek Status Kadaluarsa" << endl;
    cout << "7. Keluar" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Pilih menu (1-7): ";
}

int main() {
    adrNode rootBST;
    createTree(rootBST);


    insertProduct(rootBST, createNode({"Nugget_Ayam", "Nugget", 150, 35000.00, 15, 12, 2025}));
    insertProduct(rootBST, createNode({"Sosis_Sapi", "Sosis", 200, 45000.00, 1, 1, 2024}));
    insertProduct(rootBST, createNode({"Kentang_Fries", "Kentang", 90, 28500.00, 10, 5, 2026}));
    insertProduct(rootBST, createNode({"Dimsum_Mix", "Seafood", 120, 32000.00, 20, 11, 2025}));

    int pilihan = 0;
    string namaKey;
    ProductData newFood;

    while (pilihan != 7) {
        tampilkanMenu();
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid. Program berhenti." << endl;
            pilihan = 7;
        } else {
            if (pilihan == 1) {
                cout << "\n--- Tambah Produk Baru ---\n";
                cout << "Nama Produk : "; cin >> newFood.namaProduk;
                cout << "Kategori : "; cin >> newFood.kategori;
                cout << "Stok : "; cin >> newFood.stok;
                cout << "Harga : "; cin >> newFood.hargaSatuan;
                cout << "Tahun Kadaluarsa : "; cin >> newFood.tahunKadaluarsa;
                cout << "Bulan Kadaluarsa : "; cin >> newFood.bulanKadaluarsa;
                cout << "Hari Kadaluarsa : "; cin >> newFood.hariKadaluarsa;
                insertProduct(rootBST, createNode(newFood));
            } else if (pilihan == 2) {
                cout << "\n--- DAFTAR STOK FROZEN FOOD ---\n";
                displayInorder(rootBST);
            } else if (pilihan == 3) {
                cout << "\n--- Cari Produk ---\n";
                cout << "Masukkan Nama Produk : "; cin >> namaKey;
                adrNode result = searchNode(rootBST, namaKey);
                if (result != nullptr) {
                    cout << "Produk Ditemukan: " << result->data.namaProduk << ", Stok: " << result->data.stok << endl;
                } else {
                    cout << "Produk '" << namaKey << "' tidak ditemukan." << endl;
                }
            } else if (pilihan == 4) {
                cout << "\n--- Ubah Data Stok/Kategori ---\n";
                cout << "Masukkan Nama Produk yang diubah: "; cin >> namaKey;
                updateProduct(rootBST, namaKey);
            } else if (pilihan == 5) {
                cout << "\n--- Hapus Produk ---\n";
                cout << "Masukkan Nama Produk yang dihapus : "; cin >> namaKey;
                deleteProduct(rootBST, namaKey);
            } else if (pilihan == 6) {
                int h, b, t;
                cout << "\n--- CEK STATUS KADALUARSA ---\n";
                cout << "Sekarang Tanggal Berapa? : "; cin >> h;
                cout << "Sekarang Bulan Apa? : "; cin >> b;
                cout << "Sekarang Tahun Berapa? :"; cin >> t;
                cout << "\n--- Hasil Pengecekan (Per Tanggal " << h << "-" << b << "-" << t << ") ---" << endl;
                checkExpired(rootBST, h, b, t);
            } else if (pilihan == 7) {
                cout << "Terima kasih telah menggunakan FrozenApp! Sampai jumpa." << endl;
            } else {
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            }
        }
    }

    return 0;
}
