# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution 1:33
freqs = [{} for i in range(len(input[0]))]

for line in input:
    for i in range(len(line)):
        if line[i] in freqs[i]:
            freqs[i][line[i]] += 1
        else:
            freqs[i][line[i]] = 1

message = ""
for freq in freqs:
    message += max(freq, key=freq.get)
print(message)
