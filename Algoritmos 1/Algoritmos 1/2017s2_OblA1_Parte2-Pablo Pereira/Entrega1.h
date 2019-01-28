#ifndef ENTREGA1_H
#define ENTREGA1_H

#include "Definiciones.h"

#include "ListaOrd.h"
#include "ListaPos.h"
#include "Pila.h"
#include "Cola.h"

#include "ListaOrdImp.h"
#include "ListaPosImp.h"
#include "PilaImp.h"
#include "ColaImp.h"

// Ver Entrega1.txt para la documentación de estas funciones
//-> cuando tengo *, . cuando es &
//terminado
template <class T>
ListaOrd<T> *UnionListaOrd(const ListaOrd<T> &l1, const ListaOrd<T> &l2)
{
	ListaOrd<T>* retorno = new ListaOrdImp<T>();
	Iterador<T> it1 = l1.GetIterador();
	Iterador<T> it2 = l2.GetIterador();
	while (!it1.EsFin() || !it2.EsFin()) {
		if ((!it1.EsFin() && !it2.EsFin() && it1.Elemento() <= it2.Elemento()) ||
			(!it1.EsFin() && it2.EsFin())) {
			retorno->AgregarOrd(it1.Elemento());
			it1.Resto();
		}
		else {
			retorno->AgregarOrd(it2.Elemento());
			it2.Resto();
		}
	}
	return retorno;
}

ListaOrd<int>* Enlistar(NodoAB* a);

template <class T>
bool EstaContenida(const Pila<T> &p1, const Pila<T> &p2)
{
	bool retorno = false;
	if (p2.CantidadElementos() >= p1.CantidadElementos()) {
		Pila<T>* clonP1 = p1.Clon();
		Pila<T>* clonP2 = p2.Clon();
		ListaOrd<T>* p1EnLista = new ListaOrdImp<T>();
		ListaOrd<T>* p2EnLista = new ListaOrdImp<T>();
		while (!clonP1->EsVacia()) {
			p1EnLista->AgregarOrd(clonP1->Pop());
		}
		while (!clonP2->EsVacia()) {
			p2EnLista->AgregarOrd(clonP2->Pop());
		}
		while (!p2EnLista->EsVacia() && !p1EnLista->EsVacia()) {
			if (p2EnLista->Existe(p1EnLista->Minimo())) {
				p2EnLista->Borrar(p1EnLista->Minimo());
				p1EnLista->BorrarMinimo();
			}
			else p2EnLista->BorrarMinimo();
		}
		retorno = p1EnLista->EsVacia();
		delete clonP1;
		delete clonP2;
		delete p1EnLista;
		delete p2EnLista;
	}
	return retorno;

}

int CantidadDeHojas(NodoAB* a);

void ImprimirPorNiveles(NodoAB *a);

//recibiendo un puntero a un ABB de tipo NodoArbol, y una ListaOrd lista a la cual se le an a agregar todos los elementos de a
void EnlistarAux(NodoAB* a, ListaOrd<int>* &lista);


#endif