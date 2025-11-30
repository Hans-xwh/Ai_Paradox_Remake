#pragma once

#include <fstream>
#include <iostream>



//PROHIBIDO IMPORTAR STD COMPLETO
//using namespace std;
using std::fstream;
using std::ios;

struct GameSave
{
	char nombre[3] = { 'x','x','x' };
	int nivel = -1;
	int puntaje = -456;
};

class Guardado {
private:
	GameSave save;
	int offset = 0;
public:
	Guardado() {
	}
	~Guardado() {
	}
	void initSaveFile() {
		GameSave emptySave;

		std::ofstream records;
		records.open("save/save.bin", ios::out | ios::binary);
		records.write((const char*)&emptySave, sizeof(GameSave));
		emptySave.nivel--;
		records.write((const char*)&emptySave, sizeof(GameSave));
		emptySave.nivel--;
		records.write((const char*)&emptySave, sizeof(GameSave));
		records.close();
	}

	int WriteRecord() {
		fstream records("save/save.bin", ios::binary | ios::in | ios::out);
		//offset = 0;
		offset = (save.nivel - 1) * sizeof(GameSave);
		records.seekp(offset, ios::beg);

		if (records.is_open()) {
			records.write((const char*)&save, sizeof(GameSave));
		}
		else {
			initSaveFile();
			WriteRecord();
		}
		records.close();
		return 0;
	}

	void setName(char c1, char c2, char c3) { save.nombre[0] = c1, save.nombre[1] = c2, save.nombre[2] = c3; }
	void setPuntaje(int P) { save.puntaje = P; }
	void setNivel(int N) { save.nivel = N; }
	void setName(std::string N) {
		save.nombre[0] = N[0];
		save.nombre[1] = N[1];
		save.nombre[2] = N[2];
	}

};