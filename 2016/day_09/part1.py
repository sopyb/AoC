# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")


# Solution Time: 3:12
def decompress(input):
    i = 0
    length = 0

    while i < len(input):
        if input[i] == "(":
            marker = ""
            i += 1
            while input[i] != ")":
                marker += input[i]
                i += 1
            i += 1
            marker = marker.split("x")
            length += int(marker[0]) * int(marker[1])
            i += int(marker[0])
        else:
            length += 1
            i += 1
    return length


print(decompress(input[0]))
