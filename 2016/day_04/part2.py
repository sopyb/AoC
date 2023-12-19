from collections import Counter

# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")


# Solution Time: 2:59
def decrypt_name(name, sector_id):
    decrypted_name = ""
    for letter in name:
        if letter == "-":
            decrypted_name += " "
        else:
            letter = ord(letter) - 97
            letter = (letter + sector_id) % 26
            letter = chr(letter + 97)
            decrypted_name += letter
    return decrypted_name

def get_sector_id(input):
    for line in input:
        encrypted_name = line[:-7]

        encrypted_name = encrypted_name.split("-")
        sector_id = int(encrypted_name[-1])
        encrypted_name = encrypted_name[:-1]

        encrypted_name = "".join(encrypted_name)

        decrypted_name = decrypt_name(encrypted_name, sector_id)

        if "north" in decrypted_name:
            return sector_id


print(get_sector_id(input))
