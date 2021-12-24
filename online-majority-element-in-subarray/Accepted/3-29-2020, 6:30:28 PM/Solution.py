// https://leetcode.com/problems/online-majority-element-in-subarray

import numpy as np

class MajorityChecker:
    def __init__(self, arr):
        self.a = np.array(arr)

    def query(self, left, right, threshold):
        c = np.bincount(self.a[left:right+1])
        x = np.argmax(c)
        return x if c[x] >= threshold else -1

# Your MajorityChecker object will be instantiated and called as such:
# obj = MajorityChecker(arr)
# param_1 = obj.query(left,right,threshold)