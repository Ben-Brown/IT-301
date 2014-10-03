//Ben Brown
//southeast.C PG 45
//This is a basic navigation program.
#include <stdio.h>

void go_south_east(int lat, int lon)
{
	lat = lat - 1;
	lon = lon + 1;
}

int main ()
{
	int latitude = 32;
	int longitude = -64;
	go_south_east(latitude, longitude);
	printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
	return 0;
}
//This program compiles but the coordinates do not change.  This is because the values for latitude and longitude that are stored in memory aren't changed.  The variables need to be a pointer to an int type so that the values stored in memory are changed.