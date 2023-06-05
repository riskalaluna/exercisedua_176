#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
	string nama;
	vector<penerbit*> daftar_penerbit;
	pengarang(string pNama) :nama(pNama) {
		cout << "Pengarang \"" << nama << "\" ada\n";
	}
	~pengarang() {
		cout << "Pengarang \"" << nama << "\" tidak ada\n";
	}
	void tambahPenerbit(penerbit*);
	void cetakPenerbit();
};

class penerbit {
public:
	string nama;;
	vector<pengarang*> daftar_pengarang;

	penerbit(string pNama) :nama(pNama) {
		cout << "Penerbit \"" << nama << "\" ada\n";
	}
	~penerbit() {
		cout << "Penerbit \"" << nama << "\" tidak ada\n";
	}

	void tambahPengarang(pengarang*);
	void cetakPengarang();
};

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}
void pengarang::cetakPenerbit() {
	cout << "daftar Pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}
void penerbit::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahPenerbit(this);
}
void penerbit::cetakPengarang() {
	cout << "Daftar penerbit dari pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

class buku {
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	buku(string pNama) :nama(pNama) {
		cout << "Buku \"" << nama << "\" ada\n";
	}
	~buku() {
		cout << "Buku \"" << nama << "\" tidak ada\n";
	}
	void tambahPengarang(pengarang*);
	void cetakPengarang();
};
void buku::tambahPengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void buku::cetakPengarang() {
	cout << "daftar buku dari pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Perwira");
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");
	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemrograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Matematika 1");

	varPenerbit1->tambahPengarang(varPengarang1);
	varPenerbit1->tambahPengarang(varPengarang2);
	varPenerbit1->tambahPengarang(varPengarang3);
	varPenerbit2->tambahPengarang(varPengarang3);
	varPenerbit2->tambahPengarang(varPengarang4);
	varPengarang3->tambahPenerbit(varPenerbit1);
	varPengarang3->tambahPenerbit(varPenerbit2);
	varBuku1->tambahPengarang(varPengarang1);
	varBuku2->tambahPengarang(varPengarang1);

	varPenerbit1->cetakPengarang();
	varPenerbit2->cetakPengarang();
	varPengarang3->cetakPenerbit();
	varBuku1->cetakPengarang();
	varBuku2->cetakPengarang();

	return 0;
}