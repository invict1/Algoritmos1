#include "ColaImp.h"

#ifndef COLAIMP_CPP
#define COLAIMP_CPP

template <class T>
ostream &operator<<(ostream& out, const ColaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

//terminado
template <class T>
ColaImp<T>::ColaImp() {
	T* nuevo = new T();
	this->inicio = new NodoLista<T>(*nuevo, NULL, NULL);
	this->fin = this->inicio;
	this->cant_elem = 0;
}

//terminado
template <class T>
ColaImp<T>::ColaImp(const Cola<T> &c) {
	this->inicio = NULL; 
	this->fin = NULL;
	this->cant_elem = 0;
	*this = c;
}

//terminado
template <class T>
ColaImp<T>::ColaImp(const ColaImp<T> &c) {
	this->inicio = NULL;
	this->fin = NULL;
	this->cant_elem = 0;
	*this = c;
}

//terminado
template <class T>
Cola<T> & ColaImp<T>::operator=(const Cola<T> &c) {
	if (this != &c) {
		this->Vaciar();
		Cola<T>* clonC = c.Clon();
		while (!clonC->EsVacia()) {
			this->Encolar(clonC->Desencolar());
		}
		delete clonC;
	}
	return *this;
	/*
	if (this != &c) {
		this->Vaciar();

		for (Iterador<T> it = c.GetIterador(); !it.EsFin();) {
			this->Encolar(it++);
		}
	}
	return *this;*/
}

//terminado
template <class T>
Cola<T> & ColaImp<T>::operator=(const ColaImp<T> &c) {
	if (this != &c) {
		this->Vaciar();
		Cola<T>* clonC = c.Clon();
		while (!clonC->EsVacia()) {
			this->Encolar(clonC->Desencolar());
		}
		delete clonC;
	}
	return *this;
	/*
	if (this != &c) {
		this->Vaciar();

		for (Iterador<T> it = c.GetIterador(); !it.EsFin();) {
			this->Encolar(it++);
		}
	}
	return *this;*/
}

//terminado
template <class T>
bool ColaImp<T>::operator==(const Cola<T>& c) const {
	Cola<T>* clonC = c.Clon();
	Cola<T>* clonThis = this->Clon();
	bool retorno = !clonC->EsVacia() && !clonThis->EsVacia();
	while (!clonC->EsVacia() && !clonThis->EsVacia()) {
		if (clonC->Desencolar() != clonThis->Desencolar()) retorno = false;
	}
	delete clonC;
	delete clonThis;

	return retorno;/*
	if (this->cant_elem != c->cant_elem) {
		return false
	}
	else {
		int cantidad = 0;
		while (this->fin == c->fin) {
			cantidad++;
			this->fin = this->fin->sig;
			c->fin = c->fin->sig;
		}
		if (cantidad == this->cant_elem) {
			return true;
		}
		else {
			return false;
		}
	}*/
}

//terminado
template <class T>
ColaImp<T>::~ColaImp() {
	this->Vaciar();
	/*
	while (!this->EsVacia()) {
		T* aBorrar = this->fin;
		this->fin = this->fin->sig;
		delete[] aBorrar;
	}*/
}

//terminado
template<class T>
Cola<T>* ColaImp<T>::CrearVacia() const {
	return new ColaImp();
}

//terminado
template <class T>
void ColaImp<T>::Encolar(const T &e) {
	NodoLista<T>* nuevo = new NodoLista<T>(e, NULL, NULL);
	this->fin->sig = nuevo;
	this->fin = nuevo;
	this->cant_elem++;
	/*
	NodoLista* nuevo = new NodoLista(e);
	if (this->cant_elem == 0) {
		this->inicio = nuevo;
		this->fin = nuevo;
	}
	else {
		this->inicio->sig = nuevo;
		this->inicio = nuevo;
	}
	this->cant_elem++;
	*/
}

//terminado
template <class T>
T& ColaImp<T>::Principio()const {
	assert(!this->EsVacia());
	return this->inicio->sig->dato;/*
	assert(!this->EsVacia());
	return this->inicio;*/
}

//terminado
template <class T>
T ColaImp<T>::Desencolar() {
	assert(!this->EsVacia());
	T copia = *new T(this->inicio->sig->dato);
	NodoLista<T>* aBorrar = this->inicio;
	this->inicio = this->inicio->sig;
	delete aBorrar;
	this->cant_elem--;
	return copia;
	/*
	T* retorno = this->fin;
	this->fin = this->fin->sig;
	this->cant_elem--;
	return retorno;*/
}

//terminado
template <class T>
void ColaImp<T>::Vaciar() {
	while (!this->EsVacia()) {
		this->Desencolar();
	}
	/*
	while (!this->EsVacia()) {
		T* aBorrar = this->fin;
		this->fin = this->fin->sig;
		delete[] aBorrar;
	}
	this->cant_elem = 0;*/
}

//terminado
template <class T>
unsigned int ColaImp<T>::CantidadElementos()const {
	return this->cant_elem;
}

//terminado
template <class T>
bool ColaImp<T>::EsVacia() const {
	return this->cant_elem == 0;
}

//terminado
template <class T>
bool ColaImp<T>::EsLlena() const {
	return false;
}

//terminado
template <class T>
Cola<T>* ColaImp<T>::Clon()const {
	Cola<T>* retorno = new ColaImp();
	NodoLista<T>* temp = this->inicio->sig;
	while (temp != NULL) {
		retorno->Encolar(temp->dato);
		temp = temp->sig;
	}
	return retorno;
	/*
	NodoLista* retorno = new NodoLista();
	retorno->cant_elem = this->cant_elem;

	int cont = 0;
	while (cont < this->cant_elem) {
		retorno.Encolar(this->fin);
		this->fin = this->fin->sig;
		cont++;
	}
	return retorno;*/
}

//terminado
template <class T>
void ColaImp<T>::Imprimir(ostream& o)const {
	Cola<T> *clon = this->Clon();

	T elemento;
	while (!clon->EsVacia()) {
		elemento = clon->Desencolar();
		o << elemento;
		if (!clon->EsVacia()) {
			o << " ";
		}
	}
	delete clon;
	/*
	int cantidad = 0;
	while (cantidad < this->cant_elem) {
		o << this->Principio()->dato << " ";
		this->inicio = this->inicio->sig;
		cantidad++;
	}*/
}

#endif