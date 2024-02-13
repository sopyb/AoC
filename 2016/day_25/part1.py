# open and read the file to a string
with open("input.in", "r") as file:
    lines = [line.split() for line in file.read().split("\n")]

# ! This is absolutely cheating but oh well
# ? https://oeis.org/A000975
# ! We find the closest number that is never repeating and more than the value and subtract the value from it
# ! This is how we get the answer of what our a register should be at the start for the program to generate a clock signal

valid_never_repeating = [0, 1, 2, 5, 10, 21, 42, 85, 170, 341, 682, 1365, 2730, 5461, 10922, 21845, 43690, 87381, 174762, 349525, 699050, 1398101, 2796202, 5592405, 11184810, 22369621, 44739242, 89478485, 178956970, 357913941, 715827882, 1431655765, 2863311530, 5726623061, 11453246122]

# read first 2 args and convert to int
numbers = []
for line in lines:
    if line[0] == 'cpy' and line[1].isnumeric():
        numbers.append(int(line[1]))\

    if len(numbers) == 2:
        break

value = numbers[0] * numbers[1]
for i in valid_never_repeating:
    if i > value:
        value = i - value
        break

print(value)
