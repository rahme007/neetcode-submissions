class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;

        for (int i = 0; i < position.size(); i++) {
            arr.push_back({position[i], i});
        }
        sort(arr.begin(), arr.end(), greater<pair<int,int>>());

        stack<float> stk;

        for (auto& x : arr) {
            float t = (float)(target - x.first)/speed[x.second];
            if (stk.empty())
                stk.push(t);
            else if (!stk.empty() && t > stk.top()) {
                stk.push(t);
            }

        }
        return stk.size();
    }
};
