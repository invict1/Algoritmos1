#include "Entrega1.h"

#ifndef ENTREGA1_CPP
#define ENTREGA1_CPP

//terminado
ListaOrd<int>* Enlistar(NodoAB* a)
{
	ListaOrd<int>* retorno = new ListaOrdImp<int>();
	EnlistarAux(a, retorno);
	return retorno;
}

//aux
void EnlistarAux(NodoAB* a, ListaOrd<int>* &lista) {
	if (a != NULL) {
		EnlistarAux(a->der, lista);
		lista->AgregarOrd(a->dato);
		EnlistarAux(a->izq, lista);
	}
}

//terminado
int CantidadDeHojas(NodoAB* a)
{
	int cant = 0;
	Cola<NodoAB*>* c = new ColaImp<NodoAB*>();
	if (a != NULL) c->Encolar(a);
	while (!c->EsVacia()) {
		NodoAB* arbActual = c->Principio();
		if (arbActual->izq == NULL && arbActual->der == NULL) cant++;
		if (arbActual->izq != NULL) c->Encolar(arbActual->izq);
		if (arbActual->der != NULL) c->Encolar(arbActual->der);
		c->Desencolar();
	}
	delete c;
	return cant;
	/*if (a != NULL) return 0;
	Pila <NodoAB*>* pila = new PilaImp<NodoAB*>();
	pila->Push(a);
	int cantidad = 0;
	while (!pila->EsVacia()) {
		NodoAB* nodo = pila->Pop();
		if (nodo->der == NULL && nodo->izq == NULL)
			cantidad++;
		if (nodo->der != NULL)
			pila->Push(nodo->der);
		if (nodo->izq != NULL)
			pila->Push(nodo->izq);
	}
	delete pila;
	return cantidad;
	*/
}

//terminado
void ImprimirPorNiveles(NodoAB *a)
{
	Cola<NodoAB*>* c = new ColaImp<NodoAB*>();
	Pila<int>* p = new PilaImp<int>();
	if (a != NULL) c->Encolar(a);
	while (!c->EsVacia()) {
		NodoAB* arbActual = c->Principio();
		p->Push(arbActual->dato);
		if (arbActual->izq != NULL) c->Encolar(arbActual->izq);
		if (arbActual->der != NULL) c->Encolar(arbActual->der);
		c->Desencolar();
	}
	while (!p->EsVacia()) {
		cout << p->Pop() << " ";
	}
	delete p;
	delete c;
	/*
	Cola <NodoAB*>* cola = new ColaImp<NodoAB*>();
	Pila <NodoAB*>* pila = new PilaImp<NodoAB*>();
	cola->Encolar(a);
	int cantidad = 0;
	while (!cola->EsVacia()) {
		NodoAB* nodo = cola->Desencolar();
		if (nodo->der == NULL && nodo->izq == NULL)
			cantidad++;
		if (nodo->der != NULL)
			cola->Encolar(nodo->der);
		if (nodo->izq != NULL)
			cola->Encolar(nodo->izq);
	}
	while (!cola->EsVacia) {
		//desencolo todo hacia la pila
		// luego voy imprimiendo de a uno con el Pop
	}*/
}

#endif