#include "rycerzyk.h"

Rycerzyk::Rycerzyk(){
	imie = nullptr;
	atak = 0;
	obrona = 0;
}

void Rycerzyk::podajImie(char* imie){
	//delete [] this -> imie;

	if(imie == nullptr){
		this -> imie = nullptr;
		return;
	}

	int dlugosc = 0;
	while(imie[dlugosc] != '\0'){
		dlugosc++;	
	}

	this -> imie = new char[dlugosc + 1];

	int i = 0;
	while(imie[i] != '\0'){
		this -> imie[i] = imie[i];
		i++;
	}
	this -> imie[i] = '\0';
}

void Rycerzyk::podajAtak(int atak){
	this -> atak = atak;
}

void Rycerzyk::podajObrona(int obrona){
	this -> obrona = obrona;
}

char* Rycerzyk::dajImie() const{
	return imie;
}

int Rycerzyk::dajAtak() const{
	return atak;
}

int Rycerzyk::dajObrona() const{
	return obrona;
}

bool Rycerzyk::pusty(){
	if(imie == nullptr){
		return 1;
	}
	return 0;
	
}

void Rycerzyk::skopiuj(Rycerzyk r, const char* rimie){

	//delete[] imie;

	if(rimie == nullptr){
		imie = nullptr;
	}
	else{
		int dlugosc = 0;
		while(rimie[dlugosc] != '\0'){
			dlugosc++;
		}

		imie = new char[dlugosc + 1];
		for (int i = 0; i <= dlugosc; i++){
			imie[i] = rimie[i];
		}
	}	


	atak = r.dajAtak();
	obrona = r.dajObrona();
}

Rycerzyk::~Rycerzyk(){
	//delete [] imie;
}
