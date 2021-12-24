// https://leetcode.com/problems/combination-sum

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        n = len(candidates)
        
        def comp(i,cands):
            if(i == n):
                if sum(cands) == target:
                    ans.append(cands.copy())
                return
                        
            if (sum(cands) + candidates[i]) <= target:
                cands.append(candidates[i])
                comp(i,cands)
                cands.pop(-1)
                
            comp(i+1,cands)
            
        comp(0,[])
        return ans
            