// https://leetcode.com/problems/smallest-k-length-subsequence-with-occurrences-of-a-letter

class Solution {
public:
    string solve(string& S, int K){
        int N = S.size();
        stack<char> answer;
        for (int i = 0; i < N; ++i) {
            if (answer.empty()) {
                answer.push(S[i]);
            }
            else {
                while ((!answer.empty())
                       && (S[i] < answer.top())
                       && (answer.size() - 1 + N - i >= K)) {
                    answer.pop();
                }
                if (answer.empty() || answer.size() < K) {
                    answer.push(S[i]);
                }
            }
        }
        string ret;
        while (!answer.empty()) {
            ret.push_back(answer.top());
            answer.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }

    
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        // string S = "aabdaabc";
        // int K = 3;
        // // string ans  = smallestSubsequence(S, K);

        int cnt = 0;
        string fans = string(k,'z');
        
        int n = s.size();
        int i =0;
        
        vector<int> sums(n+1);
        for(int i = 0;i < n;i++){
            sums[i+1] = sums[i] + (s[i] == letter);
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if( (sums[j+1]- sums[i]) < repetition) continue;
                string t = s.substr(i,j-i+1);
                if(t.size() < k) continue;
                 // cout << t << endl;
                fans = min(fans,solve(t,k));
            }
        }
//         for(int j = 0;j < n;j++){
//             if(s[j] == letter){
//                 cnt += 1;
//             }
//             while(i < n && cnt > repetition){
//                 cnt -= (s[i] == letter);
//                 i++;
//             }
//             if(cnt  == repetition){
//                 string t = s.substr(i,j-i+1);
//                 cout << t << endl;
//                 fans = min(fans,solve(t,k));
//             }
            
//         }
        return fans;
    }
};