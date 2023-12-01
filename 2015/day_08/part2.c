#include <stdio.h>
#include <string.h>

// solution time: 21:11.70 (Embarrassing how long it took me to realize this)
int main() {
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[256];
    int total = 0;

    while (fgets(line, sizeof(line), fp)) {
        int line_len = strlen(line);

        for(int i = 0; i< line_len; i++)
            if (line[i] == '\\' || line[i] == '\"') total++;

        // ! Initially this was in the for loop above
        total += 2; // ? Count the quotes
    }

    fclose(fp);

    printf("%d\n", total);

    return 0;
}