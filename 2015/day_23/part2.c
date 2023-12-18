#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INSTRUCTIONS 50
#define MAX_INSTRUCTION_LENGTH 20

// Solution time: 00:34.70 (mm:ss.ms)
typedef enum {
    HLF,
    TPL,
    INC,
    JMP,
    JIE,
    JIO,
    UNKNOWN
} Instruction;

Instruction getInstructionType(char *instruction) {
    if (strncmp(instruction, "hlf", 3) == 0) return HLF;
    if (strncmp(instruction, "tpl", 3) == 0) return TPL;
    if (strncmp(instruction, "inc", 3) == 0) return INC;
    if (strncmp(instruction, "jmp", 3) == 0) return JMP;
    if (strncmp(instruction, "jie", 3) == 0) return JIE;
    if (strncmp(instruction, "jio", 3) == 0) return JIO;
    return UNKNOWN;
}

int main() {
    FILE *file = fopen("input.in", "r");
    char instructions[MAX_INSTRUCTIONS][MAX_INSTRUCTION_LENGTH];
    int num_instructions = 0;

    while (fgets(instructions[num_instructions], MAX_INSTRUCTION_LENGTH, file)) {
        instructions[num_instructions][strcspn(instructions[num_instructions], "\n")] = 0;
        num_instructions++;
    }

    fclose(file);

    int a = 1, b = 0;
    for (int i = 0; i < num_instructions; i++) {
        char *instruction = instructions[i];
        char *arg1 = strchr(instruction, ' ') + 1;
        char *arg2 = strchr(arg1, ',') ? strchr(arg1, ',') + 2 : NULL;

        switch (getInstructionType(instruction)) {
            case HLF:
                if (*arg1 == 'a') a /= 2;
                else b /= 2;
                break;
            case TPL:
                if (*arg1 == 'a') a *= 3;
                else b *= 3;
                break;
            case INC:
                if (*arg1 == 'a') a++;
                else b++;
                break;
            case JMP:
                i += atoi(arg1) - 1;
                break;
            case JIE:
                if ((*arg1 == 'a' && a % 2 == 0) || (*arg1 == 'b' && b % 2 == 0)) {
                    i += atoi(arg2) - 1;
                }
                break;
            case JIO:
                if ((*arg1 == 'a' && a == 1) || (*arg1 == 'b' && b == 1)) {
                    i += atoi(arg2) - 1;
                }
                break;
            default:
                printf("Unknown instruction: %s\n", instruction);
                break;
        }
    }

    printf("Value in register b: %d\n", b);

    return 0;
}