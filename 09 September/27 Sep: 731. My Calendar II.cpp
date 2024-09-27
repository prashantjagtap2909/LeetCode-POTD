class MyCalendarTwo {
public:
map<int , int>eventcnt;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        eventcnt[start]++;
        eventcnt[end]--;

        int curr = 0;
        for(auto &[time , change] : eventcnt){
            curr += change;
            if(curr >= 3){
                eventcnt[start]--;
                eventcnt[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
