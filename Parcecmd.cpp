// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData); 

typedef int (*pCallback) (char * , char* , void *);
extern int parseCallback(char *key, char *value, void *userData); 

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData){	
	int final,result=0,posible=0,error=false;
	for (int i=1;i<argc;){
		if (argv[i][0]=='-'){
			if (i+1>argc)
				{
				error=true;
				i=argc;
			}
			else
			{
			posible=p(&(argv[i][1],argv[i+1],userData);
			if (posible >=0){
				i+=2;
				result+=posible;
			}
			else {
				error=true;
				i=argc;
			}
			}
		}
		else{
			posible=p(NULL,argv[i],userData);
			if (posible >=0){
				i++;
				result+=posible;
			}
			else{
				error=true;
				i=argc;
			}
		}
	}
	if (error==true)
		final=-1;
	else 
		final = result;
	return final;

}

