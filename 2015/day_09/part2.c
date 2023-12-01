#include <stdio.h>
#include <string.h>
#include <limits.h>

// solution time: 0:31.70
int distanceMatrix[100][100];
char cities[100][64];
int totalCities = 0;
short visitedCities[100];
int longestlength = INT_MIN, shortestLength = INT_MAX;

int allCitiesVisited() {
    int i = 0;

    for (i = 0; i <= totalCities - 1; i++)
        if (!visitedCities[i] &&
            cities[i][0] != '\0'
                ) return 0;
    return 1;
}

int shortestPath(int startCity, int totalDistance) {
    int i = 0;

    visitedCities[startCity] = 1;

    if (allCitiesVisited()) {
        if (totalDistance > longestlength) longestlength = totalDistance;
        if (totalDistance < shortestLength) shortestLength = totalDistance;
    }

    for (i = 0; i <= totalCities; i++) {
        if (distanceMatrix[startCity][i] && !visitedCities[i]) {
            shortestPath(i, totalDistance + distanceMatrix[startCity][i]);
        }
    }
    visitedCities[startCity] = 0;
}

int main(int argc, char **argv) {
    char startCity[64], destinationCity[64];
    int distance;
    char line[256];
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%63s to %63s = %d\n", startCity, destinationCity,
               &distance);

        int startCityIndex = -1, destinationCityIndex = -1;

        for (int i = 0; i <= totalCities; i++) {
            if (strcmp(startCity, cities[i]) == 0) {
                startCityIndex = i;
            }
            if (strcmp(destinationCity, cities[i]) == 0) {
                destinationCityIndex = i;
            }
        }

        if (startCityIndex == -1) {
            strcpy(cities[totalCities], startCity);
            startCityIndex = totalCities++;
        }

        if (destinationCityIndex == -1) {
            strcpy(cities[totalCities], destinationCity);
            destinationCityIndex = totalCities++;
        }

        distanceMatrix[startCityIndex][destinationCityIndex] =
        distanceMatrix[destinationCityIndex][startCityIndex] = distance;
    }

    fclose(fp);

    for (int i = 0; i <= totalCities; i++) shortestPath(i, 0);

    printf("%d %d\n", shortestLength, longestlength);

    return 0;
}