#ifndef _PUNTO_
#define _PUNTO_

#include <string>

class Punto{
private:

	double lat;
	double lng;
	string nombre;

public:

	//	CONSTRUCTORES

	Punto (double l, double ln){

		lat = l;
		lng = ln;

	}

	Punto (double l, double ln, string n){
		
		lat = l;
		lng = ln;
		nombre = n;

	}


	// OBTENCIÓN DE VALORES	

	double getLat(){

		return lat;

	}

	double getLng(){

		return lng;

	}


	// CONSULTORES

	bool operator == (Punto otro){

		bool igual = true;
		if (lat != otro.getLat() || lng != otro.getLng()){
			igual = false;
		}

		return igual;
	}

};



#endif