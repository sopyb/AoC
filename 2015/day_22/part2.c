#include <stdio.h>
#include <limits.h>

// solution time: 01:21.45 (mm:ss.ms)
typedef struct {
    int cost, damage, heal, armor, poison, recharge, duration;
} Spell;

typedef struct {
    int player_hp, boss_hp, mana, armor, mana_spent;
    int shield_timer, poison_timer, recharge_timer;
    int boss_damage;
} State;

Spell spells[] = {
        {53,  4, 0, 0, 0, 0,   0},
        {73,  2, 2, 0, 0, 0,   0},
        {113, 0, 0, 7, 0, 0,   6},
        {173, 0, 0, 0, 3, 0,   6},
        {229, 0, 0, 0, 0, 101, 5}
};

int min_mana_spent = INT_MAX;

void simulate_combat(State state, int player_turn) {
    if (state.mana_spent >= min_mana_spent) return;

    if (player_turn) {
        state.player_hp -= 1;
        if (state.player_hp <= 0) return;
    }

    if (state.shield_timer > 0) {
        state.armor = 7;
        state.shield_timer--;
    } else {
        state.armor = 0;
    }
    if (state.poison_timer > 0) {
        state.boss_hp -= 3;
        state.poison_timer--;
    }
    if (state.recharge_timer > 0) {
        state.mana += 101;
        state.recharge_timer--;
    }

    if (state.boss_hp <= 0) {
        if (state.mana_spent < min_mana_spent) {
            min_mana_spent = state.mana_spent;
        }
        return;
    }

    if (player_turn) {
        for (int i = 0; i < 5; i++) {
            if (state.mana >= spells[i].cost &&
                (i != 2 || state.shield_timer == 0) &&
                (i != 3 || state.poison_timer == 0) &&
                (i != 4 || state.recharge_timer == 0)) {
                State next_state = state;
                next_state.mana -= spells[i].cost;
                next_state.mana_spent += spells[i].cost;
                next_state.player_hp += spells[i].heal;
                next_state.boss_hp -= spells[i].damage;
                if (i == 2) next_state.shield_timer = 6;
                if (i == 3) next_state.poison_timer = 6;
                if (i == 4) next_state.recharge_timer = 5;
                simulate_combat(next_state, 0);
            }
        }
    } else {
        int damage = state.boss_damage - state.armor;
        if (damage < 1) damage = 1;
        state.player_hp -= damage;
        if (state.player_hp > 0) {
            simulate_combat(state, 1);
        }
    }
}

int main() {
    FILE *file = fopen("input.in", "r");
    if (file == NULL) {
        printf("Could not open file input.in\n");
        return 1;
    }

    State initial_state = {50, 0, 500, 0, 0, 0, 0, 0,
                           0};
    fscanf(file, "Hit Points: %d\nDamage: %d", &(initial_state.boss_hp),
           &(initial_state.boss_damage));
    fclose(file);

    simulate_combat(initial_state, 1);

    printf("Minimum mana spent to win the fight: %d\n", min_mana_spent);

    return 0;
}