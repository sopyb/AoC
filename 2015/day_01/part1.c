#include <stdio.h>

// solution time: 2:56.8 (mm:ss.ms)
int main() {
    // open part1.in
    FILE *fp = fopen("part1.in", "r");

    // read input
    char c;
    int floor = 0;
    while ((c = fgetc(fp)) != EOF)
        if (c == '(') floor++;
        else floor--;

    // close part1.in
    fclose(fp);

    // print answer
    printf("%d\n", floor);

    return 0;
}
