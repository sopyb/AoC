# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")

def lowest_unlocked_ip(range_list):
    range_list.sort()
    lowest = 0
    for start, end in range_list:
        if lowest < start:
            return lowest
        elif lowest <= end:
            lowest = end + 1
    return lowest

ranges = [list(map(int, line.split("-"))) for line in lines]
print(lowest_unlocked_ip(ranges))
