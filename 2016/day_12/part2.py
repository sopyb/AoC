# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

registers = {'a': 0, 'b': 0, 'c': 1, 'd': 0}
i = 0

while i < len(input):
    line = input[i]
    if line.startswith('cpy'):
        x, y = line.split()[1:]
        if x in registers:
            x = registers[x]
        if y in registers:
            registers[y] = int(x)
    elif line.startswith('inc'):
        registers[line.split()[1]] += 1
    elif line.startswith('dec'):
        registers[line.split()[1]] -= 1
    elif line.startswith('jnz'):
        x, y = line.split()[1:]
        if x in registers:
            x = registers[x]
        if x != 0:
            i += int(y)
            continue
    i += 1

print(registers['a'])
