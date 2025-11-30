#pragma once

#include <fstream>
#include <iostream>

//PROHIBIDO IMPORTAR STD COMPLETO
//using namespace std;
using std::ifstream;
using std::fstream;
using std::ios;

struct GameSave
{
	char nombre[4] = { '-','-','-',0 };
	int nivel = -1;
	int puntaje = 000;
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

	GameSave* readSave(int lvl) {
		if (lvl <= 0) lvl = 1;
		ifstream records("save/save.bin", ios::binary | ios::in);
		offset = (lvl - 1) * sizeof(GameSave);

		if (records.is_open()) {
			records.seekg(offset, ios::beg);
			GameSave* tmpSave = new GameSave;
			records.read((char*)tmpSave, sizeof(GameSave));
			return tmpSave;
			records.close();
		}
		else {
			return &save;
		}

	}

	void setName(char c1, char c2, char c3) { save.nombre[0] = c1, save.nombre[1] = c2, save.nombre[2] = c3; }
	void setPuntaje(int P) { save.puntaje = P; }
	void setNivel(int N) { save.nivel = N; }
	void setName(std::string N) {
		save.nombre[0] = N[0];
		save.nombre[1] = N[1];
		save.nombre[2] = N[2];
		save.nombre[3] = char(0);
	}

	std::string translateName(GameSave*){}

};