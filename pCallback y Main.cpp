#include <stdafx.h>

typedef struct
{
	char* parameters[PARAMQUANTITY];
	char* options[OPTIONQUANTITY]; 
	char* claves[CLAVEQUANTITY];

}data_t;

int main(int argc, char* argv[])
{

	data_t myData = { { "pisa" } , {"hola"} , {"a"};
		  
	
	return 0;
}

int parseCallback(char* clave, char* valor, data_t* myData)
{
	int toReturn = 0;

	if(clave == NULL)
	{
		for(i = 0; i<PARAMQUANTITY; i++)
		{
			if(!strcmp(valor, myData->parameters[i]))
			{
				toReturn = 1;
				i = PARAMQUANTITY;
			}
		}

		if(toReturn == 0)
			toReturn = -1;
	}

	else
	{
		for(i = 0; i<CLAVEQUANTITY; i++)
		{
			if(!strcmp(clave, myData -> claves[i]))
			{
				toReturn = 1;
				i = CLAVEQUANTITY;
			}
		}
			
		if(toReturn == 0)
		{
			toReturn = -1;
		}

		else
		{
			for(i = 0; i<OPTIONQUANTITY; i++)
			{
				if(!strcmp(valor, myData -> options[i]))
				{
					toReturn = 1;
					i = OPTIONQUANTITY;
				}
			}
		}
	}

	return toReturn;
}


