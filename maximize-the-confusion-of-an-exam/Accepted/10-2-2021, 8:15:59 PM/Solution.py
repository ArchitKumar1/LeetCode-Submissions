// https://leetcode.com/problems/maximize-the-confusion-of-an-exam

class Solution:
    def maxConsecutiveAnswers(self, A: str, k: int) -> int:

        left,count,window,leftIndex = 0,0,0,0

        for right in range(len(A)):
            if A[right] == 'F': count = count + 1
            while count > k:
                if A[left] == 'F':  count = count - 1
                left = left + 1
            if right - left + 1 > window:
                window = right - left + 1
                leftIndex = left
        
        win1 = window
        
        
        left,count,window,leftIndex = 0,0,0,0

        for right in range(len(A)):
            if A[right] == 'T': count = count + 1
            while count > k:
                if A[left] == 'T':  count = count - 1
                left = left + 1
            if right - left + 1 > window:
                window = right - left + 1
                leftIndex = left

        win2 = window        
        return max(win1,win2)