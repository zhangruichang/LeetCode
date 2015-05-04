__author__ = 'richard'
class Solution:
    # @param s, a string
    # @return a string
    def reverse_words(self, s):
        print [word[::-1] for word in s[::-1].split()]
        return ' '.join([word[::-1] for word in s[::-1].split()])

S = Solution()
s = "  Huang   If    Fu  "

print S.reverse_words(s)