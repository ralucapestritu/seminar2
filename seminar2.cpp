#include <iostream>
using namespace std;

struct magazin {
	char* denumire;
	int nrRaioane;
	bool nonStop;
	int nrClienti;
};

void afisarePointerMagazin(magazin* m) {
	cout << "nume " << m->denumire << endl;
	cout << "numar raioane " << m->nrRaioane << endl;
	cout << "este nonstop " << m->nonStop << endl;
	cout << "numar clienti " << m->nrClienti << endl;

	m->nonStop ? "da" : "nu";

}

void afisareMagazin(magazin m) {

}

magazin* citirePointerMagazin() {
	magazin* m = new magazin();
	cout << "denumire";
	char buffer[100];
	cin >> buffer;
	m->denumire = new char[strlen(buffer) + 1];
	strcpy_s(m->denumire, strlen(buffer) + 1, buffer);
	cout << "numar raioane ";
	cin >> m->nrRaioane;
	cout << "este nonstop? ";
	cin >> m->nonStop;
	cout << "numar clienti ";
	cin >> m->nrClienti;
	return m;
}

int main() {
	magazin m;
	magazin* pmagazin;
	m.nonStop = false;

	pmagazin = &m;
	pmagazin = new magazin();
	pmagazin->nonStop = true;
	pmagazin->denumire = new char[strlen("lidl")+1];
	strcpy_s(pmagazin->denumire, strlen("lidl") + 1, "lidl");
	pmagazin->nrClienti = 200;
	pmagazin->nrRaioane = 50;
	delete[]pmagazin->denumire;
	delete pmagazin;

	afisarePointerMagazin(pmagazin);
	magazin* m2 = citirePointerMagazin();
	afisarePointerMagazin(m2);


	magazin* vector;
	vector = new magazin[2];
	delete[]vector;
	int nrpointeri = 2;
	magazin** pointeri;
	pointeri = new magazin * [nrpointeri];
	for (int i = 0; i < nrpointeri; i++) {
		pointeri[i] = citirePointerMagazin();

	}

	for (int i = 0; i < nrpointeri; i++) {
		afisarePointerMagazin(pointeri[i]);
	}

	for (int i = 0; i << nrpointeri; i++) {
		delete[]pointeri[i]->denumire;
		delete pointeri[i];
	}

	delete[]pointeri;
	return 0;

}
