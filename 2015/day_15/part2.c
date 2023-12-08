#include <stdio.h>
#include <string.h>

// solution time: 01:00.10
typedef struct {
    char name[16];
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
} Ingredient;

int main() {
    FILE *fp = fopen("input.in", "r");

    if (fp == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    char line[128];
    Ingredient ingredients[4];
    int ingredient_count = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        char name[16];
        int capacity;
        int durability;
        int flavor;
        int texture;
        int calories;

        sscanf(line, "%15s capacity %d, durability %d, flavor %d, texture %d, calories %d", name, &capacity, &durability, &flavor, &texture, &calories);

        Ingredient ingredient;
        strcpy(ingredient.name, name);
        ingredient.capacity = capacity;
        ingredient.durability = durability;
        ingredient.flavor = flavor;
        ingredient.texture = texture;
        ingredient.calories = calories;

        ingredients[ingredient_count++] = ingredient;
    }

    fclose(fp);

    int max_score = 0;

    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 100 - i; j++) {
            for(int k = 0; k <= 100 - i - j; k++) {
                int l = 100 - i - j - k;

                int capacity = i * ingredients[0].capacity + j * ingredients[1].capacity + k * ingredients[2].capacity + l * ingredients[3].capacity;
                int durability = i * ingredients[0].durability + j * ingredients[1].durability + k * ingredients[2].durability + l * ingredients[3].durability;
                int flavor = i * ingredients[0].flavor + j * ingredients[1].flavor + k * ingredients[2].flavor + l * ingredients[3].flavor;
                int texture = i * ingredients[0].texture + j * ingredients[1].texture + k * ingredients[2].texture + l * ingredients[3].texture;
                int calories = i * ingredients[0].calories + j * ingredients[1].calories + k * ingredients[2].calories + l * ingredients[3].calories;

                if (calories != 500 || capacity < 0 || durability < 0 || flavor < 0 || texture < 0) {
                    continue;
                }

                int score = capacity * durability * flavor * texture;

                if (score > max_score) {
                    max_score = score;
                }
            }
        }
    }

    printf("%d\n", max_score);

    return 0;
}