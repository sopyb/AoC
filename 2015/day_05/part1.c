#include <stdio.h>

// solution time: 7:12.83 (mm:ss.ms)
int main() {
    // read input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    char str[100];
    int nice = 0;
    int naughty = 0;

    while (fscanf(fp, "%99s\n", str) != EOF) {
        // check if it contains at least 3 vowels
        int vowels = 0;
        for (int i = 0; i < 100; i++) {
            if (str[i] == '\0') break;
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u') {
                vowels++;
            }
        }
        if (vowels < 3) {
            naughty++;
            continue;
        }

        // check if it contains at least one letter that appears twice in a row
        int twice = 0;
        for (int i = 0; i < 100; i++) {
            if (str[i] == '\0') break;
            if (str[i] == str[i + 1]) {
                twice = 1;
                break;
            }
        }

        if (!twice) {
            naughty++;
            continue;
        }

        // check if it contains any of the following strings:
        // ab, cd, pq, or xy
        int bad = 0;
        for (int i = 0; i < 100; i++) {
            if (str[i] == '\0') break;
            if (str[i] == 'a' && str[i + 1] == 'b') {
                bad = 1;
                break;
            }
            if (str[i] == 'c' && str[i + 1] == 'd') {
                bad = 1;
                break;
            }
            if (str[i] == 'p' && str[i + 1] == 'q') {
                bad = 1;
                break;
            }
            if (str[i] == 'x' && str[i + 1] == 'y') {
                bad = 1;
                break;
            }
        }

        if (bad) {
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
