import re

# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")[2:]

regex_pattern = re.compile(r"/dev/grid/node-x(\d+)-y(\d+)\s+(\d+)T\s+(\d+)T\s+(\d+)T\s+(\d+)%")

nodes = {}
for line in lines:
    match = regex_pattern.match(line)
    if match:
        x, y, size, used, avail, use = map(int, match.groups())
        nodes[(x, y)] = (size, used, avail, use)

x_size = max(n[0] for n in nodes.keys())
y_size = max(n[1] for n in nodes.keys())

wStart = None
hole = None
grid = [[None for _ in range(x_size + 1)] for _ in range(y_size + 1)]

for (x, y), (size, used, avail, use) in nodes.items():
    grid[y][x] = (size, used, avail, use)

for y in range(len(grid)):
    for x in range(len(grid[y])):
        n = grid[y][x]
        if x == 0 and y == 0:
            print("S", end="")
        elif x == x_size and y == 0:
            print("G", end="")
        elif n[1] == 0:
            hole = (x, y)
        elif n[0] > 250:
            if wStart is None:
                wStart = (x - 1, y)
            print("#", end="")
        else:
            print(".", end="")
    print()

result = abs(hole[0] - wStart[0]) + abs(hole[1] - wStart[1])
result += abs(wStart[0] - x_size) + wStart[1]
result += 5 * (x_size - 1)

print("Board size:", x_size,"x", y_size)
print("Result", result)
