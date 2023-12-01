#include <stdio.h>
#include <string.h>

// solution time: 02:38.22
int main() {
    // read input from file
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[256];
    int total_code_chars = 0;
    int total_memory_chars = 0;

    while (fgets(line, sizeof(line), fp)) {
        int line_len = strlen(line) - 1;  // -1 skips \n
        total_code_chars += line_len;

        // 1 to len-1 to exclude the quotes
        for (int i = 1; i < line_len - 1; i++) {
            if (line[i] == '\\') {
                if (line[i + 1] == '\\' || line[i + 1] == '\"') {
                    i++;  // Skip the next character
                } else if (line[i + 1] == 'x') {
                    i += 3;
                }
            }
            total_memory_chars++;
        }
    }

    fclose(fp);

    printf("%d\n", total_code_chars - total_memory_chars);

    return 0;
}
