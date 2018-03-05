#pragma once
#define NPARAMETERS 3
#define NKEYS 3
#define NVALUES 3 //Puede cambiarse el numero para la cantidad de parametros, claves y valores que se deseen
int parseCallback(char *key, char *value, void *userData);
typedef struct
{
	char *  parameters[NPARAMETERS];
	char *  key[NKEYS];
	char *  value[NVALUES];
}userData;