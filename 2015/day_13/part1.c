#include <stdio.h>
#include <string.h>

// solution time: 11:01.20
#define MAX_PEOPLE 8

int happiness[MAX_PEOPLE][MAX_PEOPLE];
char names[MAX_PEOPLE][16];
int people_count = 0;
int used[MAX_PEOPLE];
int max_happiness = 0;
int current_arrangement[MAX_PEOPLE];

void calculate_happiness() {
    int total_happiness = 0;
    for (int i = 0; i < people_count; i++) {
        int left = i == 0 ? people_count - 1 : i - 1;
        int right = i == people_count - 1 ? 0 : i + 1;
        total_happiness += happiness[current_arrangement[i]][current_arrangement[left]];
        total_happiness += happiness[current_arrangement[i]][current_arrangement[right]];
    }
    if (total_happiness > max_happiness) {
        max_happiness = total_happiness;
    }
}

void generate_arrangements(int n) {
    if (n == people_count) {
        calculate_happiness();
        return;
    }
    for (int i = 0; i < people_count; i++) {
        if (!used[i]) {
            used[i] = 1;
            current_arrangement[n] = i;
            generate_arrangements(n + 1);
            used[i] = 0;
        }
    }
}

int main() {
    // read input.in
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char name1[16];
        char name2[16];
        int happiness_change;

        sscanf(line, "%15s would %15s %d happiness units by sitting next to %15s.", name1, line, &happiness_change, name2);

        // remove last character from name2 (the dot)
        name2[strlen(name2) - 1] = '\0';

        int name1_index = -1;
        int name2_index = -1;

        for (int i = 0; i < people_count; i++) {
            if (strcmp(names[i], name1) == 0) {
                name1_index = i;
            }

            if (strcmp(names[i], name2) == 0) {
                name2_index = i;
            }
        }

        if (name1_index == -1) {
            strcpy(names[people_count], name1);
            name1_index = people_count;
            people_count++;
        }

        if (name2_index == -1) {
            strcpy(names[people_count], name2);
            name2_index = people_count;
            people_count++;
        }

        happiness[name1_index][name2_index] = happiness_change * (strcmp(line, "gain") == 0 ? 1 : -1);

//        printf("%s %s %d\n", name1, name2, happiness[name1_index][name2_index]);
    }

    fclose(fp);

    memset(used, 0, sizeof(used));
    generate_arrangements(0);

    printf("%d\n", max_happiness);

    return 0;
}
