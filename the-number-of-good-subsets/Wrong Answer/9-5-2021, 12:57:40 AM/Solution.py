// https://leetcode.com/problems/the-number-of-good-subsets

class Solution:
    
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        primes = [2,3,5,7,11,13,17,19,23,29]
        d = {}
        for i in range(len(primes)): d[primes[i]]= i
        n = len(nums)
        
        @cache
        def getprimes(x):
            ans = []
            y = x
            for i in range(2,int(sqrt(x)+1)):
                while y%i == 0:
                    y //= i
                    ans.append(i)
            if y > 1:
                ans.append(y)     
            return ans
        
       
        @cache
        def dp(mask,i,o):
            if i == n: return 1 if o == False else 0
            terms = getprimes(nums[i])
            newmask = mask
            safe = True
            only1 = True
            ans = 0
            for t in terms:
                if (newmask >> d[t]) & 1:
                    safe = False
                else:
                    newmask |= (1 << d[t])
                    only1 = False
            if safe:
                ans += dp(newmask,i+1,only1 & o)
            ans += dp(mask,i+1,o)
            return ans

        return dp(0,0,True)
            