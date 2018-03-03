#pragma once
#include <stdlib.h>
#include <stdio.h>
typedef int(*pCallback) (char *, char*, void *);
int parseCmdLine(int argc, char *argv[], pCallback p, void *userData);


int parseCallback(char *key, char *value, void *userData);
