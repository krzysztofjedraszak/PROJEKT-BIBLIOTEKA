#include "Autor.h"
#include "Ksiazka.h"
#include "Uzytkownik.h"
#include "Wypozyczenie.h"
#include "Wypozyczenia.h"
#include <iostream>
#include <string>
#include <list>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	//Wypozyczenia wypozyczalnia;
	//wypozyczalnia.pokaz_wyp();

	//list<Autor>lista;
	//lista.emplace_back("pawel", "coelho");
	//lista.emplace_back("van", "gogh");
	//Ksiazka k("alicja w krainie czarow",lista, 200, "567483902498",
	//    "ABC wydawnictwo", 300);
	//Uzytkownik u("tomek", "pies", "09987676545");
	//Wypozyczenie::data nowa;
	//nowa.dzien = 12;
	//nowa.miesiac = 12;
	//nowa.rok = 12;
	//nowa.godzina = 12;
	//nowa.minuta = 12;
	//nowa.sekunda = 12;
	//nowa.dzien_tyg = "wtorek";
	//Wypozyczenie::data stara;
	//stara.dzien = 112;
	//stara.miesiac = 112;
	//stara.rok = 112;
	//stara.godzina = 112;
	//stara.minuta = 112;
	//stara.sekunda = 112;
	//stara.dzien_tyg = "Sr";
	//wypozyczalnia.wypozycz_ksiazke(k,u,nowa,stara);
	//wypozyczalnia.pokaz_wyp();



	Wypozyczenia wypozyczalnia;
	char wybor = 0;

	while (true) {
		cout << "Wcisnij 1 aby zobaczyc aktualna liste wyporzyczen" << endl;
		cout << "Wcisnij 2 aby wyporzyczyc ksiazke" << endl;
		cout << "Wcisnij 3 aby oddac ksiazke" << endl;
		cout << "Wcisnij q aby wyjsc z programu" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case '1': {
			wypozyczalnia.pokaz_wyp();
			break;
		}
		case '2': {
			string tytul;
			int rok_wydania = 0;
			string ISBN;
			string wydawnictwo;
			int liczba_stron = 0;
			list<Autor> autorzy;
			int ile_autorow = 0;
			string imie_aut, nazwisko_aut;
			string imie_wyp, nazwisko_wyp;
			string PESEL;
			int dzien = 0, miesiac = 0, rok = 0, godzina = 0, minuta = 0, sekunda = 0;
			string dzien_tyg;

			Wypozyczenie::data data_wyp;
			Wypozyczenie::data data_od;

			cout << "Tytul ksiazki: ";
			cin >> tytul;
			cout << endl;

			cout << "Ilosc autorow ksiazki: ";
			cin >> ile_autorow;
			cout << endl;

			for (int i = 0; i < ile_autorow; i++) {
				cout << "Imie autora " << i + 1 << ":";
				cin >> imie_aut;
				cout << endl;
				cout << "Nazwisko autora " << i + 1 << ":";
				cin >> nazwisko_aut;
				cout << endl;
				autorzy.emplace_back(imie_aut, nazwisko_aut);
			}
			cout << "Rok wydania ksiazki: ";
			cin >> rok_wydania;
			cout << endl;

			cout << "ISBN ksiazki: ";
			cin >> ISBN;
			cout << endl;

			cout << "Wydawnictwo ksiazki: ";
			cin >> wydawnictwo;
			cout << endl;

			cout << "Liczba stron ksiazki: ";
			cin >> liczba_stron;
			cout << endl;

			cout << "Imie wypozyczajacego: ";
			cin >> imie_wyp;
			cout << endl;

			cout << "Nazwisko wypozyczajacego: ";
			cin >> nazwisko_wyp;
			cout << endl;

			cout << "PESEL wypozyczajacego: ";
			cin >> PESEL;
			cout << endl;

			cout << "Dzien miesiaca: ";
			cin >> data_wyp.dzien;
			cout << endl;

			cout << "Dzien wypozyczenia: ";
			cin >> data_wyp.dzien_tyg;
			cout << endl;

			cout << "Miesiac wypozyczenia: ";
			cin >> data_wyp.miesiac;
			cout << endl;

			cout << "Rok wypozyczenia: ";
			cin >> data_wyp.rok;
			cout << endl;

			cout << "Godzina wypozyczenia: ";
			cin >> data_wyp.godzina;
			cout << endl;

			cout << "Minuta wypozyczenia: ";
			cin >> data_wyp.minuta;
			cout << endl;

			cout << "Sekunda wypozyczenia: ";
			cin >> data_wyp.sekunda;
			cout << endl;

			data_od.dzien = data_wyp.dzien;
			if (data_wyp.miesiac >= 10) {
				data_od.rok = data_wyp.rok + 1;
				data_od.miesiac = data_wyp.miesiac - 9;
			}
			else {
				data_od.miesiac = data_wyp.miesiac + 3;
			}
			data_od.rok = data_wyp.rok;
			data_od.godzina = data_wyp.godzina;
			data_od.minuta = data_wyp.minuta;
			data_od.sekunda = data_wyp.sekunda;
			data_od.dzien_tyg = data_wyp.dzien_tyg;
			Ksiazka k(tytul, autorzy, rok, ISBN, wydawnictwo, liczba_stron);
			Uzytkownik u(imie_wyp, nazwisko_wyp, PESEL);
			wypozyczalnia.wypozycz_ksiazke(k, u, data_wyp, data_od);
			break;
		}
		case '3': {
			string tytul;
			string PESEL;

			cout << "Tytul ksiazki: ";
			cin >> tytul;
			cout << endl;

			cout << "PESEL oddajacego: ";
			cin >> PESEL;
			cout << endl;

			Ksiazka k(tytul);
			Uzytkownik u(PESEL);
			wypozyczalnia.oddaj_ksiazke(k, u);
			break;
		}
		case 'q': {
			exit(0);
		}
		default:
			break;
		}
		getchar();
		getchar();
		system("cls");
	}
	return 0;
}

