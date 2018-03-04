#pragma once
#define NPARAMETERS 1
#define NKEYS 1
#define NVALUES 1 //Puede cambiarse el numero para la cantidad de parametros, claves y valores que se deseen
int parseCallback(char *key, char *value, void *userData);
typedef struct
{
	char *  parameters[NPARAMETERS];
	char *  key[NKEYS];
	char *  value[NVALUES];
}userData;