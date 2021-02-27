#include "Control.h"

Control::Control()
{
	datos = false;
	contador = 1;
}

Instructor* Control::DatosInstructor(ListaInstrutor *o)
{
	string nombre;
	string id; 
	string telefono;

	cout << "Dijite el nombre del instructor: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "Dijite la Identificacion del instructor: ";
	cin >> id;

	if (o->rechazarInstructor(id) == true) {
		cout << endl;
		cout << "El Instructor Ya esta Ingresado " << endl;
		cout << endl;
		rechazarDatos(false);
		return NULL;
		
	}

	cout << "Dijite el # de telefono del instructor: ";
	cin >> telefono;

	Instructor* p = new Instructor(nombre, id, telefono);
	rechazarDatos(true);

	return p;
}

Socio* Control::DatosSocio(ListaInstrutor* p,FechaHora *j)
{
	string nombre, id, telefono, correo, fechadeInsc, Idinstructor;

	cout << "Dijite el nombre del Socio: ";
	cin.ignore();
	getline(cin, nombre);

	cout << "Dijite la Identificacion del Socio: ";
	cin >> id;

	cout << "Dijite el # de telefono del Socio: ";
	cin >> telefono;

	cout << "Dijite el Correo electronico del Socio: ";
	cin >> correo;

	cout << "Dijite el ID del Instructor: ";
	cin >> Idinstructor;

	if (p->rechazarInstructor(Idinstructor) == false) {
		cout << endl;
		cout << "El Instructor NO EXISTE " << endl;
		cout << endl;
		rechazarDatos(false);
		return NULL;
		
	}

	Socio* t = new Socio(nombre, id, telefono, correo, j->getFecha(),Idinstructor);
	rechazarDatos(true);

	return t;
}

Rutina* Control::DatosRutina(ListaSocio* k,Socio *p,ListaInstrutor*ñ, ListaEjercicio*v)
{
	cout << "Dijite el ID del Socio: ";
	string id;
	cin >> id;

	if (k->existeSocio(id) == true) {

		system("cls");

		cout << "------------------------------------" << endl;
		cout << "--------Gimnasio Vital Salud--------" << endl;
		cout << "------------------------------------" << endl << endl;

		cout << "Nombre del Socio: " << k->devolverNombre(id) << endl;
		cout << "Rutina numero: " << contador << endl;

		
		p->setTamano(+1);

		string codijo, ejercicio, objetivo, fechaFinalizacion, fechaCreacion, instrucciones, parte;
		int series, repeticiones;

		cout << "Fecha de inicio: ";
		int dia, mes1, anno;
		
		cout << endl;

		bool b = true;
		

		while(b == true){

			dia = 0;
			cout << "Dia: ";
			cin >> dia;

			if (dia > 31) {
				cout << "Dia no disponible" << endl;
				system("pause");
				b = true;
			}
			else if (dia <= 31) {
				b = false;
			}
		}

		b = true;

		while (b == true) {

			mes1 = 0;
			cout << "Mes: ";
			cin >> mes1;

			if (mes1 > 12) {
				cout << "Mes no disponible" << endl;
				system("pause");
				b = true;
			}
			else if (mes1 <= 12) {
				b = false;
			}
		}

		b = true;

		cout << "Anno: ";
		cin >> anno;

		stringstream x;
		x << dia << "/" << mes1 << "/" << anno;
		fechaCreacion = x.str();

		int mes2 = 0;

		cout << "Fecha de Vencimiento: ";

		cout << "Debe ser Dos meses despues de la creada";

		cout << endl;

		bool l = true;


		while (l == true) {

			dia = 0;
			cout << "Dia: ";
			cin >> dia;

			if (dia > 31) {
				cout << "Dia no disponible" << endl;
				system("pause");
				l = true;
			}
			else if (dia <= 31) {
				l = false;
			}
		}

		l = true;

	

		stringstream xy;

		if (mes1 == 11) {
			xy << dia << "/" << 01 << "/" << anno + 1;
		}
		else if (mes1 == 12) {
			xy << dia << "/" << 02 << "/" << anno + 1;
		}
		else if(mes1<11){
			xy << dia << "/" << mes1 + 2 << "/" << anno;
		}

		fechaFinalizacion = xy.str();

		cout << "Objetivo: ";
		cin.ignore();
		getline(cin, objetivo);


		ListaEjercicio* kl = new ListaEjercicio();

		bool pregunta = true;

		while (pregunta) {


			cout << "Parte del cuerpo(pierna, pecho, espala, hombro, tríceps,  bíceps,  trapecio,  antebrazo) :";
			cin >> parte;


			cout << "Nombre del Ejercicio: ";
			cin.ignore();
			getline(cin, ejercicio);
			cout << "Series: ";
			cin >> series;
			cout << "Repeticiones: ";
			cin >> repeticiones;
			
			

			Ejercicio* eje = new Ejercicio(parte, ejercicio, series, repeticiones);
			
			kl->insertarEjercicio(eje);


			cout << "Desea ingresar otro ejercicio ( s/n )";
			string opc;
			cin >> opc;

			if (opc == "n") {

				pregunta = false;

				system("cls");

				cout << "------------------------------------" << endl;
				cout << "--------Gimnasio Vital Salud--------" << endl;
				cout << "------------------------------------" << endl << endl;

				cout << "Rutina numero: " << contador << endl;
				cout << "Fecha de inicio: " << fechaCreacion << endl;
				cout << "Fecha de Vencimiento: " << fechaFinalizacion << endl;
				cout << "ID del Socio: " << id << endl;
				cout << "Nombre del Socio: " << k->devolverNombre(id) << endl;
				cout << "Nombre del instructor: " << ñ->imprimirnombre(k->devolverIdInstructor(id)) << endl;
				cout << "Objetivo: " << objetivo << endl << endl;
				instrucciones = kl->mostrarejercicios();
				cout << "Instrucciones: " << endl;
				cout << instrucciones << endl;


				Rutina* o = new Rutina(contador, objetivo, fechaFinalizacion, k->devolverNombre(id), fechaCreacion , kl, ñ->imprimirnombre(k->devolverIdInstructor(id)));

				o->setDia(dia);

				if (mes1 == 11) {
					o->setMes(01);
					o->setAnno(anno + 1);
				}
				else if (mes1 == 12) {
					o->setMes(02);
					o->setAnno(anno + 1);
				}
				else if (mes1 < 11) {
					o->setMes(mes1 + 2);
					o->setAnno(anno);
				}

				contador++;

				return o;
			}

		}
	}
	else {
		cout << "El Socio no existe" << endl;
	}
	
	

}

Medicion* Control::DatosMedicion(ListaSocio*o,ListaMedicion*io, ListaInstrutor* c)
{
	cout << "Dijite el Id del Socio: ";
	string x;
	cin >> x;

	if (o->existeSocio(x)) {

		string fecharegistro;
		int peso;
		float Altura;
		float porcentajedegrasa;
		int perdidadegrasa = 0;



		cout << "Nombre del Socio: " << o->devolverNombre(x) << endl;
		cout << "Fecha de Registro: ";
		int dia, mes1, anno;

		cout << endl;

		bool b = true;

		while (b == true) {

			dia = 0;
			cout << "Dia: ";
			cin >> dia;

			if (dia > 31) {
				cout << "Dia no disponible" << endl;
				system("pause");
				b = true;
			}
			else if (dia <= 31) {
				b = false;
			}
		}

		b = true;

		while (b == true) {

			mes1 = 0;
			cout << "Mes: ";
			cin >> mes1;

			if (mes1 > 12) {
				cout << "Mes no disponible" << endl;
				system("pause");
				b = true;
			}
			else if (mes1 <= 12) {
				b = false;
			}
		}

		b = true;

		cout << "Anno: ";
		cin >> anno;

		stringstream xz;
		xz << dia << "/" << mes1 << "/" << anno;
		fecharegistro = xz.str();

		cout << "Peso: ";
		cin >> peso;

		cout << "Altura: ";
		cin >> Altura;

		cout << "Porcentaje de grasa: ";
		cin >> porcentajedegrasa;

		if (io->calcularperdidadegrasa(x) > porcentajedegrasa) {
			perdidadegrasa = io->calcularperdidadegrasa(x) - porcentajedegrasa;
		}
		else if (io->calcularperdidadegrasa(x) == porcentajedegrasa) { 
			perdidadegrasa = 0;
		}
		else if (io->calcularperdidadegrasa(x) < porcentajedegrasa) {
			perdidadegrasa = porcentajedegrasa - io->calcularperdidadegrasa(x);
		}
		else {
			perdidadegrasa = 0;
		}
		



		Medicion* p = new Medicion(x, fecharegistro, peso, Altura, porcentajedegrasa,perdidadegrasa);
		p->setNombresocio(o->devolverNombre(x));
		p->setInstructor(c->imprimirnombre(o->devolverIdInstructor(x)));
		return p;
	}
	else {
		cout << "Socio no existente";
	}

}

void Control::mostrarHistorial(ListaSocio*a, Socio*c, ListaInstrutor*f,ListaRutina*q,FechaHora*io)
{
	cout << "Dijite el ID del Socio: ";
	string id;
	cin >> id;

	if (a->existeSocio(id)) {

		system("cls");

		cout << "------------------------------------" << endl;
		cout << "--------Gimnasio Vital Salud--------" << endl;
		cout << "------------------------------------" << endl << endl;

		cout << "Nombre del Socio: " << a->devolverNombre(id) << endl;
		cout << "Nombre del Instructor: " << f->imprimirnombre(a->devolverIdInstructor(id)) << endl;

		cout << endl;

		cout << "Clases Grupales: ";

		cout << endl << endl;

		cout << "Historial de rutinas: "  << endl << endl;

		cout << q->imprimirrutinasdesocio(a->devolverNombre(id),io);

	}
	else {
		cout << "Socio no existente" << endl;
	}
}

void Control::rechazarDatos(bool x)
{
	this->datos = x;
}

void Control::rutinasvencidasporinstructor(ListaInstrutor*a, ListaRutina*s,FechaHora*i)
{
	cout << "Dijite el ID del instructor: ";
	string id;
	cin >> id;

	if (a->rechazarInstructor(id)) {

		system("cls");

		cout << "------------------------------------" << endl;
		cout << "--------Gimnasio Vital Salud--------" << endl;
		cout << "------------------------------------" << endl << endl;

		cout << "Nombre del Instructor: " << a->imprimirnombre(id) << endl << endl;

		cout << "Rutinas vencidas: " << endl << endl;

		cout << s->devolverRutinaVencida(i, a->imprimirnombre(id));


	}
	else {
		cout << "El Instructor no existe";
	}
}

bool Control::getDatos()
{
	return datos;
}

void Control::controlPrincipal(ListaInstrutor* p,ListaSocio *a,FechaHora*lo,Instructor*l,Socio*r,ListaRutina*h,ListaEjercicio*op,ListaMedicion*jh)
{
	FechaHora vb;
	Gotoxy cy;
	int opc = 0;
	do {
		system("cls");
		cy.display(38, 0);
		cout << "Fecha: ";
		vb.calcularFecha();
		cy.display(0, 0);
		cout << "------------------------------------" << endl;
		cout << "--------Gimnasio Vital Salud--------" << endl;
		cout << "------------------------------------" << endl << endl;
		cout << "1. Ingresar nuevo Socio " << endl;
		cout << "2. Ingresar nuevo instructor " << endl;
		cout << "3. Lista general de socios " << endl;
		cout << "4. Lista general de instructores " << endl;
		cout << "5. Mejores resultados en perdida de grasa " << endl;
		cout << "6. Instructor con mejores resultados en perdida de grasa" << endl;
		cout << "7. Menu instructor" << endl << endl;
		cout << "Dijite la opcion deseada: ";
		cin >> opc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}
		switch (opc)
		{
		case 1: {
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl << endl;
			Socio* s = DatosSocio(p,lo);
			if (getDatos() == false) {
				cout << "------------------------------------" << endl;
				cout << "---------Socio NO Ingresado---------" << endl;
				cout << "------------------------------------" << endl << endl;
				system("pause");
				break;
			}
			a->insertarSocio(s);
			l->ingresarSocio(s);
			l->setTamano(+1);
			cout << endl;
			cout << "------------------------------------" << endl;
			cout << "----Socio Ingresado Correctamente---" << endl;
			cout << "------------------------------------" << endl << endl;
			system("pause");
			break; }
		case 2: {
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl << endl;
			Instructor* u = DatosInstructor(p);
			if (getDatos() == false) {
				cout << "------------------------------------" << endl;
				cout << "-------Instructor NO Ingresado------" << endl;
				cout << "------------------------------------" << endl << endl;
				system("pause");
				break;
			}
			p->insertarInstructor(u);
			cout << endl;
			cout << "------------------------------------" << endl;
			cout << "-Instructor Ingresado Correctamente-" << endl;
			cout << "------------------------------------" << endl << endl;
			system("pause");
			break; }
		case 3:{
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << a->mostrarSocios() << endl;
			system("pause");
			break; }
		case 4:{
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << p->mostrarInstructores() << endl;
			system("pause");
			break; }
		case 5: {
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << jh->mostrarperdidadegrasa();
			system("pause");
			break; }
		case 6:{
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << jh->mejorinstructor();
			system("pause");
			break;
		}
		case 7:
			system("cls");
			cy.display(38, 0);
			cout << "Fecha: ";
			vb.calcularFecha();
			cy.display(0, 0);
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			menuInstructores(p, a,r,h,op,lo,jh);
			system("pause");
			break;
		}

	} while (opc != 8);
}

void Control::menuInstructores(ListaInstrutor *p,ListaSocio *g,Socio*r,ListaRutina*f,ListaEjercicio*gf,FechaHora*nm,ListaMedicion*kh)
{

	int opc = 0;
	do {
		system("cls");
		cout << "------------------------------------" << endl;
		cout << "--------Gimnasio Vital Salud--------" << endl;
		cout << "------------------------------------" << endl<< endl;
		cout << "1. Socios por Instructor " << endl;
		cout << "2. Asignar Rutina a Socio" << endl;
		cout << "3. Detalle Socio " << endl;
		cout << "4. Rutinas vencidas por instructor " << endl;
		cout << "5. Detalle de Rutina especifica " << endl;
		cout << "6. Registrar nueva medicion socio " << endl;
		cout << "7. Mostrar mediciones socio " << endl;
		cout << "8. Regresar al menu principal " << endl;
		cout << endl;
		cout << "Dijite la opcion deseada: ";
		cin >> opc;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Wrong! Enter a #!" << endl;
			system("pause");
		}
		switch (opc)
		{
		case 1: {
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl << endl;
			cout << "Dijite la Identificacion del instructor: ";
			string c;
			cin >> c;
			cout << p->imprimirSociosPorInstructor(g,c);
			system("pause");
			break; }
		case 2: {
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			Rutina*uy = DatosRutina(g,r,p,gf);
			f->insertarRutina(uy);
			system("pause");
			break;}
		case 3: {
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			mostrarHistorial(g, r, p, f,nm);
			system("pause");
			break;}
		case 4: {
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << "Dijite la Identificacion del instructor: ";
			string c;
			cin >> c;
			cout << p->mostrarRutinasvencidas(f, c, nm);
			system("pause");
			break; }
		case 5:{
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << "Dijite el Id de la rutina: ";
			int xp;
			cin >> xp;
			cout << f->imprimirRutinaespecifica(xp,nm);
			system("pause");
			break;}
		case 6:{
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			Medicion* s = DatosMedicion(g,kh,p);
			kh->insertarMedicion(s);
			system("pause");
			break;}
		case 7: {
			system("cls");
			cout << "------------------------------------" << endl;
			cout << "--------Gimnasio Vital Salud--------" << endl;
			cout << "------------------------------------" << endl;
			cout << "Dijite el ID del socio: ";
			string id;
			cin >> id;
			cout << endl;
			cout << g->mostrarmedicion(id,kh);
			system("pause");
			break;
		}
		}
	} while (opc != 8);
}

void Control::mostrarmejoresresultadosperdida(ListaMedicion*a)
{

}
