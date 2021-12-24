// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    var ans = [];
    var n = nums.length;
    for(var i =0 ;i<n;i++){
        var cnt = 0;
        for(var j = 0;j<n;j++){
            if(nums[i] > nums[j]){
                cnt = cnt + 1;
            }
        }
        ans.push(cnt);
    }
    return ans;
};