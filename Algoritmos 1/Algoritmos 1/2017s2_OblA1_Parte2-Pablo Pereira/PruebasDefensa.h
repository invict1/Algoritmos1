#ifndef PRUEBASDEFENSA_H
#define PRUEBASDEFENSA_H

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxDefensa.h"


class PruebasDefensa : public Prueba  
{

public:
	PruebasDefensa(ConductorPrueba* conductor);
	virtual ~PruebasDefensa();
	virtual void correrPruebaConcreta();


protected:
	virtual char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

};

#endif