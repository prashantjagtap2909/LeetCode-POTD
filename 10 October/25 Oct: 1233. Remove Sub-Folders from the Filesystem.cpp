class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n=folder.size();
        sort(folder.begin(), folder.end());
        vector<string> ans={folder[0]};
        string prev=folder[0];
        for(int i=1; i<n; i++){
            string s=folder[i];
            if (s.find(prev+'/')!=0){
                ans.push_back(s);
                prev=s;
            }
        }
        return ans;
    }
};
