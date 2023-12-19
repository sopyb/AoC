# open and read the file to a string
input = open("input.in", "r")
input = input.read()


# Solution Time: 1:32
def decompress_v2(input, start, end):
    i = start
    length = 0
    while i < end:
        if input[i] != '(':
            length += 1
            i += 1
        else:
            marker_end = input.index(')', i)
            seq_len, count = map(int, input[i + 1:marker_end].split('x'))
            i = marker_end + 1
            seq_end = i + seq_len
            length += decompress_v2(input, i, seq_end) * count
            i = seq_end
    return length


print(decompress_v2(input, 0, len(input)))
