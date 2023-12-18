# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution time: 1:22
keypad = [
    [0, 0, 1, 0, 0],
    [0, 2, 3, 4, 0],
    [5, 6, 7, 8, 9],
    [0, 'A', 'B', 'C', 0],
    [0, 0, 'D', 0, 0]
]
x, y = 2,0
directions = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
bathroom_code = ""

for line in input:
    for instruction in line:
        dx, dy = directions[instruction]
        if 0 <= x + dx < 5 and 0 <= y + dy < 5 and keypad[x + dx][y + dy]  != 0:
            x += dx
            y += dy
    bathroom_code += str(keypad[x][y])

print(bathroom_code)
