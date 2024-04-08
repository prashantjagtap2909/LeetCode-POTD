class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int len = students.size();
        queue<int> studentQueue;
        for(auto i:students)
            studentQueue.push(i);
        stack<int> sandwichStack;
        for(int i=len-1;i>=0;i--) 
            sandwichStack.push(sandwiches[i]);
        int served=0;
        while(!studentQueue.empty() && served < studentQueue.size()) {
            if (sandwichStack.top() == studentQueue.front()) {
                sandwichStack.pop();
                studentQueue.pop(); 
                served = 0;
            } else {
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                served++;
            }
        }
        return studentQueue.size();
    }
};
