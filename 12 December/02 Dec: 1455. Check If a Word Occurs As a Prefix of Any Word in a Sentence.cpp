class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 1; 
        while (stream >> word) {
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        return -1;
    }
};
