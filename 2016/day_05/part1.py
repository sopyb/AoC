import hashlib

# open and read the file to a string
input = open("input.in", "r")
input = input.read()
input = input.split("\n")

# Solution time: 1:46
def find_password(door_id):
    password = ''
    index = 0

    while len(password) < 8:
        to_hash = door_id + str(index)
        result = hashlib.md5(to_hash.encode())
        hex_result = result.hexdigest()

        if hex_result.startswith('00000'):
            password += hex_result[5]

        index += 1

    return password

print(find_password(input[0]))