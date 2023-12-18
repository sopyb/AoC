# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split(", ")

# Solution Time: 00:03:21
def calc_distance(instructions):
    x, y = 0, 0
    dx, dy = 0, 1  # north

    for instruction in instructions:
        turn, distance = instruction[0], int(instruction[1:])
        if turn == "R":
            dx, dy = dy, -dx
        else:
            dx, dy = -dy, dx

        x += dx * distance
        y += dy * distance

    return abs(x) + abs(y)


print(calc_distance(input))
