// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> dq;
        int n = students.size();
        for(int i = 0;i<n;i++){
            dq.push_back(students[i]);
        }
        
        for(int i = 0;i<n;i++){
            if(dq.front() == sandwiches[i]){
                dq.pop_front();
            }else{
                dq.push_back(dq.front());
                dq.pop_front();
                i--;
            }
        }
        return dq.size();
    }
};