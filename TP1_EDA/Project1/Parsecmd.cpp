
#include "parsecmd.h"

int Banco1(void)
{
	int a = 5;
	char *arg[5] = { (char *) "parsecmd", (char *) "-Hola",(char *)"Soy",(char *)"Guido",(char *)"-KTNSIMIO" };
	pCallback p = parseCallback;
	a = parseCmdLine(a, arg, p, NULL);
	printf("El resultado es: %d\n ", a);
	getchar();
	return 0;
}
int parseCmdLine(int argc, char *argv[], pCallback p, void *userData) {
	int final = 0, result = 0, posible = 0, error = false;

	for (int i = 1; i<argc;) {
		if (argv[i][0] == '-') {
			if ((i + 1) >= argc)
			{
				error = true;
				i = argc;
			}
			else
			{
				posible = p(&(argv[i][1]), argv[i + 1], userData);
				if (posible >= 0) {
					i += 2;
					result += posible;
				}
				else {
					error = true;
					i = argc;
				}
			}
		}
		else {
			posible = p(NULL, argv[i], userData);
			if (posible >= 0) {
				i++;
				result += posible;
			}
			else {
				error = true;
				i = argc;
			}
		}
	}
	if (error == true)
		final = -1;
	else
		final = result;
	return final;

}
