# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution Time: 4:46
def process_input(input):
    screen = [['_' for x in range(50)] for y in range(6)]
    for line in input:
        if line.startswith("rect"):
            line = line.replace("rect ", "")
            line = line.split("x")
            for x in range(int(line[0])):
                for y in range(int(line[1])):
                    screen[y][x] = "#"
        elif line.startswith("rotate row"):
            line = line.replace("rotate row y=", "")
            line = line.split(" by ")
            row = int(line[0])
            amount = int(line[1])
            for x in range(amount):
                screen[row] = [screen[row][-1]] + screen[row][:-1]
        elif line.startswith("rotate column"):
            line = line.replace("rotate column x=", "")
            line = line.split(" by ")
            column = int(line[0])
            amount = int(line[1])
            for x in range(amount):
                column_values = [screen[y][column] for y in range(len(screen))]
                column_values = column_values[-1:] + column_values[:-1]
                for y in range(len(screen)):
                    screen[y][column] = column_values[y]
    return screen

def print_screen(screen):
    for row in range(0, len(screen), 6):
        for col in range(0, len(screen[0]), 5):
            for r in range(row, row+6):
                print(''.join(screen[r][col:col+5]))
            print()

print_screen(process_input(input))