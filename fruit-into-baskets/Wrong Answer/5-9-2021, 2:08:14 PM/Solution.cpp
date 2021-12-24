// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int N = tree.size();
        
        vector<int> val(N,-1);
        int fans = 0;
        for(int i=0;i <N;i++){
            if(val[i] != -1 || tree[i] == 0) continue;
            
            unordered_set<int> m1;
            int ans = 0;
            int k = i;
            for(int j = i;j <N;j++){
                if(tree[i] == 0){
                    j = N; // end loop
                    k = j;
                    continue;
                }
                m1.insert(tree[i]);
                if(m1.size() <= 2){
                    ans++;
                    fans = max(fans,ans);
                }else{
                    j = N; // end loop
                    k = j-1;
                }
            }
            for(int j = i;j <=k ;j++){
                val[i] = 0;
            }
        }
        return fans;
    }
};