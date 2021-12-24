// https://leetcode.com/problems/merge-two-sorted-lists

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import copy

class Solution:
    def mergeTwoLists(self, a: ListNode, b: ListNode) -> ListNode:
        if a and b : 
            if(a.val > b.val):
                a,b=b,a
            a.next = self.mergeTwoLists(a.next,b)
        return a or b

                
                
            