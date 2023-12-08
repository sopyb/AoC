#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// solution time: 06:03.80
int min_containers = INT_MAX;
int min_combinations = 0;

void count_combinations(int* containers, int container_count, int liters, int used_containers) {
    for (int i = 0; i < container_count; i++) {
        if (containers[i] == liters) {
            if (used_containers + 1 < min_containers) {
                min_containers = used_containers + 1;
                min_combinations = 1;
            } else if (used_containers + 1 == min_containers) {
                min_combinations++;
            }
        } else if (containers[i] < liters) {
            count_combinations(containers + i + 1, container_count - i - 1, liters - containers[i], used_containers + 1);
        }
    }
}

int main() {
    int liters = 150;
    // read input.in
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[8];
    int containers[20];
    int container_count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        containers[container_count++] = atoi(line);
    }

    fclose(fp);

    count_combinations(containers, container_count, liters, 0);
    printf("%d", min_combinations);

    return 0;
}
