# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")

from collections import deque
from itertools import permutations

def parse_map(lines):
    points = {}
    for i in range(len(lines)):
        for j in range(len(lines[i])):
            if lines[i][j].isdigit():
                points[int(lines[i][j])] = (i, j)
    return points

def bfs(start, end, lines):
    queue = deque([(start, 0)])
    visited = {start}
    while queue:
        (x, y), steps = queue.popleft()
        if (x, y) == end:
            return steps
        for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < len(lines) and 0 <= ny < len(lines[0]) and lines[nx][ny] != '#' and (nx, ny) not in visited:
                queue.append(((nx, ny), steps + 1))
                visited.add((nx, ny))

def shortest_path(lines):
    points = parse_map(lines)
    distances = [[0]*len(points) for _ in range(len(points))]
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            distances[i][j] = distances[j][i] = bfs(points[i], points[j], lines)
    min_distance = float('inf')
    for perm in permutations(range(1, len(points))):
        distance = sum(distances[i][j] for i, j in zip((0,) + perm, perm))
        min_distance = min(min_distance, distance)
    return min_distance

# lines = [
#     "###########",
#     "#0.1.....2#",
#     "#.#######.#",
#     "#4.......3#",
#     "###########"
# ]
print(shortest_path(lines))