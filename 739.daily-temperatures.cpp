class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int length = temperatures.size();
        vector<int> result(length, 0);
        stack<int> s;
        stack<int> index;
        for (int i = 0; i < length; i++) {
            if (!s.empty()) {
                while (!s.empty() && temperatures[i] > s.top()) {
                    s.pop();
                    int tmp = index.top();
                    index.pop();
                    result[tmp] = i - tmp;
                }
            }

            s.push(temperatures[i]);
            index.push(i);
        }
        while (!index.empty()) {
            int tmp = index.top();
            index.pop();
            result[tmp] = 0;
        }
        return result;
    }
};
