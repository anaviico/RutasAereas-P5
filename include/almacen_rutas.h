#ifndef _ALMACEN_RUTAS_
#define _ALMECEN_RUTAS_

#include <vector>
#include "ruta.h"
using namespace std;

class Almacen_Rutas{

private:

	vector<Ruta> rutas;

public: 

	// CONSTRUCTORES

	Almacen_Rutas ();

	Almacen_Rutas (vector<Ruta> rts){

		rutas = rts;

	}

	Almacen_Rutas (const Almacen_Rutas &otro){
		rutas = otro.getRutas();
	}


	// MODIFICADORES

	void Insertar(Ruta r){

		rutas.push_back(r);

	}


	// CONSULTORES

	vector<Ruta> getRutas() const{

		return rutas;

	}

	Almacen_Rutas GetRutas_Con_Punto(Punto p){
		
		Almacen_Rutas ar;

		for (int i = 0; i < rutas.size(); i++){
			if (rutas[i].ContienePunto(p))
				ar.Insertar(rutas[i]);
		}

		return ar;

	}

	Ruta GetRuta(string codigo){
		
		Ruta r;
		bool encontrado = false;

		for (int i = 0; i < rutas.size() && !encontrado; i++){
			if (rutas[i].GetCodigo() == codigo){
				r = rutas[i];
			}
		}

		return r;

	}



	// SOBRECARGA DE OPERADORES

	friend istream & operator >> (istream &is, Almacen_Rutas &ar){

		Almacen_Rutas rlocal;

		if (is.peek() == '#'){
			string a;
			getline(is,a);
		}

		Ruta r;

		while (is >> r);{
			rlocal.Insertar(r);
		}

		ar = rlocal;

		return is;

	}

	friend ostream & operator << (ostream & os, const Almacen_Rutas & ar){

		for (int i = 0; i < ar.rutas.size(); i++){
			os << ar.rutas[i] << "\t";
		}

		return os;

	}

	Almacen_Rutas& operator = (const Almacen_Rutas & otro){

		rutas = otro.getRutas();

		return *this;

	}

};




#endif