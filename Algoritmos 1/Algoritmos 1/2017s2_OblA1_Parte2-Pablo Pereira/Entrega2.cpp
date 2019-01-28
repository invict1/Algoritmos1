#include "Entrega2.h"

#ifndef ENTREGA2_CPP
#define ENTREGA2_CPP

bool ParentesisBalanceados(char *formula)	//VIEJO
{
	Pila<char>* pilaString = new PilaImp<char>();
	int i = 0;
	bool esBalanceado = true;
	while (formula[i] != '\0' && esBalanceado) {
		if (formula[i] == '(' || formula[i] == '{' || formula[i] == '[') {
			pilaString->Push(formula[i]);
		}
		else if (formula[i] == ')' || formula[i] == '}' || formula[i] == ']') {
			if (!pilaString->EsVacia()) {
				if ((formula[i] == ')' && pilaString->Top() == '(') || (formula[i] == '}' && pilaString->Top() == '{') || (formula[i] == ']' && pilaString->Top() == '['))
					pilaString->Pop();
			}
			else esBalanceado = false;
		}
		i++;
	}
	esBalanceado = esBalanceado && pilaString->EsVacia();
	delete pilaString;
	return esBalanceado;
}


//lista, pila o cola en lo que vamos guardando son los nodos y ahi vamos recorriendo. 
//guardar el nodo en una estructura auxiliar para poder recorrerlo, y se los vamos a ir sacando
//para arrancar hay que guardar la raiz
void ImprimirPorNiveles(NodoAG* a)
{
	if (a == NULL) return;
	Cola<NodoAG*>* cola = new ColaImp<NodoAG*>();
	cola->Encolar(a);
	while (!cola->EsVacia()) {
		NodoAG* nodo = cola->Desencolar();
		while (nodo != NULL) {
			cout << nodo->dato << " ";
			if (nodo->ph)
				cola->Encolar(nodo->ph);
			nodo = nodo->sh;
		}
	}
}

#endif
