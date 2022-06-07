# Menu 
#### El menú ofrecido a nuestro usuario en el que muestra una una lista disponible, se divide en 8 partes, sabemos que cuando se elige una opcion se ejecutara de acuerdo lo deseado, está realizará una acción asociada en el objeto actualmente seleccionado
* int main(){ 
	cargar();
	int eleccion=0;
	do{
* system("cls"); 
* cout<<"*****MANEJO BASE DE DATOS  (CRUD)*****"<<endl; 
* cout<<"1 - Ver listado de alumnos"<<endl; 
* cout<<"2 - Ingresar un nuevo alumno"<<endl; 
* cout<<"3 - Buscar alumno"<<endl; 
* cout<<"4 - Modificar Alumno"<<endl; 
* cout<<"5 - Eliminar Alumno"<<endl; 
* cout<<"6 - Deshacer ultimo cambio"<<endl; 
* cout<<"7 - Rehacer ultimo cambio"<<endl; 
* cout<<"8 - Listar cambios a realizar"<<endl; 
* cout<<"0 - SALIR"<<endl; 
* cout<<"FAVOR DE ELEGIR UNA OPCION  "<<endl; 
* cin>>eleccion; 
* cin.get(); 

# Ingresar nuevo alumno
#### Con nuestra funcion nuevo, le pediremos al usuario que ingrese los datos del la persona, en este caso tomaremos como ejemplo un alumno, cada pregunta se ira almacenando esta que esta veriable sea llamada
void nuevo(){
* Alumno *alumno = new Alumno(); 
* Cambio1 *cambio = new Cambio1(); 
* system("cls"); 
* cout  <<"Agregar Alumno"<<endl; 
* cout  <<"Ingrese la clave del alumno (no menor a 7): "; 
* cin >> alumno->clave; 
* cambio->clave1 = alumno->clave; 
* cin.ignore(); 
* cout << "Ingrese el nombre del alumno: "; 
* getline(cin, alumno->nombre); 
* cambio->nombre1 = alumno->nombre; 
* cout << "Ingrese el correo del alumno: "; 
* getline(cin, alumno->correo); 
* cambio->correo1 = alumno->correo; 
* cout << "Ingrese la fecha de nacimiento del alumno:"; 
* getline(cin, alumno->fecha); 
* cambio->fecha1 = alumno->fecha; 
* cout << "Ingrese el numero de celular del alumno: "; 
* cin >> alumno->cel; 
* cambio->cel1 = alumno->cel; 
cin.ignore(); 
* cout << "Ingrese la direccion del alumno: "; 
* getline(cin, alumno->direccion); 
* cambio->direccion1 = alumno->direccion; 
* alumno->operation = "nuevo"; 
* cambio->operation1 = "nuevo"; 
* Insertar1(cambio); 
	}
	
# Funcion mostrar
##### Cuando se haya ingreso un dato, de alguna manera, necesitamos saber que dato fue ya almacenado, para no volver a repetir el mismo nombre, o bien la misma clale de lo contario nos dara error.
##### Cuando un valor no ha sido reconocido el programa recorrera la lista si existe un numero que conincida con lo que pedimos, si es así  lo mostrará con un mensaje positivo, de lo contario nos nostrara que el dato no ha sido almacenado
* void mostrar(bool showchanges) 
* { 
* if (inicio == NULL) 
* { 
* cout << "No hay datos en la lista" << endl; 
* return; 
* } 
* Alumno *aux = inicio; 
* if(showchanges ==true){ 
* while(aux != NULL) { 
* if(aux->operation != ""){ 
* mostraralumno(aux); 
* } 
* aux = aux->	siguiente ; 
* } 
* } 
* else{ 
* while(aux!=NULL){ 
* mostraralumno(aux); 
* cout<<endl; 
* aux = aux->siguiente; 
* } 
* } 
* } 
# Buscar
##### Nos ayudará a buscar un dato expecifico, mucho más fácil, a través del menu le pedidra que ingrese la clave de nuestro alumno, el programa hará un recorrido a lo que se haya ingresado y los mostrara en pantalla, de lo contrario mostrará un mensaje de no encontrado , muy similar a la funcion de la lista, en este caso lo buscaremos con un solo dato. 

* void search(){ 
* Alumno *alumno = new Alumno(); 
* alumno = inicio; 
* int buscador = 0; 
* bool found = false; 
* cout << " Ingresa la clave del alumno a Buscar: "<<endl; 
* cin >> buscador; 
* if(inicio!=NULL){ 
* while(alumno!=NULL && found != true){ 
* if(alumno->clave == buscador){ 
* mostraralumno(alumno); 
* found = true; 
* } 
* alumno = alumno->siguiente; 
		}
* if(found==false){ 
* cout << endl << "Registro no encontrado" << endl << endl; 
		}
* }else{ 
* cout << endl << "No hay registros" << endl << endl; 
	}
}
# Modificar
##### En esta opcion, le pediremos al usuario si necesita modifar un dato, esta opcion se hara siempre y cuando el usuario lo quiera, es decir es opcional. 
##### Pedirá como referencia la clave, que es por lo que se distingue nuestra persona, con esta referencia se hace un recorrido hasta que los busque. 
##### Porterior le pediremos que modique los cambios, hasta que lo complete con un mensaje de confirmación, que fue almacenado y modificado.
* void modified(){ 
* Alumno *alumno = new Alumno(); 
* Cambio1 *cambio = new Cambio1(); 
* alumno = inicio; 
* int buscador = 0; 
* bool found = false; 
* cout << " Ingrese la clave del alumno para Modificar: "; 
* cin >> buscador; 
* if(inicio!=NULL){ 
* while(alumno!=NULL && found != true){ 
* if(alumno->clave == buscador){ 
* mostraralumno(alumno); 
* system("cls"); 
* cout  <<"Agregar Alumno"<<endl; 
* cout  <<"Ingrese la nueva clave del alumno (no menor a 7): "; 
* cin>>alumno->clave; 
* cambio->clave1 = alumno->clave; 
* cin.ignore(); 
* cout << "Ingrese el nuevo nombre del alumno: "; 
* getline(cin, alumno->nombre); 
* cambio->nombre1 = alumno->nombre; 
* cout << "Ingrese el nuevo correo del alumno: "; 
* getline(cin, alumno->correo); 
* cambio->correo1 = alumno->correo; 
* cout << "Ingrese la fecha de nacimiento del alumno:"; 
* getline(cin, alumno->fecha); 
* cambio->fecha1 = alumno->fecha;
* cout << "Ingrese el nuevo numero de celular del alumno: ";
* cin>>alumno->cel;
* cambio->cel1 = alumno->cel;
* cin.ignore();
* cout << "Ingrese la nueva direccion del alumno: ";
getline(cin, alumno->direccion);
* cambio->direccion1 = alumno->direccion;
* alumno->operation = "modificado";
* cambio->operation1 = "modificado";
* Insertar1(cambio);
* cout << endl << "Registro modificado " << endl << endl;
* found = true;
* }
* alumno = alumno->siguiente;
* }
* if(found==false){
* cout << endl << " Registro no Encontrado" << endl << endl;
* }
* }else{
* cout << endl << " No hay nigun registro" << endl << endl;
* }
* }
# Eliminar
##### En esta opción, le pediremos la usuario que lo busque por medio de la clave que es la base fundamental para hacerlo
* void trash() {
* Alumno *aux;
* Alumno *aux_borrar;
* Alumno *anterior = NULL;
* aux_borrar = inicio;
* int x = 0;
* cout << " Ingresa la clave del alumno a eliminar: "<<endl;
* cin >> x;
* 
* if(inicio == NULL) {
* cout << "No hay alumnos" << endl;
* }
* 
* while(aux_borrar->clave != x){
* anterior = aux_borrar;
* aux_borrar = aux_borrar->siguiente;
* }
* 
* if(aux_borrar == NULL) {
* cout<< "no se encontro";
* }
* else if(anterior == NULL){
* inicio = inicio->siguiente;
* Cambio1 *cambio = new Cambio1();
* cambio->clave1 = aux_borrar->clave;
* cambio->nombre1 = aux_borrar->nombre;
* cambio->correo1 = aux_borrar->correo;
* cambio->fecha1 = aux_borrar->fecha;
* cambio->cel1 = aux_borrar->cel;
* cambio->direccion1 = aux_borrar->direccion;
* cambio->operation1 = "Eliminar";
* // Insertar1(cambio);
* delete aux_borrar;
* cout<<"El alumno con clave "<< x << " fue eliminado "<<endl;
* }
* else if(anterior != NULL) {
* inicio = anterior;
* inicio->siguiente = aux_borrar->siguiente;
* Cambio1 *cambio = new Cambio1();
* cambio->clave1 = aux_borrar->clave;
* cambio->nombre1 = aux_borrar->nombre;
* cambio->correo1 = aux_borrar->correo;
* cambio->fecha1 = aux_borrar->fecha;
* cambio->cel1 = aux_borrar->cel;
* cambio->direccion1 = aux_borrar->direccion;
* cambio->operation1 = "Eliminar";
* Insertar1(cambio);
* delete aux_borrar;
* cout<<"El alumno con clave "<< x << " fue eliminado "<<endl;
* }
* 
* }
# Deshacer, Rehacer 
##### al optar por la opcion de Deshacer en donde se vera en funcion, sera cuando eliminemos, o moficaremos un dato, desechará cualquiera de los cambios que hicimos
##### Por otra parte Rehacer, no lo elimara por el todo, quedara almacenada dentro la función, lista para ser llamada nuevamente si es lo que desea el usuario, si es así volverá, lo veremos como ctrl + z
* void ctrlz(){
* Cambio1 *cambio = new Cambio1();
* Cambio2 *cambiox = new Cambio2();
* if (inicio1 == NULL){
* cout << "No hay elementos para sacar" << endl;
* return;
* }
* cambio = inicio1;
* inicio1 = cambio->siguiente1;
* cout << "Se Desahizo el ultimo cambio : " << cambio->clave1 << ") " << cambio->nombre1 << endl;
* cambiox->clave2 = cambio->clave1 ;
* cambiox->nombre2 = cambio->nombre1;
* cambiox->correo2 = cambio->correo1;
* cambiox->fecha2 = cambio->fecha1;
* cambiox->cel2 = cambio->cel1;
* cambiox->direccion2 = cambio->direccion1;
* cambiox->operation2 = cambio->operation1;
* Insertar2(cambiox);
* delete(cambio);
* }
* 
* void ctrly(){
* Cambio1 *cambio = new Cambio1();
* Cambio2 *cambiox = new Cambio2();
* if (inicio2 == NULL){
* cout << "No hay elementos para sacar" << endl;
* return;
* }
* cambiox = inicio2;
* inicio2 = cambiox->siguiente2;
* cout << "Se Rehizo el ultimo cambio : " << cambiox->clave2 << ") " << cambiox->nombre2 << endl;
* cambio->clave1 = cambiox->clave2;
* cambio->nombre1 = cambiox->nombre2;
* cambio->correo1 = cambiox->correo2;
* cambio->fecha1 = cambiox->fecha2;
* cambio->cel1 = cambiox->cel2;
* cambio->direccion1 = cambiox->direccion2;
* cambio->operation1 = cambiox->operation2;
* Insertar1(cambio);
* delete(cambiox);
* }

# Listar cambios  a realizar
##### Si deseas salir sin guardar los cambios escribe 'n' si deseas salir sin guardar y 's' para guardar
##### Esta pregunta será clave, ya que lo guerdado sera enviado a la base de datos 

 