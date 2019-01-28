#include "PilaImp.h"

#ifndef PILAIMP_CPP
#define PILAIMP_CPP

template <class T>
inline ostream &operator<<(ostream& out, const PilaImp<T> &c) {
	c.Imprimir(out);
	return out;
}

//terminado 
template <class T>
PilaImp<T>::PilaImp() {
	this->top = NULL;
	this->cant_elem = 0;
}

//terminado
template<class T>
PilaImp<T>::PilaImp(const Pila<T>& p) {
	this->top = NULL();
	this->cant_elem = 0;
	*this = p;
}

//terminado
template<class T>
PilaImp<T>::PilaImp(const PilaImp<T>& p) {
	this->top = NULL;
	this->cant_elem = 0;
	*this = p;
}

//terminado
template<class T>
Pila<T>& PilaImp<T>::operator=(const Pila<T>& p) {
	if (this != &p) {
		this->Vaciar();

		Pila<T>* clonP = p.Clon();
		Pila<T>* pilaAlReves = new PilaImp<T>();
		while (!clonP->EsVacia()) {
			pilaAlReves->Push(clonP->Pop());
		}
		while (!pilaAlReves->EsVacia()) {
			this->Push(pilaAlReves->Pop());
		}
		delete clonP;
		delete pilaAlReves;
	}
	return *this;
}

//terminado
template<class T>
Pila<T>& PilaImp<T>::operator=(const PilaImp<T>& p) {
	if (this != &p) {
		this->Vaciar();

		Pila<T>* clonP = p.Clon();
		Pila<T>* pilaAlReves = new PilaImp<T>();
		while (!clonP->EsVacia()) {
			pilaAlReves->Push(clonP->Pop());
		}
		while (!pilaAlReves->EsVacia()) {
			this->Push(pilaAlReves->Pop());
		}
		delete clonP;
		delete pilaAlReves;
	}
	return *this;
}

//terminado
template<class T>
bool PilaImp<T>::operator==(const Pila<T> &p) const {
	Pila<T>* clonP = p.Clon();
	Pila<T>* clonThis = this->Clon();
	bool retorno = !clonP->EsVacia() && !clonThis->EsVacia();
	while (!clonP->EsVacia() && !clonThis->EsVacia()) {
		if (clonP->Pop() != clonThis->Pop()) retorno = false;
	}
	delete clonP;
	delete clonThis;

	return retorno;
	/*if (this->cant_elem != p->cant_elem) {
		return false
	}
	else {
		int cantIguales = 0;
		while (this->top->dato == p->top->dato) {
			cantIguales++;
		}
		return this->cant_elem == cantIguales;
	}*/
}

//terminado
template<class T>
PilaImp<T>::~PilaImp() {
	this->Vaciar();
	/*this->Vaciar();
	this->cant_elem = 0;*/
}

//terminado
template<class T>
Pila<T>* PilaImp<T>::CrearVacia() const {
	return new PilaImp<T>();
}

//terminado
template<class T>
void PilaImp<T>::Push(const T& e) {
	NodoLista<T>* nuevo = new NodoLista<T>(e, NULL, this->top);
	this->top = nuevo;
	this->cant_elem++;
	/*
	if (this->cant_elem == 0) {
		this->top = new NodoLista(e);
	}
	else {
		NodoLista *l = new NodoLista(e);
		l->sig = this->top;
		this->top = l;
	}
	this->cant_elem++;
	*/
}

//terminado
template<class T>
T& PilaImp<T>::Top() const {
	/*return this->top;*/
	assert(!this->EsVacia());
	return this->top->dato;
}

//terminado
template<class T>
T PilaImp<T>::Pop() {
	assert(!this->EsVacia());
	T copia = *new T(this->top->dato);
	NodoLista<T>* aBorrar = this->top;
	this->top = this->top->sig;
	delete aBorrar;
	this->cant_elem--;
	return copia;
	/*
	NodoLista *copia = new NodoLista(this->top->dato);
	NodoLista<T>* aBorrar = top;
	this->top = this->top->sig;
	delete[] aBorrar;
	this->cant_elem--;
	return copia;*/
}

//terminado
template<class T>
void PilaImp<T>::Vaciar() {
	while (!this->EsVacia()) {
		this->Pop();
	}
	/*while (this->cant_elem > 0) {
		NodoLista *test = top;
		top = top->sig;
		delete[] test;
		cant_elem--;
	}
	*/
}

//terminado
template<class T>
unsigned int PilaImp<T>::CantidadElementos() const {
	return this->cant_elem;
}

// terminada
template<class T>
bool PilaImp<T>::EsVacia() const {
	return this->cant_elem == 0;
}

// terminada
template <class T>
bool PilaImp<T>::EsLlena() const {
	return false;
}

// terminada
template<class T>
Pila<T>* PilaImp<T>::Clon() const {
	Pila<T>* retorno = new PilaImp();
	Pila<T>* alReves = new PilaImp();
	NodoLista<T>* temp = this->top;
	while (temp != NULL) {
		alReves->Push(temp->dato);
		temp = temp->sig;
	}
	while (!alReves->EsVacia()) {
		retorno->Push(alReves->Pop());
	}
	delete alReves;
	return retorno;
	/*PilaImp<T> retorno = new PilaImp<T>();
	retorno->cant_elem = this->cant_elem;

	int cont = 0;
	while (cont < this->cant_elem) {
		retorno.Push(this->top);
		this->top = this->top->sig;
		cont++;
	}
	return retorno;*/
}

// terminado
template<class T>
void PilaImp<T>::Imprimir(ostream & o) const
{
	Pila<T> *clon = this->Clon();
	while (!clon->EsVacia()) {
		T e = clon->Top();

		o << e;
		clon->Pop();
		if (!clon->EsVacia()) {
			o << " ";
		}

	}
	delete clon;
	/*
	int cont = 0;
	while (cont < this->cant_elem) {
		o << this->top->dato << " ";
		top = top->sig;
		cont++;
	}*/
}

#endif