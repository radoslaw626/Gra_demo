#include "Klasy_funkcje.h"
#include <iostream>
#include "Windows.h"

int main()
{
	Character* h1 = new Hero();
	Character* Wolf = new Enemy();
	cout << " Podaj imie postaci: ";
	cin >> h1->name;
start:
	cout << endl;
	cout << "1. Atak." << endl;
	cout << "2. Ulecz." << endl;
	cout << "3. Sprawdz statystyki." << endl;
	cout << "8. Wyjdz." << endl;
	if (Wolf->hp <= 0) {
		Wolf->Heal();
		Wolf->changecoins(15);
	}
	int a;
	cin >> a;
	system("cls");
	switch (a) {
	case 1:
		h1->Attack(*h1, *Wolf);
		break;
	case 2:
		h1->Heal();
		h1->showstats('h');
		break;
	case 3:
		h1->showstats();
		break;
	case 8:
		h1->~Character();
		exit(0);

		break;
	};
	goto start;







}
