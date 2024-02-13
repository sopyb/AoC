from itertools import permutations

# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read().split("\n")

class PasswordScrambler:
    def __init__(self, password):
        self.password = list(password)

    def swap(self, a, b):
        self.password[a], self.password[b] = self.password[b], self.password[a]

    def swap_pos(self, x, y):
        self.swap(x, y)

    def swap_letter(self, a, b):
        a, b = self.password.index(a), self.password.index(b)
        self.swap(a, b)

    def rotate(self, direction, steps):
        steps %= len(self.password)
        if direction == 'left':
            self.password = self.password[steps:] + self.password[:steps]
        else:
            self.password = self.password[-steps:] + self.password[:-steps]

    def rotate_pos(self, x):
        index = self.password.index(x)
        steps = 1 + index + (1 if index >= 4 else 0)
        self.rotate('right', steps)

    def reverse(self, x, y):
        self.password[x:y+1] = self.password[x:y+1][::-1]

    def move(self, x, y):
        char = self.password.pop(x)
        self.password.insert(y, char)

    def unrotate_pos(self, x):
        index = self.password.index(x)
        end_to_start_position_map = {0: 7, 1: 0, 2: 4, 3: 1, 4: 5, 5: 2, 6: 6, 7: 3}
        steps = end_to_start_position_map[index] - index
        if steps < 0:
            steps += len(self.password)
        self.rotate('left', steps)

    def unmove(self, x, y):
        char = self.password.pop(y)
        self.password.insert(x, char)

    def get_password(self):
        return ''.join(self.password)

    def scramble(self, instructions):
        for line in instructions:
            line = line.split()
            if line[0] == 'swap':
                if line[1] == 'position':
                    self.swap_pos(int(line[2]), int(line[5]))
                else:
                    self.swap_letter(line[2], line[5])
            elif line[0] == 'rotate':
                if line[1] == 'based':
                    self.rotate_pos(line[6])
                else:
                    self.rotate(line[1], int(line[2]))
            elif line[0] == 'reverse':
                self.reverse(int(line[2]), int(line[4]))
            else:
                self.move(int(line[2]), int(line[5]))
        return self

scrambled = 'fbgdceah'
for s in permutations(scrambled):
    # ! Why did I make scrambling give the object back? I could have just made it return the password and not waste
    # ! a lot of time trying to figure out why I can't find the password in the permutations. 🤦
    if PasswordScrambler(''.join(s)).scramble(lines).get_password() == scrambled:
        print(''.join(s))
