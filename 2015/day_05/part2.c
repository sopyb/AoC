#include <stdio.h>

// solution time: 5:28.61 (mm:ss.ms)
int main() {
    // read input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    char str[100];
    int nice = 0;
    int naughty = 0;

    while (fscanf(fp, "%99s\n", str) != EOF) {
        // check if 2 letters repeat with no overlap
        int repeat = 0;
        for (int i = 0; i < 100; i++) {
            if (str[i] == '\0'
                || str[i + 1] == '\0'
                || str[i + 2] == '\0')
                break;
            for (int j = i + 2; j < 100; j++) {
                if (str[j] == '\0') break;
                if (str[i] == str[j] && str[i + 1] == str[j + 1]) {
                    repeat = 1;
                    break;
                }
            }
            if (repeat) break;
        }

        if (!repeat) {
            naughty++;
            continue;
        }

        // check if at least one letter repeats with exactly one letter in between
        repeat = 0;
        for(int i = 0; i < 100; i++) {
            if (str[i] == '\0' || str[i + 2] == '\0') break;
            if (str[i] == str[i + 2]) {
                repeat = 1;
                break;
            }
        }

        if (!repeat) {
            naughty++;
            continue;
        }

        nice++;
    }

    // close input.in
    fclose(fp);

    // print answer
    printf("nice: %d\n", nice);
    printf("naughty: %d\n", naughty);

    return 0;
}
