# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = int(input)

def is_open(x, y):
    return bin(x*x + 3*x + 2*x*y + y + y*y + input).count('1') % 2 == 0

def neighbors(x, y):
    for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        nx, ny = x + dx, y + dy
        if nx >= 0 and ny >= 0 and is_open(nx, ny):
            yield nx, ny

def print_maze(width, height):
    for y in range(height):
        for x in range(width):
            print('.' if is_open(x, y) else '#', end='')
        print()

def bfs(start, goal):
    queue = [(start, 0)]
    visited = set()
    while queue:
        (x, y), dist = queue.pop(0)
        if (x, y) == goal:
            return dist
        for nx, ny in neighbors(x, y):
            if (nx, ny) not in visited:
                visited.add((nx, ny))
                queue.append(((nx, ny), dist + 1))
    return -1

# print_maze(50, 50)
print(bfs((1, 1), (31, 39)))


