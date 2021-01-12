#ifndef _ALMACEN_RUTAS_
#define _ALMECEN_RUTAS_

#include <map>
#include "ruta.h"
using namespace std;

class Almacen_Rutas{

private:

	multimap<string, Ruta> rutas;

public: 

	// CONSTRUCTORES

	Almacen_Rutas ();

	Almacen_Rutas (multimap<string, Ruta> rts){

		rutas = rts;

	}

	Almacen_Rutas (const Almacen_Rutas &otro){
		rutas = otro.getRutas();
	}


	// MODIFICADORES

	void Insertar(Ruta r){

		rutas.insert(pair<const string, Ruta> (r.GetCodigo(), r));

	}


	// CONSULTORES

	multimap<string, Ruta> getRutas() const{

		return rutas;

	}

	Almacen_Rutas GetRutas_Con_Punto(Punto p){
		
		Almacen_Rutas ar;

		for (auto &it : rutas){
			if(it.second.ContienePunto(p))
				ar.Insertar(it.second);
		}

		return ar;

	}

	Ruta GetRuta(string codigo){
		
		Ruta r;
		bool encontrado = false;

		for (multimap<string, Ruta>::iterator it = rutas.begin(); it != rutas.end(); it++){
			if ((*it).second.GetCodigo() == codigo){
				r = (*it).second;
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
// arreglar
	friend ostream & operator << (ostream & os, const Almacen_Rutas & ar){

		for (multimap<string, Ruta>::iterator it = ar.getRutas().begin(); it != ar.getRutas().end(); it++){
			os << (*it).second << "\t";
		}

		return os;

	}

	Almacen_Rutas& operator = (const Almacen_Rutas & otro){

		rutas = otro.getRutas();

		return *this;

	}


	// CLASES ITERADORAS
	
	class cont_iterator;
	class iterator{
	private:
		multimap<string, Ruta>::iterator p;
	public:
		iterator(){}
		iterator & operator ++(){
			++p;
			return *this;
		}

		iterator & operator --(){
			--p;
			return *this;
		}

		bool operator == (const iterator &it){
			return it.p == p;
		}

		bool operator != (const iterator &it){
			return it.p != p;
		}
// wtf?!?!
		const Ruta & operator *() const{
			return *p;
		}

		friend class Almacen_Rutas;
		friend class const_iterator;
	};

	class const_iterator{
	private:
		multimap<string, Ruta>::const_iterator p;
	public:
		const_iterator(){}

	};

};




#endif