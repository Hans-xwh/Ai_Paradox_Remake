#pragma once

#include <fstream>
#include <iostream>



//PROHIBIDO IMPORTAR STD COMPLETO
using namespace std;
//using std::fstream;
//using std::ios;

struct GameSave
{
	char nombre[3] = { 'x','x','x' };
	int nivel = 123;
	int puntaje = -456;
};

class Guardado {
public:
	Guardado() {

	}
	void initSateveFile() {
		GameSave emptySave;

		std::ofstream records;
		records.open("save/save.bin", ios::out | ios::binary);
		records.write((const char*)&emptySave, sizeof(GameSave));
		records.write((const char*)&emptySave, sizeof(GameSave));
		records.write((const char*)&emptySave, sizeof(GameSave));
	}

	int WriteRecord(GameSave* save) {
		fstream records("save/save.bin", ios::out | ios::binary);

		if (records.is_open()) {

		}
		else {
			return 1;
		}
	}

};