#include "divide.h"

complex divide(complex r, complex s)
	{
	    complex result;
	    result.real = ((r.real * s.real) + (r.img * s.img)) / ((s.real * s.real) + (s.img * s.img));
	    result.img = ((r.img * s.real) - (r.real * s.img)) / ((s.real * s.real) + (s.img * s.img));
	    return result;
	}
