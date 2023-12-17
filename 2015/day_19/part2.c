#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Solution time: 11:37.27
#define MAX_LINE_LENGTH 512
#define MAX_REPLACEMENTS 64

typedef struct {
    char key[MAX_LINE_LENGTH];
    char val[MAX_LINE_LENGTH];
} Replacement;

char *replace_first(char *str, const char *old, const char *new) {
    char *pos = strstr(str, old);
    if (pos == NULL) {
        return str;
    }

    char buffer[MAX_LINE_LENGTH];
    strncpy(buffer, str, pos - str);
    buffer[pos - str] = '\0';

    sprintf(buffer + (pos - str), "%s%s", new, pos + strlen(old));

    strcpy(str, buffer);

    return str;
}

int main() {
    FILE *fp = fopen("input.in", "r");
    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    Replacement replacements[MAX_REPLACEMENTS];
    int repl_count = 0;
    char *source;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (line[0] == '\n') continue;
        char *key = strtok(line, " =>\n");
        char *val = strtok(NULL, " =>\n");
        if (val) {
            strncpy(replacements[repl_count].key, key, MAX_LINE_LENGTH);
            strncpy(replacements[repl_count].val, val, MAX_LINE_LENGTH);
            repl_count++;
        } else {
            source = strdup(key);
        }
    }
    fclose(fp);

    int count = 0;

    while (strcmp(source, "e") != 0) {
        for (int i = 0; i < repl_count; i++) {
            if (strstr(source, replacements[i].val) != NULL) {
                replace_first(source, replacements[i].val, replacements[i].key);
                count++;

//                printf("%d %s\n", count, source);
            }
        }
    }

    printf("Count: %d\n", count);

    return 0;
}