# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")


def count_allowed(range_list):
    range_list.sort()
    allowed_ips = 0
    highest = 0
    for start, end in range_list:
        if highest < start:
            allowed_ips += start - highest
        if highest < end + 1:
            highest = end + 1
    # consider the IPs after the last range
    allowed_ips += 4294967296 - highest  # 4294967296 is the total number of IPs
    return allowed_ips

ranges = [list(map(int, line.split("-"))) for line in lines]
print(count_allowed(ranges))
