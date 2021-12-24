// https://leetcode.com/problems/remove-stones-to-minimize-the-total

import heapq
class Solution:
    def minStoneSum(self, piles: List[int], k: int) -> int:
        piles = [-x for x in piles]
        heapq.heapify(piles)         
        
        for _ in range(k):
            t = heapq.heappop(piles)
            heapq.heappush(piles,-ceil((-t)/2))
            
            print(piles)
        return -sum(list(piles))
