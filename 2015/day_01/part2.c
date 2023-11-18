#include <stdio.h>

// solution time: 0:55.5 (mm:ss.ms)
int main() {
    // open input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    char c;
    int floor = 0, position = 0;
    while ((c = fgetc(fp)) != EOF) {
        position++;
        if (c == '(') floor++;
        else floor--;

        if (floor == -1) break;
    }

    // close input.in
    fclose(fp);

    // print answer
    printf("%d\n", position);
    return 0;
}
