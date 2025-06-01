#ifndef TURNIEJEK_H
#define TURNIEJEK_H
#include "rycerzyk.h"
#include <iostream>

class Turniejek{
private:
	int ile;
	Rycerzyk* uczestnicy;
public:
	Turniejek(const Rycerzyk* uczestnicy, int ile);

	const char* gra();

	~Turniejek();
};

#endif //TURNIEJEK_G
