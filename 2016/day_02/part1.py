# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution Time: 1:05
keypad = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
x, y = 1, 1
directions = {'U': (-1, 0), 'D': (1, 0), 'L': (0, -1), 'R': (0, 1)}
bathroom_code = ""

for line in input:
    for instruction in line:
        dx, dy = directions[instruction]
        if 0 <= x + dx < 3 and 0 <= y + dy < 3:
            x += dx
            y += dy
    bathroom_code += str(keypad[x][y])

print(bathroom_code)
