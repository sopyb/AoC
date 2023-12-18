# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution Time: 1:37
valid_triangle_count = 0

for line in input:
    line = line.split()

    if len(line) != 3:
        continue

    line = [int(x) for x in line]
    line.sort()
    if line[0] + line[1] > line[2]:
        valid_triangle_count += 1


print(valid_triangle_count)
