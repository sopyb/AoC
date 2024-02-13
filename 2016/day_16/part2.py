# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read()

def dragon(e):
    return e + "0" + e[::-1].translate(str.maketrans("01", "10"))

def checksum(e):
    c = ""
    for i in range(0, len(e), 2):
        c += "1" if e[i] == e[i + 1] else "0"
    return c if len(c) % 2 else checksum(c)

d_size = 35651584
while len(lines) < d_size:
    lines = dragon(lines)

lines = lines[:d_size]
print(checksum(lines))