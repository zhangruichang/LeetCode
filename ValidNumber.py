import os;
class Solution:
# @param s, a string
# @return a boolean
    def isNumber(self, s):
    num_s=s.strip().lower()
    (_start, _num1, _e, _signed_e, _null_point, _num_point, _num2, _num3)=range(8)
    state=_start
    for c in num_s:
        if state==_start:
            if c=='.':
                state=_null_point
            elif c=='-' or c=='+':
                state=_start
            elif ord(c)>=48 and ord(c)<=57:
                state=_num1
            else:
                return False
        elif state==_num1:
            if c=='.':
                state=_num_point
            elif c=='e':
                state=_e
            elif ord(c)>=48 and ord(c)<=57:
                state=_num1
            else:
                return False
        elif state==_null_point:
            if ord(c)>=48 and ord(c)<=57:
                state=_num2
            else:
                return False
        elif state==_num_point:
            if ord(c)>=48 and ord(c)<=57:
                state=_num2
            elif c=='e':
                state=_e
            else:
                return False
        elif state==_num2:
            if ord(c)>=48 and ord(c)<=57:
                state=_num2
            elif c=='e':
                state=_e
            else:
                return False
        elif state==_e:
            if ord(c)>=48 and ord(c)<=57:
                state=_num3
            elif c=='-' or c=='+':
                state=_signed_e
            else:
                return False
        elif state==_signed_e:
            if ord(c)>=48 and ord(c)<=57:
                state=_num3
            else:
                return False
        elif state==_num3:
            if ord(c)>=48 and ord(c)<=57:
                state=_num3
            else:
                return False
    if state==_num_point or state==_num1 or state==_num2 or state==_num3:
        return True
    else:
        return False