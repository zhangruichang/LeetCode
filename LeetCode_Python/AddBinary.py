__author__ = 'richard'
class Solution:
    # @param {string} a
    # @param {string} b
    # @return {string}
    def addBinary(self, a, b):
        #print int(a, 2), int(b, 2)
        #print bin(int(a, 2)+int(b, 2), 10)
        return str(bin(int(a, 2)+int(b, 2)))[2:]

S=Solution()
a='10'
b='11'
print S.addBinary(a, b)