from collections import deque
import copy
import re

def is_valid(state):
    for floor in state:
        generators = [item for item in floor if item[1] == 'G']
        microchips = [item for item in floor if item[1] == 'M']
        if generators and (set(microchips) - set(generators)):
            return False
    return True

def get_neighbors(state, elevator):
    neighbors = []
    for direction in [-1, 1]:
        if 0 <= elevator + direction < 4:
            for i in range(len(state[elevator])):
                new_state = copy.deepcopy(state)
                new_state[elevator + direction].append(new_state[elevator].pop(i))
                if is_valid(new_state):
                    neighbors.append((new_state, elevator + direction))
                if len(state[elevator]) > 1:
                    for j in range(i + 1, len(state[elevator])):
                        new_state = copy.deepcopy(state)
                        items_to_move = [new_state[elevator].pop(j), new_state[elevator].pop(i)]
                        new_state[elevator + direction].extend(items_to_move)
                        if is_valid(new_state):
                            neighbors.append((new_state, elevator + direction))
    return neighbors

def bfs(state):
    queue = deque([(state, 0, 0)])
    visited = set()
    while queue:
        state, elevator, steps = queue.popleft()
        if (tuple(map(len, state)), elevator) in visited:
            continue
        visited.add((tuple(map(len, state)), elevator))
        if all(len(floor) == 0 for floor in state[:-1]):
            return steps
        for neighbor in get_neighbors(state, elevator):
            queue.append((*neighbor, steps + 1))
    return -1

def read_input(file_path):
    with open(file_path, 'r') as file:
        inputdata = file.read().strip().splitlines()

    state = [[], [], [], []]
    for index, line in enumerate(inputdata):
        words = line.split()
        floor = index

        if 'nothing' == words[4]:
            continue

        for i in range(4, len(words)):
            if re.findall(r'(generator|microchip)', words[i], re.IGNORECASE):
                state[floor].append(words[i - 1][0].upper() + words[i - 1][1] + words[i][0].upper())

    state[0].extend(['ElG', 'ElM', 'DiG', 'DiM'])
    return state

print(bfs(read_input('input.in')))
