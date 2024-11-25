class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int rowSize = 2;
        int colSize = 3;
        string compare = "";
        string target  = "123450";
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < colSize; j++){
                compare += to_string(board[i][j]);
            }
        }
        queue<pair<string, int>> q; 
        q.push({compare, 0});

        unordered_set<string> visited;
        visited.insert(compare);
        while(!q.empty()){
            auto[curr_state, steps] = q.front();
            q.pop();
            if(curr_state == target){
                return steps;
            }

            int zero_index = -1;
            for(int i = 0; i < curr_state.size(); i++){
                if(curr_state[i] == '0'){
                    zero_index = i;
                    break;
                }
            }
            if(zero_index == -1){
                break;
            }
            
            if(zero_index > 2){

                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index-3]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            if(zero_index < 3){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index+3]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }

            if(zero_index != 0 && zero_index != 3){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index-1]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }
            if(zero_index != 2 && zero_index != 5){
                string temp = curr_state;
                swap(temp[zero_index], temp[zero_index+1]);

                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    q.push({temp, steps+1});
                }
            }
        }
        return -1;
    }
};
