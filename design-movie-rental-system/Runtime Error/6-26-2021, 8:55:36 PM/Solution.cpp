// https://leetcode.com/problems/design-movie-rental-system


class MovieRentingSystem {

public:
    int n;
    vector<set<pair<int,int>>> S;
    vector<set<pair<int,int>>> M;
    set<vector<int>> R;
    map<pair<int,int>,int> P;
    MovieRentingSystem(int N, vector<vector<int>>& entries) {
        n = N;
        S.resize(100001);M.resize(100001);
        for(auto x : entries){
            int s = x[0],m = x[1],p = x[2];
            S[s].insert({m,p});
            M[m].insert({p,s});
            P[{m,s}] = p;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int cnt =  5;
        for(auto x : M[movie]){
            if(cnt == 0) break;
            res.push_back(x.second);
            cnt--;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = P[{movie,shop}];
        M[movie].erase({price,shop});
        S[shop].erase({movie,price});
        R.insert({price,shop,movie});
    }
    
    void drop(int shop, int movie) {
        int price = P[{movie,shop}];
        M[movie].insert({price,shop});
        S[shop].insert({movie,price});
        R.erase({price,shop,movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt =  5;
        for(auto x : R){
            if(cnt == 0) break;
            // cout << x[0] << " " << x[1] <<" " << x[2] << endl;
            res.push_back(vector<int>({x[1],x[2]}));
            cnt--;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */