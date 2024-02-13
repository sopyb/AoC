# ? Couldn't figure out how to optimize properly, so I checked the subreddit for hints
# ? https://gist.github.com/anonymous/029b99a3e15e19d875761ca62243c317
# ? This is the solution I came up with after reading the code in the link above

# open and read the file to a string
with open("input.in", "r") as file:
    lines = [line.split() for line in file.read().split("\n")]

def get_value(registers, value):
    return registers[value] if value.isalpha() else int(value)

def cpy(registers, instructions, i, x, y):
    if y.isalpha():
        registers[y] = get_value(registers, x)
    return 1

def inc(registers, instructions, i, x):
    if x.isalpha():
        # Peephole optimize inc/dec/jnz loops
        if i + 3 < len(instructions) and i - 1 >= 0 and instructions[i-1][0] == 'cpy' and \
            instructions[i+1][0] == 'dec' and instructions[i+2][0] == 'jnz' and \
            instructions[i+3][0] == 'dec' and instructions[i+4][0] == 'jnz':

            incop = x

            cpysrc, cpydest = instructions[i-1][1:]
            dec1op = instructions[i+1][1]
            jnz1cond, jnz1off = instructions[i+2][1:]
            dec2op = instructions[i+3][1]
            jnz2cond, jnz2off = instructions[i+4][1:]

            if cpydest == dec1op and dec1op == jnz1cond and \
                dec2op == jnz2cond and \
                jnz1off == "-2" and jnz2off == "-5":
                    # inner loop:
                    # incop += cpysrc
                    # dec1op <- 0

                    # outer loop:
                    # dec2op times

                    # net result:  incop += (cpysrc * dec2op)
                    # dec1op, dec2op <- 0
                    registers[incop] += (get_value(registers, cpysrc) * get_value(registers, dec2op))
                    registers[dec1op] = 0
                    registers[dec2op] = 0
                    return 5

        registers[x] += 1
    return 1

def dec(registers, instructions, i, x):
    if x.isalpha():
        registers[x] -= 1
    return 1

def jnz(registers, instructions, i, x, y):
    return get_value(registers, y) if get_value(registers, x) != 0 else 1

def tgl(registers, instructions, i, x):
    target = i + get_value(registers, x)
    if 0 <= target < len(instructions):
        target_instruction = instructions[target]
        if len(target_instruction) == 2:
            target_instruction[0] = 'dec' if target_instruction[0] == 'inc' else 'inc'
        else:
            target_instruction[0] = 'cpy' if target_instruction[0] == 'jnz' else 'jnz'
    return 1

operations = {'cpy': cpy, 'inc': inc, 'dec': dec, 'jnz': jnz, 'tgl': tgl}

def execute_assembunny_code(instructions, registers):
    i = 0
    while i < len(instructions):
        operation, *args = instructions[i]
        jump = operations[operation](registers, instructions, i, *args)
        i += jump
    return registers['a']

registers = {'a': 12, 'b': 0, 'c': 0, 'd': 0}
print(execute_assembunny_code(lines, registers))