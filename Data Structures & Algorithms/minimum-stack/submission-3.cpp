class MinStack {
public:
    vector<int> stk;
    vector<int> minStk;
    MinStack() {
        stk = {};
    }
    
    void push(int val) {
        stk.push_back(val);

        if (minStk.empty() ||val < minStk[minStk.size() -1]) {
            minStk.push_back(val);
        }
        else
            minStk.push_back(minStk[minStk.size() -1]);
    }
    
    void pop() {

        stk.pop_back();
        minStk.pop_back();
    }
    
    int top() {
        return stk[stk.size() -1];
    }
    
    int getMin() {
        return minStk[minStk.size() -1];
    }
};
