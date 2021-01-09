#ifndef _RUTA_
#define _RUTA_


#include <list>
#include <ostream>
#include "Punto.h"

using namespace std;

class Ruta{
private:
	list<Punto> puntos;
	string codigo;

public:

	//  CONSTRUCTORES

	Ruta(){
		codigo ="";
	}

	Ruta(list<Punto> v){
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
		Ruta::iterator it = this->begin(); 

		while (it != this->end()){
			if(*it == p){
				tiene_punto = true;
			}
			++it;
		}

		return tiene_punto;

	}

	void Insertar(Punto p){
		puntos.push_back(p);
	}

	//SOBRECARGA DE OPERADORES

	Ruta operator = (const Ruta & r){
		this->codigo = r.codigo;
		this->puntos = r.puntos;

		return *this;
	}

	bool operator<(const Ruta &R)const{

	    return codigo < R.codigo;

	}

  	class const_iterator;
		class iterator{

			private:

			    list<Punto>::iterator p;

			public:

			    iterator(){}
			    iterator & operator ++(){

					++p;
					return * this;

			    }
			    
			    iterator & operator --(){

					--p;
					return * this;

			    }

			    bool operator == (const iterator  & it){

					return it.p == p;

			    }
			    bool operator != (const iterator  & it){

					return it.p != p;

			    }
			    
			    Punto & operator*(){

				 	return *p;

			    }

			    friend class Ruta;

			    friend class const_iterator;
		};

		class const_iterator{

			private:
			    list<Punto>::const_iterator p;
			public:
			    const_iterator(){}
			    const_iterator(const iterator & it){
			      p = it.p;
			      
			    }
			    const_iterator & operator = (const iterator & it){

					p = it.p;
					return *this;

			    }	

			    const_iterator & operator ++(){

					++p;
					return * this;

			    }
			    
			    const_iterator & operator --(){

					--p;
					return * this;

			    }

			    bool operator == (const const_iterator  & it){

					return it.p == p;

			    }

			    bool operator != (const const_iterator  & it){

					return it.p != p;
			    }


			    const Punto &operator*()const {

				 	return *p;

			    }

			    friend class Ruta;
			   
		};

		iterator begin(){

		  	iterator it;
		  	it.p = puntos.begin();
		  	return it;

		}  
		
		const_iterator begin()const{

		  	const_iterator it;
		  	it.p = puntos.begin();
		  	return it;

		}

		iterator end(){

		  	iterator it;
		  	it.p = puntos.end();
		  	return it;

		}

		const_iterator end()const{

			const_iterator it;
		  	it.p = puntos.end();
		 	return it;

		}

		iterator find (const Punto &p){

		    iterator it;
		    list<Punto>::iterator i;
		    for (i = puntos.begin(); i != puntos.end() && !(*i == p); ++i);
		    it.p = i;
		    return it;

		}

		friend istream & operator>>(istream & is, Ruta & R){

			Ruta rlocal;
		      
		    is >> rlocal.codigo; 
		    int n;
		    is >> n;
		    int i;
		    for (i = 0; i< n && is; i++){
				Punto p;
				is >> p;
				rlocal.Insertar(p);
		    }

		    R = rlocal;
		    return is;

		}

		friend ostream & operator<<(ostream & os, const Ruta &R){

		    os << R.codigo << '\t' << R.puntos.size() << '\t';
		    Ruta::const_iterator it;
		    for (it = R.begin(); it != R.end(); ++it){  
		    	os << *it << "\t";
		    }

		    return os;

		}
	
};

#endif