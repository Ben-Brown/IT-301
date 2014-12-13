#include "subtract.h"
int choice, temp1, temp2, temp3;
  complex a;
  complex b;
  complex c;

complex subtraction(complex r, complex s)
	{
	      complex result;
	      result.real = r.real - s.real;
	      result.img = r.img - s.img;
	      return result;
    }
