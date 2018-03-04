#include "parsecallback.h"
#include <string.h>
#include <fwpstypes.h>
#include <stdio.h>
int parseCallback(char *key, char *value, void *userinfo)
{
	int i = 0, equal;
	char * val = value;
	if (key == NULL)
	{
		while (val[i])
		{
			val[i] = toupper(val[i++]);
		}
		printf("%s\n", val);
		equal = strcmp(val, ((userData*)userinfo)->parameters[0]);
	}
	return equal;
}