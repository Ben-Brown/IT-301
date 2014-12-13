#include "add.h"

complex addition(complex r, complex s)
	{
	      complex result;
	      result.real = r.real + s.real;
	      result.img = r.img + s.img;
	      return result;
	}
