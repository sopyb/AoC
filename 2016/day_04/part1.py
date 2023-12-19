from collections import Counter

# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")


# Solution Time: 3:24
def get_sector_sum(input):
    sector_sum = 0
    for line in input:
        checksum = line[-6:-1]
        encrypted_name = line[:-7]

        encrypted_name = encrypted_name.split("-")
        sector_id = int(encrypted_name[-1])
        encrypted_name = encrypted_name[:-1]

        encrypted_name = "".join(encrypted_name)

        letters = Counter(encrypted_name)

        letter_items = letters.items()

        def sort_letters(x):
            letters = x[0]
            count = x[1]
            return (-count, letters)

        sorted_letters = sorted(letter_items, key=sort_letters)

        checksum_from_letters = ""
        for i in range(5):
            checksum_from_letters += sorted_letters[i][0]
        if checksum == checksum_from_letters:
            sector_sum += sector_id

    return sector_sum


print(get_sector_sum(input))
