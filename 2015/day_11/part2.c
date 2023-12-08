#include <stdio.h>

// solution time: 00:22.60
int main() {
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[128];

    if (fgets(line, sizeof(line), fp) == NULL) {
        printf("Could not read line from file input.in\n");
        return 1;
    }

    fclose(fp);

    int times = 2;

    while (1) {
        for (int i = 7; i >= 0; i--) {
            if (line[i] == 'z') {
                line[i] = 'a';
            } else {
                line[i]++;
                break;
            }
        }

        int has_straight = 0;
        int has_two_pairs = 0;
        int has_invalid_char = 0;
        int pair_count = 0;
        char last_pair = 0;

        for (int i = 0; i < 8; i++) {
            if (line[i] == 'i' || line[i] == 'o' || line[i] == 'l') {
                has_invalid_char = 1;
                break;
            }

            if (i < 6 && line[i] + 1 == line[i + 1] && line[i] + 2 == line[i + 2]) {
                has_straight = 1;
            }

            if (i < 7 && line[i] == line[i + 1] && (pair_count == 0 || line[i] != last_pair)) {
                pair_count++;
                last_pair = line[i];
            }
        }

        has_two_pairs = pair_count >= 2;

        if (has_straight && has_two_pairs && !has_invalid_char) {
            --times;
        }

        if (times == 0) {
            break;
        }
    }

    printf("%s", line);

    return 0;
}