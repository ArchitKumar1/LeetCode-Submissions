// https://leetcode.com/problems/rings-and-rods

class Solution {
public:
    int countPoints(string rings) {
        map<char,int> m1;
        m1['R']=0;
        m1['G']=1;
        m1['B']=2;
        bitset<10> bs[3];
        for(int i=0;i < rings.size();i+=2){
            bs[m1[rings[i]]][rings[i+1]]=1;
        }
        return (bs[0]&bs[1]&bs[2]).count();
    }
};