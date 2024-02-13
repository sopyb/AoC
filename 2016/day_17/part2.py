import hashlib

# open and read the file to a string
with open("input.in", "r") as file:
    passcode = file.readline().strip()

def dfs():
    directions = [('U', -1, 0), ('D', 1, 0), ('L', 0, -1), ('R', 0, 1)]
    stack = [((0, 0), '')]
    longest_path = ''

    while stack:
        (x, y), path = stack.pop()

        if (x, y) == (3, 3):
            if len(path) > len(longest_path):
                longest_path = path
            continue

        hash = hashlib.md5((passcode + path).encode()).hexdigest()

        for i, (direction, dx, dy) in enumerate(directions):
            if hash[i] in 'bcdef':
                nx, ny = x + dx, y + dy
                if 0 <= nx < 4 and 0 <= ny < 4:
                    stack.append(((nx, ny), path + direction))

    return len(longest_path)

print(dfs())