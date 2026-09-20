class MinStack {
public:
    vector<int> stk;
    MinStack() {
        stk = {};
    }
    
    void push(int val) {
        stk.push_back(val);
    }
    
    void pop() {
        if (stk.empty())
            return;
        stk.pop_back();
    }
    
    int top() {
        return stk[stk.size() -1];
    }
    
    int getMin() {
        int minVal = INT_MAX;
        if (stk.empty())
            return minVal;
        for (auto& s : stk) {
            minVal = min(s,minVal);
        }
        return minVal;
    }
};
