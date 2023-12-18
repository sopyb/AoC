#include <stdio.h>
#include <stdlib.h>

// solution time: 05:56.22 (mm:ss.ms)
int main() {
    FILE *fp;
    fp = fopen("input.in", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    getline(&line, &len, fp);
    int input = atoi(line);
    fclose(fp);

    int *presents = (int *)calloc(input, sizeof(int));

    for (int elf = 1; elf <= input; elf++) {
        for (int house = elf; house <= input; house += elf) {
            presents[house] += elf * 10;
        }
    }

    int house;
    for (house = 1; house <= input; house++) {
        if (presents[house] >= input) {
            break;
        }
    }

    printf("House: %d\n", house);

    free(presents);

    return 0;
}