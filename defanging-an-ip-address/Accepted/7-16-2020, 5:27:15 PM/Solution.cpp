// https://leetcode.com/problems/defanging-an-ip-address

class Solution {
public:
    string defangIPaddr(string address) {
        return regex_replace(address,regex("[.]"),"[.]");
    }
};