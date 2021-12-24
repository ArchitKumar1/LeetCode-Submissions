// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted

# @param {Integer[]} numbers
# @param {Integer} target
# @return {Integer[]}
def two_sum(numbers, target)
    
    ans = []
    i = 0
    j = numbers.length - 1
    while i < j
        if numbers[i] + numbers[j] < target
            i += 1
        elsif numbers[i]+numbers[j] == target
            ans = [i+1,j+1]
            break
        elsif numbers[i] + numbers[j] > target
            j -= 1
        end
    end
    return ans
        
end