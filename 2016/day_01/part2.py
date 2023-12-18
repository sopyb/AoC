# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split(", ")

# Solution Time: 00:02:00
def calc_distance_to_revisited(instructions):
    x, y = 0, 0
    dx, dy = 0, 1  # north
    visited = [[x,y]]

    for instruction in instructions:
        turn, distance = instruction[0], int(instruction[1:])
        if turn == "R":
            dx, dy = dy, -dx
        else:
            dx, dy = -dy, dx

        for _ in range(distance):
            x += dx
            y += dy
            if [x,y] in visited:
                return abs(x) + abs(y)
            visited.append([x,y])

    return abs(x) + abs(y)

print(calc_distance_to_revisited(input))
