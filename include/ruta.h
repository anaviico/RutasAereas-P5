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
		
	   for (int i = 0; i < R.puntos.size(); i++){
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
	      
	   Punto P;

	   while (is>>P){
			rlocal.Insertar(P); 
	   }

	   R=rlocal;
	    
	   return is;
	}

	Ruta operator = (const Ruta & r){
		this->codigo = r.codigo;
		this->puntos = r.puntos;

		return *this;
	}

	class iterator{
	private:
	    vector<Punto>::iterator p;
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
	    bool operator ==(const iterator  & it){
		return it.p ==p;
	    }
	    bool operator !=(const iterator  & it){
		return it.p !=p;
	    }
	     const Punto & operator*()const{
		  return *p;
	    }
	};    
	class const_iterator{
	private:
	    vector<Punto>::const_iterator p;
	public:
	    const_iterator(){}
	    const_iterator(const iterator & it){
	      p=it.p;
	      
	    }
	    const_iterator & operator=(const iterator & it){
		p=it.p;
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
	    bool operator ==(const const_iterator  & it){
		return it.p ==p;
	    }
	    bool operator !=(const const_iterator  & it){
		return it.p !=p;
	    }
	    const Pais &operator*()const {
		  return *p;
	    }
	    friend class Paises;
	   
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
};

#endif