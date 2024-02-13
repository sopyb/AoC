import hashlib

# open and read the file to a string
input = open("input.in", "r")
input = input.read()

hash_dict = {}
def find_keys():
    index = 0
    keys_found = 0
    while keys_found < 64:
        hash = get_stretched_hash(input + str(index))
        triple = find_triple(hash)
        if triple:
            for i in range(1, 1001):
                next_hash = get_stretched_hash(input + str(index + i))
                if triple * 5 in next_hash:
                    keys_found += 1
                    # print(keys_found, index, hash, next_hash)
                    break
        index += 1
    return index - 1

def find_triple(hash):
    for i in range(len(hash) - 2):
        if hash[i] == hash[i + 1] == hash[i + 2]:
            return hash[i]
    return None

def get_stretched_hash(input):
    if input in hash_dict:
        return hash_dict[input]
    else:
        hash = stretch_hash(input)
        hash_dict[input] = hash
        return hash

def stretch_hash(input):
    hash = hashlib.md5(input.encode()).hexdigest()
    for _ in range(2016):
        hash = hashlib.md5(hash.encode()).hexdigest()
    return hash

print(find_keys())