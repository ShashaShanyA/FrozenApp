#ifndef FROZENFOOD_H_INCLUDED
#define FROZENFOOD_H_INCLUDED

#include <iostream>
using namespace std;

struct ProductData {
    string namaProduk;
    string kategori;
    int stok;
    float hargaSatuan;
    int tahunKadaluarsa;
    int bulanKadaluarsa;
    int hariKadaluarsa;
};

typedef struct Node* adrNode;

struct Node {
    ProductData data;
    adrNode left;
    adrNode right;
};

void createTree(adrNode &root);
adrNode createNode(ProductData item);
void insertProduct(adrNode &root, adrNode p);
void updateProduct(adrNode root, string namaKey);
void deleteProduct(adrNode &root, string namaKey);
void displayInorder(adrNode root);
adrNode searchNode(adrNode root, string namaKey);
adrNode getMinNode(adrNode root);
bool isExpired(int pTahun, int pBulan, int pHari, int hTahun, int hBulan, int hHari);
void checkExpired(adrNode root, int hariIni, int bulanIni, int tahunIni);
#endif
