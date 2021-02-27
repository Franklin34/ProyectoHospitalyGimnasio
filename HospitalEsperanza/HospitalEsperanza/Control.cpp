#include "Control.h"
#include "Control.h"
#include "Paciente.h"
#include <iostream>

using namespace std;

void Control::controlPrincipal()
{
	Pabellon* p = new Pabellon();
	Contenedor* d = new Contenedor;
	Contenedor3 *f = new Contenedor3;
	Contenedor2 e;
	Doctor* u = new Doctor();
	int opc;
	int valor = 0;
	do {
		cin.clear();
		system("cls");
		cout << "**************************" << endl;
		cout << "*   Hospital Esperanza  *" << endl;
		cout << "**************************" << endl;
		cout << " 1- Especialidad " << endl;
		cout << " 2- Doctores " << endl;
		cout << " 3- Camas " << endl;
		cout << " 4- Pacientes" << endl;
		cout << " 5- Salir" << endl << endl;
		cout << "Digite la opcion que desea realizar: ";
		cin.clear();
		cin >> opc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}

		switch (opc) {
		case 1:
			menuespecialidad(d);
			system("pause");
			break;
		case 2:
			menudoctor(d,u,f);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "*    Hospital Esperanza  *" << endl;
			menucamas(p, d, e, f);
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "*    Hospital Esperanza  *" << endl;
			menupacientes(p, d, e, f);
			system("pause");
			break;
         }
	} while (opc != 5);
	
	delete p;
	delete f;
	delete u;
	delete d;
}
string Control::imprimeDoctor(Contenedor *con)
{
	return con->imprimeDoctores();
}
string Control::imprimenombredeldoctor(Contenedor*g)
{
	return g->imprimeNombresdeldoctor();
}
string Control::imprimeEspecialidad(Contenedor* cin) {
	return cin->imprimeEspecialidad();
}

string Control::imprimecamas(Pabellon *sdf)
{
	return sdf->imprimacamas();
}
bool Control::insertaDoctor(Contenedor* con)
{

	string id, nombre, especialidad;
	int edad;
	cout << "\nDigite el nombre del Doctor: ";
	cin.ignore();
	getline(cin, nombre);
	cout << "\nDigite la edad del doctor:  ";
	cin.clear();
	cin >> edad;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Wrong! Enter a #!" << endl;
		return 0;
	}
	cin.ignore();
	cout << "\nDigite especialidad del Doctor: ";
	cin >> especialidad;
	if (con->eliminaDoctor(especialidad) == false) {
		cout << "Esta especialidad no se encuentra en este Hospital" << endl;
		return 0;
	}
	cout << "\nDigite el ID del Doctor: ";
	cin >> id;
	if (con->rechazaDoctor(id) == true) {
		cout << "El doctor ya se encuentra ingresado" << endl;
		return 0;
	}
	Doctor* d = new Doctor(nombre, edad, especialidad, id, false);
	if (con->insertaDoctor(d)) {
		return true;
	}
	else {
		return false;
	}
	

}

bool Control::insertaEspecialidad(Contenedor*cxz)
{
	string especialidad;
	cout << "Dijite la especialidad: ";
	cin >> especialidad;

	Especialidad *e = new Especialidad(especialidad);
	if (cxz->insertarEspecialidad(e)) {
		return true;
	}
	else {
		return false;
	}
	
}

bool Control::insertarcama(Pabellon* cd, Contenedor3* k,Contenedor *y)
{
	cout << "Puede ingresar un total de " << 20 - cd->getCantCamas() <<" camas"<< endl;
	int opc;
	cout << "En que estado desea poner la cama(0 = Desocupado y 1 = Ocupada): ";
	cin >> opc;
	Cama* c1 = new Cama();
	Doctor* d1 = new Doctor();
	if (opc == 0)
	{
		c1->setEstado(false);
		c1->setNombre("Sin asignar");
		cd->insertarCama(c1);
		cout << endl;
		cout << "Una cama ha sido insertada" << endl;
	}
	else if(opc == 1)
	{
		c1->setEstado(true);
		string nombre, id, apellidos, direccion, cirugia, fecha, doctor, prioridad, cama, patologia;
		bool estado;
		system("cls");
		cout << "Dijite los datos del paciente: " << endl << endl;

		cout << "Dijite el nombre del paciente: ";
		cin >> nombre;
		cout << "Dijite el ID del paciente: ";
		cin >> id;
		if (k->rechazar(id) == true) {
			cout << "El Paciente ya se encuentra ingresado" << endl;
			return 0;
		}
		cout << "Dijite los apellidos del paciente: ";
		cin.ignore();
		getline(cin, apellidos);
		cout << "Dijite la direccion del paciente: ";
		cin.ignore();
		getline(cin, direccion);
		cout << "Dijite el tipo de cirugia del paciente: ";
		cin >> cirugia;
		cout << "Dijite la fecha: ";
		cin >> fecha;
		cout << "Diijite el doctor del paciente: ";
		cin.ignore();
		getline(cin, doctor);
		if (y->rechazaPaciente(doctor) == false) {
			cout << "El doctor no se encuentra ingresado" << endl;
			return 0;
		}
		cout << "Dijite la prioridad del paciente: ";
		cin >> prioridad;
		cout << "Dijite la patologia del pacciente: ";
		cin >> patologia;
		cout << "Dijite la cama del paciente: ";
		cin >> cama;
		Paciente *i = new Paciente(id, nombre, apellidos, direccion, patologia, cirugia, true, prioridad, fecha, cama, doctor);
		c1->setNombre(nombre);
		cout << endl;
		cout << "Paciente Asignado" << endl;
		cout << endl;
		y->cambiarestadopaciente(doctor);
		d1->setPacientes(true);
		cd->insertarCama(c1);
		cout << "Una cama ha sido insertada" << endl;

		if (k->insertarpaciente(i)) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		cout << "Opcion invalida";
		return false;
	}
	
	
}

void Control::eliminarcama(Pabellon*f,Contenedor2&r)
{
	char x;
	cout << "Dijite el pabellon para eliminar cama: ";
	cin >> x;
	if (r.buscarpabellon(x)->existeCamas() == true) {
		cout << r.toString() << endl;
		cout << "Dijite el codigo de cama a eliminar: ";
		string y;
		cin >> y;
		if (f->eliminacama(y) == true) {
			cout << "CAMA ELIMINADA" << endl; 
		}
		else {
			cout << "LA CAMA ESTA OCUPADA" << endl;
		}
	}
	else {
		cout << "No hay camas ingresadas" << endl;
		return;
	}
	
}

void Control::menuespecialidad(Contenedor* c)
{
	int opc2;
	do {
		system("cls");
		cout << "**************************" << endl;
		cout << "*    Hospital Esperanza  *" << endl ;
		cout << "**************************" << endl << endl;
		cout << " 1- Ingresar especialidad" << endl;
		cout << " 2- Lista de especialidades" << endl;
		cout << " 3- Mostrar médicos por especialidad" << endl;
		cout << " 4- Regresar menu principal" << endl << endl;
		cout << "Digite la opcion que desea realizar: ";
		cin.clear();
		cin >> opc2;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}
		switch (opc2) {
		case 1: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*    Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			if (insertaEspecialidad(c) == true) {
				cout << "Especialidad incluida" << endl;
			}
			else {
				cout << "Las especialidades llegaron a su limite" << endl;
			}
			system("pause");
			break; }
		case 2: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*    Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << imprimeEspecialidad(c) << endl;
			system("pause");
			break; }
		case 3: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*    Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << imprimedoctorporespecialidad(c) << endl;
			system("pause");
			break; }
		} 
	} while (opc2 != 4);
}

void Control::menudoctor(Contenedor*a,Doctor*y,Contenedor3*e)
{
	int opc3;
	do {
		system("cls");
		cout << "**************************" << endl;
		cout << "*   Hospital Esperanza  *" << endl;
		cout << "**************************" << endl << endl;
		cout << " 1- Ingresar Doctor" << endl;
		cout << " 2- Lista de doctores" << endl;
		cout << " 3- Informe detalle del doctor" << endl;
		cout << " 4- Buscar doctor para ver sus pacientes" << endl;
		cout << " 5- Renuncia o despido del doctor" << endl;
		cout << " 6- Regresar menu principal" << endl << endl;
		cout << "Digite la opcion que desea realizar: ";
		cin.clear();
		cin >> opc3;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}
		switch (opc3) {
		case 1: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			if (insertaDoctor(a)) {
				cout << "Doctor ingresado" << endl;
			}
			else {
				cout << "Los Doctores estan completos" << endl;
			}
			system("pause");
			break; }
		case 2: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << imprimenombredeldoctor(a) << endl;
			system("pause");
			break; }
		case 3: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << imprimeDoctor(a) << endl;
			system("pause");
			break; }
		case 4: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << imprimirpacientesdeldoctor(e);
			system("pause");
			break; }
		case 5:
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			despidedoctor(a);
			system("pause");
			break;
		}
	} while (opc3 != 6);

}

void Control::menucamas(Pabellon* p, Contenedor* d, Contenedor2& e, Contenedor3* f)
{
	int opc4;
	do {
		system("cls");
		cout << "**************************" << endl;
		cout << "*   Hospital Esperanza  *" << endl;
		cout << "**************************" << endl << endl;
		cout << " 1- Ingresar cama a Pabellon" << endl;
		cout << " 2- Eliminar cama" << endl;
		cout << " 3- Informe Pabellones y sus camas" << endl;
		cout << " 4- Regresar menu principal" << endl << endl;
		cout << "Digite la opcion que desea realizar: ";
		cin.clear();
		cin >> opc4;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}
		switch (opc4) {
		case 1: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			if (escogerPabellon(e))
			{
				p = escogerPabellon(e);
				insertarcama(p, f, d);
			}
			else
			{
				cout << "No existe ese pabellon" << endl;
			}
			system("pause");
			break; }
		case 2: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			eliminarcama(p, e);
			system("pause");
			break; }
		case 3: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << e.toString() << endl;
			system("pause");
			break; }
		} 

	} while (opc4 != 4);
}
void Control::menupacientes(Pabellon*p, Contenedor*d, Contenedor2&e, Contenedor3*f)
{
	int opc4;
	do {
		system("cls");
		cout << "**************************" << endl;
		cout << "*   Hospital Esperanza  *" << endl;
		cout << "**************************" << endl << endl;
		cout << " 1- Ingresar paciente a cama desocupada" << endl;
		cout << " 2- Informe general de pacientes" << endl;
		cout << " 3- Informe estado paciente especifico" << endl;
		cout << " 4- Dar de alta al paciente" << endl;
		cout << " 5- Cambiar de cama a paciente" << endl;
		cout << " 6- Cambiar de Doctor a Paciente" << endl;
		cout << " 7- Regresar menu principal" << endl << endl;
		cout << "Digite la opcion que desea realizar: ";
		cin.clear();
		cin >> opc4;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}
		switch (opc4) {
		case 1: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			if (escogerPabellon(e))
			{
				p = escogerPabellon(e);
				insertaPaciente(e, d, p, f);
			}
			else
			{
				cout << "No existe ese pabellon" << endl;
			}
			
			system("pause");
			break; }
		case 2: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << imprimepaciente(f) << endl;
			system("pause");
			break; }
		case 3: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cout << buscapaciente(f) << endl;
			system("pause");
			break; }
		case 4: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			if (escogerPabellon2(e))
			{
				p = escogerPabellon2(e);
				dardealtapaciente(f, p, e);
			}
			else
			{
				cout << "No existe ese pabellon" << endl;
			}
			
			system("pause");
			break;}
		case 5: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			if (escogerPabellon2(e))
			{
				p = escogerPabellon2(e);
				cambiarcama(p, e, f, d);
			}
			else
			{
				cout << "No existe ese pabellon" << endl;
			}
			
			system("pause");
			break; }
		case 6: {
			system("cls");
			cout << "**************************" << endl;
			cout << "*   Hospital Esperanza  *" << endl;
			cout << "**************************" << endl << endl;
			cambiarDoctor(*f, d);
			system("pause");
			break;
		}
		}

	} while (opc4 != 7);
}
string Control::imprimedoctorporespecialidad(Contenedor*f)
{
	return f->imprimedoctorporespecialidad();
}

string Control::imprimepaciente(Contenedor3*j)
{
	return j->imprimepacientes();
}

void Control::dardealtapaciente(Contenedor3*s,Pabellon*o,Contenedor2&r)
{
	system("cls");
	cout << r.toString() << endl;
	cout << "Dijite el codigo de cama donde se encuentra el paciente: ";
	string y;
	cin >> y;
	if (o->eliminacama2(y) == true) {
		cout << "Cama eliminada" << endl << endl;
	}
	else {
		cout << "La cama esta desocupada" << endl << endl;
		return;
	}
	
	cout << "Dijite el ID del paciente para dar de alta: ";
	string z;
	cin >> z;
	if (s->dardealta(z,o) == true) {
		cout << "Paciente dado de Alta" << endl;
	}
	else {
		cout << "Paciente no encontrado" << endl;
	}
}

void Control::despidedoctor(Contenedor* d)
{
	cout << "Dijite el nombre del doctor a despedir: ";
	string x;
	cin >> x;
	if (d->despedirdoctor(x) == true) {
		cout << "Doctor despedido" << endl;
	}
	else {
		cout << "No se puede eliminar el doctor porque tiene pacientes asignados" << endl;
	}
}

void Control::cambiarDoctor(Contenedor3&d, Contenedor*v)
{
	cout << d.imprimenombres() << endl;
	cout << "Dijiite el ID del paciente para cambiar el doctor: ";
	string id;
	cin >>id;
	if (d.existepacientes(id) == true) {
		cout << "Dijite el nombre del nuevo doctor para el paciente: ";
		string doc;
		cin >> doc;
		if (v->rechazaPaciente(doc) == true) {
			d.cambiardedoctor(id,doc);
			v->cambiarestadopaciente(doc);
		}
		else {
			cout << "Doctor no encontrado";
		}
	}

}
bool Control::cambiarcama(Pabellon* d, Contenedor2& r, Contenedor3* k, Contenedor* y)
{
	cout << r.toString() << endl;
	cout << "Dijite el codigo de cama donde se encuentra el paciente: ";
	string e;
	cin >> e;
	if (d->cambiarcama2(e) == true) {
		cout << "Cama liberada" << endl << endl;
	}
	else {
		cout << "La cama esta desocupada" << endl << endl;
		return false;
	}
	if (escogerPabellon2(r))
	{
		d = escogerPabellon2(r);
		cout << r.toString() << endl;
		cout << "Dijite el nombre del paciente a cambiar de cama: ";
		string q;
		cin >> q;
		cout << "Dijite el codijo de cama para cambiar el paciente: ";
		string o;
		cin >> o;
		if (d->cambiar(q, o) == true) {
			cout << "Paciente cambiado de cama";
		}
		else {
			"La cama esta ocupada";
		}
	}
	else
	{
		cout << "No existe ese pabellon" << endl;
	}	
}

bool Control::insertaPaciente(Contenedor2&k,Contenedor*y,Pabellon*sd,Contenedor3*l)
{
	Cama* c1 = new Cama;
	Doctor* d1 = new Doctor();
	string x;
	system("cls");
	cout << k.toString() << endl;
	cout << "Dijite el codigo de cama para dijitar el paciente: ";
	string c;
	cin >> c;
	if (sd->camasdisp(c) == true) {
		string nombre, id, apellidos, direccion, cirugia, fecha, doctor, prioridad, cama, patologia;
		bool estado;
		Cama* c1 = new Cama;
		cout << "Dijite los datos del paciente: " << endl << endl;

		cout << "Dijite el nombre del paciente: ";
		cin >> nombre;
		cout << "Dijite el ID del paciente: ";
		cin >> id;
		if (l->rechazar(id) == true) {
			cout << "El Paciente ya se encuentra ingresado" << endl;
			return 0;
		}
		cout << "Dijite los apellidos del paciente: ";
		cin >> apellidos;
		cout << "Dijite la direccion del paciente: ";
		cin >> direccion;
		cout << "Dijite el tipo de cirugia del paciente: ";
		cin >> cirugia;
	    cout << "Dijite la fecha: ";
		cin >> fecha;
		cout << "Diijite el doctor del paciente: ";
		cin >> doctor;
	    if (y->rechazaPaciente(doctor) == false) {
			cout << "El doctor no se encuentra ingresado" << endl;
			return 0;
		}
		cout << "Dijite la prioridad del paciente: ";
		cin >> prioridad;
		cout << "Dijite la patologia del pacciente: ";
		cin >> patologia;
		cout << "Dijite la cama del paciente: ";
		cin >> cama;
		Paciente *i = new Paciente(id, nombre, apellidos, direccion, patologia, cirugia, true, prioridad, fecha, cama, doctor);
		cout << "Paciente Asignado" << endl;
		d1->setPacientes(true);
		y->cambiarestadopaciente( doctor);
		sd->cambiarcama(c1, nombre);
		cout << "Una cama ha sido modificada" << endl;
	    if (l->insertarpaciente(i)) {
		     return true;
		}
		else
		{
			return false;
		}
	}
	else {
		cout << "La cama esta ocupada" << endl;
		return false;
	}
}

string Control::buscapaciente(Contenedor3*f)
{
	cout << "Dijite el ID del paciente: ";
	string x;
	cin >> x;
	return f->buscarPaciente(x);
}

string Control::imprimirpacientesdeldoctor(Contenedor3*g)
{
	Doctor* p = new Doctor();
	cout << "Dijite el nombre del doctor para ver sus pacientes: ";
	string y;
	cin >> y;
	return g->listadepacientespordoctor(y);
}

Pabellon* Control::escogerPabellon(Contenedor2& cont)
{
	cout << "Digite la letra correspondiente al pabellon: " ;
	char opc;
	cin >> opc;
	opc = toupper(opc);
	for (int i = 0; i < 10; i++)
	{
		if (cont.getPabellones(i)->getCodigo() == opc)
		{

			return cont.getPabellones(i);
		}
	}
	return nullptr;
}

Pabellon* Control::escogerPabellon2(Contenedor2& cont)
{
	cout << "Digite la letra correspondiente al pabellon donde se encuentra el paciente: " ;
	char opc;
	cin >> opc;
	opc = toupper(opc);
	for (int i = 0; i < 10; i++)
	{
		if (cont.getPabellones(i)->getCodigo() == opc)
		{

			return cont.getPabellones(i);
		}
	}
	return nullptr;
}



