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

viable_pairs = sum(1 for n in nodes.values() if n[1] > 0 and any(o != n and o[2] >= n[1] for o in nodes.values()))


print(viable_pairs)
