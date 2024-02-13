import hashlib

# open and read the file to a string
input = open("input.in", "r")
input = input.read()

def find_keys():
    index = 0
    keys_found = 0
    while keys_found < 64:
        hash = hashlib.md5((input + str(index)).encode()).hexdigest()
        triple = find_triple(hash)
        if triple:
            for i in range(1, 1001):
                next_hash = hashlib.md5((input + str(index + i)).encode()).hexdigest()
                if triple * 5 in next_hash:
                    keys_found += 1
                    break
        index += 1
    return index - 1

def find_triple(hash):
    for i in range(len(hash) - 2):
        if hash[i] == hash[i + 1] == hash[i + 2]:
            return hash[i]
    return None

print(find_keys())