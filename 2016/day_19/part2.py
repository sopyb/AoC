from collections import deque

# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read()

def find_all_presents_elf(count):
    winner = 1
    for i in range(1, count):
        winner = winner % i + 1
        if winner > (i + 1) // 2:
            winner += 1
    return winner



print(find_all_presents_elf(int(lines)))
