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

	Punto();

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

	double GetLatitud(){

		return lat;

	}
	double GetLatitud() const{

		return lat;

	}

	double GetLongitud(){

		return lng;

	}
	double GetLongitud() const{

		return lng;

	}

	// MODIFICADORES

	void setLat(double l){
		lat = l;
	}
	void setLng(double l){
		lng = l;
	}


	// CONSULTORES

	bool operator == (Punto otro){

		bool igual = true;
		if (lat != otro.getLat() || lng != otro.getLng()){
			igual = false;
		}

		return igual;
	}

	// SOBRECARGA DE OPERADORES

	friend ostream & operator << (ostream &os, const Punto &p){
		
		os << "Latitud: " << p.lat << endl;
		os << "Longitud: " << p.lng;
	   
	   return os;
	}

	friend istream & operator >> (istream &is, Punto &P){

	   //leemos el comentario
	   if (is.peek()=='#'){
			string a;
			getline(is,a);
	   }	
	      
	   double l;
	   int count = 0;

	   while (is>>P && count < 2){
			if (count%2 == 0){
				P.setLat(l);
			}
			else {
				P.setLng(l);
			}
	   }
	    
	   return is;
	}

	Punto & operator = (const Punto &otro){

		lat = otro.getLat();
		lng = otro.getLng();

		return *this;

	}

};



#endif