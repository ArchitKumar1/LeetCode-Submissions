// https://leetcode.com/problems/three-equal-parts

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        
        int cnt = count(A.begin(),A.end(),1);
        vector<int> ccnt(n,0);
        ccnt[0] = A[0];
        
        for(int i =1;i<n;i++){
            ccnt[i] += ccnt[i-1] + (A[i] == 1); 
        }
        if(cnt %3 != 0) return {-1,-1};
        
        auto it1 = lower_bound(ccnt.begin(),ccnt.end(),cnt/3);
        auto it2 = lower_bound(ccnt.begin(),ccnt.end(),2*cnt/3);
        
        
        int l1 = it1 - ccnt.begin();
        int l2 = it2 - ccnt.begin() + 1;
        int x = it1 - ccnt.begin();
        int y = it2 - ccnt.begin();
        int z = n-1;
        
        cout << x << " " << y << " " << z << endl;
        cout << l1 << "  " << l2 << endl;
        bool ok = 1;
        for(;x>=0 && y>=l1 && z>=l2;x--,y--,z--){
            if(A[x] != A[y] || A[y] != A[z]) {
                ok =0;
                break;
            }
            
        }
        if(ok){
            return {l1,l2};
        }else{
            return {-1,-1};
        }
        
        
        
            
        
        
    }
};