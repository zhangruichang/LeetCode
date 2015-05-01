__author__ = 'richard'
class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        return ' '.join(s.split()[2])

S=Solution();
s="Huang If Fu"

print S.reverseWords(s)