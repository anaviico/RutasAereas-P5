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

	Almacen_Rutas (Almacen_Rutas &otro){
		rutas = otro.getRutas();
	}


	// MODIFICADORES

	void Insertar(Ruta r){

		rutas.push_back(r);

	}


	// CONSULTORES

	vector<Ruta> getRutas(){

		return rutas;

	}

	/*Almacen_Rutas GetRutas_con_Punto(Punto p){
		// Llamar a tiene el punto
		// ruta.h
	}

	Ruta GetRuta(string a){
		// obtener ruta por código
		// ruta.h
	}


	*/

	// SOBRECARGA DE OPERADORES

	friend istream & operator >> (istream &is, const Almacen_Rutas &ar){

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

	//sobrecargar =

};




#endif