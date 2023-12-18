#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_PACKAGES 30

// Solution Time: 5:06.00
// ! stopped and cleared timer at the same time by mistake, so this is an
// ! estimate based on browser history
long weights[MAX_PACKAGES];
int num_packages;

long min_qe = LONG_MAX;
int min_packages = INT_MAX;

void find_combinations(int index, int num, long sum, long qe) {
    if (sum == 0) {
        if (min_packages == -1 || num < min_packages || (num == min_packages && qe < min_qe)) {
            min_packages = num;
            min_qe = qe;
        }
        return;
    }

    if (index == num_packages || num >= min_packages) {
        return;
    }

    if (weights[index] <= sum) {
        find_combinations(index + 1, num + 1, sum - weights[index], qe * weights[index]);
    }

    find_combinations(index + 1, num, sum, qe);
}

int main() {
    FILE *file = fopen("input.in", "r");
    char line[MAX_PACKAGES];
    long total_weight = 0;

    while (fgets(line, sizeof(line), file)) {
        weights[num_packages] = atoll(line);
        total_weight += weights[num_packages];
        num_packages++;
    }

    fclose(file);

    find_combinations(0, 0, total_weight / 3, 1);

    printf("%ld\n", min_qe);

    return 0;
}