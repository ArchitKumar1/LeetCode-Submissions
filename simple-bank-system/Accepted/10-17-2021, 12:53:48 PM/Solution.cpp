// https://leetcode.com/problems/simple-bank-system

class Bank {
public:
    vector<long long> B;
    Bank(vector<long long>& balance) {
        B = balance;
        B.insert(B.begin(),0);
    }
    bool validAccount(int account){
        return 1 <= account && account <= B.size()-1;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(!validAccount(account1) || !validAccount(account2)) return false;
        if(B[account1] < money) return false;
        B[account1] -= money;
        B[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(!validAccount(account)) return false;
        B[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(!validAccount(account)) return false;
        if(B[account] < money) return false;
        B[account] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */