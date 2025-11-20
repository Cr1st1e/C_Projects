#define _CRT_SECURE_NO_WARNINGS
#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EARTH_RADIUS 6371.0  // Earth's radius in km

typedef struct {
    double latitude;
    double longitude;
} geoCoord;

// Function to convert degrees to radians
double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

// Function to calculate the distance between two coordinates using the Haversine formula
double haversine(geoCoord a, geoCoord b) {
    double dLat = toRadians(b.latitude - a.latitude);
    double dLon = toRadians(b.longitude - a.longitude);
    double lat1 = toRadians(a.latitude);
    double lat2 = toRadians(b.latitude);

    double h = sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1) * cos(lat2) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(h), sqrt(1 - h));

    return EARTH_RADIUS * c;
}

int main() {
    int n;

    // Get valid number of waypoints
    while (1) {
        printf("Enter number of waypoints: ");
        if (scanf("%d", &n) == 1 && n > 0) break;
        else {
            printf("Invalid input. Try again (expected number >= 0).\n");
            while (getchar() != '\n');  // Clear input buffer
        }
    }

    // Dynamically allocate memory for waypoints
    geoCoord* waypoints = (geoCoord*)malloc(n * sizeof(geoCoord));
    if (waypoints == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Get waypoints
    for (int i = 0; i < n; i++) {
        while (1) {
            printf("Waypoint %d: ", i + 1);
            if (scanf("%lf %lf", &waypoints[i].latitude, &waypoints[i].longitude) == 2) {
                while (getchar() != '\n');
                break;
            }
            else {
                printf("Invalid input (expected \"<latitude> <longitude>\"). Try again.\n");
                while (getchar() != '\n');  // Clear input buffer
            }
        }
    }

    // Calculate total travel distance
    double total_distance = 0.0;
    for (int i = 0; i < n - 1; i++) {
        total_distance += haversine(waypoints[i], waypoints[i + 1]);
    }

    printf("\nBy taking this route you will travel %.1f km.\n", total_distance);

    // Free allocated memory
    free(waypoints);

    return 0;
}
