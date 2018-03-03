
#include "parsecmd.h"
#include "parsecallback.h"

int parseCmdLine(int argc, char *argv[], pCallback p, void *userData) {
	int final = 0, result = 0, posible = 0, error = false;

	for (int i = 1; i<argc;) {
		if (argv[i][0] == '-') {
			if ((i + 1) >= argc)
			{
				error = ERROR1;

			}
			if (argv[i][1] == 0)
			{
				error = ERROR2;
				i= argc;
			}
			else
			{
				posible = p(&(argv[i][1]), argv[i + 1], userData);
				if (posible >= 0) {
					i += 2;
					result += posible;
				}
				else {
					error = ERROR3;
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
				error = ERROR3;
				i = argc;
			}
		}
	}
	if (error == ERROR1)
		final = ERROR1;
	else if (error == ERROR2)
		final = ERROR2;
	else if (error == ERROR3)
		final = ERROR3;
	else
		final = result;
	return final;

}
