//Ben Brown
//southeast.c - A navigation program

#include <stdio.h>

void go_south_east(int *addr_lat, int *addr_lon)
{
	*addr_lat = *addr_lat - 1;
	*addr_lon = *addr_lon + 1;
}

int main ()
{
	int latitude = 32;
	int longitude = -64;
	
	go_south_east(&latitude, &longitude);
	
	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
	
	return 0;
}