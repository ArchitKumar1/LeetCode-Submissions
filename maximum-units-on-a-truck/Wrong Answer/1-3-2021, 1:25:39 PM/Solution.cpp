// https://leetcode.com/problems/maximum-units-on-a-truck

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](vector<int> a,vector<int>b){
            return a[1]>b[1];
        });
        
        int mx = 0;
        int ans=0;
        for(auto x : boxTypes){
            for(int i=0;i<x[0];i++){
                if(mx+x[1] <=truckSize ){
                    mx+=1;
                    ans+=x[0];
                }else{
                    goto end;
                }
            }
        }
        end:;
        return ans;
        
    }
};