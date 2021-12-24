// https://leetcode.com/problems/find-mode-in-binary-search-tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import Counter
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        def dfs(root,res):
            if root:
                res[root.val]+=1
                dfs(root.left,res)
                dfs(root.right,res)
        a = Counter()
        if not root:
            return []
        dfs(root,a)
        v = a.most_common()[0][1]
        
        ans = [k for k,l in a.items() if l ==v]
        return ans
        