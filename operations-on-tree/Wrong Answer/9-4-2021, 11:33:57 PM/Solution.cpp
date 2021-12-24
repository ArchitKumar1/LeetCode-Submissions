// https://leetcode.com/problems/operations-on-tree


class LockingTree {
public:
    vector<vector<int>> G;
    vector<bool> locker;
    vector<int> who;
    int N;
    vector<int> par;
    LockingTree(vector<int>& parent) {
        par = parent;
        N = parent.size();
        G.resize(N);
        locker.assign(N,0);
        who.assign(N,-1);
        for(int i = 1;i < N;i++){
            G[parent[i]].push_back(i);
        }
    }
    
    int dfs(int s){
        int count = locker[s];
        for(int c: G[s]){
            count += dfs(c);
        }
        return count;
    }
    void set(int s){
        locker[s] = 0;
        for(int c: G[s]) set(c);
    }
    bool lock(int num, int user) {
        if(locker[num] == 1) return 0;
        locker[num] = 1,who[num] = user;
        return 1;
    }
    
    bool unlock(int num, int user) {
        if(locker[num] == 0) return 0;
        if(who[num] != user) return 0;
        return 1;
    }
    bool anc(int num){
        while(num!=-1){
            if(locker[num] == 1) return 1;
            num = par[num];
        }
        return 0;
    }
    bool upgrade(int num, int user) {
        if(locker[num] == 1) return 0;
        int count = dfs(num);
        cout << count << " " << num << " " <<user << endl;
        if(count == 0)return 0;
        if(anc(num)) return 0;
        set(num);
        lock(num,user);
        return 1;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */