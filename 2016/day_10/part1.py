# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution Time: 4:20
bots = {}
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
        low = int(instruction[6]) if instruction[5] == "bot" else None
        high = int(instruction[11]) if instruction[10] == "bot" else None
        if bot in bots and len(bots[bot]) == 2:
            if 61 in bots[bot] and 17 in bots[bot]:
                bot_responsible = bot
            if low is not None and low not in bots:
                bots[low] = []
            if high is not None and high not in bots:
                bots[high] = []
            if instruction[5] == "bot":
                bots[low].append(min(bots[bot]))
            if instruction[10] == "bot":
                bots[high].append(max(bots[bot]))
            bots[bot] = []
            instructions.remove(" ".join(instruction))
            break

print(f"bot {bot_responsible}")