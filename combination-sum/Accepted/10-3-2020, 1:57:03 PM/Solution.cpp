// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    vector<int> C;
    vector<vector<int>> fans;
    
    int N;
    
    void dfs(int index,vector<int> curr,int target){
        if(target < 0) return;
        if(index == N){
            if(target == 0 ){
                fans.push_back(curr);
            }
            return;
        }
        
        dfs(index+1,curr,target);
        curr.push_back(C[index]);
        dfs(index,curr,target-C[index]);
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        C = candidates,N = C.size();
        dfs(0,vector<int>(),target);
        return fans;
    }
};