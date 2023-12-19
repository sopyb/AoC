import hashlib

# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution time: 1:20
def find_password(door_id):
    password = ['_'] * 8
    index = 0
    found = 0

    while found < 8:
        to_hash = door_id + str(index)
        result = hashlib.md5(to_hash.encode())
        hex_result = result.hexdigest()

        if hex_result.startswith('00000'):
            pos = int(hex_result[5], 16)

            if pos < 8 and password[pos] == '_':
                password[pos] = hex_result[6]
                found += 1

        index += 1

    return ''.join(password)

print(find_password(input[0]))