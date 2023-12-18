# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution Time: 3:10
valid_triangle_count = 0
triangles = []

for line in input:
    line = line.split()

    if len(line) != 3:
        continue

    line = [int(x) for x in line]
    triangles.append(line)

    # ! This messed me up for a bit
    # line.sort()

    if len(triangles) == 3:
        for i in range(3):
            column = [triangles[0][i], triangles[1][i], triangles[2][i]]
            column.sort()
            if column[0] + column[1] > column[2]:
                valid_triangle_count += 1
        triangles = []


print(valid_triangle_count)
