// https://leetcode.com/problems/two-sum

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}


def two_sum(nums, target)
    hash = {}
    hash2 = {}
    ans = [-1,-1]
    for i in 0...nums.length do
        x = nums[i]
        if hash[target-x] == 1
            ans =[i,hash2[target-x]]
        end
        hash[x]=1
        hash2[x] = i
    end
    return ans  
end