#include "rycerzyk.h"
#include "turniejek.h"

int main(){
	int ile = 0;
	Rycerzyk* uczestnicy = nullptr;
	char* imionko = nullptr;
	int ataczek = 0;
	int obronka = 0;
	std::cin >> ile;
	uczestnicy = new Rycerzyk[ile];
	imionko = new char[100];
	for(int i = 0; i < ile; i++){
		std::cin >> imionko >> ataczek >> obronka;
		
		uczestnicy[i].podajImie(imionko);
		uczestnicy[i].podajAtak(ataczek);
		uczestnicy[i].podajObrona(obronka);
	}

	Turniejek wh(uczestnicy, ile); //Nazwa od polskiej husarii a raczej jej określenia z angielskiego ""Winged Hussars" oraz tytuł piosenki grupy Sabaton, której obecnie słucham 
	
	std::cout << wh.gra() << "\n";

	return 0;
}
