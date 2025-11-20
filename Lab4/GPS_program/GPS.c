#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>
double degreesToRadians(double degrees);
int isNorthernHemisphere(double lati1);
int isSouthernHemisphere(double lati1);
double localDistanceKm(double longi1, double longi2, double lati1, double lati2);
double distanceKm(double longi1, double longi2, double lati1, double lati2);

int main(void)
{
	double longi1, longi2, lati1, lati2;
	char locations[7][20] = { "HAW Hamburg", "Eiffel Tower", "Palma de Mallorca", "Las Vegas", "Copacabana", "Waikiki Beach", "Surfer's Paradise" };
	double lon[7] = { 10.023109, 2.294481, 2.661947, -115.148736, -43.182543, -157.837456, 153.431781 };
	double lat[7] = { 53.557078, 48.858363, 39.562553, 36.156214, -22.971177, 21.281004, -28.002695 };

	printf("Enter longitude of the first place:");
	scanf("%lf", &longi1);
	printf("Enter latitude of the first place:");
	scanf("%lf", &lati1);
	printf("Enter longitude of the second place:");
	scanf("%lf", &longi2);
	printf("Enter latitude of the second place:");
	scanf("%lf", &lati2);

	printf("The distance between the two places is %.1f km \n \n", localDistanceKm(longi1, longi2, lati1, lati2));
	printf("The distance between the two places using 15.4 eq is %.1f km \n\n ", distanceKm(longi1, longi2, lati1, lati2));

	// Checks if the first location is in the northern or southern hemisphere and prints the result
	if (isNorthernHemisphere(lati1) == 1)
		printf("The first place is in the northern hemisphere\n\n");
	else if (isSouthernHemisphere(lati1) == 1)
		printf(" The first place is in the southern hemisphere\n\n");

	printf("________________________________________________________________________________________________________________________\n\n");
	printf("   Location                  Latitude       Longitude      Distance(15.4)to HAW[km]  Local distance (15.3)to HAW [km]\n");
	printf("________________________________________________________________________________________________________________________\n\n");

	// Loop to calculate and display distances for each location to the first location (HAW Hamburg).
	for (int i = 0; i < 7; i++)
	{
		printf("   %-25s %-14lf %-14lf %-25.1lf %-14.1lf\n", locations[i], lat[i], lon[i], distanceKm(lon[0], lon[i], lat[0], lat[i]), localDistanceKm(lon[0], lon[i], lat[0], lat[i]));
	}
	printf("________________________________________________________________________________________________________________________\n");
}

//Degrees to radian converter
double degreesToRadians(double degrees)
{
	// Converts degrees to radians by multiplying by Pi and dividing by 180.
	return degrees * M_PI / 180.0;
}

//Location check for northern hemisphere
int isNorthernHemisphere(double lati1)
{
	// Returns 1 if the latitude is positive (northern hemisphere), else 0.
	if (lati1 > 0)
		return 1;
	else
		return 0;
}

//Location check for southern hemisphere
int isSouthernHemisphere(double lati1)
{
	// Returns 1 if the latitude is negative (southern hemisphere), else 0
	if (lati1 < 0)
		return 1;
	else
		return 0;
}

//Calculates the distance in km according to (15.3)
double localDistanceKm(double longi1, double longi2, double lati1, double lati2)
{
	double x, y, z, distance;
	y = 111.3 * fabs(lati1 - lati2);
	z = (lati1 + lati2) / 2;
	x = 111.3 * cos(degreesToRadians(z)) * fabs(longi1 - longi2);
	x *= x;
	y *= y;
	// Returns the square root of the sum of squared distances, giving the total distance.
	return distance = sqrt(x + y);
}

//Calculates the distance in km according to (15.4)
double distanceKm(double longi1, double longi2, double lati1, double lati2)
{
	double distance;
	//Returns the exact distance between two points on earth using the Haversine Formula
	return distance = 6378.388 * acos(sin(degreesToRadians(lati1)) * sin(degreesToRadians(lati2)) + cos(degreesToRadians(lati1)) * cos(degreesToRadians(lati2)) * cos(degreesToRadians(longi1 - longi2)));
}