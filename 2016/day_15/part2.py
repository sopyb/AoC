import re

# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")

discs = []
for line in lines:
    match = re.match(r"Disc #\d+ has (\d+) positions; at time=0, it is at position (\d+).", line)
    positions = int(match.group(1))
    initial_position = int(match.group(2))
    discs.append((positions, initial_position))

discs.append((11, 0))

time = 0
while True:
    for i, (positions, initial_position) in enumerate(discs, start=1):
        position = (initial_position + time + i) % positions
        if position != 0:
            break
    else:
        break
    time += 1

print(time)