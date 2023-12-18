#include <stdio.h>

// solution time: 04:12.60 (mm:ss.ms)
int main() {
    const long FIRST_CODE = 20151125;
    const long MULTIPLIER = 252533;
    const long DIVISOR = 33554393;

    FILE *file = fopen("input.in", "r");
    if (file == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    int row, column;
    fscanf(file, "To continue, please consult the code grid in the manual.  Enter the code at row %d, column %d.", &row, &column);
    fclose(file);

    long position = ((long)row + column) * (row + column - 1) / 2 - row + 1;
    long code = FIRST_CODE;

    for (long i = 1; i < position; i++) {
        code = (code * MULTIPLIER) % DIVISOR;
    }

    printf("%ld\n", code);

    return 0;
}