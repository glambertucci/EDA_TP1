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

	myinfo.key[0]  = (char*)"KEY1";
	myinfo.key[1] = (char*)"KEY2";
	myinfo.key[2] = (char*)"KEY3";

	myinfo.value[0] = (char*) "VALUE1";
	myinfo.value[1] = (char*) "VALUE2";
	myinfo.value[2] = (char*) "VALUE3";

	myinfo.parameters[0]  = (char*) "PARAMETER1";
	myinfo.parameters[1] = (char*) "PARAMETER2";
	myinfo.parameters[2] = (char*) "PARAMETER3";

	result = parseCmdLine(argc, argv, p, &myinfo);
	if (result == ERROR1)
		cout << "Error tipo 1, se ha ingresado una opcion sin valor" << endl;
	else if (result == ERROR2)
		cout << "Error tipo 2, se ha ingresado una opcion sin clave" << endl;
	else if (result == ERROR3)
		cout << "Los datos ingresados no corresponden con nuestra base de datos" << endl;
	else
		cout << "Se han ingresado " << result << " argumentos" << endl;

	getchar();

	return 0;
}