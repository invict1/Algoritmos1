#include "ListaOrdImp2.h"

#ifndef LISTAORDIMP2_CPP
#define LISTAORDIMP2_CPP

template <class T>
inline ostream &operator<<(ostream& out, const ListaOrdImp2<T> &l)
{
	l.Imprimir(out);
	return out;
}

//terminado
template <class T>
ListaOrd<T>* ListaOrdImp2<T>::CrearVacia() const
{
	return new ListaOrdImp2<T>();
}

//terminado
template <class T>
ListaOrdImp2<T>::ListaOrdImp2()
{
	this->raiz = NULL;
	this->cant_elem = 0;
}

//terminado
template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrd<T> &l)
{
	this->raiz = NULL;
	this->cant_elem = 0;

	*this = l;
}

//terminado
template <class T>
ListaOrdImp2<T>::ListaOrdImp2(const ListaOrdImp2<T> &l)
{
	this->raiz = NULL;
	this->cant_elem = 0;

	*this = l;
}

//terminado
template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrd<T> &l)
{
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &it = l.GetIterador(); !it.EsFin();) {
			this->AgregarOrd(it++);
		}
	}
	return *this;
}

//terminado
template <class T>
ListaOrd<T> &ListaOrdImp2<T>::operator=(const ListaOrdImp2<T> &l)
{
	if (this != &l) {
		this->Vaciar();

		for (Iterador<T> &it = l.GetIterador(); !it.EsFin();) {
			this->AgregarOrd(it++);
		}
	}
	return *this;
}

//terminado
template <class T>
ListaOrdImp2<T>::~ListaOrdImp2()
{
	this->Vaciar();
}

//terminado
template <class T>
void ListaOrdImp2<T>::AgregarOrd(const T &e)
{
	AgregarOrdAux(e, this->raiz);
	this->cant_elem++;
}

//terminado
template <class T>
void ListaOrdImp2<T>::AgregarOrdAux(const T &e, NodoABB<T>* &arbol)
{
	if (arbol == NULL) {
		arbol = new NodoABB<T>(e);
	}
	else if (e < arbol->dato) AgregarOrdAux(e, arbol->izq);
	else if (e > arbol->dato) AgregarOrdAux(e, arbol->der);
	else arbol->auxiliar++;
	/*if (pos == NULL) {
		NodoABB<T>* nuevo = new NodoABB<T>(e);
	}
	else {
		if (pos->dato > e) {
			AgregarOrdAux(e, pos->izq);
		}
		else if (pos->dato < e) {
			AgregarOrdAux(e, pos->der);
		}
		else if (pos->dato == e) {
			pos->auxiliar++;
		}
	}*/
}

//terminado
template <class T>
void ListaOrdImp2<T>::BorrarMinimo()
{
	BorrarMinimoAux(this->raiz);
	this->cant_elem--;
}

//terminado
template <class T>
void ListaOrdImp2<T>::BorrarMinimoAux(NodoABB<T>* & arbol) {
	if (arbol != NULL) {
		if (arbol->izq != NULL) BorrarMinimoAux(arbol->izq);
		else {
			if (arbol->auxiliar > 0) arbol->auxiliar--;
			else {
				NodoABB<T>* aBorrar = arbol;
				arbol = arbol->der;
				delete aBorrar;
			}
		}
	}
	/*if (pos != NULL) {
		if (pos->izq == NULL) {
			if (pos->auxiliar > 0) {
				pos->auxiliar--;
			}
			else {
				NodoABB<T>* aux = pos;
				pos = pos->der;
				delete aux;
			}
			//this->cant_elem--;
		}
		else {
			BorrarMinimoAux(pos->izq);
		}
	}*/
}

//terminado
template <class T>
void ListaOrdImp2<T>::BorrarMaximo()
{
	BorrarMaximoAux(this->raiz);
	this->cant_elem--;
}

//terminado
template <class T>
void ListaOrdImp2<T>::BorrarMaximoAux(NodoABB<T>* &arbol) {
	if (arbol != NULL) {
		if (arbol->der != NULL) BorrarMaximoAux(arbol->der);
		else {
			if (arbol->auxiliar > 0) arbol->auxiliar--;
			else {
				NodoABB<T>* aBorrar = arbol;
				arbol = arbol->izq;
				delete aBorrar;
			}
		}
	}
	/*if (pos != NULL) {
		if (pos->der == NULL) {
			if (pos->auxiliar > 0) {
				pos->auxiliar--;
			}
			else {
				NodoABB<T>* aux = pos;
				pos = pos->izq;
				delete aux;
			}
			//this->cant_elem--;
		}
		else {
			BorrarMaximoAux(pos->der);
		}
	}*/
}

//terminado
template <class T>
void ListaOrdImp2<T>::Borrar(const T &e)
{
	BorrarAux(this->raiz,e);
	this->cant_elem--;
}

template <class T>
void ListaOrdImp2<T>::BorrarAux(NodoABB<T>* &arbol, T e)
{
	if (arbol != NULL) {
		if (e < arbol->dato) BorrarAux(arbol->izq, e);
		else if (e > arbol->dato) BorrarAux(arbol->der, e);
		else { 
			if (arbol->auxiliar > 0) arbol->auxiliar--;
			else if (arbol->izq == NULL) {
				NodoABB<T>* aBorrar = arbol;
				arbol = arbol->der;
				delete aBorrar;
			}
			else if (arbol->der == NULL) {
				NodoABB<T>* aBorrar = arbol;
				arbol = arbol->izq;
				delete aBorrar;
			}
			else {
				NodoABB<T>* minimo = MinimoAux(arbol->der);
				arbol->dato = minimo->dato;
				arbol->auxiliar = minimo->auxiliar;
				minimo->auxiliar = 0;
				BorrarAux(arbol->der, arbol->dato);
			}
		}
	}
}



//terminado
template <class T>
const T& ListaOrdImp2<T>::Minimo() const
{
	return MinimoAux(this->raiz)->dato;
}

//terminado
template <class T>
NodoABB<T>* ListaOrdImp2<T>::MinimoAux(NodoABB<T> *arbol) const
{
	if (arbol == NULL) return NULL;
	else if (arbol->izq != NULL) return MinimoAux(arbol->izq);
	else return arbol;
}

//terminado
template <class T>
const T& ListaOrdImp2<T>::Maximo() const
{
	return MaximoAux(this->raiz)->dato;
}

//terminado
template <class T>
NodoABB<T>* ListaOrdImp2<T>::MaximoAux(NodoABB<T>* arbol) const
{
	if (arbol == NULL) return NULL;
	else if (arbol->der != NULL) return MinimoAux(arbol->der);
	else return arbol;
}

//terminado
template <class T>
const T& ListaOrdImp2<T>::Recuperar(const T &e) const
{
	NodoABB<T>* recuperado = RecuperarAux(this->raiz, e);
	return recuperado->dato;
}

//terminado
template <class T>
NodoABB<T>* ListaOrdImp2<T>::RecuperarAux(NodoABB<T>* arbol, const T &e) const
{
	bool esta = false;
	while (arbol != NULL && !esta) {
		if (arbol->dato == e) esta = true;
		else if (arbol->dato > e) arbol = arbol->izq;
		else arbol = arbol->der;
	}
	return arbol;
}

//terminado
template <class T>
bool ListaOrdImp2<T>::Existe(const T &e) const
{
	return RecuperarAux(this->raiz, e) != NULL;
}

//terminado
template <class T>
void ListaOrdImp2<T>::Vaciar()
{
	while (!this->EsVacia()) {
		this->Borrar(this->raiz->dato);
	}
}

//terminado
template <class T>
unsigned int ListaOrdImp2<T>::CantidadElementos()const
{
	return this->cant_elem;
}

//terminado
template <class T>
bool ListaOrdImp2<T>::EsVacia()const
{
	return this->cant_elem == 0;
}

//terminado
template <class T>
bool ListaOrdImp2<T>::EsLlena()const
{
	return false;
}

//terminado
template<class T>
ListaOrd<T>* ListaOrdImp2<T>::Clon() const
{
	ListaOrd<T>* clon = new ListaOrdImp2<T>();

	for (Iterador<T>& i = this->GetIterador(); !i.EsFin();)
		clon->AgregarOrd(i++);

	return clon;
}

/*
//terminado
template<class T>
void ListaOrdImp2<T>::ClonAux(NodoABB<T>* arbol, NodoABB<T>* &clon) const
{
	if (arbol != NULL) {
		if (arbol->izq != NULL) {
			ClonAux(arbol->izq, clon);
		}
		clon.AgregarOrd(arbol->dato);
		if (arbol->der != NULL) {
			ClonAux(arbol->der, clon);
		}
	}
}*/

//terminado
template <class T>
Iterador<T> ListaOrdImp2<T>::GetIterador() const
{
	ListaPosImp<T> l;
	pasarALista(this->raiz, &l);
	return IteradorListaOrdImp2<T>(l);
}

template <class T>
void ListaOrdImp2<T>::pasarALista(NodoABB<T>* arbol, ListaPosImp<T>* l) const
{
	if (arbol != NULL) {
		pasarALista(arbol->der, l);
		for (int i = arbol->auxiliar; i >= 0; i--) {
			l->AgregarPpio(arbol->dato);
		}
		pasarALista(arbol->izq, l);
	}
}

template <class T>
void ListaOrdImp2<T>::Imprimir(ostream& o) const
{
	for (Iterador<T> &i = GetIterador(); !i.EsFin();) {
		o << i++ << " ";
	}
}

#endif