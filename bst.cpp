#include "bst.h"

void createTree(adrNode &root) {
    root = nullptr;
}

adrNode createNode(ProductData item) {
    adrNode p = new Node;
    p->data = item;
    p->left = nullptr;
    p->right = nullptr;
    return p;
}

void insertProduct(adrNode &root, adrNode p) {
    if (root == nullptr) {
        root = p;
        cout << "Produk '" << p->data.namaProduk << "' berhasil ditambahkan." << endl;
        return;
    }


    if (p->data.namaProduk < root->data.namaProduk) {
        insertProduct(root->left, p);

   
    } else if (p->data.namaProduk > root->data.namaProduk) {
        insertProduct(root->right, p);

    
    } else {
       
        root->data.stok += p->data.stok;

        cout << "\n[INFO] Produk '" << p->data.namaProduk << "' sudah ada." << endl;
        cout << "Stok berhasil ditambahkan! Total Stok sekarang: " << root->data.stok << endl;

        delete p;
    }
}

adrNode searchNode(adrNode root, string namaKey) {
    if (root == nullptr || root->data.namaProduk == namaKey) {
        return root;
    }
    if (namaKey < root->data.namaProduk) {
        return searchNode(root->left, namaKey);
    } else {
        return searchNode(root->right, namaKey);
    }
}

void updateProduct(adrNode root, string namaKey) {
    adrNode target = searchNode(root, namaKey);

    if (target != nullptr) {
        cout << "\n[UPDATE] Produk '" << namaKey << "' ditemukan." << endl;
        int pilihan;


        cout << "1. Ubah Stok (" << target->data.stok << ")" << endl;
        cout << "2. Ubah Kategori (" << target->data.kategori << ")" << endl;
        cout << "3. Ubah Harga (Rp" << target->data.hargaSatuan << ")" << endl; // Opsi Baru
        cout << "Pilih data yang ingin diubah (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Stok Baru: ";
                cin >> target->data.stok;
                break;
            case 2:
                cout << "Masukkan Kategori Baru : ";
                cin >> target->data.kategori;
                break;
            case 3:
                cout << "Masukkan Harga Baru : ";
                cin >> target->data.hargaSatuan;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                return;
        }
        cout << "Data produk '" << namaKey << "' berhasil diubah." << endl;
    } else {
        cout << "Gagal update: Produk '" << namaKey << "' tidak ditemukan." << endl;
    }
}
adrNode getMinNode(adrNode root) {
    adrNode current = root;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

adrNode deleteRekursif(adrNode root, string namaKey) {
    if (root == nullptr) {
        return root;
    }

    if (namaKey < root->data.namaProduk) {
        root->left = deleteRekursif(root->left, namaKey);
    } else if (namaKey > root->data.namaProduk) {
        root->right = deleteRekursif(root->right, namaKey);
    } else {
        if (root->left == nullptr) {
            adrNode temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            adrNode temp = root->left;
            delete root;
            return temp;
        }

        adrNode temp = getMinNode(root->right);
        root->data = temp->data;
        root->right = deleteRekursif(root->right, temp->data.namaProduk);
    }
    return root;
}

void deleteProduct(adrNode &root, string namaKey) {
    adrNode oldRoot = root;
    root = deleteRekursif(oldRoot, namaKey);

    if (searchNode(root, namaKey) == nullptr) {
         cout << "Produk '" << namaKey << "' berhasil dihapus." << endl;
    } else {
        cout << "Gagal menghapus produk '" << namaKey << "'. Mungkin tidak ditemukan." << endl;
    }
}

void displayInorder(adrNode root) {
    if (root != nullptr) {
        displayInorder(root->left);

        cout << "| " << root->data.namaProduk
             << " | " << root->data.kategori
             << " | Stok : " << root->data.stok
             << " | Rp" << root->data.hargaSatuan << endl;

        displayInorder(root->right);
    }
}
bool isExpired(int pTahun, int pBulan, int pHari, int hTahun, int hBulan, int hHari){

    if(pTahun < hTahun){
        return true;
    }
    if(pTahun == hTahun){
        if(pBulan < hBulan){
            return true;
        }
        if(pBulan == hBulan) {
            if(pHari < hHari) {
                return true;
            }
        }
    }
    return false;
}

void checkExpired(adrNode root, int hariIni, int bulanIni, int tahunIni) {
    if (root != nullptr) {
        checkExpired(root->left, hariIni, bulanIni, tahunIni);

        bool expired = isExpired(
            root->data.hariKadaluarsa,
            root->data.bulanKadaluarsa,
            root->data.tahunKadaluarsa,
            tahunIni,
            bulanIni,
            hariIni
        );

        cout << "| " << root->data.namaProduk
             << " | Kadaluarsa: " << root->data.tahunKadaluarsa << "-" << root->data.bulanKadaluarsa << "-" << root->data.hariKadaluarsa
             << " | Status: ";

        if (expired) {
            cout << "EXPIRED" << endl;
        } else {
            cout << "AMAN" << endl;
        }
        checkExpired(root->right, hariIni, bulanIni, tahunIni);
    }
}
