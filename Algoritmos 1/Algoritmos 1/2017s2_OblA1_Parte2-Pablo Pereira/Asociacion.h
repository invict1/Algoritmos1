#ifndef ASOCIACION_H
#define ASOCIACION_H

#include <iostream>
using namespace std;

template <class Dominio, class Rango>
class Asociacion {

public:
	Asociacion();
	Asociacion(const Dominio &d);
	Asociacion(const Dominio &d, const Rango &r);
	Asociacion(const Asociacion &o);

	virtual ~Asociacion();

	Asociacion<Dominio, Rango> &operator=(const Asociacion<Dominio, Rango> &o);

	const Dominio &GetDominio() const;
	//void SetDominio(const Dominio &d);

	const Rango &GetRango() const;
	Rango &GetRangoInseguro() const;
	void SetRango(const Rango &r);

	bool operator==(const Asociacion<Dominio, Rango> &o) const;
	bool operator!=(const Asociacion<Dominio, Rango> &o) const;
	bool operator<(const Asociacion<Dominio, Rango> &o) const;
	bool operator>(const Asociacion<Dominio, Rango> &o) const;
	bool operator<=(const Asociacion<Dominio, Rango> &o) const;
	bool operator>=(const Asociacion<Dominio, Rango> &o) const;

	void Imprimir(ostream& o) const;

private:
	Dominio d;
	Rango r;
};

#include "Asociacion.cpp"

#endif