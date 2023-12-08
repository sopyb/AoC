#include <stdio.h>
#include <string.h>
#include <jansson.h>

// ! This needs the janosson library
// ! Debian/Ubuntu: sudo apt-get install libjansson-dev
// ! Fedora:        sudo dnf install jansson-devel
// ! Arch Linux:    sudo pacman -S jansson
// ! macOS:         brew install jansson
// solution time: 03:01.50
long json_sum(json_t *root) {
    long sum = 0;
    if (json_is_array(root)) {
        size_t index;
        json_t *value;
        json_array_foreach(root, index, value) {
            sum += json_sum(value);
        }
    } else if (json_is_object(root)) {
        const char *key;
        json_t *value;
        json_object_foreach(root, key, value) {
            if (json_is_string(value) && strcmp(json_string_value(value), "red") == 0) {
                return 0;
            }
        }
        json_object_foreach(root, key, value) {
            sum += json_sum(value);
        }
    } else if (json_is_integer(root)) {
        sum += json_integer_value(root);
    }
    return sum;
}

int main() {
    // read input.in to a string
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char text[5000000];

    if (fgets(text, sizeof(text), fp) == NULL) {
        printf("Could not read line from file input.in\n");
        return 1;
    }

    fclose(fp);

    json_error_t error;
    json_t *root = json_loads(text, 0, &error);

    if(!root) {
        fprintf(stderr, "error: on line %d: %s\n", error.line, error.text);
        return 1;
    }

    long sum = json_sum(root);
    printf("Sum of all numbers: %ld\n", sum);

    json_decref(root);

    return 0;
}
