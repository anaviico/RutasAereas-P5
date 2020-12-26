#ifndef _RUTA_
#define _RUTA_
#include <vector>
#include <ostream>
#include "Punto.h"

using namespace std;

class Ruta{
private:
	vector<Punto> puntos;
	string codigo;

public:

	//  CONSTRUCTORES

	Ruta(vector<Punto> v){
		puntos = v;
	}

	Ruta(Ruta &R){
		puntos = R.puntos;
		codigo = R.codigo;
	}


	//  CONSULTORES

	string GetCodigo(){
		return codigo;
	}


	// METODOS EXTRA

	bool TieneElPunto(Punto p){
		bool tiene_punto = false;
		for (int i = 0; i < puntos.size(); i++){
			if(puntos[i] == p)
				tiene_punto = true;			 
		}

		return tiene_punto;

	}

	//  SOBRECARGA DE OPERADORES

	friend ostream & operator << (ostream &os, const Ruta &R){
		Ruta::const_iterator it;
	    for (it=R.begin(); it!=R.end(); ++it){
			os<<*it<<"\t";
	    }
	    return os;
	}
}

#endif