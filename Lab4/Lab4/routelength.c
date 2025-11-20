#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846

#include <stdio.h>
#include <math.h>

double getRouteLengthKm(double* lon, double* lat, int n);
double distanceKm(double longi1, double longi2, double lati1, double lati2);
double degreesToRadians(double degrees);

int main()
{
	double lon[7] = { -47.6560, -48.1139, -48.4108, -47.9532, -48.1725, -47.7351, -47.6096 };
	double lat[7] = { -71.0369, -71.0256, -71.1397, -71.1203, -71.2518, -71.2021, -71.0584 };
	int size = sizeof lon / sizeof lon[0];
	printf("The total route distance is %lf km", getRouteLengthKm(lon, lat, size));
}

//Calculates the total distance of the route between coordinates
double getRouteLengthKm(double *lon, double *lat, int n)
{
	double routeDistance = 0;

	//loop for calculating the distance between two adjacent coordinates
	for (int i = 0; i < n-1 ; i++)
	{
		routeDistance += distanceKm( lon [i] , lon[i + 1], lat[i], lat[i + 1] );
	}
	return routeDistance;
}

//Calculates the distance in km according to (15.4)
double distanceKm(double longi1, double longi2, double lati1, double lati2)
{
	double distance;

	//Returns the exact distance between two points on earth using the Haversine Formula
	return distance = 6378.388 * acos(sin(degreesToRadians(lati1)) * sin(degreesToRadians(lati2)) + cos(degreesToRadians(lati1)) * cos(degreesToRadians(lati2)) * cos(degreesToRadians(longi1 - longi2)));
}

//Degrees to radian converter
double degreesToRadians(double degrees)
{
	// Converts degrees to radians by multiplying by Pi and dividing by 180.
	return degrees * M_PI / 180.0;
}