//TP1 EDA PARSER Grupo 3
//Alumnos:
//Lambertucci Guido
//Alan Mechoulam 
//Ariel Martorell
#include "parsecmd.h"
#include "parsecallback.h"
#include <iostream>
using namespace std;
int main(int argc, char ** argv)
{
	int result;
	pCallback p = parseCallback;
	userData myinfo;

	//USAR MAYUSCULAS PARA LA BASE DE DATOS

	myinfo.key[0]  = (char*)"GUIDO";
	myinfo.key[1] = (char*)"ALAN";
	myinfo.key[2] = (char*)"MARTORELL";

	myinfo.value[0] = (char*) "LAMBERTUCCI";
	myinfo.value[1] = (char*) "MECHOULAM";
	myinfo.value[2] = (char*) "ARIEL";

	myinfo.parameters[0]  = (char*) "58009";
	myinfo.parameters[1] = (char*) "58427";
	myinfo.parameters[2] = (char*) "56209";

	result = parseCmdLine(argc, argv, p, &myinfo);
	if (result == ERROR1)
		cout << "Error tipo 1, se ha ingresado una opcion sin valor" << endl;
	else if (result == ERROR2)
		cout << "Error tipo 2, se ha ingresado una opcion sin clave" << endl;
	else if (result == ERROR3)
		cout << "Error tipo 3, los datos ingresados no corresponden con nuestra base de datos" << endl;
	else
		cout << "Se han ingresado " << result << " argumentos" << endl;

	return 0;
}