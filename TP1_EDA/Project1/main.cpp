#include "parsecmd.h"
#include "parsecallback.h"
#include <iostream>
using namespace std;
int main(int argc, char ** argv)
{
	int result;
	pCallback p = parseCallback;
	userData myinfo;
	myinfo.key[0]   = (char*)"GUIDO";
	myinfo.value[0] = (char*) "LAMBERTUCCI";
	myinfo.key[0]   = (char*) "58009";

	result = parseCmdLine(argc, argv, p, &myinfo);
	if (result == ERROR1)
		cout << "Error tipo 1, se ha ingresado una opcion sin valor" << endl;
	else if (result == ERROR2)
		cout << "Error tipo 2, se ha ingresado una opcion sin clave" << endl;
	else if (result == ERROR3)
		cout << "Los datos ingresados no corresponden con nuestra base de datos" << endl;
	else
		cout << "Se han ingresado " << result << " argumentos" << endl;
	return 0;
}