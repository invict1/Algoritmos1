#include "ListaPosImp.h"

#ifndef LISTAPOSIMP_CPP
#define LISTAPOSIMP_CPP

template <class T>
inline ostream & operator<<(ostream &out, const ListaPosImp<T> &l)
{
	l.Imprimir(out);
	return out;
}

// terminado
template <class T>
ListaPos<T>* ListaPosImp<T>::CrearVacia() const
{
	return new ListaPosImp<T>();
}

// terminado
template <class T>
ListaPosImp<T>::ListaPosImp()
{
	this->vector = new T[2];
	this->largoVector = 2;
	this->cantidadElementos = 0;
}

// terminado
template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPos<T> &l)
{
	this->vector = new T[2];
	this->largoVector = 2;
	this->cantidadElementos = 0;

	*this = l;
}

// terminado
template <class T>
ListaPosImp<T>::ListaPosImp(const ListaPosImp<T> &l)
{
	this->vector = new T[2];
	this->largoVector = 2;
	this->cantidadElementos = 0;

	*this = l; //asigno los elementos de "l" a this.
}

// terminado
template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPos<T> &l)
{
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &it = l.GetIterador(); !it.EsFin();) {
			this->AgregarFin(it++);
		}
	}
	return *this;
}

// terminado
template <class T>
ListaPos<T>& ListaPosImp<T>::operator=(const ListaPosImp<T> &l)
{
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &it = l.GetIterador(); !it.EsFin();) {
			AgregarFin(it++);
		}
	}
	return *this;
}

template <class T>
ListaPosImp<T>::~ListaPosImp()
{
	delete[] this->vector;
}

// terminado
template <class T>
void ListaPosImp<T>::AgregarPpio(const T &e)
{
	if (this->largoVector == this->cantidadElementos) {
		expandir();
	}
	for (int i = this->cantidadElementos - 1; i >= 0; i--)
	{
		this->vector[i + 1] = this->vector[i];
	}
	this->vector[0] = e;
	this->cantidadElementos++;
}
          
// terminado
template <class T>
void ListaPosImp<T>::AgregarFin(const T &e)
{
	//if (this->EsLlena()) {
	if (this->largoVector == this->cantidadElementos){
		this->expandir();
	}
	this->vector[this->cantidadElementos] = e;
	//this->AgregarPos(e, this->cantidadElementos + 1);
	this->cantidadElementos++;
}

// terminado
template <class T>
void ListaPosImp<T>::AgregarPos(const T &e, unsigned int pos)
{
	this->expandir();
	this->correrHaciaAdelante(pos);
	this->vector[pos] = e;
	this->cantidadElementos++;
}

// terminado
template <class T>
void ListaPosImp<T>::BorrarPpio()
{
	this->correrHaciaAtras(0);
	this->cantidadElementos--;
}

// terminado
template <class T>
void ListaPosImp<T>::BorrarFin()
{
	if (this->cantidadElementos > 0) this->cantidadElementos--;
	/*
	BorrarPos(this->cantidadElementos - 1);
	*/
}

// terminado
template <class T>
void ListaPosImp<T>::BorrarPos(unsigned int pos)
{
	this->correrHaciaAtras(pos);
	this->cantidadElementos--;
}

// terminado
template <class T>
void ListaPosImp<T>::Borrar(const T &e)
{
	if (Existe(e)) {
		int pos = Posicion(e);
		BorrarPos(pos);
	}
}

// terminado
template <class T>
T& ListaPosImp<T>::ElementoPpio() const
{
	assert(!this->EsVacia());
	return this->vector[0];
}

// terminado
template <class T>
T& ListaPosImp<T>::ElementoFin() const
{
	assert(!this->EsVacia());
	return this->vector[this->cantidadElementos - 1];
}

// terminado
template <class T>
T& ListaPosImp<T>::ElementoPos(unsigned int pos) const
{
	return this->vector[pos];
}

// terminado
template <class T>
unsigned int ListaPosImp<T>::Posicion(const T &e) const
{
	int pos = 0;
	for (pos; pos < this->cantidadElementos && this->vector[pos] != e; pos++);
	return pos;
}

// terminado
template <class T>
bool ListaPosImp<T>::Existe(const T &e) const
{
	int pos = 0;
	for (pos; pos < this->cantidadElementos && this->vector[pos] != e; pos++);
	return pos != this->cantidadElementos;
}

// terminado
template <class T>
void ListaPosImp<T>::Vaciar()
{
	this->cantidadElementos = 0;
}

// terminado
template <class T>
unsigned int ListaPosImp<T>::CantidadElementos() const
{
	return this->cantidadElementos;
}

// terminado
template <class T>
bool ListaPosImp<T>::EsVacia() const
{
	return this->cantidadElementos == 0;
}

//terminado
template <class T>
bool ListaPosImp<T>::EsLlena() const
{
	return false;
}

//terminado
template <class T>
ListaPos<T>* ListaPosImp<T>::Clon() const
{
	ListaPos<T>* clon = new ListaPosImp<T>();

	for (Iterador<T>& i = this->GetIterador(); !i.EsFin();)
		clon->AgregarFin(i++);

	return clon;

}

// terminado
template <class T>
Iterador<T> ListaPosImp<T>::GetIterador() const
{
	return IteradorListaPosImp<T>(*this);
}

template <class T>
void ListaPosImp<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++;
		if (!i.EsFin()) o << " ";
	}
}

// AUXILIARES

template <class T>
void ListaPosImp<T>::expandir() {
	if (this->cantidadElementos == this->largoVector) {
		T* nuevo = new T[this->largoVector * 2];
		for (int i = 0; i < this->cantidadElementos; i++) {
			nuevo[i] = this->vector[i];
		}
		this->largoVector = this->largoVector * 2;
		delete[] this->vector;
		this->vector = nuevo;
	}
}

template <class T>
void ListaPosImp<T>::correrHaciaAdelante(int desde) {
	for (int i = this->cantidadElementos - 1; i >= desde; i--) {
		this->vector[i + 1] = this->vector[i];
	}
}

template <class T>
void ListaPosImp<T>::correrHaciaAtras(int hasta) {
	for (int i = hasta; i < this->cantidadElementos; i++) {
		this->vector[i] = this->vector[i + 1];
	}
}

#endif