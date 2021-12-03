#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void array_exchanger(int* array_a, int* array_b, int length)
{
	int i, tmp;
	for(i=0;i<length;i++)
	{
		tmp = array_a[i];
		array_a[i] = array_b[i];
		array_b[i] = tmp;
	}
}
