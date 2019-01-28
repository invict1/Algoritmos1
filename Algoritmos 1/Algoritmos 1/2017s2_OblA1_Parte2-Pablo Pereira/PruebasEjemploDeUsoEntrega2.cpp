
#include "PruebasEjemploDeUsoEntrega2.h"

PruebasEjemploDeUsoEntrega2::PruebasEjemploDeUsoEntrega2(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUsoEntrega2::~PruebasEjemploDeUsoEntrega2()
{
	
}
char* PruebasEjemploDeUsoEntrega2::getNombre()const
{
	return "PruebasEjemploDeUsoEntrega2";
}

void PruebasEjemploDeUsoEntrega2::correrPruebaConcreta()
{
	PruebasEjerciciosTAD2();
	pruebaListaOrd();
	pruebaListaOrd2();
	pruebaTabla();
	pruebaMultiSet();
}

void PruebasEjemploDeUsoEntrega2::PruebasEjerciciosTAD2()
{
	// Pruebas ObtenerRepetidos
	this->mImpresion.iniciarSeccion("PRUEBAS ObtenerRepetidos");
	pruebaObtenerRepetidos("(1, 1, 2)");
	ver3("Prueba ObtenerRepetidos 1");
	pruebaObtenerRepetidos("()");
	ver3("Prueba ObtenerRepetidos 2");
	pruebaObtenerRepetidos("(1, 2, 3, 2, 1)");
	ver3("Prueba ObtenerRepetidos 3");
	pruebaObtenerRepetidos("(10, 4, 6, 1, 1, 10, 5, 8)");
	ver3("Prueba ObtenerRepetidos 4");
	pruebaObtenerRepetidos("(4)");
	ver3("Prueba ObtenerRepetidos 5");
	pruebaObtenerRepetidos("(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)");
	ver3("Prueba ObtenerRepetidos 6");
	pruebaObtenerRepetidos("(1, 1, 1, 1, 1, 1)");
	ver3("Prueba ObtenerRepetidos 7");
	pruebaObtenerRepetidos("(1, 10, 100, 1000)");
	ver3("Prueba ObtenerRepetidos 8");
	pruebaObtenerRepetidos("(4, 6, 4, 6, 4, 6, 4, 6)");
	ver3("Prueba ObtenerRepetidos 9");
	pruebaObtenerRepetidos("(1, 2, 1, 4, 2, 1, 4, 2, 7)");
	ver3("Prueba ObtenerRepetidos 10");
	pruebaObtenerRepetidos("(6, 6)");
	ver3("Prueba ObtenerRepetidos 11");
	pruebaObtenerRepetidos("(6, 6, 6, 7, 7, 7)");
	ver3("Prueba ObtenerRepetidos 12");
	this->mImpresion.cerrarSeccion("PRUEBAS ObtenerRepetidos");

	// Pruebas ContarOcurrencias
	this->mImpresion.iniciarSeccion("PRUEBAS ContarOcurrencias");
	pruebaContarOcurrencias("(1, 1, 2)");
	ver3("Prueba ContarOcurrencias 1");
	pruebaContarOcurrencias("()");
	ver3("Prueba ContarOcurrencias 2");
	pruebaContarOcurrencias("(1, 2, 3, 2, 1)");
	ver3("Prueba ContarOcurrencias 3");
	pruebaContarOcurrencias("(10, 1, 1, 1, 1, 10, 5, 8)");
	ver3("Prueba ContarOcurrencias 4");
	pruebaContarOcurrencias("(1)");
	ver3("Prueba ContarOcurrencias 5");
	pruebaContarOcurrencias("(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)");
	ver3("Prueba ContarOcurrencias 6");
	pruebaContarOcurrencias("(1, 1, 1, 1, 1, 1)");
	ver3("Prueba ContarOcurrencias 7");
	pruebaContarOcurrencias("(1, 10, 100, 1000)");
	ver3("Prueba ContarOcurrencias 8");
	pruebaContarOcurrencias("(4, 6, 4, 6, 4, 6, 4, 6)");
	ver3("Prueba ContarOcurrencias 9");
	pruebaContarOcurrencias("(1, 2, 1, 4, 2, 1, 4, 2, 7)");
	ver3("Prueba ContarOcurrencias 10");
	this->mImpresion.cerrarSeccion("PRUEBAS ContarOcurrencias");

	// Pruebas Xor
	this->mImpresion.iniciarSeccion("PRUEBAS Xor de multisets");
	pruebaXor("()", "()");
	ver3("Prueba Xor de multisets 1");  //()
	pruebaXor("(1,2,3)", "(3,2,1)");
	ver3("Prueba Xor de multisets 2");  //()
	pruebaXor("(1,2,3)", "()");
	ver3("Prueba Xor de multisets 3");  //(1,2,3)
	pruebaXor("()", "(3,2,1)");
	ver3("Prueba Xor de multisets 4");  //(3,2,1)
	pruebaXor("(1,3,4,7)", "(8,1,2,3)");  //(4,7,8,2)
	ver3("Prueba Xor de multisets 5");
	pruebaXor("(1,1,2)", "(1,2)");  //(1)
	ver3("Prueba Xor de multisets 6");
	pruebaXor("(1,1,2,3,3,3)", "(1,3)");  //(1,2,3,3)
	ver3("Prueba Xor de multisets 7");
	pruebaXor("(1,1,1)", "()");  //(1,1,1)
	ver3("Prueba Xor de multisets 8");
	pruebaXor("(1,1,1)", "(5)");  //(1,1,1,5)
	ver3("Prueba Xor de multisets 9");
	pruebaXor("(1,1,1,0)", "(1,1,1)");  //(0)
	ver3("Prueba Xor de multisets 10");
	this->mImpresion.cerrarSeccion("PRUEBAS Xor de multisets");

	// Pruebas parentesisBalanceados
	this->mImpresion.iniciarSeccion("PRUEBAS Paréntesis Balanceados");
	pruebaParentesisBalanceados("{(1,3),(4,5)}++{[1,3,4]}");
	ver3("Prueba parentesisBalanceados 1");
	pruebaParentesisBalanceados("((5*2)+(2-a)+b)");
	ver3("Prueba parentesisBalanceados 2");	
	pruebaParentesisBalanceados("((a&&b)||((!c)&&(d&&!e)))");
	ver3("Prueba parentesisBalanceados 3");	
	pruebaParentesisBalanceados("((a&&b)||((!c)&&(d&&!e))");
	ver3("Prueba parentesisBalanceados 4");	
	pruebaParentesisBalanceados("((a&&b)||((!c)))&&)(d&&!e");
	ver3("Prueba parentesisBalanceados 5");	
	pruebaParentesisBalanceados("())(");
	ver3("Prueba parentesisBalanceados 6");	
	pruebaParentesisBalanceados("{(1,3),(4,5)}++1,3,4]}");
	ver3("Prueba parentesisBalanceados 7");	
	pruebaParentesisBalanceados("[(1+3){]}");
	ver3("Prueba parentesisBalanceados 8");	
	pruebaParentesisBalanceados("[(13)+{1,2,3}]");
	ver3("Prueba parentesisBalanceados 9");	
	pruebaParentesisBalanceados("{[((({}+{})))]()})");
	ver3("Prueba parentesisBalanceados 10");
	this->mImpresion.cerrarSeccion("PRUEBAS Paréntesis Balanceados");

	// Pruebas ImprimirPorNiveles
	this->mImpresion.iniciarSeccion("PRUEBAS ImprimirPorNiveles AG");
	pruebaImprimirPorNivelesAG("{{}}");
	ver3("Prueba imprimir AG por niveles 1");
	
	pruebaImprimirPorNivelesAG("{{1,-7,5,#,15,#,#,3,#,4,8,34}}");
	ver3("Prueba imprimir AG por niveles 2");

	pruebaImprimirPorNivelesAG("{{1,-7,5,1,#,#,15,#,#,3,#,4,8,34,#,#,7,24,13,#,7,1,#,#,#,#,2}}");
	ver3("Prueba imprimir AG por niveles 3");

	this->mImpresion.cerrarSeccion("PRUEBAS ImprimirPorNiveles AG");
}

void PruebasEjemploDeUsoEntrega2::pruebaListaOrd()
{	
	this->mImpresion.iniciarSeccion("PRUEBAS LISTA ORD");

	
	ListaOrd<int>* l = new ListaOrdImp<int>();


	//cout << "------------------- Prueba agregar elemento ----------------------" << endl << endl << endl;

	l->AgregarOrd(5);
	l->AgregarOrd(3);
	l->AgregarOrd(3);
	l->AgregarOrd(6);
	l->AgregarOrd(6);
	l->AgregarOrd(1);
	l->AgregarOrd(4);
	l->AgregarOrd(2);
	l->AgregarOrd(1);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar 9 datos");

	
	//cout<<"--------------------Prueba largo de la lista-------------------"<<endl<<endl<<endl;
	
	cout << l->CantidadElementos()<<endl;
	ver3("Imprimo el largo de la lista");

	
	//cout<<"--------------------Prueba clon de la lista-------------------"<<endl<<endl<<endl;
	
	
	ListaOrd<int>* clonL = l->Clon();

	cout << "Resultado Original: " << endl << *l<< endl << endl;

	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo la lista original y su clon");
	////////////////////////////////////////////////////////////////////////////////////////
	ListaOrd<int>* listaIgual = l->CrearVacia();
	*listaIgual = *l;

	cout << "Resultado Original: " << endl << *l<< endl << endl;

	cout << "Resultado lista obtenida operador =: " << endl << *listaIgual << endl;

	ver3("Imprimo la lista original y la obtenida");
	//cout<<"--------------------Prueba == de la lista (iguales)-------------------"<<endl<<endl<<endl;

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}
	ver3("Imprimo prueba de == sobre listas iguales");

	//cout<<"--------------------Prueba == de la lista (diferentes)-------------------"<<endl<<endl<<endl;
	clonL->BorrarMinimo();

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}

	ver3("Imprimo prueba de == sobre listas distintas");

	//cout<<"--------------------Prueba elemento principio-------------------"<<endl<<endl<<endl;
	

	cout << l->Minimo()<<endl;
	ver3("Imprimo el principio de la lista");

	
	//cout<<"--------------------Prueba elemento fin-------------------"<<endl<<endl<<endl;
	

	cout << l->Maximo() <<endl;
	ver3("Imprimo el fin de la lista");

	
	//cout<<"--------------------Prueba eliminar elemento principio-------------------"<<endl<<endl<<endl;
	
	l->BorrarMinimo();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el principio");

	//cout<<"--------------------Prueba eliminar elemento fin-------------------"<<endl<<endl<<endl;
	
	l->BorrarMaximo();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el fin");

	//cout<<"--------------------Prueba eliminar elemento-------------------"<<endl<<endl<<endl;
	
	l->Borrar(3);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el elemento 3");

	
	//cout<<"--------------------Prueba recuperar elemento-------------------"<<endl<<endl<<endl;
	
	cout << l->Recuperar(2)<<endl;
	
	ver3("Imprimo la recuperación del elemento 2");

	//cout<<"---------------------Prueba elemento pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(2))
	{
		cout<<"Elemento 2 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 2 no pertenece a la lista"<<endl<<endl<<endl;
	}
	ver3("Imprimo si el elemento 2 existe en la lista");
	//cout<<"---------------------Prueba elemento no pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(6))
	{
		cout<<"Elemento 6 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 6 no pertenece a la lista"<<endl<<endl<<endl;
	}

	ver3("Imprimo si el elemento 6 existe en la lista");
	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista es vacia");
	/////////////////////////////////////////////////////////////////////////
	ListaOrd<int>* lVacia= l->CrearVacia();
	if(lVacia->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista creada es vacia ");
	delete lVacia;
	/////////////////////////////////////////////////////////////////////////
	if(l->EsLlena())
	{
		cout<<"La lista se encuentra llena"<<endl<<endl<<endl;
	}
	else
	{
		cout<<"La lista no se encuentra llena"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista esta llena");

	//cout<<"-------------------Prueba lista es vaciar ----------------------"<<endl<<endl<<endl;
	
	l->Vaciar();
	
	cout<<"["<<*l<<"]"<<endl<<endl<<endl;

	ver3("Imprimo la lista luego de vaciarla");

	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista es vacia");
	delete l;
	delete clonL;

	this->mImpresion.cerrarSeccion("PRUEBAS LISTA ORD");
}

void PruebasEjemploDeUsoEntrega2::pruebaListaOrd2()
{	
	this->mImpresion.iniciarSeccion("PRUEBAS LISTA ORD");

	
	ListaOrd<int>* l = new ListaOrdImp2<int>();


	//cout << "------------------- Prueba agregar elemento ----------------------" << endl << endl << endl;

	l->AgregarOrd(5);
	l->AgregarOrd(3);
	l->AgregarOrd(3);
	l->AgregarOrd(6);
	l->AgregarOrd(6);
	l->AgregarOrd(1);
	l->AgregarOrd(4);
	l->AgregarOrd(2);
	l->AgregarOrd(1);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de agregar 9 datos");

	
	//cout<<"--------------------Prueba largo de la lista-------------------"<<endl<<endl<<endl;
	
	cout << l->CantidadElementos()<<endl;
	ver3("Imprimo el largo de la lista");

	
	//cout<<"--------------------Prueba clon de la lista-------------------"<<endl<<endl<<endl;
	
	
	ListaOrd<int>* clonL = l->Clon();

	cout << "Resultado Original: " << endl << *l<< endl << endl;

	cout << "Resultado Clon: " << endl << *clonL << endl;

	ver3("Imprimo la lista original y su clon");
	////////////////////////////////////////////////////////////////////////////////////////
	ListaOrd<int>* listaIgual = l->CrearVacia();
	*listaIgual = *l;

	cout << "Resultado Original: " << endl << *l<< endl << endl;

	cout << "Resultado lista obtenida operador =: " << endl << *listaIgual << endl;

	ver3("Imprimo la lista original y la obtenida");
	//cout<<"--------------------Prueba == de la lista (iguales)-------------------"<<endl<<endl<<endl;

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}
	ver3("Imprimo prueba de == sobre listas iguales");

	//cout<<"--------------------Prueba == de la lista (diferentes)-------------------"<<endl<<endl<<endl;
	clonL->BorrarMinimo();

	if(*l==*clonL)
	{
		cout<<"La lista original es igual a la lista clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista original no es igual a la lista clon"<<endl<<endl<<endl;
	}

	ver3("Imprimo prueba de == sobre listas distintas");

	//cout<<"--------------------Prueba elemento principio-------------------"<<endl<<endl<<endl;
	//

	cout << l->Minimo()<<endl;
	ver3("Imprimo el principio de la lista");

	
	//cout<<"--------------------Prueba elemento fin-------------------"<<endl<<endl<<endl;
	

	cout << l->Maximo() <<endl;
	ver3("Imprimo el fin de la lista");

	
	//cout<<"--------------------Prueba eliminar elemento principio-------------------"<<endl<<endl<<endl;
	
	l->BorrarMinimo();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el principio");

	//cout<<"--------------------Prueba eliminar elemento fin-------------------"<<endl<<endl<<endl;
	
	l->BorrarMaximo();

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el fin");

	//cout<<"--------------------Prueba eliminar elemento-------------------"<<endl<<endl<<endl;
	
	l->Borrar(3);

	cout << *l <<endl;
	ver3("Imprimo la lista luego de eliminar el elemento 3");

	
	//cout<<"--------------------Prueba recuperar elemento-------------------"<<endl<<endl<<endl;
	
	cout << l->Recuperar(2)<<endl;
	
	ver3("Imprimo la recuperación del elemento 2");

	//cout<<"---------------------Prueba elemento pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(2))
	{
		cout<<"Elemento 2 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 2 no pertenece a la lista"<<endl<<endl<<endl;
	}
	ver3("Imprimo si el elemento 2 existe en la lista");
	//cout<<"---------------------Prueba elemento no pertenece ---------------------"<<endl<<endl<<endl;
	if(l->Existe(6))
	{
		cout<<"Elemento 6 pertenece  a la lista"<<endl<<endl<<endl;
	}else
	{
		cout<<"Elemento 6 no pertenece a la lista"<<endl<<endl<<endl;
	}

	ver3("Imprimo si el elemento 6 existe en la lista");
	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista es vacia");
	/////////////////////////////////////////////////////////////////////////
	ListaOrd<int>* lVacia= l->CrearVacia();
	if(lVacia->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista creada es vacia ");
	delete lVacia;
	/////////////////////////////////////////////////////////////////////////
	if(l->EsLlena())
	{
		cout<<"La lista se encuentra llena"<<endl<<endl<<endl;
	}
	else
	{
		cout<<"La lista no se encuentra llena"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista esta llena");

	//cout<<"-------------------Prueba lista es vaciar ----------------------"<<endl<<endl<<endl;
	
	l->Vaciar();
	
	cout<<"["<<*l<<"]"<<endl<<endl<<endl;

	ver3("Imprimo la lista luego de vaciarla");

	//cout<<"-------------------Prueba lista es vacia ----------------------"<<endl<<endl<<endl;
	
	if(l->EsVacia())
	{
		cout<<"La lista se encuentra vacia"<<endl<<endl<<endl;
	}else
	{
		cout<<"La lista no se encuentra vacia"<<endl<<endl<<endl;
	}	

	ver3("Imprimo si la lista es vacia");
	delete l;
	delete clonL;

	this->mImpresion.cerrarSeccion("PRUEBAS LISTA ORD");
}

void PruebasEjemploDeUsoEntrega2::pruebaTabla(){

	this->mImpresion.iniciarSeccion("PRUEBAS TABLA");

	Tabla<Cadena,int>* tablaAlCuadrado = new TablaImp<Cadena,int>();

	//cout << "------------------- Prueba agregar elemento ----------------------" << endl << endl << endl;

	tablaAlCuadrado->Insertar(Cadena("Dos"),4); 
	tablaAlCuadrado->Insertar(Cadena("Tres"),9); 
	tablaAlCuadrado->Insertar(Cadena("Cuatro"),16); 
	tablaAlCuadrado->Insertar(Cadena("Cinco"),25); 
	cout<<*tablaAlCuadrado<<endl;
	ver3("Imprimo la tabla luego de agregar cuatro elementos");

	//cout<<"--------------------Prueba cantidad de elementos-------------------"<<endl<<endl<<endl;
	
	cout << tablaAlCuadrado->CantidadElementos()<<endl;
	ver3("Imprimo la cantidad de elementos en la tabla ");

	
	//cout<<"--------------------Prueba clon de la tabla-------------------"<<endl<<endl<<endl;
	
	
	Tabla<Cadena,int>* tablaClon = tablaAlCuadrado->Clon();

	cout << "Resultado Original: " << endl << *tablaAlCuadrado<< endl << endl;

	cout << "Resultado Clon: " << endl << *tablaClon << endl;

	ver3("Imprimo la tabla y su clon");
	///////////////////////////////////////////////////////////////////////////
	Tabla<Cadena,int>* tablaIgual =  tablaAlCuadrado->CrearVacia();
	*tablaIgual = *tablaAlCuadrado;

	cout << "Resultado Original: " << endl << *tablaAlCuadrado<< endl << endl;

	cout << "Resultado tabla utilizando operador =: " << endl << *tablaIgual << endl;

	ver3("Imprimo la tabla y la tabla obtenida");
	//cout<<"--------------------Prueba == de la tabla (iguales)-------------------"<<endl<<endl<<endl;

	if(*tablaAlCuadrado==*tablaClon)
	{
		cout<<"La tabla original es igual a la tabla clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La tabla original no es igual a la tabla clon"<<endl<<endl<<endl;
	}
	ver3("Imprimo prueba de == sobre tablas iguales");

	//cout<<"--------------------Prueba == de la table (diferentes)-------------------"<<endl<<endl<<endl;
	tablaClon->Insertar(Cadena("Seis"),36);

	if(*tablaAlCuadrado==*tablaClon)
	{
		cout<<"La tabla original es igual a la tabla clon"<<endl<<endl<<endl;
	}else
	{
		cout<<"La tabla original no es igual a la tabla clon"<<endl<<endl<<endl;
	}

	ver3("Imprimo prueba de == sobre tablas distintas");

		
	//cout<<"--------------------Prueba esta definido (elemento definido) -------------------"<<endl<<endl<<endl;
	
	if(tablaAlCuadrado->EstaDefinida("Dos")){
		cout<<"Dos se encuentra definido en la tabla" <<endl;
	}else{
		cout<<"Dos no se encuentra definido en la tabla" <<endl;
	}
	ver3("Imprimo si Dos se encuentra definido en la tabla");

	
	//cout<<"--------------------Prueba esta definido (elemento no definido)-------------------"<<endl<<endl<<endl;
	
	if(tablaAlCuadrado->EstaDefinida("Uno")){
		cout<<"Uno se encuentra definido en la tabla" <<endl;
	}else{
		cout<<"Uno no se encuentra definido en la tabla" <<endl;
	}
	ver3("Imprimo si Uno se encuentra definido en la tabla");

	
	//cout<<"--------------------Prueba recuperar -------------------"<<endl<<endl<<endl;
	
	cout<< tablaAlCuadrado->Recuperar("Dos")<<endl;
	
	ver3("Imprimo la recuperación del elemento Dos");

//	cout<<"--------------------Prueba borrar -------------------"<<endl<<endl<<endl;
	
	tablaAlCuadrado->Borrar("Tres");
	cout<< *tablaAlCuadrado<<endl;
	
	ver3("Imprimo la tabla luego de borrar el elemento Tres");

	
	//cout<<"--------------------Prueba es vacia-------------------"<<endl<<endl<<endl;
	
	if(tablaAlCuadrado->EsVacia()){
		cout<<"La tabla se encuentra vacia" <<endl;
	}else{
		cout<<"La tabla no se encuentra vacia" <<endl;
	}

	ver3("Imprimo si la tabla es vacia");
	///////////////////////////////////////////////////////////////////////////////////

	Tabla<Cadena,int>* tablaCrearVacia =  tablaAlCuadrado->CrearVacia();
	if(tablaCrearVacia->EsVacia()){
		cout<<"La tabla se encuentra vacia" <<endl;
	}else{
		cout<<"La tabla no se encuentra vacia" <<endl;
	}

	ver3("Imprimo si la tabla creada  es vacia");
	
	///////////////////////////////////////////////////////////////////////////////////
	if(tablaCrearVacia->EsLlena()){
		cout<<"La tabla se encuentra llena" <<endl;
	}else{
		cout<<"La tabla no se encuentra llena" <<endl;
	}

	ver3("Imprimo si la tabla creada  se encuentra llena");
	delete tablaCrearVacia;
	//cout<<"--------------------Prueba vaciar -------------------"<<endl<<endl<<endl;
	
	tablaAlCuadrado->Vaciar();
	cout<<"["<< *tablaAlCuadrado<<"]"<<endl;
	
	ver3("Imprimo la tabla luego de vaciarla");

	//cout<<"--------------------Prueba es vacia-------------------"<<endl<<endl<<endl;
	
	if(tablaAlCuadrado->EsVacia()){
		cout<<"La tabla se encuentra vacia" <<endl;
	}else{
		cout<<"La tabla no se encuentra vacia" <<endl;
	}

	ver3("Imprimo si la tabla es vacia");

	delete tablaClon;
	delete tablaAlCuadrado;
	this->mImpresion.cerrarSeccion("PRUEBAS TABLA");

}

void PruebasEjemploDeUsoEntrega2::pruebaMultiSet()
{
	this->mImpresion.iniciarSeccion("PRUEBAS MULTISET");

	MultiSet<int>* multiset = new MultiSetImp<int>();

	//cout << "------------------- Prueba MultiSet agregar ----------------------" << endl << endl << endl;
	for (int i = 1; i <= 5; i++)
	{
		multiset->Insertar(i,1);
	}
	for (int i = 1; i <= 5; i += 2)
	{
		multiset->Insertar(i,2);
	}
	cout << *multiset << endl;
	ver3("Imprimo la Multiset luego de agregar 10 datos se espera que la cantidad de elementos sea 5");

	// prueba elminar elemento
	int elem = 2;
	Cadena c = elem != NULL ? "True" : "False";
	cout << elem << "- Es null?: " << c << endl;
	multiset->Borrar(elem,1);
	cout << *multiset << endl;
	ver3("Imprimo el Multiset luego de eliminar una ocurrencia del elemento 2");

	elem = 1;
	c = elem != NULL ? "True" : "False";
	cout << elem << "- Es null?: " << c << endl;
	multiset->Borrar(elem,2);
	cout << *multiset << endl;
	ver3("Imprimo el Multiset luego de eliminar dos ocurrencias del elemento 1");

	//cout << "------------------- Prueba MultiSet cantidad de ocurrencias ----------------------" << endl << endl << endl;

	cout << "Cantidad Ocurrencias del 3: " << multiset->OcurrenciasElemento(3) << " == 3" << endl;
	ver3("Muestro la cantidad de ocurrencias de un elemento");

	//cout << "------------------- Prueba MultiSet no vacio ----------------------" << endl << endl << endl;

	c = multiset->EsVacia() ? "True" : "False";
	cout << "Es Vacio: " << c << " == False" << endl;
	ver3("Muestro que el multiset no es vacio");

	//cout << "---------------------Prueba Clon MultiSet ----------------------" << endl << endl << endl;

	MultiSet<int> *clon = multiset->Clon();

	cout << "Resultado Original: " << endl << *multiset << endl;
	cout << "Resultado Clon: " << endl << *clon << endl;
	ver3("Clono el multiset y imprmio el original y el clon");

	//cout << "---------------------Prueba la operacion asignacion multiset ----------------------" << endl << endl << endl;

	MultiSet<int> *asg = new MultiSetImp<int>();
	*asg = *multiset;
	cout << "Resultado Original: " << endl << *multiset << endl;
	cout << "Resultado Clon: " << endl << *asg << endl;
	ver3("Asigno un nuevo multiset y imprimo la original y la asignada");

	//cout << "---------------------Prueba == MultiSet ----------------------" << endl << endl << endl;

	c = (*multiset == *clon) ? "True" : "False";

	cout << "Es Igual: " << c << " == True" << endl;
	ver3("Muestro que el set clon y el original son iguales");

	//cout << "---------------------Prueba vaciar MultiSet ----------------------" << endl << endl << endl;

	multiset->Vaciar();

	cout << *multiset << endl;
	c = multiset->EsVacia() ? "True" : "False";
	cout << "Es Vacia: " << c << " == True" << endl;
	ver3("Vacio el multiset y lo imprimo, verifico que sea vacio");

	//cout << "---------------------Prueba Crear Vacia MultiSet ----------------------" << endl << endl << endl;

	cout << *multiset << endl;
	MultiSet<int> *vacia = multiset->CrearVacia();
	c = vacia->EsVacia() ? "True" : "False";
	cout << "El set es vacio MultiSet: " << c << " == True" << endl;
	ver3("Creo un multiset usando CrearVacia y muestro que es vacio");

	//cout << "--------------Prueba CantidadElementos MultiSet --------------" << endl << endl << endl;

	cout << "Resultado MultiSet Original: " << multiset->Cardinal() << " == 0" << endl;
	cout << "Resultado MultiSet Clon: " << clon->Cardinal() << " == 4" << endl;
	ver3("Muestro la cantidad de elementos del multiset original y el clon");

	MultiSet<int> *recuperar = clon->Clon();
	
	elem = 4;
	int recuperado = recuperar->Recuperar(elem);
	c = elem == recuperado ? "True" : "False";
	cout << elem << " == " << recuperado << " Elemento recuperado igual al elemento esperado: " << c << endl;
	ver3("Imprimo un elemento del set recuperado");

	elem = 100;
	c = recuperar->Pertenece(elem) ? "True" : "False";
	cout << "El elemento " << elem << " pertence al multiset: " << c << " == False" << endl;
	ver3("Imprimo un elemento del multiset recuperado y pregunto si pertenece");

	bool correcto = true;
	while (!recuperar->EsVacia())
	{
		elem = recuperar->Elemento();
		correcto = correcto && recuperar->Pertenece(elem);
		recuperar->Borrar(elem, 1);
	}
	c = correcto ? "True" : "False";
	cout << "Todos los elementos pertenecen del multiset " << c << " == True" << endl;
	ver3("Pregunto si todos los elementos pertenecen al multiset");

	MultiSet<int> *unionParteA = new MultiSetImp<int>();
	unionParteA->Insertar(1,1);
	unionParteA->Insertar(2,1);
	MultiSet<int> *unionParteB = new MultiSetImp<int>();
	unionParteB->Insertar(3, 1);
	unionParteB->Insertar(2, 2); //aa
	MultiSet<int> *unionAB = unionParteA->Union(*unionParteB);
	MultiSet<int> *unionReferencia = new MultiSetImp<int>();
	unionReferencia->Insertar(2, 2);
	unionReferencia->Insertar(1, 1);
	unionReferencia->Insertar(3, 1);
	cout << "Se espera: " << *unionReferencia << endl;
	cout << "Se obtiene:" << *unionAB << endl;
	ver3("Pruebo la union entre dos multiset");

	MultiSet<int> *interseccionParteA = new MultiSetImp<int>();
	interseccionParteA->Insertar(1, 2);
	interseccionParteA->Insertar(2, 2);
	MultiSet<int> *interseccionParteB = new MultiSetImp<int>();
	interseccionParteB->Insertar(3, 1);
	interseccionParteB->Insertar(2, 3);
	MultiSet<int> *interseccionAB = interseccionParteA->Interseccion(*interseccionParteB);
	MultiSet<int> *interseccionReferencia = new MultiSetImp<int>();
	interseccionReferencia->Insertar(2, 2);
	cout << "Se espera: " << *interseccionReferencia << endl;
	cout << "Se obtiene:" << *interseccionAB << endl;
	ver3("Pruebo la Interseccion entre dos multiset");

	interseccionParteA->Vaciar();
	interseccionParteA->Insertar(1, 3);
	interseccionParteA->Insertar(2, 2);
	interseccionParteA->Insertar(3, 3);
	interseccionParteB->Vaciar();
	interseccionParteB->Insertar(1, 1);
	interseccionParteB->Insertar(2, 3);
	interseccionParteB->Insertar(3, 2);
	interseccionAB->Vaciar();
	interseccionAB = interseccionParteA->Interseccion(*interseccionParteB);
	interseccionReferencia->Vaciar();
	interseccionReferencia->Insertar(1, 1);
	interseccionReferencia->Insertar(2, 2);
	interseccionReferencia->Insertar(3, 2);
	cout << "Se espera: " << *interseccionReferencia << endl;
	cout << "Se obtiene:" << *interseccionAB << endl;
	ver3("Segunda prueba  Interseccion entre dos multiset");


	MultiSet<int> *diferenciaParteA = new MultiSetImp<int>();
	diferenciaParteA->Insertar(1, 2);
	diferenciaParteA->Insertar(2, 3);
	diferenciaParteA->Insertar(3, 1);
	MultiSet<int> *diferenciaParteB = new MultiSetImp<int>();
	diferenciaParteB->Insertar(3, 2);
	diferenciaParteB->Insertar(2, 1);
	MultiSet<int> *diferenciaAB = diferenciaParteA->Diferencia(*diferenciaParteB);
	MultiSet<int> *diferenciaReferencia = new MultiSetImp<int>();
	diferenciaReferencia->Insertar(1, 2);
	diferenciaReferencia->Insertar(2, 2);
	cout << "Se espera: " << *diferenciaReferencia << endl;
	cout << "Se obtiene:" << *diferenciaAB << endl;
	ver3("Pruebo la Diferencia entre dos multiset");

	MultiSet<int> *contenidoA = new MultiSetImp<int>();
	contenidoA->Insertar(1, 2);
	contenidoA->Insertar(2, 1);
	MultiSet<int> *contenidoB = new MultiSetImp<int>();
	contenidoB->Insertar(3, 1);
	contenidoB->Insertar(2, 2);
	contenidoB->Insertar(1, 3);
	cout << "MultiSet A: " << *contenidoA << endl;
	cout << "MultiSet B:" << *contenidoB << endl;
	cout << "A contenidoEn B:" << contenidoA->ContenidoEn(*contenidoB) << " == True" << endl;
	cout << "B contenidoEn A:" << contenidoB->ContenidoEn(*contenidoA) << " == False" << endl;
	cout << "A contenidoEn A:" << contenidoA->ContenidoEn(*contenidoA) << " == True" << endl;
	ver3("Pruebo  ContendioEn entre dos multiset");


	contenidoA->Vaciar();
	contenidoA->Insertar(4, 2);
	contenidoA->Insertar(5, 1);
	contenidoA->Insertar(6, 1);
	contenidoB->Vaciar();
	contenidoB->Insertar(4, 2);
	contenidoB->Insertar(5, 2);
	contenidoB->Insertar(6, 3);
	cout << "MultiSet A: " << *contenidoA << endl;
	cout << "MultiSet B:" << *contenidoB << endl;
	cout << "A contenidoEn B:" << contenidoA->ContenidoEn(*contenidoB) << " == True" << endl;
	cout << "B contenidoEn A:" << contenidoB->ContenidoEn(*contenidoA) << " == False" << endl;
	cout << "A contenidoEn A:" << contenidoA->ContenidoEn(*contenidoA) << " == True" << endl;
	ver3("Pruebo la ContendioEn entre dos multiset");

	delete multiset;
	delete clon;
	delete vacia;
	delete recuperar;

	delete unionParteA;
	delete unionParteB;
	delete unionAB;
	delete unionReferencia;

	delete interseccionParteA;
	delete interseccionParteB;
	delete interseccionAB;
	delete interseccionReferencia;
	
	delete diferenciaParteA;
	delete diferenciaParteB;
	delete diferenciaAB;
	delete diferenciaReferencia;

	delete contenidoA;
	delete contenidoB;

	this->mImpresion.cerrarSeccion("PRUEBAS MULTISET");
}