class Solution {
public:
    int find(int x,vector<int> &p){
        if(x==p[x])return x;
        return p[x] = find(p[x],p);
    }
    void unon(int a,int b,vector<int> &s,vector<int> &p){
        int x = find(a,p), y = find(b,p);
        if(x != y){
            if(s[x] < s[y])swap(x,y);
            s[x] += s[y];
            p[y] = x;
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size()==1)return true;
        for(auto &i: nums){
            if(i==1)return false;
        }
        int n = 1e5+2,x,y;
        sort(nums.begin(),nums.end(),[&](int &a,int &b){return a>b;});
        vector<int> p(n),s(n);
        for(int i = 0; i < n; i++){
            s[i] = 1;
            p[i] = i;
        }
        for(auto &i: nums){
            x = i;
            for(int j = 2; j <= sqrt(i); j++){
                if(x%j==0){
                    unon(i,j,s,p);
                    while(x%j==0)x /= j;
                    unon(p[i],p[j],s,p);
                }
            }
            if(x>1){
                unon(i,x,s,p);
                unon(p[i],p[x],s,p);
            }
        }
        for(auto &i: nums){
            x = i;
            for(int j = 2; j <= sqrt(i); j++){
                if(x%j==0){
                    unon(i,j,s,p);
                    while(x%j==0)x /= j;
                    unon(p[i],p[j],s,p);
                }
            }
            if(x>1){
                unon(i,x,s,p);
                unon(p[i],p[x],s,p);
            }
        }
        unordered_set<int> s1;
        for(auto &i: nums){
            s1.insert(p[i]);
        }
        return s1.size()==1;
    }
};
