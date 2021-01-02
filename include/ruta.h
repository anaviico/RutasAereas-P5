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

	Ruta(){
		codigo ="";
	}

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

	bool ContienePunto(Punto p){
		bool tiene_punto = false;
		for (int i = 0; i < puntos.size(); i++){
			if(puntos[i] == p)
				tiene_punto = true;			 
		}

		return tiene_punto;

	}

	void Insertar(Punto p){
		puntos.push_back(p);
	}

	//  SOBRECARGA DE OPERADORES

	friend ostream & operator << (ostream &os, const Ruta &R){
		
	   for (int i = 0; i < ar.rutas.size(); i++){
			os << R.puntos[i] << "\t";
	   }
	   return os;
	}

	friend istream & operator >> (istream &is, Ruta &R){
		Ruta rlocal;

	   //leemos el comentario
	   if (is.peek()=='#'){
			string a;
			getline(is,a);
	   }	
	      
	   Pais P;

	   while (is>>P){
			rlocal.Insertar(P); 
	   }

	   R=rlocal;
	    
	   return is;
	}
};

#endif