#include "PruebasAuxEntrega2.h"

void pruebaObtenerRepetidos(char *lista)
{
	int largo;
	NodoListaS* listaParseada = (NodoListaS*)FrameworkA1::parsearColeccion(lista, largo);
	
	MultiSet<int> *m = FrameworkA1::ConvertirAMultiSet(listaParseada);

	ListaOrd<int>* l = ObtenerRepetidos(*m);

	cout << *l << endl;

	FrameworkA1::destruir(listaParseada);
	delete m;
	delete l;
}

void pruebaContarOcurrencias(char *lista) {

	int largo;
	NodoListaS* listaParseada = (NodoListaS*)FrameworkA1::parsearColeccion(lista, largo);

	ListaOrd<int> *listaOrd = FrameworkA1::ConvertirAListaOrd(listaParseada);

	Tabla<int, int> *tabla = ContarOcurrencias(*listaOrd);

	cout << *tabla << endl;

	FrameworkA1::destruir(listaParseada);
	delete listaOrd;
	delete tabla;
}

void pruebaXor(char* inputMultiSet1, char* inputMultiSet2)
{
	int largoLista1;
	int largoLista2;
	NodoListaS* lista1 = (NodoListaS*)FrameworkA1::parsearColeccion(inputMultiSet1, largoLista1);
	NodoListaS* lista2 = (NodoListaS*)FrameworkA1::parsearColeccion(inputMultiSet2, largoLista2);

	MultiSet<int> *m1 = FrameworkA1::ConvertirAMultiSet(lista1);
	MultiSet<int> *m2 = FrameworkA1::ConvertirAMultiSet(lista2);

	MultiSet<int> *res = Xor<int>(*m1, *m2);

	cout << *res << endl;

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	delete m1;
	delete m2;
	delete res;
}

void pruebaParentesisBalanceados(char *formula)
{
	char *formulaCopia = FrameworkA1::copioString(formula);

	bool res = ParentesisBalanceados(formula);

	bool parametrosModificados = !FrameworkA1::sonIguales(formula, formulaCopia);

	if(parametrosModificados) {
		cout << "ERROR parametro modificado" << endl;
	} 
	else
	{
		if (res)
		{
			cout << "Estan balanceados" << endl;			
		}
		else
		{
			cout << "No estan balanceados" << endl;			
		}
	}

	delete [] formulaCopia;
}

void pruebaImprimirPorNivelesAG(char* inputTree)
{
	int largo;
	NodoAG* arbol = (NodoAG*)FrameworkA1::parsearColeccion(inputTree, largo);

	ImprimirPorNiveles(arbol);
	FrameworkA1::destruir(arbol);
}

