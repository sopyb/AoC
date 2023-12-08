#include <stdio.h>
#include <stdlib.h>

// solution time: 02:53.30
int count_combinations(int* containers, int container_count, int liters) {
    int combinations = 0;

    for (int i = 0; i < container_count; i++) {
        if (containers[i] == liters) {
            combinations++;
        } else if (containers[i] < liters) {
            combinations += count_combinations(containers + i + 1, container_count - i - 1, liters - containers[i]);
        }
    }

    return combinations;
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

    printf("%d", count_combinations(containers, container_count, liters));

    return 0;
}
