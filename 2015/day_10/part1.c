#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// solution time: 03:24.00
char* look_and_say(const char* input) {
    static char result[500000];
    char current_char = input[0];
    int count = 1;
    int j = 0;

    for (int i = 1; i < strlen(input); i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            j += sprintf(&result[j], "%d%c", count, current_char);
            current_char = input[i];
            count = 1;
        }
    }
    sprintf(&result[j], "%d%c", count, current_char);

    return result;
}

int main() {
    // read input.in
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[500000];

    if (fgets(line, sizeof(line), fp) == NULL) {
        printf("Could not read line from file input.in\n");
        return 1;
    }

    fclose(fp);

    // process input
    for (int i = 0; i < 40; i++) {
        strcpy(line, look_and_say(line));
    }

    printf("%ld", strlen(line));

    return 0;
}
