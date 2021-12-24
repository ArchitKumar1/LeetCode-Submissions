// https://leetcode.com/problems/remove-outermost-parentheses

class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        
        stack = []
        curr = []
        fans = []
        
        for x in S:
            if x == '(':
                stack.append('(')
                curr.append('(')
            else:
                stack.pop(-1)
                curr.append(')')
                if len(stack) == 0:
                    fans += curr[1:-1]
                    curr = []
        return ''.join(fans)