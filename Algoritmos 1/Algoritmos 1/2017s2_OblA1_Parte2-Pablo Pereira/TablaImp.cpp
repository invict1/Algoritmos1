#include "TablaImp.h"

#ifndef TABLAIMP_CPP
#define TABLAIMP_CPP

template <class D, class R>
inline ostream &operator<<(ostream& out, const TablaImp<D, R> &t) {
	t.Imprimir(out);
	return out;
}

template <class D, class R>	
TablaImp<D, R>::TablaImp() {
	this->lista = new ListaOrdImp<Asociacion<D, R>>();
}

template <class D, class R> 
TablaImp<D, R>::TablaImp(const Tabla<D, R> &t) {
	this->lista = new ListaOrdImp<Asociacion<D, R>>();
	*this = t;
}

template <class D, class R> 
TablaImp<D, R>::TablaImp(const TablaImp<D, R> &t) {
	this->lista = new ListaOrdImp<Asociacion<D, R>>();
	*this = t;
}

template <class D, class R> 
Tabla<D, R>& TablaImp<D, R>::operator=(const Tabla<D, R> &t) {
	if (this != &t) {
		this->Vaciar();
		Tabla<D, R>* temp = t.Clon();
		while (!temp->EsVacia()) {
			D dominio = temp->Elemento();
			R rango = temp->Recuperar(dominio);
			this->Insertar(dominio, rango);
			temp->Borrar(dominio);
		}
		delete temp;
	}
	return *this;
}

template <class D, class R> 
Tabla<D, R>& TablaImp<D, R>::operator=(const TablaImp<D, R> &t) {
	if (this != &t) {
		this->Vaciar();
		Tabla<D, R>* temp = t.Clon();
		while (!temp->EsVacia()) {
			D dominio = temp->Elemento();
			R rango = temp->Recuperar(dominio);
			this->Insertar(dominio, rango);
			temp->Borrar(dominio);
		}
		delete temp;
	}
	return *this;
}

template <class D, class R> 
TablaImp<D, R>::~TablaImp() {
	this->Vaciar();
}

template <class D, class R> 
Tabla<D, R>* TablaImp<D, R>::CrearVacia() const {
	return new TablaImp<D, R>();
}

template <class D, class R> 
void TablaImp<D, R>::Vaciar() {
	this->lista->Vaciar();
}

template <class D, class R> 
void TablaImp<D, R>::Insertar(const D &d, const R &r) {
	Asociacion<D, R> * dato = new Asociacion<D, R>(d, r);
	if (this->EstaDefinida(d)) this->Borrar(d);
	this->lista->AgregarOrd(*dato);
}

template <class D, class R> 
bool TablaImp<D, R>::EstaDefinida(const D &d) const {
	Asociacion<D, R> * dato = new Asociacion<D, R>(d);
	return this->lista->Existe(*dato);
}

template <class D, class R> 
bool TablaImp<D, R>::operator==(const Tabla<D, R> &t) const {
	Tabla<D, R>* temp = t.Clon();
	bool esIgual = this->CantidadElementos() == temp->CantidadElementos();
	while (!temp->EsVacia() && esIgual) {
		D dominio = temp->Elemento();
		R rango = temp->Recuperar(dominio);
		Asociacion<D, R>* dato = new Asociacion<D, R>(dominio, rango);
		if (this->lista->Existe(*dato)) {
			Asociacion<D, R> busc = this->lista->Recuperar(*dato);
			if (busc.GetRango() != rango) esIgual = false;
			else temp->Borrar(dominio);
		}
		else esIgual = false;
	}
	delete temp;
	return esIgual;
};

template <class D, class R> 
const R& TablaImp<D, R>::Recuperar(const D &d) const {
	Asociacion<D, R>* dato = new Asociacion<D, R>(d);
	Asociacion<D, R> buscado = this->lista->Recuperar(*dato);
	return buscado.GetRango();
}

template <class D, class R> 
const D& TablaImp<D, R>::Elemento() const {
	return this->lista->Minimo().GetDominio();
}

template <class D, class R> 
void TablaImp<D, R>::Borrar(const D &d) {
	Asociacion<D, R> * dato = new Asociacion<D, R>(d);
	this->lista->Borrar(*dato);
}

template <class D, class R> 
bool TablaImp<D, R>::EsVacia() const {
	return this->CantidadElementos() == 0;
}

template <class D, class R> 
bool TablaImp<D, R>::EsLlena() const {
	return false;
}

template <class D, class R> 
unsigned int TablaImp<D, R>::CantidadElementos() const {
	return this->lista->CantidadElementos();
}

template <class D, class R> 
Tabla<D, R>* TablaImp<D, R>::Clon() const {
	Tabla<D, R> * retorno = new TablaImp<D, R>();
	Iterador<Asociacion<D, R>> &i = this->lista->GetIterador();
	for (i; !i.EsFin(); i++) {
		D dominio = i.Elemento().GetDominio();
		R rango = i.Elemento().GetRango();
		retorno->Insertar(dominio, rango);
	}
	return retorno;
}

template <class D, class R> 
void TablaImp<D, R>::Imprimir(ostream & o) const {
	Iterador<Asociacion<D, R>> &i = this->lista->GetIterador();
	while (!i.EsFin()) {
		D dominio = i.Elemento().GetDominio();
		R rango = i.Elemento().GetRango();
		o << "{D:" << dominio << "|R:" << rango << "}";
		i++;
		if (!i.EsFin()) {
			o << " ";
		}
	}
}


#endif