#include <stdio.h>
#include <limits.h>

// solution time: 01:29.55 (mm:ss.ms)
typedef struct {
    int cost;
    int damage;
    int armor;
} Item;

typedef struct {
    int hit_points;
    int damage;
    int armor;
} Character;

#define WEAPONS_SIZE 5
Item weapons[] = {{8,  4, 0},
                  {10, 5, 0},
                  {25, 6, 0},
                  {40, 7, 0},
                  {74, 8, 0}};
#define ARMOR_SIZE 6
Item armor[] = {{0,   0, 0},
                {13,  0, 1},
                {31,  0, 2},
                {53,  0, 3},
                {75,  0, 4},
                {102, 0, 5}};
#define RINGS_SIZE 8
Item rings[] = {{0,   0, 0},
                {0,   0, 0},
                {25,  1, 0},
                {50,  2, 0},
                {100, 3, 0},
                {20,  0, 1},
                {40,  0, 2},
                {80,  0, 3}};

int simulate_fight(Character player, Character boss) {
    while (1) {
        boss.hit_points -=
                player.damage - boss.armor > 0 ? player.damage - boss.armor : 1;
        if (boss.hit_points <= 0) return 1;
        player.hit_points -=
                boss.damage - player.armor > 0 ? boss.damage - player.armor : 1;
        if (player.hit_points <= 0) return 0;
    }
}

int main() {
    Character player = {100, 0, 0};
    Character boss;

    FILE *file = fopen("input.in", "r");
    fscanf(file, "Hit Points: %d\nDamage: %d\nArmor: %d\n", &boss.hit_points,
           &boss.damage, &boss.armor);
    fclose(file);

    int max_gold = INT_MIN;

    for (int i = 0; i < WEAPONS_SIZE; i++) {
        for (int j = 0; j < ARMOR_SIZE; j++) {
            for (int k = 0; k < RINGS_SIZE; k++) {
                for (int l = k + 1; l < RINGS_SIZE; l++) {
                    Character player_copy = player;
                    player_copy.damage += weapons[i].damage + rings[k].damage +
                                          rings[l].damage;
                    player_copy.armor +=
                            armor[j].armor + rings[k].armor + rings[l].armor;

                    Character boss_copy = boss;
                    while (1) {
                        boss_copy.hit_points -=
                                player_copy.damage - boss_copy.armor > 0 ? player_copy.damage - boss_copy.armor : 1;
                        if (boss_copy.hit_points <= 0) break;
                        player_copy.hit_points -=
                                boss_copy.damage - player_copy.armor > 0 ? boss_copy.damage - player_copy.armor : 1;
                        if (player_copy.hit_points <= 0) break;
                    }

                    if (player_copy.hit_points <= 0) {
                        int gold = weapons[i].cost + armor[j].cost +
                                   rings[k].cost + rings[l].cost;
                        if (gold > max_gold) max_gold = gold;
                    }
                }
            }
        }
    }

    printf("%d\n", max_gold);
    return 0;
}