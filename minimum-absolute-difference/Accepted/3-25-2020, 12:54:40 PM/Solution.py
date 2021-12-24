// https://leetcode.com/problems/minimum-absolute-difference

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr = sorted( arr)
        ans = 10**20
        for i in range(0,len(arr)-1):
            ans = min(ans,abs(arr[i]- arr[i+1]))
        l = []
        for i in range(0,len(arr)-1):
            if(abs(arr[i]- arr[i+1]) is ans):
                l.append([arr[i],arr[i+1]])
        return l