#include <stdio.h>

// solution time: 24:10.9 (mm:ss.ms)
// ! I kept running part 1 being confused why the output wasn't changing. 🤦
int main() {
    // read input from input.in
    FILE *fp = fopen("input.in", "r");

    // read input
    int l, w, h;
    int ribbon = 0;

    while (fscanf(fp, "%dx%dx%d\n", &l, &w, &h) != EOF) {
        int min, mid;

        // ! comparisons are evil
        // ! I was using < instead of <= and it was causing me to get the wrong answer
        if (l <= w && l <= h) {
            min = l;
            mid = (w < h) ? w : h;
        } else if (w <= l && w <= h) {
            min = w;
            mid = (l < h) ? l : h;
        } else {
            min = h;
            mid = (l < w) ? l : w;
        }

        ribbon += (min + min + mid + mid) + (l * w * h);
    }

    // close input.in
    fclose(fp);

    // print answer
    printf("%d\n", ribbon);


    return 0;
}
