#include <stdio.h>
#include <string.h>

// solution time: 01:47.90
#define SIZE 100
#define STEPS 100

int main() {
    bool grid[SIZE][SIZE];
    bool new_grid[SIZE][SIZE];

    int dx[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

    FILE *file = fopen("input.in", "r");
    char temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            fscanf(file, "%c\n", &temp);
            grid[i][j] = (temp == '#');
        }
    }
    fclose(file);

    // Set the four corners to "on"
    grid[0][0] = grid[0][SIZE-1] = grid[SIZE-1][0] = grid[SIZE-1][SIZE-1] = true;

    for (int step = 0; step < STEPS; step++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int count = 0;
                for (int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < SIZE && ny >= 0 && ny < SIZE && grid[nx][ny]) {
                        count++;
                    }
                }

                if (grid[i][j] && (count == 2 || count == 3)) {
                    new_grid[i][j] = true;
                } else if (!grid[i][j] && count == 3) {
                    new_grid[i][j] = true;
                } else {
                    new_grid[i][j] = false;
                }
            }
        }

        // Set the four corners to "on"
        new_grid[0][0] = new_grid[0][SIZE-1] = new_grid[SIZE-1][0] = new_grid[SIZE-1][SIZE-1] = true;

        memcpy(grid, new_grid, sizeof(grid));
    }

    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}