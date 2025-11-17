#pragma once

#include <iostream>
#include <string>

using namespace System::Drawing;
using namespace System::Windows::Forms;	//No se si esto sea necesario pero porsiaca
using std::string;	//No importar std completo en headers, da conflictos con System::String

class Dialogo {
private:
	std::string mensaje; //mensaje actual del dialogo 
	string mensajeLento; //mensaje que se muestra lentamente
	int index;
	int sizeY; //altura del cuadro de dialogo
	//Quizas añadir la posibilidad de mostrar imagenes junto al dialogo

public:
	Dialogo(string msgLento, int SY = 50) {
		mensaje = msgLento;
		mensajeLento = msgLento;
		sizeY = SY;
	}
	Dialogo(string msgIni, string msgLento, int SY = 50) {
		mensaje = msgIni;
		mensajeLento = msgLento;
		sizeY = SY;
	}


	string getMensaje() {
		return mensaje;
	}
	string getMensajeLento() {
		return mensajeLento;
	}

	void actualizarMensajeLento(int indice) {	//funcion inecesaria
		if (indice < mensaje.length()) {
			mensajeLento += mensaje[indice];
		}
	}

	void dibujar(Graphics^ canvas) {
		//While(mensaje.length < )


		Rectangle mainSqr = Rectangle(20, int(canvas->VisibleClipBounds.Height - sizeY - 20), int(canvas->VisibleClipBounds.Width - 40), sizeY);
		Rectangle innerSqr = Rectangle(25, int(canvas->VisibleClipBounds.Height - sizeY - 15), int(canvas->VisibleClipBounds.Width - 50), sizeY - 10);

		canvas->FillRectangle(Brushes::Black, mainSqr);

		canvas->DrawRectangle(Pens::White, innerSqr);

		canvas->DrawString(gcnew String(mensaje.c_str()), gcnew Font("Arial", 10), Brushes::White, innerSqr);
	}

	void setHeight(int H) { sizeY = H; }
	
};