#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// solution time: 06:34.00
// ! I wasn't initially accounting for the fact that the input could be 0 for a property
typedef struct {
    int *children;
    int *cats;
    int *samoyeds;
    int *pomeranians;
    int *akitas;
    int *vizslas;
    int *goldfish;
    int *trees;
    int *cars;
    int *perfumes;
} Sue;

int main() {
    Sue sues[500];

    // read input.in
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[128];

    int sue_count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        Sue sue = {NULL};  // initialize all properties to NULL

        char *token = strtok(line, " :\n");  // split the line into tokens
        while (token != NULL) {
            if (strcmp(token, "Sue") == 0) {
                token = strtok(NULL, " :\n");  // skip the Sue number
            } else {
                int *value = malloc(sizeof(int));
                *value = atoi(strtok(NULL, " :\n"));

                if (strcmp(token, "children") == 0) {
                    sue.children = value;
                } else if (strcmp(token, "cats") == 0) {
                    sue.cats = value;
                } else if (strcmp(token, "samoyeds") == 0) {
                    sue.samoyeds = value;
                } else if (strcmp(token, "pomeranians") == 0) {
                    sue.pomeranians = value;
                } else if (strcmp(token, "akitas") == 0) {
                    sue.akitas = value;
                } else if (strcmp(token, "vizslas") == 0) {
                    sue.vizslas = value;
                } else if (strcmp(token, "goldfish") == 0) {
                    sue.goldfish = value;
                } else if (strcmp(token, "trees") == 0) {
                    sue.trees = value;
                } else if (strcmp(token, "cars") == 0) {
                    sue.cars = value;
                } else if (strcmp(token, "perfumes") == 0) {
                    sue.perfumes = value;
                }
            }

            token = strtok(NULL, " :\n");  // get the next token
        }

        sues[sue_count++] = sue;
    }

    fclose(fp);

    // process input
    for (int i = 0; i < sue_count; i++) {
        Sue sue = sues[i];

        if (sue.children && *sue.children != 3) {
            continue;
        }

        if (sue.cats && *sue.cats < 7) {
            continue;
        }

        if (sue.samoyeds && *sue.samoyeds != 2) {
            continue;
        }

        if (sue.pomeranians && *sue.pomeranians > 3) {
            continue;
        }

        if (sue.akitas && *sue.akitas != 0) {
            continue;
        }

        if (sue.vizslas && *sue.vizslas != 0) {
            continue;
        }

        if (sue.goldfish && *sue.goldfish >= 5) {
            continue;
        }

        if (sue.trees && *sue.trees <= 3) {
            continue;
        }

        if (sue.cars && *sue.cars != 2) {
            continue;
        }

        if (sue.perfumes && *sue.perfumes != 1) {
            continue;
        }

        printf("%d\n", i + 1);
        break;
    }

    return 0;
}
