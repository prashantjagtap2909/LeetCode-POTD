struct Node{
    int count=0;
    Node *list[26]={NULL};
    bool containKey(char ch){
        return list[ch-'a']!=NULL;
    }
    Node *get(char ch){
        return list[ch-'a'];
    }
    void put(char ch,Node *new_node){
        list[ch-'a']=new_node;
    }
    void inc(char ch){
        list[ch-'a']->count+=1;
    }
    int retCount(char ch){
        return list[ch-'a']->count;
    }
};
class Solution {
private:
Node *root;
public:
    Solution(){
        root=new Node;
    }
    void insert(string word){
        Node *node=root;
        for(auto ch:word){
            if(!node->containKey(ch)){
                node->put(ch,new Node);
            }
            node->inc(ch);
            node=node->get(ch);
        }
    }
    int search(string word){
        Node *node=root;
        int preCount=0;
        for(auto ch:word){
            preCount+=node->retCount(ch);
            node=node->get(ch);
        }
        return preCount;
    }
    vector<int> sumPrefixScores(vector<string>& words) {

        for(auto word:words){
            insert(word);
        }
        int n=words.size();
        vector<int>res(n);
        for(int i=0;i<n;i++){
            int preCount=search(words[i]);
            res[i]=preCount;
        }
        return res;
    }
};
