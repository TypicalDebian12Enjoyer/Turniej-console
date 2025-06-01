#ifndef RYCERZYK_H
#define RYCERZYK_H
#include <cstring>

class Rycerzyk{
private:
	char* imie;
	int atak;
	int obrona;
public:
	Rycerzyk();
	void podajImie(char* imie);
	void podajAtak(int atak);
	void podajObrona(int obrona);
	char* dajImie() const;
	int dajAtak() const;
	int dajObrona() const;
	bool pusty();
	void skopiuj(Rycerzyk r, const char* rimie);
	~Rycerzyk();
};

#endif //RYCERZYK_H
