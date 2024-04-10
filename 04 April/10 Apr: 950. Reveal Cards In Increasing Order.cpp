class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
         sort(deck.begin(), deck.end()); 
        
        int n = deck.size();
        vector<int> result(n);
        deque<int> indices;
        
        for (int i = 0; i < n; i++) {
            indices.push_back(i); 
        }
        
        for (int card : deck) {
            int idx = indices.front(); 
            indices.pop_front(); 
            result[idx] = card; 
            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }
        
        return result;
    }
};
