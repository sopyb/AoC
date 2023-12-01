#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Solution time: ~6h (both parts - lost track - I was stuck on a SIGSEGV for a long time)

typedef enum {
    AND,
    OR,
    NOT,
    LSHIFT,
    RSHIFT,
    ASSIGN
} InstructionType;

typedef struct {
    char leftOperand[64];
    char rightOperand[64];
    unsigned short result;
    InstructionType operation;
} Instruction;

unsigned short circuitWireValues[1000];
Instruction instructions[1000];

int computeWireHash(char *str) {
    int result = 0;
    int i;

    int length = strlen(str);
    for (i = 1; i <= length; i++) {
        int charValue = str[i - 1] - 'a';
        result += charValue + (length - i) * 31 * (charValue + 1);
    }

    return result;
}

Instruction *getInstructionByWire(char *str) {
    int wire = atoi(str);

    if (!wire && *str && *str != '0') {
        wire = computeWireHash(str);

        for (int i = 0; i < 1000; i++) {
            if (instructions[i].result == wire) {
                return &instructions[i];
            }
        }
    }

    return NULL;
}

unsigned short value(Instruction *i) {
    if (circuitWireValues[i->result] && i->operation != ASSIGN)
        return circuitWireValues[i->result];

    unsigned short left =
            getInstructionByWire(i->leftOperand) == NULL ? atoi(i->leftOperand) : value(
                    getInstructionByWire(i->leftOperand));
    unsigned short right =
            getInstructionByWire(i->rightOperand) == NULL ? atoi(i->rightOperand) : value(
                    getInstructionByWire(i->rightOperand));

    switch (i->operation) {
        case ASSIGN:
            return circuitWireValues[i->result] = left;
        case RSHIFT:
            return circuitWireValues[i->result] = left >> right;
        case LSHIFT:
            return circuitWireValues[i->result] = left << right;
        case NOT:
            return circuitWireValues[i->result] = ~left;
        case OR:
            return circuitWireValues[i->result] = left | right;
        case AND:
            return circuitWireValues[i->result] = left & right;
    }
}

void parseInstruction(char* left, char* right, int index) {
    if (strstr(left, "AND")) {
        sscanf(left, "%s AND %s", instructions[index].leftOperand, instructions[index].rightOperand);
        instructions[index].operation = AND;
    } else if (strstr(left, "OR")) {
        sscanf(left, "%s OR %s", instructions[index].leftOperand, instructions[index].rightOperand);
        instructions[index].operation = OR;
    } else if (strstr(left, "NOT")) {
        sscanf(left, "NOT %s", instructions[index].leftOperand);
        instructions[index].operation = NOT;
    } else if (strstr(left, "LSHIFT")) {
        sscanf(left, "%s LSHIFT %s", instructions[index].leftOperand, instructions[index].rightOperand);
        instructions[index].operation = LSHIFT;
    } else if (strstr(left, "RSHIFT")) {
        sscanf(left, "%s RSHIFT %s", instructions[index].leftOperand, instructions[index].rightOperand);
        instructions[index].operation = RSHIFT;
    } else {
        sscanf(left, "%s", instructions[index].leftOperand);
        instructions[index].operation = ASSIGN;
    }

    instructions[index].result = computeWireHash(right);
}

int main(void) {
    char left[64], right[64];
    int wireCount = 0;

    FILE *file = fopen("input.in", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    while (fscanf(file, "%20[0-9a-zA-Z ] -> %s\n", left, right) != -1)
        parseInstruction(left, right, wireCount++);

    fclose(file);

    printf("%d\n", value(getInstructionByWire("a")));
}