class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> box_90(col, vector<char>(row));

        for (int i = 0; i < row; i++) {
            int cell = col - 1;
            for (int j = col - 1; j >= 0; j--) {
                if (box[i][j] == '*') {
                    cell = j - 1;
                } else if (box[i][j] == '#') {
                    box[i][j] = '.';
                    box[i][cell--] = '#';
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                box_90[j][row - i - 1] = box[i][j];
            }
        }

        return box_90;
    }
};
