# open and read the file to a string
import regex

input = open("input.in", "r")
input = input.read()
input = input.split("\n")


# Solution Time: 2:52
def tls_comp(ip):
    segments = regex.split(r'\[|\]', ip)
    out = segments[::2];
    inn = segments[1::2];

    def has_abba(s):
        for i in range(len(s) - 3):
            if s[i] == s[i + 3] and s[i + 1] == s[i + 2] and s[i] != s[i + 1]:
                return True
        return False

    return any(map(has_abba, out)) and not any(map(has_abba, inn))


print(sum(map(tls_comp, input)))
