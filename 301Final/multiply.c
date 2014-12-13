#include "multiply.h"

complex multiply(complex r, complex s)
	{
	    complex result;
	    result.real = r.real * s.real - r.img * s.img;
	    result.img = r.img * s.real + r.real * s.img;
	    return result;
	}
