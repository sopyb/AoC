#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// solution time: 5:32.20 (mm:ss.ms)
typedef struct coords {
    int x;
    int y;
} Coords;

typedef struct ArrayList {
    Coords* data;
    int size;
    int capacity;
} ArrayList;

ArrayList* initializeArrayList(int initialCapacity)
{
    ArrayList* arrayList = (ArrayList*) malloc(sizeof(ArrayList));
    arrayList->data = (Coords*) malloc(sizeof(Coords) * initialCapacity);
    arrayList->size = 0;
    arrayList->capacity = initialCapacity;

    return arrayList;
}

void freeArrayList(ArrayList* arrayList)
{
    free(arrayList->data);
    free(arrayList);
}

void resizeArrayList(ArrayList* arrayList, int newCapacity)
{
    Coords* newData = (Coords*) realloc(arrayList->data, sizeof(Coords) * newCapacity);
    if (newData == NULL) {
        printf("Error reallocating memory!\n");
        return;
    }
    arrayList->data = newData;
    arrayList->capacity = newCapacity;
}

void addElement(ArrayList* arrayList, Coords element)
{
    if (arrayList->size == arrayList->capacity) {
        int newCapacity = arrayList->capacity == 0 ? 1 : arrayList->capacity * 2;
        resizeArrayList(arrayList, newCapacity);
    }

    arrayList->data[arrayList->size++] = element;
}

Coords getElement(const ArrayList* arrayList, int index)
{
    if (index < 0 || index >= arrayList->size) {
        printf("Index %d out of bounds for array list of size %d\n", index, arrayList->size);
        return (Coords) {NAN, NAN};
    }

    return arrayList->data[index];
}

int main() {
    // read input from input.in
    FILE *fp = fopen("input.in", "r");

    // define variables
    ArrayList *coords = initializeArrayList(0);
    addElement(coords, (Coords) {0, 0}); // add first coord
    int santaX = 0, santaY = 0;
    int roboX = 0, roboY = 0;
    int santa = 1;

    // read input
    int c;
    while ((c = fgetc(fp)) != EOF) {
        int *x, *y;

        switch (santa) {
            case 1:
                santa = 0;
                x = &santaX;
                y = &santaY;
                break;
            case 0:
                santa = 1;
                x = &roboX;
                y = &roboY;
                break;

        }

        // update coords
        switch (c) {
            case '^':
                (*y)++;
                break;
            case 'v':
                (*y)--;
                break;
            case '>':
                (*x)++;
                break;
            case '<':
                (*x)--;
                break;
            default:
                printf("Error: invalid character '%c'!\n", c);
                exit(1);
        }

        // ! I ran part 1... again... 🤦 this was used to Debug but made me realize I was running part 1
        // printf("%s: %d, %d\n", santa ? "Santa" : "Robo", *x, *y);

        // add coord
        addElement(coords, (Coords) {*x, *y});
    }

    // loop through coords and count unique coords
    int unique_coords = 0;
    for (int i = 0; i < coords->size; i++) {
        Coords coord = getElement(coords, i);
        int unique = 1;
        for (int j = 0; j < i; j++) {
            Coords other = getElement(coords, j);
            if (coord.x == other.x && coord.y == other.y) {
                unique = 0;
                break;
            }
        }
        if (unique) unique_coords++;
    }

    // close input.in
    fclose(fp);

    // print answer
    printf("%d\n", unique_coords);

    return 0;
}
