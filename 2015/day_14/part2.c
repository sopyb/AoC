#include <stdio.h>
#include <string.h>

// solution time: 02:15.00
typedef struct {
    char name[16];
    int speed;
    int fly_time;
    int rest_time;
    int points;
} Reindeer;

int main() {
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
        reindeer.points = 0;

        reindeers[reindeer_count++] = reindeer;
    }

    fclose(fp);

    int distances[reindeer_count][2503];
    memset(distances, 0, sizeof(distances));

    for (int second = 1; second < 2503; second++) {
        for (int i = 0; i < reindeer_count; i++) {
            Reindeer reindeer = reindeers[i];
            int cycle_time = reindeer.fly_time + reindeer.rest_time;

            if (second % cycle_time <= reindeer.fly_time && second % cycle_time != 0) {
                distances[i][second] = distances[i][second - 1] + reindeer.speed;
            } else {
                distances[i][second] = distances[i][second - 1];
            }
        }

        int max_distance = 0;
        for (int i = 0; i < reindeer_count; i++) {
            if (distances[i][second] > max_distance) {
                max_distance = distances[i][second];
            }
        }

        for (int i = 0; i < reindeer_count; i++) {
            if (distances[i][second] == max_distance) {
                reindeers[i].points++;
            }
        }
    }

    int max_points = 0;
    for (int i = 0; i < reindeer_count; i++) {
        if (reindeers[i].points > max_points) {
            max_points = reindeers[i].points;
        }
    }

    printf("%d\n", max_points);

    return 0;
}