# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")


def parse_instruction(instruction):
    parts = instruction.split()
    return (parts[0], parts[1:])


def get_value(registers, value):
    if value.isalpha():
        return registers[value]
    else:
        return int(value)


def execute_assembunny_code(instructions, registers):
    i = 0
    while i < len(instructions):
        operation, args = parse_instruction(instructions[i])
        if operation == 'cpy' and len(args) == 2 and args[1].isalpha():
            registers[args[1]] = get_value(registers, args[0])
        elif operation == 'inc' and args[0].isalpha():
            registers[args[0]] += 1
        elif operation == 'dec' and args[0].isalpha():
            registers[args[0]] -= 1
        elif operation == 'jnz':
            if get_value(registers, args[0]) != 0:
                i += get_value(registers, args[1])
                continue
        elif operation == 'tgl':
            target = i + get_value(registers, args[0])
            if 0 <= target < len(instructions):
                target_operation, target_args = parse_instruction(instructions[target])
                if len(target_args) == 1:
                    if target_operation == 'inc':
                        instructions[target] = 'dec ' + ' '.join(target_args)
                    else:
                        instructions[target] = 'inc ' + ' '.join(target_args)
                else:
                    if target_operation == 'jnz':
                        instructions[target] = 'cpy ' + ' '.join(target_args)
                    else:
                        instructions[target] = 'jnz ' + ' '.join(target_args)
        i += 1
    return registers['a']

registers = {'a': 7, 'b': 0, 'c': 0, 'd': 0}
print(execute_assembunny_code(lines, registers))
