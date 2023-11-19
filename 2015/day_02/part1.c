#include <stdio.h>

// solution time: 3:25.1 (mm:ss.ms)
int main() {
    // read input from input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    int l, w, h, area = 0;

    while (fscanf(fp, "%dx%dx%d\n", &l, &w, &h) != EOF) {
        int lw = l * w;
        int wh = w * h;
        int hl = h * l;

        int min = lw;
        if (wh < min) min = wh;
        if (hl < min) min = hl;

        area += 2 * lw + 2 * wh + 2 * hl + min;
    }

    // close input.in
    fclose(fp);

    // print answer
    printf("%d\n", area);


    return 0;
}
