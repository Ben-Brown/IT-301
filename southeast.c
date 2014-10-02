//Ben Brown
//southeast.c - A navigation program

#include <stdio.h>

void go_south_east(int *addr_lat, int *addr_lon)
{
	//Dereferences the address of pointer-to-int type *addr_lat and physically subtracts 1 from the value stored 
	*addr_lat = *addr_lat - 1;
	//Dereferences the address of pointer-to-int type *addr_lat and physically adds 1 to the value stored 
	*addr_lon = *addr_lon + 1;
}

int main ()
{
	//Stores 32 as an int type in memory
	int latitude = 32;
	//Stores 64 as an int type in memory
	int longitude = -64;
	
	//Retrieves the new values of the latitude and longitude variables
	go_south_east(&latitude, &longitude);
	
	//Inserts the latitude and longitude value into the output string
	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
	
	return 0;
}
