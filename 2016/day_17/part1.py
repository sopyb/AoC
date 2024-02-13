import hashlib
import collections

# open and read the file to a string
with open("input.in", "r") as file:
    passcode = file.readline().strip()

def bfs():
    directions = [('U', -1, 0), ('D', 1, 0), ('L', 0, -1), ('R', 0, 1)]
    queue = collections.deque([((0, 0), '')])

    while queue:
        (x, y), path = queue.popleft()

        if (x, y) == (3, 3):
            return path

        hash = hashlib.md5((passcode + path).encode()).hexdigest()

        for i, (direction, dx, dy) in enumerate(directions):
            if hash[i] in 'bcdef':
                nx, ny = x + dx, y + dy
                if 0 <= nx < 4 and 0 <= ny < 4:
                    queue.append(((nx, ny), path + direction))

print(bfs())