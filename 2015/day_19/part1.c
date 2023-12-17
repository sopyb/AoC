#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "uthash.h"

// solution time: ~5h across 3 days
// ! I never doubted the MAX_LINE_LENGTH of 256, but it was too small for the input
// ! So I was modifying the logic that seemed correct because it must be wrong
// ! I should have checked the input to upadte constants first... lesson learned
#define MAX_LINE_LENGTH 512
#define MAX_REPLACEMENTS 64

typedef struct {
    char *key;
    char *vals[MAX_REPLACEMENTS];
    int pos[MAX_REPLACEMENTS][2];
    int val_count;
    int pos_count;
} Replacement;

typedef struct {
    char id[MAX_LINE_LENGTH];
    int count;
    UT_hash_handle hh;
} Molecule;

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
    Molecule *molecules = NULL;

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        if (line[0] == '\n') continue;
            char *key = strtok(line, " =>\n");
            char *val = strtok(NULL, " =>\n");
            if (val) {
                int found = 0;
                for (int i = 0; i < repl_count; i++) {
                    if (strcmp(replacements[i].key, key) == 0) {
                        replacements[i].vals[replacements[i].val_count] = strdup(val);
                        replacements[i].val_count++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    replacements[repl_count].key = strdup(key);
                    replacements[repl_count].vals[0] = strdup(val);
                    replacements[repl_count].val_count = 1;
                    repl_count++;
                }
            } else {
                source = strdup(key);
            }
        }
    fclose(fp);

    for (int i = 0; i < repl_count; i++) {
        char *pos = source;
        while ((pos = strstr(pos, replacements[i].key)) != NULL) {
            replacements[i].pos[replacements[i].pos_count][0] = pos - source;
            replacements[i].pos[replacements[i].pos_count][1] = pos - source + strlen(replacements[i].key);
            replacements[i].pos_count++;
            pos++;
        }
    }

    for (int i = 0; i < repl_count; i++) {
        for (int j = 0; j < replacements[i].val_count; j++) {
            for (int k = 0; k < replacements[i].pos_count; k++) {
                char *head = strndup(source, replacements[i].pos[k][0]);
                char *tail = strdup(source + replacements[i].pos[k][1]);
                char new_molecule[MAX_LINE_LENGTH];
                sprintf(new_molecule, "%s%s%s", head, replacements[i].vals[j], tail);

                Molecule *s;
                HASH_FIND_STR(molecules, new_molecule, s);
                if (s==NULL) {
                    s = (Molecule*)malloc(sizeof *s);
                    strncpy(s->id, new_molecule, MAX_LINE_LENGTH);
                    s->count = 1;
                    HASH_ADD_STR(molecules, id, s);
                } else {
                    s->count++;
                }

                free(head);
                free(tail);
            }
        }
    }

    printf("Unique molecules: %u\n", HASH_COUNT(molecules));

    /* free the hash table contents */
    Molecule *current_entry, *tmp;
    HASH_ITER(hh, molecules, current_entry, tmp) {
        HASH_DEL(molecules, current_entry);
        free(current_entry);
    }

    free(source);
    for (int i = 0; i < repl_count; i++) {
        free(replacements[i].key);
        for (int j = 0; j < replacements[i].val_count; j++) {
            free(replacements[i].vals[j]);
        }
    }

    return 0;
}