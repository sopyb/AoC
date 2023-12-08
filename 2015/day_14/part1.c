#include <stdio.h>
#include <string.h>

// solution time: 04:01.70
typedef struct {
    char name[16];
    int speed;
    int fly_time;
    int rest_time;
} Reindeer;

int main() {
    // read input.in
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[128];

    Reindeer reindeers[9];
    int reindeer_count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char name[16];
        int speed;
        int fly_time;
        int rest_time;

        sscanf(line, "%15s can fly %d km/s for %d seconds, but then must rest for %d seconds.", name, &speed, &fly_time, &rest_time);

        Reindeer reindeer;
        strcpy(reindeer.name, name);
        reindeer.speed = speed;
        reindeer.fly_time = fly_time;
        reindeer.rest_time = rest_time;

        reindeers[reindeer_count++] = reindeer;
    }

    fclose(fp);

    // process input
    int max_distance = 0;

    for (int i = 0; i < reindeer_count; i++) {
        Reindeer reindeer = reindeers[i];

        int distance = 0;
        int time = 0;

        while (time < 2503) {
            if (time + reindeer.fly_time > 2503) {
                distance += (2503 - time) * reindeer.speed;
                break;
            } else {
                distance += reindeer.fly_time * reindeer.speed;
                time += reindeer.fly_time;
            }

            time += reindeer.rest_time;
        }

        if (distance > max_distance) {
            max_distance = distance;
        }
    }

    printf("%d\n", max_distance);

    return 0;
}
