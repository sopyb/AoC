#include <stdio.h>

// solution time: 2:56.8 (mm:ss.ms)
int main() {
    // open input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    char c;
    int floor = 0;
    while ((c = fgetc(fp)) != EOF)
        if (c == '(') floor++;
        else floor--;

    // close input.in
    fclose(fp);

    // print answer
    printf("%d\n", floor);

    return 0;
}
