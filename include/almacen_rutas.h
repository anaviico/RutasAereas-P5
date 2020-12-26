#ifndef _ALMACEN_RUTAS_
#define _ALMECEN_RUTAS_

#include <vector>
#include "ruta.h"

class Almacen_Rutas{

private:

	vector<Ruta> rutas;

public: 

	// CONSTRUCTORES

	Almacen_Rutas ();

	Almacen_Rutas (vector<Ruta> rts){

		rutas = rts;

	}

	Almacen_Rutas (const Almacen_Rutas & otro){
		rutas = otro.getRutas();
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
};




#endif