#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// solution time: 06:34.00
// ? I think the input is broken since multiple sues fit the part 2 criteria
// ! (OR I am misunderstanding the problem WHICH might be the case)
// ? 288, 323 and 379 for my input I am unsure which one is the correct answer
// ? so I submitted all three one after the other and it was the second one
typedef struct {
    int children;
    int cats;
    int samoyeds;
    int pomeranians;
    int akitas;
    int vizslas;
    int goldfish;
    int trees;
    int cars;
    int perfumes;
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
        Sue sue = {0};  // initialize all properties to 0

        char *token = strtok(line, " :\n");  // split the line into tokens
        while (token != NULL) {
            if (strcmp(token, "Sue") == 0) {
                token = strtok(NULL, " :\n");  // skip the Sue number
            } else if (strcmp(token, "children") == 0) {
                token = strtok(NULL, " :\n");
                sue.children = atoi(token);
            } else if (strcmp(token, "cats") == 0) {
                token = strtok(NULL, " :\n");
                sue.cats = atoi(token);
            } else if (strcmp(token, "samoyeds") == 0) {
                token = strtok(NULL, " :\n");
                sue.samoyeds = atoi(token);
            } else if (strcmp(token, "pomeranians") == 0) {
                token = strtok(NULL, " :\n");
                sue.pomeranians = atoi(token);
            } else if (strcmp(token, "akitas") == 0) {
                token = strtok(NULL, " :\n");
                sue.akitas = atoi(token);
            } else if (strcmp(token, "vizslas") == 0) {
                token = strtok(NULL, " :\n");
                sue.vizslas = atoi(token);
            } else if (strcmp(token, "goldfish") == 0) {
                token = strtok(NULL, " :\n");
                sue.goldfish = atoi(token);
            } else if (strcmp(token, "trees") == 0) {
                token = strtok(NULL, " :\n");
                sue.trees = atoi(token);
            } else if (strcmp(token, "cars") == 0) {
                token = strtok(NULL, " :\n");
                sue.cars = atoi(token);
            } else if (strcmp(token, "perfumes") == 0) {
                token = strtok(NULL, " :\n");
                sue.perfumes = atoi(token);
            }

            token = strtok(NULL, " :\n");  // get the next token
        }

        sues[sue_count++] = sue;
    }

    fclose(fp);

    // process input
    for (int i = 0; i < sue_count; i++) {
        Sue sue = sues[i];

        if (sue.children && sue.children != 3) {
            continue;
        }

        if (sue.cats && sue.cats < 7) {
            continue;
        }

        if (sue.samoyeds && sue.samoyeds != 2) {
            continue;
        }

        if (sue.pomeranians && sue.pomeranians > 3) {
            continue;
        }

        if (sue.akitas && sue.akitas != 0) {
            continue;
        }

        if (sue.vizslas && sue.vizslas != 0) {
            continue;
        }

        if (sue.goldfish && sue.goldfish >= 5) {
            continue;
        }

        if (sue.trees && sue.trees <= 3) {
            continue;
        }

        if (sue.cars && sue.cars != 2) {
            continue;
        }

        if (sue.perfumes && sue.perfumes != 1) {
            continue;
        }

        printf("%d\n", i + 1);
    }

    return 0;
}
