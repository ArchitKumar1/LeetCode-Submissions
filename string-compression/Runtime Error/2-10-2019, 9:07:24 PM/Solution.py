// https://leetcode.com/problems/string-compression

class Solution:
    def compress(self, chars: 'List[str]') -> 'int':
        a=''
        s=set(chars)
        for x in s:
            a=a+x+str(chars.count(x))
        return len(a)