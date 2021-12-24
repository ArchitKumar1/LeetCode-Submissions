// https://leetcode.com/problems/jewels-and-stones

class Solution:
    def numJewelsInStones(self, J, S):
        return sum([S.count(x) for x in J])
        