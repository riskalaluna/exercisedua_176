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