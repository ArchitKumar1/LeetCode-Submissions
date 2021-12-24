// https://leetcode.com/problems/palindrome-pairs

class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        
        n = len(words)
        
        ans = []
        for i in range(n):
            for j in range(n):
                if(i ==j): 
                    continue
                s = words[i] + words[j]
                
                if(s == s[::-1]):
                    ans.append([i,j])
                    
        return ans
                
