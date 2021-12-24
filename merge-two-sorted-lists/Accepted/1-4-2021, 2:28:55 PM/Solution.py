// https://leetcode.com/problems/merge-two-sorted-lists

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import copy

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        fans = ans  = ListNode(0)
        while l1 or l2 : 
            if l1 and l2:
                if(l1.val < l2.val):
                    ans.next = l1
                    
                    l1 = l1.next
                else:
                    ans.next = l2
                    l2 = l2.next
            elif l1:
                ans.next = l1
                l1 = l1.next
            else:
                ans.next = l2
                l2 = l2.next
                
            ans = ans.next
        return fans.next
                
                
            