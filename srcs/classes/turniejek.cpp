#include "turniejek.h"

Turniejek::Turniejek(const Rycerzyk* uczestnicy, int ile){
	this -> ile = ile;
	this -> uczestnicy = new Rycerzyk[ile];
	for(int i = 0; i < ile; i++){
		this -> uczestnicy[i].skopiuj(uczestnicy[i], uczestnicy[i].dajImie());
	}
}

const char* Turniejek::gra(){

	int liczba = ile;

	while(liczba > 1){
		for(int i = 0; i < liczba - 1; i += 2){
			if(uczestnicy[i].pusty() || uczestnicy[i+1].pusty()){
				break;
			}

			Rycerzyk uczestnik1, uczestnik2;

			uczestnik1.skopiuj(uczestnicy[i], uczestnicy[i].dajImie());
			uczestnik2.skopiuj(uczestnicy[i+1], uczestnicy[i+1].dajImie());

			int obrazenia1 = uczestnik1.dajAtak() - uczestnik2.dajObrona();
			int obrazenia2 = uczestnik2.dajAtak() - uczestnik1.dajObrona();

			if(obrazenia1 > obrazenia2){
				uczestnicy[i+1].podajImie(nullptr);
			}
			else if(obrazenia1 < obrazenia2){
				uczestnicy[i].podajImie(nullptr);
			}
			else if(obrazenia1 == obrazenia2){
				uczestnicy[i+1].podajImie(nullptr);
			}
		}
		
		Rycerzyk* kuczestnicy = nullptr;
		kuczestnicy = new Rycerzyk[liczba];
		int ilo = 0; //Ilość elementów w nowej tablicy
		for(int i = 0; i < liczba; i++){
			if(!uczestnicy[i].pusty()){
				kuczestnicy[ilo].skopiuj(uczestnicy[i], uczestnicy[i].dajImie());
				ilo++;
			}
		}

		delete [] uczestnicy;
		uczestnicy = new Rycerzyk[ilo];

		for(int i = 0; i < ilo; i++){
			uczestnicy[i].skopiuj(kuczestnicy[i], kuczestnicy[i].dajImie());
		}

		delete [] kuczestnicy;

		liczba = ilo;
		
	}

	const char* zwyciezca = uczestnicy[0].dajImie();

	return zwyciezca;
}


Turniejek::~Turniejek(){
	//delete [] uczestnicy;
}
