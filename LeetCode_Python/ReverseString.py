__author__ = 'richard'
def reverse(s):
    if len(s) <= 1:
        return s
    return reverse(s[1:])+s[0]

s='pao'
print reverse(s)