#ifndef _PUNTO_
#define _PUNTO_

#include <string>
#include <cassert>
#include <fstream>
#include <iostream>
#include <iostream>

using namespace std;
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
		
		this->lat = l;
		this->lng = ln;
		this->nombre = n;

	}


	// OBTENCIÓN DE VALORES	
	double GetLatitud() const{
		return lat;
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
		if (lat != otro.GetLatitud() || lng != otro.GetLongitud()){
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
	      
	   double la, lo;
	   int count = 0;

	   is >> la >> lo;

	   P.setLat(la);
	   P.setLng(lo);
	    
	   return is;
	}

	Punto & operator = (const Punto &otro){

		lat = otro.GetLatitud();
		lng = otro.GetLongitud();

		return *this;

	}

	bool operator == (const Punto &otro) const{
		return (lat == otro.GetLatitud() && lng == otro.GetLongitud());
	}

};



#endif