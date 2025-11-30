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
	int nivel = 123;
	int puntaje = -456;
};

class Guardado {
private:
	GameSave save;
public:
	Guardado() {
	}
	~Guardado() {
	}
	void initSateveFile() {
		GameSave emptySave;

		std::ofstream records;
		records.open("save/save.bin", ios::out | ios::binary);
		records.write((const char*)&emptySave, sizeof(GameSave));
		records.write((const char*)&emptySave, sizeof(GameSave));
		records.write((const char*)&emptySave, sizeof(GameSave));
		records.close();
	}

	int WriteRecord() {
		fstream records("save/save.bin", ios::out | ios::binary);

		if (records.is_open()) {
			records.write((const char*)&save, sizeof(GameSave));
		}
		else {
			return 1;
		}
		records.close();
	}

	//void setName(std::string N) { save->nombre = N; }
	void setName(char c1, char c2, char c3) { save.nombre[0] = c1, save.nombre[1] = c2, save.nombre[2] = c2; }
	void setPuntaje(int P) { save.puntaje = P; }
	void setNivel(int N) { save.nivel = N; }

};