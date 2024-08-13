class Solution {
public:
    void helper(vector<vector<int>> &answer, vector<int> &candidates, vector<int> &tmpCandidates, int target, int idx){
        if(target == 0){
            answer.push_back(tmpCandidates);
        }
        for(int i = idx ; i < candidates.size() ; i++){
            if(i > idx and candidates[i] == candidates[i - 1]) continue;
            if(target >= candidates[i]){
                tmpCandidates.push_back(candidates[i]);
                helper(answer, candidates, tmpCandidates, target - candidates[i], i + 1);
                tmpCandidates.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> answer;
        vector<int> tmpCandidates;
        helper(answer, candidates, tmpCandidates, target, 0);
        return answer;
    }
};
