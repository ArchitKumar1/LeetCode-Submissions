// https://leetcode.com/problems/recover-a-tree-from-preorder-traversal

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, traversal: str) -> TreeNode:
        n = len(traversal)
        st = []
        i = 0
        while i < n:
            cnt = 0;
            while i < n and traversal[i] == '-':
                cnt += 1
                i += 1
            val = 0
            while i < n and traversal[i] !='-':
                val *= 10
                val += int(traversal[i])
                i += 1
            
            while st and len(st) > cnt:
                st.pop()
            t = TreeNode(val)
            
            if st:
                node = st[-1]
                if not node.left:
                    node.left = t
                else:
                    node.right = t
            st.append(t)
        return st[0]
            
                
            
            