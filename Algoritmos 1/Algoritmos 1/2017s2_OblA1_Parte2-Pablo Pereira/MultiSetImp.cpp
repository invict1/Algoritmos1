#include "MultiSetImp.h"

#ifndef MULTISET_IMP_CPP
#define MULTISET_IMP_CPP

template <class T>	
MultiSetImp<T>::MultiSetImp() {
	this->lista = new ListaOrdImp<T>();
}

template <class T> 
MultiSetImp<T>::MultiSetImp(const MultiSet<T> &multiSet) {
	this->lista = new ListaOrdImp<T>();
	*this = multiSet;
}

template <class T> 
MultiSetImp<T>::MultiSetImp(const MultiSetImp<T> &multiSet) {
	this->lista = new ListaOrdImp<T>();
	*this = multiSet;
}

template <class T> 
MultiSet<T>& MultiSetImp<T>::operator=(const MultiSet<T> &multiSet) {
	if (this != &multiSet) {
		this->Vaciar();
		MultiSet<T>* temp = multiSet.Clon();
		while (!temp->EsVacia()) {
			T elem = temp->Elemento();
			this->Insertar(elem, 1);
			temp->Borrar(elem, 1);
		}
		delete temp;
	}
	return *this;
}

template <class T> 
MultiSet<T>& MultiSetImp<T>::operator=(const MultiSetImp<T> &multiSet) {
	if (this != &multiSet) {
		this->Vaciar();
		MultiSet<T>* temp = multiSet.Clon();
		while (!temp->EsVacio()) {
			T elem = temp->Elemento();
			this->Insertar(elem, 1);
			temp->Borrar(elem, 1);
		}
		delete temp;
	}
	return *this;
}

template <class T> 
bool MultiSetImp<T>::operator==(const MultiSet<T> &multiSet) const {
	MultiSet<T>* temp = multiSet.Clon();
	ListaOrd<T>* listaTemp = this->lista->Clon();
	bool esIgual = this->Cardinal() == temp->Cardinal();
	while (!temp->EsVacia() && esIgual) {
		T elem = temp->Elemento();
		if (this->lista->Existe(elem)) {
			temp->Borrar(elem, 1);
			listaTemp->Borrar(elem);
		}
		else esIgual = false;
	}
	delete temp;
	delete listaTemp;
	return esIgual;
}

template <class T> 
MultiSetImp<T>::~MultiSetImp() {
	this->Vaciar();
}

template <class T> 
void MultiSetImp<T>::Insertar(const T &e, unsigned int cantidad) {
	for (unsigned int i = 0; i < cantidad; i++) {
		this->lista->AgregarOrd(e);
	}
}

template <class T>
void MultiSetImp<T>::Borrar(const T &e, unsigned int cantidad) {
	for (unsigned int i = 0; i < cantidad; i++) {
		this->lista->Borrar(e);
	}
}

template <class T> 
const T& MultiSetImp<T>::Elemento() const {
	return this->lista->Minimo();
}

template <class T> 
const T& MultiSetImp<T>::Recuperar(const T &e) const {
	return this->lista->Recuperar(e);
}

template <class T> 
unsigned int MultiSetImp<T>::OcurrenciasElemento(const T &e) const {
	Iterador<T> &i = this->lista->GetIterador();
	unsigned int cant = 0;
	while (!i.EsFin()) {
		if (i.Elemento() == e) cant++;
		i++;
	}
	return cant;
}

template <class T> 
bool MultiSetImp<T>::Pertenece(const T &e) const {
	return OcurrenciasElemento(e) > 0;
}

template <class T> 
void MultiSetImp<T>::Vaciar() {
	this->lista->Vaciar();
}

template <class T> 
bool MultiSetImp<T>::EsVacia() const
{
	return Cardinal() == 0;
}

template <class T>
bool MultiSetImp<T>::EsLlena() const {
	return false;
}

template <class T>
unsigned int MultiSetImp<T>::Cardinal() const {
	Iterador<T> &i = this->lista->GetIterador();
	unsigned int cant = 0;
	T elemAnterior;
	if (!i.EsFin()) {
		elemAnterior = i.Elemento();
		i++;
		cant++;
	}
	while (!i.EsFin()) {
		if (i.Elemento() != elemAnterior) {
			cant++;
			elemAnterior = i.Elemento();
		}
		i++;
	}
	return cant;
}

template <class T> /*Funciona para este caso, pero lo que tengo que hacer es ver cual es el que tiene la mayor 
cantidad de ocurrencias del elemento y agregar esas veces dicho elemento a mi multiset de retorno*/
MultiSet<T>* MultiSetImp<T>::Union(const MultiSet<T>& s) const {
	MultiSet<T>* clonMultiSet = s.Clon();
	MultiSet<T>* auxiliar = new MultiSetImp<T>();
	MultiSet<T>* retorno = new MultiSetImp<T>();
	ListaOrd<T>* lista = this->lista->Clon();
	while (!clonMultiSet->EsVacia()) { //agrego todo a lista
		lista->AgregarOrd(clonMultiSet->Elemento());
		clonMultiSet->Borrar(clonMultiSet->Elemento(), 1);
	}
	while (!lista->EsVacia()) { // paso todo a multiset
		auxiliar->Insertar(lista->Minimo(), 1);
		lista->Borrar(lista->Minimo());
	}

	while (!auxiliar->EsVacia()) {
		int veces = auxiliar->OcurrenciasElemento(auxiliar->Elemento());
		int total = veces;
		if (veces % 2 != 0) veces = (veces / 2) + 1;
		else veces = veces / 2;
		if (!retorno->Pertenece(auxiliar->Elemento())) {
			while (veces>0) {
				retorno->Insertar(auxiliar->Elemento(), 1);	
				veces--;
			}
			while (total > 0) {
				auxiliar->Borrar(auxiliar->Elemento(), 1);
				total--;
			}
		}
		else {
			auxiliar->Borrar(auxiliar->Elemento(), 1);
		}
	}
	return retorno;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Interseccion(const MultiSet<T>& s) const {
	MultiSet<T>* clonMultiSet = s.Clon();
	MultiSet<T>* retorno = new MultiSetImp<T>();
	ListaOrd<T>* copiaLista = this->lista->Clon();
	while (!clonMultiSet->EsVacia() && !copiaLista->EsVacia()) {
		if (copiaLista->Minimo() == clonMultiSet->Elemento()) {
			retorno->Insertar(copiaLista->Minimo(), 1);
			copiaLista->Borrar(copiaLista->Minimo());
			clonMultiSet->Borrar(clonMultiSet->Elemento(), 1);
		}
		else if (copiaLista->Minimo() < clonMultiSet->Elemento())
			copiaLista->Borrar(copiaLista->Minimo());
		else
			clonMultiSet->Borrar(clonMultiSet->Elemento(), 1);
	}
	delete clonMultiSet;
	delete copiaLista;
	return retorno;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Diferencia(const MultiSet<T>& s) const {
	MultiSet<T>* clonMultiSet = s.Clon();
	MultiSet<T>* retorno = new MultiSetImp<T>();
	Iterador<T> &i = this->lista->GetIterador();
	while (!i.EsFin()) {
		if (!clonMultiSet->Pertenece(i.Elemento())) {
			retorno->Insertar(i.Elemento(), 1);
		}
		clonMultiSet->Borrar(i.Elemento(), 1);
		i++;
	}
	delete clonMultiSet;
	return retorno;
}

template <class T>
bool MultiSetImp<T>::ContenidoEn(const MultiSet<T> &s) const {
	MultiSet<T>* clonMultiSet = s.Clon();
	Iterador<T> &i = this->lista->GetIterador();
	while (!i.EsFin() && clonMultiSet->Pertenece(i.Elemento())) {
		clonMultiSet->Borrar(i.Elemento(), 1);
		i++;
	}
	delete clonMultiSet;
	return i.EsFin();
}

template <class T>
MultiSet<T>* MultiSetImp<T>::Clon() const {
	MultiSet<T> * retorno = new MultiSetImp<T>();
	Iterador<T> &i = this->lista->GetIterador();
	for (i; !i.EsFin(); i++) {
		T elem = i.Elemento();
		retorno->Insertar(elem, 1);
	}
	return retorno;
}

template <class T>
MultiSet<T>* MultiSetImp<T>::CrearVacia() const {
	return new MultiSetImp<T>();
}

template<class T>
void MultiSetImp<T>::Imprimir(ostream& o) const {
	for (Iterador<T> &it = this->lista->GetIterador(); !it.EsFin();) {
		o << it++ << " ";
	}
}

#endif
