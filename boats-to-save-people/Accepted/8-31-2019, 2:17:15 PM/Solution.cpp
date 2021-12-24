// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        sort(people.begin(),people.end());
        int ans = 0;
        int j = people.size()-1;
        int i = 0;
        for(;i<people.size() && i<=j;){
            if(people[i] + people[j] <=limit){
                i++;j--;
            }else{
                j--;
            }
            ans++;
        }
        return ans;
    }
};