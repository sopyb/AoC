# open and read the file to a string
import regex

input = open("input.in", "r")
input = input.read()
input = input.split("\n")


# Solution Time: 1:20
def ssl_comp(ip):
    segments = regex.split(r'\[|\]', ip)
    out = segments[::2];
    inn = segments[1::2];

    def has_abba(s):
        for i in range(len(s) - 2):
            if s[i] == s[i + 2] and s[i] != s[i + 1]:
                yield s[i + 1] + s[i] + s[i + 1]

    def has_bab(s, aba):
        for i in range(len(s) - 2):
            if s[i] == aba[0] and s[i + 1] == aba[1] and s[i + 2] == aba[2]:
                return True
        return False

    for o in out:
        for aba in has_abba(o):
            for i in inn:
                if has_bab(i, aba):
                    return True
    return False


print(sum(map(ssl_comp, input)))
