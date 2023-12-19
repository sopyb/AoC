# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution Time: 10:55
bots = {}
outputs = {}
instructions = []

for line in input:
    if line.startswith("value"):
        line = line.split(" ")
        value = int(line[1])
        bot = int(line[5])
        if bot not in bots:
            bots[bot] = []
        bots[bot].append(value)
    else:
        instructions.append(line)

bot_responsible = None

while len(instructions) > 0:
    for instruction in instructions:
        instruction = instruction.split(" ")
        bot = int(instruction[1])
        low = int(instruction[6])
        high = int(instruction[11])
        if bot in bots and len(bots[bot]) == 2:
            if 61 in bots[bot] and 17 in bots[bot]:
                bot_responsible = bot
            if instruction[5] == "bot":
                if low not in bots:
                    bots[low] = []
                bots[low].append(min(bots[bot]))
            else:
                outputs[low] = min(bots[bot])
            if instruction[10] == "bot":
                if high not in bots:
                    bots[high] = []
                bots[high].append(max(bots[bot]))
            else:
                outputs[high] = max(bots[bot])
            bots[bot] = []
            instructions.remove(" ".join(instruction))
            break

product = outputs[0] * outputs[1] * outputs[2]
print(product)
