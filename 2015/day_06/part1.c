#include <stdio.h>

// solution time: 15:47.36 (mm:ss.ms)
int main() {
    // read input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    int matrix[1000][1000] = {0};
    int lit = 0;
    char str[100];

    // ! Had issues with selecting the whole line with fscanf with %s
    while (fscanf(fp, "%99[^\n]\n", str) != EOF) {
        int x1, y1, x2, y2;

//        printf("%s\nSelected: %c\n\n", str, str[6]);

        if (str[6] == 'n') {
            sscanf(str, "turn on %d,%d through %d,%d", &x1, &y1, &x2, &y2);
        } else if (str[6] == 'f') {
            sscanf(str, "turn off %d,%d through %d,%d", &x1, &y1, &x2, &y2);
        } else {
            sscanf(str, "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2);
        }

        // Turn on, off, or toggle the lights
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (str[6] == 'n') {
                    matrix[i][j] = 1;
                } else if (str[6] == 'f') {
                    matrix[i][j] = 0;
                } else {
                    // ? XOR the value with 1 to toggle it
                    // ? 0 ^ 1 = 1
                    // ? 1 ^ 1 = 0
                    matrix[i][j] ^= 1;
                }
            }
        }
    }

    // close input.in
    fclose(fp);

    // count the number of lit lights
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++)
            lit += matrix[i][j];
    }

    // print answer
    printf("%d\n", lit);

    return 0;
}
