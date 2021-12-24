// https://leetcode.com/problems/find-k-th-smallest-pair-distance

class Solution {
    public int smallestDistancePair(int[] nums, int k) {
        Arrays.sort(nums);
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a,b)-> Math.abs(a[0]-a[1]) - Math.abs(b[0]-b[1]));
        for(int i = 0; i< nums.length-1; i++){
            minHeap.add(new int[]{nums[i], nums[i+1], i+1});
        }
        int index = 0;
        while(!minHeap.isEmpty()){
            int[] cur = minHeap.poll();
            if(++index == k) return  Math.abs(cur[0]-cur[1]);
            if(cur[2]==nums.length-1) continue; // the sequence end
            minHeap.add(new int[]{cur[0], nums[cur[2]+1], cur[2]+1});
           
        }
       
        return 0;
    }
}