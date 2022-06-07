//PROYECTO FINAL PROGRAMACION I
//Melvin Cali
//Elmer Eduardo Istupe Ruiz 7691-21-10969
//Bairon Ismael Castellanos Valle 7691-21-10973
//Santos Genaro Hernandez Gabriel 7691-21-21318
//CRUD con base de Datos y Listas Enlazadas

#include <iostream>
#include <mysql.h>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <sstream>

using namespace std;
struct Alumno{
	int clave;
	string nombre;
	string correo;
	string fecha;
	int cel;
	string direccion; 
	string operation;
	Alumno *siguiente;
};
Alumno *inicio = NULL;

struct Cambio1{
	int clave1;
	string nombre1;
	string correo1;
	string fecha1;
	int cel1;
	string direccion1; 
	string operation1;
	Cambio1 *siguiente1;
	
};
Cambio1 *inicio1 = NULL;	


struct Cambio2{
	int clave2;
	string nombre2;
	string correo2;
	string fecha2;
	int cel2;
	string direccion2; 
	string operation2;
	Cambio2 *siguiente2;
};
Cambio2 *inicio2 = NULL;


void cargar();
void Insertar(Alumno *&alumno);
void Insertarx(Alumno *&alumno);
void Insertar1(Cambio1 *&cambio);
void Insertar2(Cambio2 *&cambiox);
void mostrar(bool showchanges);
void mostraralumno(Alumno *&alumno);
void mostrarx() ;
void search();
void nuevo();
void modified();
void update();
void trash();
void ctrlz();
void ctrly();
void querynuevo();
void queryupdate();
void querytrash();
char guardar;
char serverdb[] = "localhost";
char userdb[] = "root";
char passworddb[] = "A5000shg";
char database[] = "umg";

void cargar(){
	MYSQL *connection;
	long alumno1;
	string sql;
	int i, altura, k, l;
	unsigned long   *lon;
	const char* query;
	int result;
	connection = mysql_init(0);
		if (connection) 
	{
		cout << "La biblioteca MySQL se ha iniciado correctamente" << endl;
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		if (connection) 
		{
			cout << "Conexion exitosa a la base de datos" << endl;	
			cout << "Cargando datos ." << endl;							
			MYSQL_ROW row;
			MYSQL_RES* data;
			sql = "SELECT clave, name, mail, fecha, phone, location FROM alumno ORDER BY clave";
			query = sql.c_str();
			result = mysql_query(connection, query);
			if (result == 0) 
			{
				cout << "Se han obtenido los datos de forma exitosa" << endl;
				if((data=mysql_store_result(connection))){
					i=(int)mysql_num_rows(data);
					altura=(int)mysql_num_fields(data);
					cout<<endl<<""<<endl;
					l=1;
					for(l=0;l<i;l++){
						row=mysql_fetch_row(data);
						lon=mysql_fetch_lengths(data);
						cout<<endl; 
						Alumno *alumno = new Alumno();
							alumno->clave = atoi(row[0]);
							alumno->nombre = row [1];
							alumno->correo = row[2];
							alumno->fecha =row[3];
							alumno->cel =atoi(row[4]);
							alumno->direccion =row[5];
							alumno->operation = "";
						Insertarx(alumno);
						}												
					}
					cout<<endl;
				}			
			else
			{
				cout << "No fue posible obtener los registros " << mysql_error(connection) << endl;
			}			
}
		else 
		{
			cout << "No fue posible conectarse a la base de datos: " << mysql_error(connection) << endl;
		}
	}
	else 
	{
		cout << "No es posible iniciar la biblioteca de MySQL" << endl;
	}
	}
	
	
void Insertarx(Alumno *&alumno){ 
	alumno->siguiente = NULL;
	if(inicio == NULL){
	inicio = alumno;
	return;
	}
	Alumno *aux = inicio;
	Alumno *aux1;
	while((aux !=NULL) && (aux->clave < alumno->clave)){
	aux1 = aux;
	aux = aux->siguiente;
	}
	if(inicio == aux){
	inicio == alumno;
	}
	else{
	aux1->siguiente = alumno;
	}
	alumno->siguiente = aux;
}	

void Insertar(Alumno *&alumno){ 
	alumno->siguiente = NULL;
	if(inicio == NULL){
		inicio = alumno;
		return;
	}
	Alumno *aux = inicio;
	while((aux !=NULL)){
		if(aux->clave < alumno->clave) {
			aux = aux->siguiente;
		}
		break;
	}
	
	if(aux->siguiente == NULL) {
		aux->siguiente = alumno;
	} else {
		Alumno *siguiente = aux->siguiente;
		aux->siguiente = alumno;
		alumno->siguiente = siguiente;
		
	}
}

void Insertar1(Cambio1 *&cambio){ 
	cambio->siguiente1 = NULL;
	if(inicio1 == NULL){
		inicio1 = cambio;
		return;
	}
	Cambio1 *aux = inicio1;
	while((aux !=NULL)){
		if(aux->clave1 < cambio->clave1) {
			aux = aux->siguiente1;
		}
		break;
	}
	
	if(aux->siguiente1 == NULL) {
		aux->siguiente1 = cambio;
	} else {
		Cambio1 *siguiente1 = aux->siguiente1;
		aux->siguiente1 = cambio;
		cambio->siguiente1 = siguiente1;
		
	}
}

void nuevo(){
	Alumno *alumno = new Alumno();
	Cambio1 *cambio = new Cambio1();	
	system("cls");
	cout  <<"Agregar Alumno"<<endl;
	cout  <<"Ingrese la clave del alumno (no menor a 7): ";
	cin >> alumno->clave;
	cambio->clave1 = alumno->clave;
	cin.ignore();
	cout << "Ingrese el nombre del alumno: ";
	getline(cin, alumno->nombre);
	cambio->nombre1 = alumno->nombre;
    cout << "Ingrese el correo del alumno: ";
    getline(cin, alumno->correo);
    cambio->correo1 = alumno->correo; 
	cout << "Ingrese la fecha de nacimiento del alumno:";
	getline(cin, alumno->fecha);
	cambio->fecha1 = alumno->fecha;
	cout << "Ingrese el numero de celular del alumno: ";
	cin >> alumno->cel;
	cambio->cel1 = alumno->cel;
	cin.ignore();
	cout << "Ingrese la direccion del alumno: ";
	getline(cin, alumno->direccion);
	cambio->direccion1 = alumno->direccion;
	alumno->operation = "nuevo"; 
	cambio->operation1 = "nuevo";	
	//Insertar(alumno);
	Insertar1(cambio);	
	}
		
void mostrar(bool showchanges) 
{	
	if (inicio == NULL) 
	{
		cout << "No hay datos en la lista" << endl;
		return;
	}
	Alumno *aux = inicio;
	if(showchanges ==true){
		while(aux != NULL) {
			if(aux->operation != ""){
				mostraralumno(aux);
			}
			aux = aux->	siguiente ;
		} 
	}
	else{
		while(aux!=NULL){
			mostraralumno(aux);
			cout<<endl;
			aux = aux->siguiente;
		}
	}
}

void mostraralumno(Alumno *&alumno) 
{	
	cout << "Clave: " << alumno->clave <<"	";
	cout << "Nombre: " << alumno->nombre <<"	";
	cout << "Correo: " << alumno->correo<<"	";
	cout << "fecha: " << alumno->fecha<<"	";
	cout << "cel: " << alumno->cel<<"	";
	cout << "direccion: " << alumno->direccion<<"	";
	cout << "Operacion: " << alumno->operation<<endl;		
}
	
void mostrarx(){	
	Cambio1 *cambio = new Cambio1;	
	if (inicio1 == NULL) 
	{
		cout << "No hay datos en la lista" << endl;
		return;
	}
	Cambio1 *aux = inicio1;
	while(aux != NULL) {
		cout << "Clave: " << aux->clave1 <<"	";
		cout << "Nombre: " << aux->nombre1 <<"	";
		cout << "Correo: " << aux->correo1<<"	";
		cout << "fecha: " << aux->fecha1<<"	";
		cout << "cel: " << aux->cel1<<"	";
		cout << "direccion: " << aux->direccion1<<"	";
		cout << "Operacion: " << aux->operation1<<endl;
		aux = aux->siguiente1;
	}
}
		
	
	
void search(){
	Alumno *alumno = new Alumno();
	alumno = inicio;
	int buscador = 0;
	bool found = false;
	cout << " Ingresa la clave del alumno a Buscar: "<<endl;
	cin >> buscador;
	if(inicio!=NULL){
		while(alumno!=NULL && found != true){				
			if(alumno->clave == buscador){
				mostraralumno(alumno);
				found = true;
			}	
			alumno = alumno->siguiente;
		}
		if(found==false){
			cout << endl << "Registro no encontrado" << endl << endl;
		}
	}else{
		cout << endl << "No hay registros" << endl << endl;
	}
}

void modified(){
	Alumno *alumno = new Alumno();
	Cambio1 *cambio = new Cambio1();
	alumno = inicio;
	int buscador = 0;
	bool found = false;
	cout << " Ingrese la clave del alumno para Modificar: ";
	cin >> buscador;
	if(inicio!=NULL){
		while(alumno!=NULL && found != true){
			if(alumno->clave == buscador){
				mostraralumno(alumno);
				system("cls");
				cout  <<"Ingresa los nuevos datos de el alumno " << alumno->nombre << " con clave " <<alumno->clave<< ":"<<endl;
				cambio->clave1 = alumno->clave;
				cambio->nombre1 = alumno->nombre;
				cin.get();
			    cout << "Ingrese el nuevo correo del alumno: ";
				getline(cin, alumno->correo);
				cambio->correo1 = alumno->correo;
				cout << "Ingrese la fecha de nacimiento del alumno:";
				getline(cin, alumno->fecha);
				cambio->fecha1 = alumno->fecha;
				cout << "Ingrese el nuevo numero de celular del alumno: ";
				cin>>alumno->cel;
				cambio->cel1 = alumno->cel;
				cin.ignore();
				cout << "Ingrese la nueva direccion del alumno: ";
				getline(cin, alumno->direccion);
				cambio->direccion1 = alumno->direccion;
				alumno->operation = "modificado"; 
				cambio->operation1 = "modificado";
				Insertar1(cambio);
				cout << endl << "Registro modificado " << endl << endl;
				found = true;
			}			
			alumno = alumno->siguiente;
		}
		if(found==false){
			cout << endl << " Registro no Encontrado" << endl << endl;
		}
	}else{
		cout << endl << " No hay nigun registro" << endl << endl;
	}	
}

void trash() {
	Alumno *aux;
    Alumno *aux_borrar;
    Alumno *anterior = NULL;
    aux_borrar = inicio;
    int x = 0;
	cout << " Ingresa la clave del alumno a eliminar: "<<endl;
	cin >> x;

    if(inicio == NULL) {
        cout << "No hay alumnos" << endl;
    }
	
    while(aux_borrar->clave != x){
        anterior = aux_borrar;
        aux_borrar = aux_borrar->siguiente;
  	  }

    if(aux_borrar == NULL) {
        cout<< "no se encontro";
    } 
	else if(anterior == NULL){
        inicio = inicio->siguiente;
        Cambio1 *cambio = new Cambio1();
        cambio->clave1 = aux_borrar->clave;
		cambio->nombre1 = aux_borrar->nombre;
		cambio->correo1 = aux_borrar->correo;
		cambio->fecha1 = aux_borrar->fecha;
		cambio->cel1 = aux_borrar->cel;
		cambio->direccion1 = aux_borrar->direccion;
		cambio->operation1 = "Eliminar";
		// Insertar1(cambio);
        delete aux_borrar;
        cout<<"El alumno con clave "<< x << " fue eliminado "<<endl;
	}
	 else if(anterior != NULL) {
            inicio = anterior;
	        inicio->siguiente = aux_borrar->siguiente;
	        Cambio1 *cambio = new Cambio1();
            cambio->clave1 = aux_borrar->clave;
			cambio->nombre1 = aux_borrar->nombre;
			cambio->correo1 = aux_borrar->correo;
			cambio->fecha1 = aux_borrar->fecha;
			cambio->cel1 = aux_borrar->cel;
			cambio->direccion1 = aux_borrar->direccion;
			cambio->operation1 = "Eliminar";
			Insertar1(cambio);
	        delete aux_borrar;
            cout<<"El alumno con clave "<< x << " fue eliminado "<<endl;
    }
    
} 	

void Insertar2(Cambio2 *&cambiox){ 
	cambiox->siguiente2 = NULL;
	if(inicio2 == NULL){
		inicio2 = cambiox;
		return;
	}
	Cambio2 *aux = inicio2;
	while((aux !=NULL)){
		if(aux->clave2 < cambiox->clave2) {
			aux = aux->siguiente2;
		}
		break;
	}
	
	if(aux->siguiente2 == NULL) {
		aux->siguiente2 = cambiox;
	} else {
		Cambio2 *siguiente2 = aux->siguiente2;
		aux->siguiente2 = cambiox;
		cambiox->siguiente2 = siguiente2;
		
	}
}

void ctrlz(){
	Cambio1 *cambio = new Cambio1();
	Cambio2 *cambiox = new Cambio2();
	if (inicio1 == NULL){
		cout << "No hay elementos para sacar" << endl;
		return;
	}
	cambio = inicio1;
	inicio1 = cambio->siguiente1;
	cout << "Se Desahizo el ultimo cambio : " << cambio->clave1 << ") " << cambio->nombre1 << endl;
    cambiox->clave2 = cambio->clave1 ;
	cambiox->nombre2 = cambio->nombre1;
	cambiox->correo2 = cambio->correo1;
	cambiox->fecha2 = cambio->fecha1;
	cambiox->cel2 = cambio->cel1;
	cambiox->direccion2 = cambio->direccion1;
	cambiox->operation2 = cambio->operation1;
	Insertar2(cambiox);
	delete(cambio);
}

void ctrly(){
	Cambio1 *cambio = new Cambio1();
	Cambio2 *cambiox = new Cambio2();
	if (inicio2 == NULL){
		cout << "No hay elementos para sacar" << endl;
		return;
	}
	cambiox = inicio2;
	inicio2 = cambiox->siguiente2;
	cout << "Se Rehizo el ultimo cambio : " << cambiox->clave2 << ") " << cambiox->nombre2 << endl;
    cambio->clave1 = cambiox->clave2;
	cambio->nombre1 = cambiox->nombre2;
	cambio->correo1 = cambiox->correo2;
	cambio->fecha1 = cambiox->fecha2;
	cambio->cel1 = cambiox->cel2;
	cambio->direccion1 = cambiox->direccion2;
	cambio->operation1 = cambiox->operation2;
	Insertar1(cambio);
	delete(cambiox);
}
	
void querynuevo(char guardar){
	MYSQL* connection;
	string clave;
	string sql;
	string name;
	string correo;
	string fecha;
	string cel;
	string direccion;
	long alumno;
	const char *query;
	int result;

	cout<<"Si deseas salir sin guardar los cambios escribe 'n' si deseas salir sin guardar y 's' para guardar "<<endl;
	cin>>guardar;
	if(guardar == 'n') {
		cout << "Adios"<<endl;
		return;
	}
	
	if(inicio1 == NULL) {
		cout << "No hay cambios nuevos." << endl;
	}		
	connection = mysql_init(0);
	if (connection) 
	{
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		
		if(connection == NULL) {
			cout << "no se conecto."<<endl;
		}		
		Cambio1 *aux = new Cambio1();
		aux = inicio1;
		while(aux != NULL) {
			if(aux->operation1 == "nuevo") {
				int clave1=0;
				int cel1=0;
				clave1 = aux->clave1;
				cel1= aux->cel1;
				string num_str1(to_string(clave1));
				string num_str2(to_string(cel1));
				clave = clave1;
				name = aux->nombre1 ;
				correo = aux->correo1 ;
				fecha = aux->fecha1 ;
				cel = cel1 ;
				direccion = aux->direccion1 ;
				sql = "INSERT INTO alumno(clave, name, mail, fecha, phone, location) VALUES ('" + clave + "', '" + name + "', '" + correo + "', '" + fecha + "', '" + cel + "', '" + direccion + "')"; 
				query = sql.c_str();
				result = mysql_query(connection, query);
				cout << "Registro guardado"<< endl;				
			}
			if(aux->operation1 != "nuevo"){
				cout<<"No hay nuevos registros"<<endl;
			}
		if (result == 0) {
						
		}
		else
		{
			cout << "No fue posible ejecutar la operacion " << aux->operation1 << " en el registro " << mysql_error(connection) << endl;
		}
		aux =  aux->siguiente1;
		}		
	}	
}

void queryupdate(char guardar){
	MYSQL* connection;
	string clave;
	string sql;
	string name;
	string correo;
	string fecha;
	string cel;
	string direccion;
	long alumno;
	const char *query;
	int result;

	if(guardar == 'n') {
		cout << "Adios"<<endl;
		return;
	}	
	if(inicio1 == NULL) {
		cout << "No hay cambios que actualizar." << endl;
	}		
	connection = mysql_init(0);
	if (connection) 
	{
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		
		if(connection == NULL) {
			cout << "no se conecto."<<endl;
		}		
		Cambio1 *aux = new Cambio1();
		aux = inicio1;
		while(aux != NULL) {
			if(aux->operation1 == "modificado") {
				ostringstream str1;
				int cel1=0;
				cel1= aux->cel1;
				string num_str2(to_string(cel1));
				name = aux->nombre1 ;
				correo = aux->correo1 ;
				fecha = aux->fecha1 ;
				cel = cel1 ;
				direccion = aux->direccion1 ;
				sql = "UPDATE alumno SET mail = ('" + correo + "'), fecha = ('" + fecha + "'), phone = ('" + cel + "'), location = ('" + direccion + "') WHERE name = ('" + name + "')" ;
				query = sql.c_str();
				result = mysql_query(connection, query);	
				cout << "Registro actualizado"<< endl;		
				}
				else{
					cout<<"No hay registros a modificar"<<endl;
				}
		if (result == 0){
						
			}
		else
			{
			cout << "No fue posible ejecutar la operacion " << aux->operation1 << " en el registro " << mysql_error(connection) << endl;
			}
			aux =  aux->siguiente1;
		}		
	}	
}

void querytrash(char guardar){
	MYSQL* connection;
	string clave;
	string sql;
	string name;
	string correo;
	string fecha;
	string cel;
	string direccion;
	long alumno;
	const char *query;
	int result;

	if(guardar == 'n') {
		cout << "Adios"<<endl;
		return;
	}	
	if(inicio1 == NULL) {
		cout << "No hay cambios que eliminar." << endl;
	}		
	connection = mysql_init(0);
	if (connection) 
	{
		connection = mysql_real_connect(connection, serverdb, userdb, passworddb, database, 3306, NULL, 0);
		
		if(connection == NULL) {
			cout << "no se conecto."<<endl;
		}		
		Cambio1 *aux = new Cambio1();
		aux = inicio1;
		while(aux != NULL) {
			if(aux->operation1 == "Eliminar") {
				clave = aux->clave1 ;
				name = aux->nombre1 ;
				sql = "DELETE FROM alumno WHERE name = ('" + name + "')" ;
				query = sql.c_str();
				result = mysql_query(connection, query);	
				cout << "Registro eliminado"<< endl;	
			}
			else{
				cout<<"No hay registros a modificar"<<endl;
			}
		if (result == 0) {
							
		}
		else{
			cout << "No fue posible ejecutar la operacion " << aux->operation1 << " en el registro " << mysql_error(connection) << endl;
		}
		aux =  aux->siguiente1;
		}		
	}	
}

int main(){
	cargar();
	int eleccion=0;
	do{
		system("cls");
	    cout<<"*****MANEJO BASE DE DATOS  (CRUD)*****"<<endl;
	    cout<<"1 - Ver listado de alumnos"<<endl;
	    cout<<"2 - Ingresar un nuevo alumno"<<endl;
	    cout<<"3 - Buscar alumno"<<endl;
        cout<<"4 - Modificar Alumno"<<endl;
        cout<<"5 - Eliminar Alumno"<<endl;
        cout<<"6 - Deshacer ultimo cambio"<<endl;
        cout<<"7 - Rehacer ultimo cambio"<<endl;
        cout<<"8 - Listar cambios a realizar"<<endl;    
        cout<<"0 - SALIR"<<endl;
        cout<<"FAVOR DE ELEGIR UNA OPCION  "<<endl;
        cin>>eleccion;
        cin.get();
        
	  	switch (eleccion){
		    case 1: mostrar(false);
		    system ("pause");
	        break;
	        
	        case 2: nuevo();
	        system ("pause");
	        break;
	        
	        case 3: search();
	        system ("pause");
	        break;
	        
	        case 4: modified();
	        system ("pause");
	        break;
	
	        case 5: trash();
	        system ("pause");
	        break;
	        
	        case 6: ctrlz();
	        system ("pause");
	        break;
	        
	        case 7: ctrly();
	        system ("pause");
	        break;
	        
	        case 8: mostrarx();
	        system ("pause");
	        break;
	        
	        case 0:querynuevo(guardar);	
	        queryupdate(guardar);
	        querytrash(guardar);
	        cout<<"Saliendo..."; 
			system ("pause");
	        break;
	        
	        default: querynuevo(guardar);
	        queryupdate(guardar);
	        querytrash(guardar);
	        cout<<"opcion Invalida";system ("pause");
	        break;    
	     }
   	}
	while (eleccion!=0);
	system("cls");      
	return 0;
}		
 



           
	
	
	
	
	
	


