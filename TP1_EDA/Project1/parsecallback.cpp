#include "parsecallback.h"
#include <string.h>
#include <fwpstypes.h>
#include <stdio.h>

int parseCallback(char *key, char *value, void *userinfo)
{
	int i = 0, equal = -1;
	char * ke = key;
	char * val = value;
	if (key == NULL)
	{
		while (val[i])
		{
			val[i] = toupper(val[i]);
			i++;
		}
		printf("%s\n", val);  //DEBUG

		for (i = 0; i < NPARAMETERS; i++)
		{
			equal = strcmp(val, ((userData*)userinfo)->parameters[i]);
			if (equal == 0)
				i = NPARAMETERS;
		}
	}
	else
	{
		while (key[i])
		{
			ke[i] = toupper(ke[i]);
			i++;
		}
		printf("%s\n", ke); //DEBUG

		for (i = 0; i < NKEYS; i++)
		{
			equal = strcmp(ke, ((userData*)userinfo)->key[i]);
			if (equal == 0)
				i = NKEYS;
		}

		if (equal == 0)
		{
			while (val[i])
			{
				val[i] = toupper(val[i]);
				i++;
			}
			printf("%s\n", val); //DEBUG

			for (i = 0; i < NVALUES; i++)
			{
				equal = strcmp(val, ((userData*)userinfo)->key[i]); 
				if (equal == 0)
					i = NVALUES;
			}
		}
	}

	if (equal != 0)
		equal = -1;

	return equal;
}