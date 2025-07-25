class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> res; 
    
    
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            res.push(i);
        }
    }
    
    int reserve() {
        int ans = res.top();
        res.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        res.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
