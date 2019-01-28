
#ifndef ENTREGA2_H
#define ENTREGA2_H

#include "Definiciones.h"

#include "ColaImp.h"
#include "PilaImp.h"
#include "ListaOrd.h"
#include "TablaImp.h"
#include "MultiSet.h"
#include "ListaOrdImp.h"
#include "MultiSetImp.h"


template <class T> //VIEJO
ListaOrd<T>* ObtenerRepetidos(const MultiSet<T> &m)
{
	ListaOrd<T>* retorno = new ListaOrdImp<T>();
	MultiSet<T>* clon = m.Clon();
	while (!clon->EsVacia()) {
		T elem = clon->Elemento();
		int cantOcu = clon->OcurrenciasElemento(elem);
		if (cantOcu > 1) {
			retorno->AgregarOrd(elem);
		}
		clon->Borrar(elem, cantOcu);
	}
	delete clon;
	return retorno;
}

template <class T> //VIEJO
Tabla<T, int> *ContarOcurrencias(const ListaOrd<T>& l)
{
	Tabla<T, int>* retorno = new TablaImp<T, int>();
	Iterador<T> &i = l.GetIterador();
	while (!i.EsFin()) {
		T elem = i.Elemento();
		if (retorno->EstaDefinida(elem)) {
			int cantidad = retorno->Recuperar(elem);
			cantidad++;
			retorno->Insertar(elem, cantidad);
		}
		else retorno->Insertar(elem, 1);
		i++;
	}
	return retorno;
}





template <class T> //VIEJO
MultiSet<T>* Xor(const MultiSet<T> &m1, const MultiSet<T> &m2) {	//Observar que: AxorB = (AuB)-(AnB)
	MultiSet<T>* clonM1 = m1.Clon();
	MultiSet<T>* clonM2 = m2.Clon();
	MultiSet<T>* retorno = clonM1->Diferencia(*clonM2);
	MultiSet<T>* difM2 = clonM2->Diferencia(*clonM1);
	while (!difM2->EsVacia()) {
		T elem = difM2->Elemento();
		retorno->Insertar(elem, 1);
		difM2->Borrar(elem, 1);
	}
	delete clonM2;
	delete clonM1;
	delete difM2;
	return retorno;
}

bool ParentesisBalanceados(char *formula);

void ImprimirPorNiveles(NodoAG* a);

#endif
